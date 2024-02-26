-- 1. Viết function
-- Đếm số đề tài tham gia của 1 mã giảng viên cho trước

create function demSoDT(@magv varchar(3))
returns int
as
	begin
		return( select count(distinct madt) from THAMGIADT where magv = @magv)
	end
go
print dbo.demSoDT( '001')

-- Đếm số công việc đã tham gia của một giảng viên
create function demSoCV(@magv varchar(3))
returns int
as
	begin
		return (select count(*) from THAMGIADT where magv = @magv)
	end
go
print dbo.demSoCV('001')

-- Tính tổng phụ cấp đã chi cho 1 giảng viên trong 1 đề tài
create function tongPhuCap (@magv varchar(3), @madt varchar(3))
returns int
as
	begin
		return (select sum(phucap) from THAMGIADT where magv = @magv and madt = @madt)
	end
go

declare @magv varchar(3)
set @magv = '001'
declare @madt varchar(3)
set @madt = '002'
print 'Tong phu cap cua giang vien ' + @magv + ' cua de tai ' + @madt + ' la ' + cast(dbo.tongPhuCap(@magv, @madt) as varchar(10))

-- Tính tổng phụ cấp đã chi cho 1 đề tài
create function tongPhuCapCho1DT(@madt varchar(3))
returns int
as
	begin
		return (select sum(phucap) from THAMGIADT where madt = @madt)
	end
go

declare @madt varchar(3)
set @madt = '002'
print 'Tong phu cap của de tai ' + @madt + ' la ' + cast(dbo.tongPhuCapCho1DT(@madt) as varchar(10))

-- Đếm số công việc có kết quả “Đạt” của 1 đề tài
create function demSoKQDat (@madt varchar(3))
returns int
as
	begin
		return (select count(*) from THAMGIADT where madt = @madt and ketqua = N'Đạt')
	end
go

declare @madt varchar(3)
set @madt = '002'
print 'So cong viec co ket qua Dat cua de tai ' + @madt +' la ' + cast(dbo.demSoKQDat(@madt))

-- Đếm số công việc có kết quả “Không đạt” của một đề tài
create function demSoKQKDat (@madt varchar(3))
returns int
as
	begin
		return (select count(*) from THAMGIADT where madt = @madt and ketqua = N'Không đạt')
	end
go


declare @madt varchar(3)
set @madt = '002'
print 'So cong viec co ket qua Khong dat cua de tai ' + @madt +' la ' + cast(dbo.demSoKQKDat(@madt))

-- Viết stored procedure
-- 1. Cho danh sách (mã đề tài, tên đề tài, tổng phụ cấp thực chi của đề tài, kinh phí của đề tài, tình trạng). Với Tình trạng là 
--“Đủ kinh phí” : nếu thục chi = kinh phí
-- “Vượt kinh phí”, nếu thực chi > kinh phí
--“Dư kinh phí”. Nếu thực chi < kinh phí

create or alter proc DanhGia
as
	begin
		select madt, tendt, tong, kinhphi, tinhtrang
		from (
			select tg.madt, tendt, sum(tg.phucap) as tong, kinhphi,
			case
				when sum(phucap) > kinhphi then N'Vượt kinh phí'
				when sum(phucap) < kinhphi then N'Dư kinh phí'
				when sum(phucap) = kinhphi then N'Đủ kinh phí'
			end as tinhtrang
			from THAMGIADT tg join DETAI dt on tg.madt = dt.madt
			group by tg.madt, tendt, kinhphi
		) as kqua
	end
go
DanhGia

-- 2. Cho danh sách các đề tài gồm (mã đề tài, tên đề tài, xếp loại đề tài). Biết:
--Xếp loại “đạt”, nếu >= 70%, <=90 công việc có kết quả đạt 
--Xếp loại “xuất sắc” nếu > 90% kết quả đạt
--Ngược lại: Xếp loại “ Không đạt”

create proc xepLoai
as
begin
	select madt,
	tendt,
	case
		when dat > 0.9 * socv then N'Xuất sắc'
		when dat >= 0.7 * socv and dat <= 0.9 * socv then N'Đạt'
		else N'Không đạt'
	end as xeploaidt
	from (select distinct jointable.madt, count(jointable.sott) as socv, tendt,
		 sum(case when ketqua = N'Đạt' then 1 else 0 end) as dat,
		 sum(case when ketqua = N'Không đạt' then 1 else 0 end) as khdat,
		 sum(case when ketqua is NULL then 1 else 0 end) as chuahthanh
		  from (select dt.madt, dt.tendt, cv.sott, ketqua from DETAI dt join CONGVIEC cv on dt.madt = cv.madt left join THAMGIADT tg on dt.madt = tg.madt group by dt.madt, dt.tendt, cv.sott, ketqua) as jointable
		  group by jointable.madt, jointable.tendt
		  ) as kqua
end
go
xepLoai

-- 3. Phân công công việc cho 1 giảng viên trong 1 đề tài. Biết rằng, mỗi giảng viên không tham gia quá 3 công việc trong 1 đề tài

create proc phanCongTG
	@magv varchar(3),
	@madt varchar(3),
	@stt varchar(3)
as
begin

	if not exists (select * from DETAI where madt = @madt)
	begin
		raiserror(N'Không tồn tại đề tài cần phân công!', 15, 1)
	end

	if not exists (select * from CONGVIEC where madt = @madt and sott = @stt)
	begin
		raiserror(N'Không tồn tại công việc cần phân công!', 15, 1)
	end

	if not exists (select * from GIAOVIEN where magv = @magv)
	begin
		raiserror(N'Không tồn tại giáo viên cần phân công!', 15, 1)
	end

	if exists (select * from THAMGIADT where magv = @magv and madt = @madt and stt = @stt)
	begin
		raiserror(N'Giáo viên đã tham gia vào công việc của đề tài này!', 15, 1)
	end

	if exists (select count(*) from THAMGIADT where magv = @magv and madt = @madt group by magv, madt having count(*) >= 3)
	begin
		raiserror(N'Giảng viên đã tham gia tối đa 3 công việc! Không phân công!', 15, 1)
	end
	
	insert into THAMGIADT
	values(@magv, @madt, @stt, 0.0, NULL)
end
go

phanCongTG '006', '006', '2'

-- 4. Cập nhật trưởng khoa cho 1 khoa bất kỳ theo các bước:
-- Kiểm tra mã trưởng khoa có thuộc tập giáo viên không
-- Kiểm tra trưởng khoa có đang kiêm nhiệm: trưởng bộ môn hay đang là trưởng 1 khoa không?
-- Trưởng khoa phải trên 37 tuổi, và phải là giáo viên trong khoa
-- Trưởng khoa phải chủ nhiệm ít nhất là 2 đề tài.
-- Nếu vi phạm bất cứ 1 yêu cầu nào ở trên, báo lỗi và thoát
-- Ngược lại: thực hiện cập nhật trưởng khoa cho khoa.
create proc capNhatTK 
	@truongkhoa varchar(5),
	@makhoa varchar(5) 
as
begin
	if not exists (select magv from GIAOVIEN where magv = @truongkhoa)
	begin
		raiserror(N'trưởng khoa này không tồn tại!',15,1)
		return 1
	end
	if not exists (select makhoa from KHOA where makhoa = @makhoa)
	begin
		raiserror(N'khoa này không tồn tại!', 15,1)
		return 1
	end
	if not exists (select magv from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
					where magv = @truongkhoa and bm.makhoa = @makhoa)
	begin
		raiserror(N'Giáo viên được xét làm trưởng khoa không thuộc khoa đó!', 15, 1)
		return 2
	end
	if not exists (select gvqlcm from GIAOVIEN where gvqlcm = @truongkhoa) and 
	   not exists (select truongbm from BOMON where truongbm = @truongkhoa)
	begin
		raiserror(N'Giảng viên được xét không được kiêm nhiệm chức vụ khác!', 15, 1)
		return 3
	end
	
	if exists (select magv from GIAOVIEN where magv = @truongkhoa and DATEADD(YEAR, 37, ngsinh) > 2023)
	and not exists (select truongkhoa from KHOA where truongkhoa = @truongkhoa and makhoa = @makhoa)
	begin
		raiserror(N'Giảng viên phải lớn hơn 37 tuổi và là giáo viên trong khoa!', 15, 1)
		return 4
	end
	update khoa
	set truongkhoa = @truongkhoa
	where makhoa = @makhoa
	
end
go

capNhatTK '001', 'CNTT'

-- 5. Thêm mới cột SoGV_BM vào bảng bộ môn. Thực hiện cập nhật số giảng viên cho các bộ môn
create or alter proc themCot
as
	begin
		alter table BOMON
		add sogv_bm int

		update BOMON set sogv_bm = T.sogv
		from (select mabm, count(*) as sogv from GIAOVIEN group by mabm) as T
		where BOMON.mabm = T.mabm
	end
go

-- 6. Tạo 1 report, cho biết mã gv, họ tên, số đề tài đã tham gia
create or alter proc soDTTG
as
	begin
		select gv.magv, hoten, count(distinct madt) as soDTTG
		from GIAOVIEN gv join THAMGIADT tg on gv.magv = tg.magv
		group by gv.magv, hoten
	end
go
soDTTG