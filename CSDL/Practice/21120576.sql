use QLDeTai

-- 1. Viết stored thực hiện phân công 1 giảng viên tham gia 1 công việc của 1 đề tài cụ thể. Lưu ý:
-- mỗi giảng viên chỉ được tham gia tối đa 3 công việc của 1 đề tài. Nếu vi phạm thì báo lỗi
-- không thực hiện phân công
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
select * from THAMGIADT
go
--2. Viết store thực hiện cập nhật ngày kết thúc của dự án. Lưu ý, ngày kết thúc phải sau ngày
--bắt đầu theo quy định:
-- Đề tài cấp trường: thời gian thực hiện tối thiểu là 3 tháng, tối đa là 6 tháng
-- Đề tài cấp ĐHQG thời gian thực hiện tối thiểu là 6 tháng, tối đa là 9 tháng
-- Đề tài cấp nhà nước thời gian thực hiện tối thiểu là 12 tháng, tối đa là 24 tháng
create proc capNhatNgayKTDT
	@madt varchar(3),
	@ngayKT date
as
begin

	if not exists (select * from DETAI where madt = @madt)
	begin
		raiserror(N'Mã đề tài này không tồn tại!', 15, 1)
	end

	if exists (select * from DETAI where madt = @madt and capql = N'Trường' and DATEADD(MONTH, -3, ngaybd) < @ngayKT or DATEADD(MONTH, -6, ngaybd) > @ngayKT) 
	begin
		raiserror(N'Thời gian thực hiện của đề tài cấp quản lí Trường phải từ 3 đến 6 tháng!', 15, 1)
	end
	if exists (select * from DETAI where madt = @madt and capql = N'ĐHQG' and DATEADD(MONTH, -6, ngaybd) < @ngayKT or DATEADD(MONTH, -9, ngaybd) > @ngayKT) 
	begin
		raiserror(N'Thời gian thực hiện của đề tài cấp quản lí ĐHQG phải từ 6 đến 9 tháng!', 15, 1)
	end
	if exists (select * from DETAI where madt = @madt and capql = N'Nhà nước' and DATEADD(MONTH, -12, ngaybd) < @ngayKT or DATEADD(MONTH, -24, ngaybd) > @ngayKT) 
	begin
		raiserror(N'Thời gian thực hiện của đề tài cấp quản lí Nhà nước phải từ 12 đến 24 tháng!', 15, 1)
	end
	update DETAI
	set ngaykt = @ngayKT
	where madt = @madt
end
go
capNhatNgayKTDT '001', '2008-11-20'
select * from DETAI
go
-- 3. Viết store thực hiện cập nhật giáo viên quản lý chuyên môn cho 1 giảng viên cụ thể. Lưu ý,
-- GVQLCM phải cùng bộ môn với giảng viên cần cập nhật.
create proc capNhatGVQLCM
	@magv varchar(3),
	@gvqlcm varchar(3)
as
begin
	if not exists (select magv from GIAOVIEN where magv = @magv)
	begin
		raiserror(N'Không tồn tại giáo viên cần thêm gvqlcm!', 15, 1)
	end
	if not exists (select magv from GIAOVIEN where magv = @gvqlcm)
	begin
		raiserror(N'Không tồn tại giáo viên quản lí chuyên môn!', 15, 1)
	end
	if not exists(select mabm from GIAOVIEN where magv=@magv
					intersect
					select mabm from GIAOVIEN where magv=@gvqlcm)
	begin
		raiserror(N'Giáo viên cần thêm quản lí chuyên môn và giáo viên quản lí chuyên môn không chung bộ môn!', 15, 1)
	end
	update GIAOVIEN
	set gvqlcm = @gvqlcm
	where magv = @magv
end
go
capNhatGVQLCM '001', '002'
go
--4. Viết stored thực hiện cập nhật trưởng khoa cho 1 khoa cụ thể. Lưu ý, trưởng khoa phải là
--người trong khoa và không được kiêm nhiệm chức vụ khác (trưởng bộ môn, gvqlcm)
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
	update khoa
	set truongkhoa = @truongkhoa
	where makhoa = @makhoa
	
end
go

capNhatTK '001', 'CNTT'
go
-- 5. Viết stored đếm số lượng công việc có kết quả “Đạt” của mỗi đề tài
create proc soLuongDat
as
begin
	select madt, count(*)
	from THAMGIADT
	where ketqua = N'Đạt'
	group by madt

end
go
soLuongDat
go
-- 6. Viết stored đếm số lượng công việc có kết quả: “Không đạt” của mỗi đề tài
create proc soLuongKDat
as
begin
	select madt, count(*)
	from THAMGIADT
	where ketqua = N'Không đạt'
	group by madt

end
go

soLuongKDat
go
--7. Viết stored đếm số lượng công việc chưa có kết quả: “NULL” của mỗi đề tài
create proc soLuongChuaKQ
as
begin
	select madt, count(*)
	from THAMGIADT
	where ketqua is NULL
	group by madt

end
go

soLuongChuaKQ

--8. Với mỗi đề tài đã kết thúc, xuất kết quả nghiệm thu đề tài:
-- Mã đề tài:
-- Tỷ lệ đạt:
-- Tỷ lệ không đạt:
-- Tỷ lệ chưa hoàn thành (NULL):
-- XẾP LOẠI ĐỀ TÀI: (GIỎI: 100% đạt; KHÁ: 80% đạt và không có công việc nào chưa
--hoàn thành; TRUNG BÌNH: 70% đạt, 30% không đạt, không có công việc chưa hoàn
--thành; FAILED: <= 50% đạt và còn công việc chưa hoàn thành)
go
create proc nghiemThuDT
as
begin
	select madt,
	100.0 * dat / socv as tyledat,
	100.0 * khdat / socv as tylekhongdat,
	100.0 * chuahthanh / socv as tylechuahoanthanh ,
	case
		when dat = socv then N'GIỎI'
		when dat >= 0.8 * socv and chuahthanh = 0 then N'KHÁ'
		when dat >= 0.7 * socv and khdat >= 0.3*socv and chuahthanh = 0 then N'TRUNG BÌNH'
		when dat <= 0.5 * socv and chuahthanh <> 0 then 'FAILED'
	end as xeploaidt
	from (select distinct jointable.madt, count(jointable.sott) as socv,
		 sum(case when ketqua = N'Đạt' then 1 else 0 end) as dat,
		 sum(case when ketqua = N'Không đạt' then 1 else 0 end) as khdat,
		 sum(case when ketqua is NULL then 1 else 0 end) as chuahthanh
		  from (select dt.madt, cv.sott, ketqua from DETAI dt join CONGVIEC cv on dt.madt = cv.madt left join THAMGIADT tg on dt.madt = tg.madt group by dt.madt, cv.sott, ketqua) as jointable
		  group by jointable.madt
		  ) as kqua
end
go
nghiemThuDT

select *
from DETAI dt left join THAMGIADT tg on dt.madt = tg.madt