use master
go
create database QLDeTai
go
use QLDeTai
-- tạo bảng GIAOVIEN
create table GIAOVIEN(
	magv varchar(3),
	hoten nvarchar(20),
	luong float,
	phai nvarchar(10) check (phai in ('Nam', N'Nữ')),
	ngsinh date,
	diachi nvarchar(50),
	gvqlcm varchar(3),
	mabm nvarchar(10),
	constraint PK_GIAOVIEN primary key (magv)
);
 

-- tạo bảng KHOA
create table KHOA(
	makhoa varchar(10),
	tenkhoa nvarchar(20),
	namtl int,
	phong varchar(3),
	dienthoai varchar(10),
	truongkhoa varchar(3),
	ngaynhanchuc date,
	constraint PK_KHOA primary key (makhoa)
);
 

-- tạo bảng BOMON
create table BOMON(
	mabm nvarchar(10),
	tenbm nvarchar(20),
	phong varchar(3),
	dienthoai char(10),
	truongbm varchar(3),
	makhoa varchar(10),
	ngaychanchuc date,
	constraint PK_BOMON primary key (mabm)
);
 

-- tạo bảng CONGVIEC
create table CONGVIEC(
	madt varchar(3),
	sott int,
	tencv nvarchar(50),
	ngaybd date,
	ngaykt date,
	constraint PK_CONGVIEC primary key (madt, sott)
);
 

-- tạo bảng DETAI
create table DETAI (
	madt varchar(3),
	tendt nvarchar(50),
	capql nvarchar(20),
	kinhphi decimal,
	ngaybd date,
	ngaykt date,
	macd nvarchar(5),
	gvcndt varchar(3),
	constraint PK_DETAI primary key (madt)
);
 

-- tạo bảng THAMGIADT
create table THAMGIADT(
	magv varchar(3),
	madt varchar(3),
	stt int,
	phucap decimal,
	ketqua nvarchar(5),
	constraint PK_THAMGIADT primary key (magv, madt, stt)
);
 

-- tạo bảng NGUOITHAN
create table NGUOITHAN (
	magv varchar(3),
	tennt nvarchar(50),
	ngsinh date,
	phai nvarchar(4) check (phai in ('Nam', N'Nữ'))
	constraint PK_NGUOITHAN primary key (magv, tennt)
);
 

-- tạo bảng CHUDE
create table CHUDE(
	macd nvarchar(5),
	tencd nvarchar(40),
	constraint PK_CHUDE primary key (macd)
);
 

-- tạo bảng GVDT
create table GVDT(
	magv varchar(3),
	dienthoai char(10),
	constraint PK_GVDT primary key (magv, dienthoai)
);

 
-- tạo khóa ngoại FK_NguoiThan_GiaoVien
alter table NGUOITHAN
add constraint FK_NguoiThan_GiaoVien
foreign key (magv)
references GIAOVIEN(magv)
 


-- tạo khóa ngoại FK_Khoa_GiaoVien
alter table KHOA
add constraint FK_Khoa_GiaoVien
foreign key (truongkhoa)
references GIAOVIEN(magv)
 


-- tạo khóa ngoại FK_GiaoVien_GiaoVien
alter table GIAOVIEN
add constraint FK_GiaoVien_GiaoVien
foreign key (gvqlcm)
references GIAOVIEN(magv)
 


-- tạo khóa ngoại FK_GiaoVien_BoMon
alter table GIAOVIEN
add constraint FK_GiaoVien_BoMon
foreign key (mabm)
references BOMON(mabm)
 


-- tạo khóa ngoại FK_BoMon_GiaoVien
alter table BOMON
add constraint FK_BoMon_GiaoVien
foreign key (truongbm)
references GIAOVIEN(magv)
 



-- tạo khóa ngoại FK_GVDT_GiaoVien
alter table GVDT
add constraint FK_GVDT_GiaoVien
foreign key (magv)
references GIAOVIEN(magv)
 


-- tạo khóa ngoại FK_BoMon_Khoa
alter table BOMON
add constraint FK_BoMon_Khoa
foreign key (makhoa)
references KHOA(makhoa)
 



-- tạo khóa ngoại FK_ThamGiaDT_GiaoVien
alter table THAMGIADT
add constraint FK_ThamGiaDT_GiaoVien
foreign key (magv)
references GIAOVIEN(magv)
 



-- tạo khóa ngoại FK_ThamGiaDT_CongViec
alter table THAMGIADT
add constraint FK_ThamGiaDT_CongViec
foreign key (madt, stt)
references CONGVIEC(madt, sott)
  


-- tạo khóa ngoại FK_CongViec_DeTai
alter table CONGVIEC
add constraint FK_CongViec_DeTai
foreign key (madt)
references DETAI(madt)
  


-- tạo khóa ngoại FK_DeTai_ChuDe
alter table DETAI
add constraint FK_DeTai_ChuDe
foreign key (macd)
references CHUDE(macd)
  


-- tạo khóa ngoại FK_DeTai_GiaoVien
alter table DETAI
add constraint FK_DeTai_GiaoVien
foreign key (gvcndt)
references GIAOVIEN(magv)

-- nhập bảng GIAOVIEN
insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('001', N'Nguyễn Hoài An', 2000.0, 'Nam', '1973/02/15', N'25/3 Lạc Long Quân, Q.10, TP HCM', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('002', N'Trần Trà Hương', 2500.0, N'Nữ', '1960/06/20', N'125 Trần Hưng Đạo, Q.1, TP HCM', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('003', N'Nguyễn Ngọc Ánh', 2200.0, N'Nữ', '1975/05/11', N'12/21 Võ Văn Ngân, Thủ Đức, TP HCM', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('004', N'Trương Nam Sơn', 2300.0, 'Nam', '1959/06/20', N'215 Lý Thường Kiệt, TP Biên Hòa', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('005', N'Lý Hoàng Hà', 2500.0, 'Nam', '1954/10/23', N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('006', N'Trần Bạch Tuyết', 1500.0, N'Nữ', '1980/05/20', N'127 Hùng Vương, TP Mỹ Nho', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('007', N'Nguyễn An Trung', 2100.0, 'Nam', '1976/06/05', N'234 3/2, TP Biên Hòa', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('008', N'Nguyễn Trung Hiếu', 1800.0, 'Nam', '1977/08/06', N'22/11 Lý Thường Kiệt, TP Mỹ Tho', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('009', N'Trần Hoàng Nam', 2000.0, 'Nam', '1975/11/22', N'234 Trần Não, An Phú, TP HCM', NULL, NULL)
 


insert into GIAOVIEN(magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm)
values ('010', N'Pham Nam Thanh', 1500.0, 'Nam', '1980/12/12', N'221 Hùng Vương, Q.5, TP HCM', NULL, NULL)
 





-- nhập bảng BOMON
insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', NULL, NULL, NULL)
 


insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('HHC', N'Hóa hữu cơ', 'B44', '838222222', NULL, NULL, NULL)
 


insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('HL', N'Hóa lý', 'B42', '0838878787', NULL, NULL, NULL)
 


insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('HPT', N'Hóa phân tích', 'B43', '0838777777', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('MMT', N'M ạng maý tính', 'B16', '0838676767', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('SH', N'Sinh hóa', 'B33', '0838898989', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values (N'VLĐT', N'Vật lý điện tử', 'B23', '0838234234', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values (N'VLƯD', N'Vật lý ứng dụng', 'B24', '0838454545', NULL, NULL, NULL)
 

insert into BOMON(mabm, tenbm, phong, dienthoai, truongbm, makhoa, ngaychanchuc)
values ('VS', N'Vi sinh', 'B32', '0838909090', NULL, NULL, NULL)
 

-- cập nhật FK_BoMon_GiaoVien
update BOMON
set truongbm = '007', ngaychanchuc = '2007/10/15'
where mabm = 'HPT'

update BOMON
set truongbm = '002', ngaychanchuc = '2004/09/20'
where mabm = 'HTTT'

update BOMON
set truongbm = '001', ngaychanchuc = '2005/05/15'
where mabm = 'MMT'

update BOMON
set truongbm = '005', ngaychanchuc = '2006/02/18'
where mabm = N'VLƯD'

update BOMON
set truongbm = '004', ngaychanchuc = '2007/01/01'
where mabm = N'VS'



-- nhập bảng KHOA
insert into KHOA(makhoa, tenkhoa, namtl, phong, dienthoai, truongkhoa, ngaynhanchuc)
values ('CNTT', N'Công nghệ thông tin', 1995, 'B11', '0838123456',NULL,NULL)
 

insert into KHOA(makhoa, tenkhoa, namtl, phong, dienthoai, truongkhoa, ngaynhanchuc)
values ('HH', N'Hóa học', 1980, 'B41', '0838456456', NULL,NULL)
 

insert into KHOA(makhoa, tenkhoa, namtl, phong, dienthoai, truongkhoa, ngaynhanchuc)
values ('SH', N'Sinh học', 1980, 'B31', '0838454545', NULL,NULL)
 

insert into KHOA(makhoa, tenkhoa, namtl, phong, dienthoai, truongkhoa, ngaynhanchuc)
values ('VL', N'Vật lý', 1976, 'B21', '083822323', NULL,NULL)

-- cập nhật FK_Khoa_GiaoVien
update KHOA
set  truongkhoa = '002', ngaynhanchuc = '2005/02/20'
where makhoa='CNTT'

update KHOA
set  truongkhoa = '007', ngaynhanchuc = '2001/10/15'
where makhoa='HH'

update KHOA
set  truongkhoa = '004', ngaynhanchuc = '2000/10/11'
where makhoa='SH'

update KHOA
set  truongkhoa = '005', ngaynhanchuc = '2003/09/10'
where makhoa='VL'

-- cập nhật FK_GiaoVien_BoMon
update GIAOVIEN
set mabm = 'MMT'
where magv='001'or magv='009'

update GIAOVIEN
set mabm = 'HTTT'
where magv='002'or magv='003'

update GIAOVIEN
set mabm = 'VS'
where magv='004'or magv='006'

update GIAOVIEN
set mabm = N'VLĐT'
where magv='005'

update GIAOVIEN
set mabm = 'HPT'
where magv = '007'or magv = '008' or magv = '010'

-- cập nhật FK_GiaoVien_GiaoVien 
update GIAOVIEN
set gvqlcm = '002'
where mabm='HTTT' and magv != '002'

update GIAOVIEN
set gvqlcm = '004'
where mabm='VS' and magv != '004'

update GIAOVIEN
set gvqlcm = '007'
where mabm='HPT' and magv != '007'

update GIAOVIEN
set gvqlcm = '001'
where mabm='MMT' and magv != '001'

-- cập nhật FK_BoMon_Khoa
update BOMON
set makhoa = 'CNTT'
where mabm = 'CNTT' or mabm = 'HTTT' or mabm = 'MMT'

update BOMON
set makhoa = 'HH'
where mabm = 'HHC' or mabm = 'HL' or mabm = 'HPT'

update BOMON
set makhoa = 'SH'
where mabm = 'SH' or mabm = 'VS' 

update BOMON
set makhoa = 'VL'
where mabm = N'VLĐT' or mabm = N'VLƯD'


-- nhập bảng GVDT
insert into GVDT(magv, dienthoai)
values ('001', '0838912112')
 

insert into GVDT(magv, dienthoai)
values ('001', '0903123123')
 

insert into GVDT(magv, dienthoai)
values ('002', '0913454545')
 

insert into GVDT(magv, dienthoai)
values ('003', '0838121212')
 

insert into GVDT(magv, dienthoai)
values ('003', '0903656565')
 

insert into GVDT(magv, dienthoai)
values ('003', '0937125125')
 

insert into GVDT(magv, dienthoai)
values ('006', '0937888888')
 

insert into GVDT(magv, dienthoai)
values ('008', '0653717171')
 

insert into GVDT(magv, dienthoai)
values ('008', '0913232323')
 


-- nhập bảng DETAI
insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('001', N'HTTT quản lí các trường ĐH', 'ÐHQG', 20.0, '2007/10/20', '2008/10/20', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('002', N'HTTT quản lí giáo vụ cho một Khoa', N'Truờng', 20.0, '2000/10/12', '2001/10/12', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('003', N'Nghiên cứu chế tạo sợi Nanô Platin', N'ÐHQG', 300.0, '2008/05/15', '2010/05/15', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('004', N'Tái tạo vật liệu sinh học bằng màng ối người', N'Nhà nuớc', 100.0, '2007/01/01', '2009/12/31', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('005', N'Ứng dụng hóa học xanh', 'Truờng', 200.0, '2003/10/10', '2004/12/10', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('006', N'Nghiên cứu tế bào gốc', 'Nhà nước', 4000.0, '2006/10/20', '2009/10/20', NULL, NULL)
 

insert into DETAI(madt, tendt, capql, kinhphi, ngaybd, ngaykt, macd, gvcndt)
values ('007', N'HTTT quản lí thư viện của các trường ÐH', 'Trường', 20.0, '2009/05/10', '2010/05/10', NULL, NULL)


--  nhập bảng CHUDE
insert into CHUDE(macd, tencd)
values ('NCPT', N'Nghiên cứu phát triển')
 

insert into CHUDE(macd, tencd)
values ('QLGD', N'Quản lý giáo dục')
 

insert into CHUDE(macd, tencd)
values (N'ƯDCN', N'Ứng dụng công nghệ')


-- cập nhật FK_DeTai_GiaoVien
update DETAI
set gvcndt = '002'
where madt = '001' or madt = '002'

update DETAI
set gvcndt = '004'
where madt = '004' or madt = '006'

update DETAI
set gvcndt = '001'
where madt = '007'

update DETAI
set gvcndt = '005'
where madt = '003'

update DETAI
set gvcndt = '007'
where madt = '005'

-- cập nhật FK_Detai_ChuDe
update DETAI
set macd = 'QLGD'
where madt = '001' or madt = '002' or madt = '007'

update DETAI
set macd = 'NCPT'
where madt = '003' or madt = '004' or madt = '006'

update DETAI
set macd = N'ƯDCN'
where madt = '005'

-- nhập bảng CONGVIEC
insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('001', 1, N'Khởi tạo và Lập kế hoạch', '2007-10-20', '2008-12-20')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('001', 2, N'Xác đinh yêu cầu', '2008-12-21', '2008-03-21')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('001', 3, N'Phân tích hệ thống', '2008-03-22', '2008-05-22')
 


insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('001', 4, N'Thiết kế hệ thông', '2008-05-23', '2008-06-23')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('001', 5, N'Cài đặt thử nghiệm', '2008-06-24', '2008-10-20')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('002', 1, N'Khởi tạo và Lập kế hoạch', '2009-05-10', '2009-07-10')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('002', 2, N'Xác định yêu cầu', '2009-07-11', '2009-10-11')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('002', 3, N'Phân tích hệ thống', '2009-10-12', '2009-12-20')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('002', 4, N'Thiết kế hệ thống', '2009-12-21', '2010-03-22')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('002', 5, N'Cài đặt thử nghiệm', '2010-03-23', '2010-05-10')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('006', 1, N'Lấy mẫu', '2006-10-20', '2007-02-20')
 

insert into CONGVIEC(madt, sott, tencv, ngaybd, ngaykt)
values ('006', 2, N'Nuôi cấy', '2007-02-21', '2008-08-21')
 


-- nhập bảng THAMGIADT
insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('001', '001', 1, 0.0, NULL)
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('001', '002', 2, 0.0, NULL)
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('002', '001', 4, 2.0, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('003', '001', 1, 1.0, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('003', '001', 2, 0.0, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('003', '001', 4, 1.0, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('003', '002', 2, 0.0, NULL)
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('004', '006', 1, 0.0, N'Đạt')

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('004', '006', 2, 1.0, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('006', '006', 2, 1.5, N'Đạt')
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('009', '002', 3, 0.5, NULL)
 

insert into THAMGIADT(magv, madt, stt, phucap, ketqua)
values ('009', '002', 4, 1.5, NULL)


-- nhập bảng NGUOITHAN
insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('001', N'Hùng', '1990/01/14', 'Nam')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('001', N'Thủy', '1994/12/08', N'Nữ')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('003', N'Hà', '1998/09/03', N'Nữ')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('003', N'Thu', '1998/09/03', N'Nữ')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('007', N'Mai', '2003/03/26', N'Nữ')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('007', N'Vy', '2000/02/14', N'Nữ')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('008', N'Nam', '1991/05/06', N'Nam')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('009', N'An', '1996/08/19', N'Nam')
 

insert into NGUOITHAN(magv, tennt, ngsinh, phai)
values ('010', N'Nguyệt', '2006/01/14', N'Nữ')

select *
from GIAOVIEN

-- Q38 Cho biết tên giáo viên lớn tuổi nhất của bộ môn hệ thống thông tin
--select hoten, ngsinh
--from GIAOVIEN gv
--where ngsinh = (select min(ngsinh) from GIAOVIEN gv where mabm = N'HTTT' )

-- Q1. Cho biết họ tên và mức lương của các giáo viên nữ.
select hoten, luong
from GIAOVIEN
where phai = N'Nữ'

-- Q2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%
select hoten, (luong * 1.1) as luong_tang_10
from GIAOVIEN
where phai = N'Nữ'

-- Q3. Cho biết mã của các giáo viên có họ tên bắt đầu là "Nguyễn"
-- và lương trên $2000 hoặc, giáo viên là trưởng bộ môn nhận chức sau 1995.
select magv, hoten
from GIAOVIEN
where (hoten LIKE N'Nguyễn%' and luong > 2000.0)
or magv IN (select truongbm from BOMON where YEAR(ngaychanchuc) > 1995)

-- Q4 Cho biết tên những giáo viên khoa Công nghệ thông tin.
select hoten
from GIAOVIEN
where mabm IN (select bm.mabm from KHOA k join BOMON bm
              on k.makhoa = bm.makhoa where k.makhoa = 'CNTT')
              
-- Q5 Cho biết thông tin của bộ môn cùng thông tin giảng viên
-- làm trưởng bộ môn đó
select *
from BOMON bm join GIAOVIEN gv on bm.truongbm = gv.magv

-- Q6 Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc
select *
from BOMON bm join GIAOVIEN gv on bm.mabm = gv.mabm

-- Q7 Cho biết tên đề tài và giáo viên chủ nhiệm đề tài
select tendt, hoten
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
join DETAI dt on tgdt.madt = dt.madt
where gv.magv = dt.gvcndt

-- Q8 Với mỗi khoa cho biết thông tin trưởng khoa
select magv, hoten, luong, phai, ngsinh, diachi, gvqlcm, mabm
from GIAOVIEN gv join KHOA k on k.truongkhoa = gv.magv

-- Q9 Cho biết các giáo viên của bộ môn "Vi sinh" có tham gia đề tài 006
select *
from GIAOVIEN
where mabm = 'VS' and magv IN (select magv from THAMGIADT where madt = '006')

-- Q10 Với những đề tài thuộc cấp quản lí "Thành phố", cho biết mã đề 
-- tài, đề tài thuộc về chủ đề nào, họ tên người chủ nhiệm đề tài cùng Với
-- ngày sinh và địa chỉ của người ấy.
select madt, macd, hoten, ngsinh, diachi
from DETAI dt join GIAOVIEN gv on dt.gvcndt = gv.magv
where dt.capql = N'Thành phố'

-- Q11 Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp
-- của giáo viên đó
select gv.hoten, phutrach.hoten
from GIAOVIEN gv join GIAOVIEN phutrach on gv.magv = phutrach.gvqlcm

-- Q12 Tìm họ tên của những giáo viên được "Nguyễn Thanh Tùng"
-- phụ trách trực tiếp
select hoten
from GIAOVIEN
where gvqlcm = (select magv from GIAOVIEN where hoten = N'Nguyễn Thanh Tùng')

-- Q13 Cho biết tên giáo viên là trưởng bộ môn "Hệ thống thông tin"

select hoten
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
where bm.tenbm = N'Hệ thống thông tin'

--- Q14 Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề
-- Quản lý giáo dục
select hoten
from GIAOVIEN gv join DETAI dt on dt.gvcndt = gv.magv
where dt.macd = (select macd from CHUDE where tencd = N'Quản lý giáo dục')

-- Q15 Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời
-- gian bắt đầu trong tháng 3/2008
select tencv
from CONGVIEC cv join DETAI dt on dt.madt = cv.madt
where tendt = N'HTTT quản lý các trường ĐH' and (cv.ngaybd >= '2008-03-01' and cv.ngaybd <=  '2008-03-31')

-- Q16 Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó.
select gv.hoten, phutrach.hoten
from GIAOVIEN gv join GIAOVIEN phutrach on gv.magv = phutrach.gvqlcm

-- Q17 Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007
select *
from CONGVIEC
where ngaybd between '01/01/2007' and '01/08/2007'

-- Q18 Cho biết họ tên các giáo viên cùng bộ môn với giáo viên
-- "Trần Trà Hương"
select hoten
from GIAOVIEN
where mabm = (select mabm from GIAOVIEN where hoten = N'Trần Trà Hương')
except
select hoten from GIAOVIEN where hoten = N'Trần Trà Hương'

-- Q19 Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài
select *
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select gvcndt from DETAI)

-- Q20 Cho biết tên những giáo viên vừa chủ nhiệm đề tài
select hoten
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select truongkhoa from KHOA)

-- Q21 Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài
select hoten
from GIAOVIEN
where magv IN (select truongbm from BOMON) and magv IN (select gvcndt from DETAI)

-- Q22 Cho biết mã số các trưởng khoa có chủ nhiệm đề tài
select magv
from GIAOVIEN
where magv IN (select gvcndt from DETAI) and magv IN (select truongkhoa from KHOA)

-- Q23 Cho biết mã số các giáo viên thuộc bộ môn "HTTT" hoặc có tham gia đề tài mã "001"
select gv.magv
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
where gv.mabm = N'HTTT' or tgdt.madt = '001'

-- Q24 Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002
select *
from GIAOVIEN
where mabm = (select mabm from GIAOVIEN where magv = '002')

-- Q25 Tìm những giáo viên là trưởng bộ môn
select *
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
where gv.magv = bm.truongbm

-- Q26 Cho biết họ tên và mức lương của các giáo viên
select hoten, luong
from GIAOVIEN

-- Q27 Cho biết số lượng giáo viên viên và tổng lương của họ.
select count(magv) soluonggiaovien, sum(luong) tongluong
from GIAOVIEN

-- Q28 Cho biết số lượng giáo viên và lương trung bình của từng bộ môn.
select count(magv) soluonggiaovien, AVG(luong) luongtrungbinh
from GIAOVIEN
group by mabm

-- Q29 Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó.
select tencd, count(madt) soluongdetai
from CHUDE cd left join DETAI dt on cd.macd = dt.macd
group by cd.macd, tencd

-- Q30 Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó tham gia.
select hoten, count(distinct madt) sodetai
from GIAOVIEN gv left join THAMGIADT tgdt on gv.magv = tgdt.magv
group by gv.magv, gv.hoten

-- Q31 Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó làm chủ nhiệm.
select hoten, count(madt) soluongdetai
from GIAOVIEN gv join DETAI dt on gv.magv = dt.gvcndt
group by gv.magv, gv.hoten

-- Q32 Với mỗi giáo viên cho tên giáo viên và số người thân của giáo viên đó.
select gv.hoten, count(tennt) songuoithan
from GIAOVIEN gv join NGUOITHAN nt on gv.magv = nt.magv
group by gv.magv, gv.hoten

-- Q33 Cho biết tên những giáo viên đã tham gia từ 3 đề tài trở lên.
select gv.hoten, count(distinct madt) sodetai
from GIAOVIEN gv join THAMGIADT tgdt on gv.magv = tgdt.magv
group by gv.magv, gv.hoten
having count(madt) > 3

-- Q34 Cho biet so luong giao vien da tham gia vao de tai Ung dung hoa hoc xanh
select count(tgdt.magv) soluonggiaovien
from THAMGIADT tgdt join DETAI dt on tgdt.madt = dt.madt
where dt.tendt = N'Ứng dụng hóa học xanh'
group by dt.tendt

-- Q35 Cho biết mức lương cao nhất của các giảng viên
select max(luong) mucluongcaonhat
from GIAOVIEN

-- Q36 Cho biết những giáo viên có lương lớn nhất
select *
from GIAOVIEN
where luong >= all(select max(luong) from GIAOVIEN)

-- Q37 Cho biết lương cao nhất trong bộ môn HTTT
select max(luong) luongcaonhatHTTT
from GIAOVIEN
where mabm = 'HTTT'

-- Q38 Cho biết tên giáo viên lớn tuổi nhất của bộ môn HTTT
select hoten
from GIAOVIEN
where mabm = 'HTTT' and ngsinh <= all (select min(ngsinh) from GIAOVIEN where mabm = 'HTTT')

-- Q39 Cho biết tên giáo viên nhỏ tuổi nhất khoa Công nghệ thông tin
select *
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
where bm.makhoa = 'CNTT' and gv.ngsinh >= all (select max(ngsinh) from GIAOVIEN gv
                                                join BOMON bm on gv.mabm = bm.mabm
                                                where bm.makhoa = 'CNTT')
                                                

-- Q40 Cho biết tên giáo viên và tên khoa của giáo viên có lương cao nhất
select gv.hoten, k.tenkhoa
from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm join KHOA k on bm.makhoa = k.makhoa
where luong >= all (select max(luong) from GIAOVIEN)

-- Q41 Cho biết tên những giáo viên có lương lớn nhất trong bộ môn của họ
select hoten
from GIAOVIEN
where luong in (select max(luong) from GIAOVIEN group by mabm)

-- Q42 Cho biết tên những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia
select distinct dt.tendt
from DETAI dt left join THAMGIADT tgdt on dt.madt = tgdt.madt
where tgdt.madt != '001' or tgdt.madt is null

-- Q43 Cho biết những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia. Xuất ra tên đề tài, tên người chủ nhiệm đề tài

-- Q58 Cho biết tên giáo viên nào mà tham gia đề tài đủ tất cả các chủ đề
select gv.magv, gv.hoten
from GIAOVIEN gv join THAMGIADT tg on gv.magv = tg.magv
where not exists (
  select macd from CHUDE s
  where not exists (
        select macd from THAMGIADT r join DETAI dt on dt.madt = r.madt
        where tg.magv = r.magv and dt.macd = s.macd
  )
)

-- Q59 Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn HTTT tham gia
-- c1
select distinct dt.tendt
from THAMGIADT tg join DETAI dt on tg.madt = dt.madt
where not exists (
        select magv from GIAOVIEN s where mabm = 'HTTT'
        and not exists (
              select magv from THAMGIADT r where s.magv = r.magv and tg.madt = r.madt
        )
      )

-- c2 not in
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt
where not exists (
      select s.magv from GIAOVIEN s where mabm = 'HTTT'
      and s.magv not in (
              select tg.magv from THAMGIADT tg where tg.madt = r.madt
      )
)

-- c3 except
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt
where not exists (
      select magv from GIAOVIEN s where mabm = 'HTTT'
      except
      select magv from THAMGIADT tg where tg.madt = r.madt
)

-- c4 group by having
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt join GIAOVIEN gv on r.magv = gv.magv
where gv.mabm = 'HTTT'
group by dt.tendt, dt.madt	
having count(distinct gv.magv) = (select count(distinct magv) from GIAOVIEN where mabm = 'HTTT')
-- Q60 Cho biết tên đề tài có tất cả giảng viên bộ môn "Hệ thống thông tin" tham gia
-- c1 not exists
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt
where not exists (
      select magv from GIAOVIEN gv join BOMON bm on gv.mabm = bm.mabm
      where bm.tenbm = N'Hệ thống thông tin'
      and not exists (
        select madt from THAMGIADT s where gv.magv = s.magv and s.madt = r.madt 
      )
    )
-- c2 not in
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt
where not exists (
      select s.magv from GIAOVIEN s join BOMON bm on s.mabm = bm.mabm
      where bm.tenbm = N'Hệ thống thông tin'
      and s.magv not in (
        select madt from THAMGIADT tg where tg.madt = r.madt 
      )
    )
-- c3 except
select distinct dt.tendt
from THAMGIADT r join DETAI dt on r.madt = dt.madt
where not exists (
      select magv from GIAOVIEN s join BOMON bm on s.mabm = bm.mabm
      where bm.tenbm = N'Hệ thống thông tin'
      except
      select magv from THAMGIADT tg where tg.madt = r.madt
)

-- Q61 Cho biết tên giáo viên nào đã tham gia tất cả các đề tài có mã chủ đề là QLGD
-- c1 not exists
select r.magv
from GIAOVIEN r
where not exists (
    select macd from CHUDE s where macd = 'QLGD'
    and not exists (
        select macd from THAMGIADT tg join DETAI dt on dt.madt = tg.madt
        where r.magv = tg.magv and s.macd = dt.macd and dt.macd = 'QLGD'
    )
)

-- c2 except
select r.magv
from GIAOVIEN r
where not exists (
    select macd from CHUDE s where macd = 'QLGD'
    except
    select macd from THAMGIADT tg join DETAI dt on dt.madt = tg.madt
        where r.magv = tg.magv and dt.macd = 'QLGD'
)

--test
select gv.magv
from GIAOVIEN gv
where not exists (
        select dt.madt from DETAI dt where dt.macd = N'ƯDCN'
        except
        select tg.madt from THAMGIADT tg where tg.madt = gv.magv
      )

-- c3 not in
select r.hoten,r.magv
from GIAOVIEN r
where not exists (
    select s.madt from DETAI s where macd = 'QLGD'
    and s.madt not in (
    select dt.macd from THAMGIADT tg join DETAI dt on dt.madt = tg.madt
        where r.magv = tg.magv and dt.macd = 'QLGD'
        )
)

-- Q61 Cho biết tên giáo viên nào đã tham gia tất cả các đề tài có mã chủ đề là QLGD
-- c4 group by having
select r.hoten, r.magv, count(distinct dt.madt)
from GIAOVIEN r join THAMGIADT tg on r.magv = tg.magv join DETAI dt on tg.madt = dt.madt
where dt.macd = 'QLGD'
group by r.hoten, r.magv
having count(distinct dt.madt) = (select count(distinct madt) from  DETAI where macd = 'QLGD')
select*from DETAI
select*from THAMGIADT

-- Q62 Cho biết tên giáo viên nào tham gia tất cả các đề tài
-- mà giáo viên Trần Trà Hương đã tham gia
select hoten
from GIAOVIEN r
where not exists (
      select dt1.madt from DETAI dt1
      join GIAOVIEN gv1 on gv1.magv = dt1.gvcndt
      where dt1.gvcndt = '002'
      except
      select tg.madt from THAMGIADT tg join DETAI dt on dt.madt = tg.madt
      join GIAOVIEN gv on gv.magv = dt.gvcndt
      where dt.gvcndt = '002' and gv.magv = r.magv 
)


-- 1. Viết stored thực hiện phân công 1 giảng viên tham gia 1 công việc của 1 đề tài cụ thể. Lưu ý:
-- mỗi giảng viên chỉ được tham gia tối đa 3 công việc của 1 đề tài. Nếu vi phạm thì báo lỗi
-- không thực hiện phân công
create proc phanCongTG
	@magv varchar(3),
	@madt varchar(3),
	@stt varchar(3)
as
begin

	if not exists (select * from CONGVIEC where madt = @madt and sott = @stt)
	begin
		raiserror(N'Không tồn tại công việc cần phân công!', 15, 1)
	end
	

	if not exists (select * from DETAI where madt = @madt)
	begin
		raiserror(N'Không tồn tại đề tài cần phân công!', 15, 1)
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
	@gvqlcm varchar(3),
	@mabm varchar(3)
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
	if not exists (select mabm from BOMON where mabm = @mabm)
	begin
		raiserror(N'Không tồn tại bộ môn cần thực hiện!', 15, 1)
	end
	if not exists(select mabm from GIAOVIEN where magv=@magv
					intersect
					select mabm from GIAOVIEN where magv=@gvqlcm)
	begin
		raiserror(N'Giáo viên cần thêm quản lí chuyên môn và giáo viên quản lí chuyên môn không chung bộ môn!', 15, 1)
	end
	update GIAOVIEN
	set gvqlcm = @gvqlcm
	where mabm = @mabm and magv = @magv
end
go
capNhatGVQLCM '001', '002', 'MMT'
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
--thành; FAILED: &lt;=50% đạt và còn công việc chưa hoàn thành)
go
create proc nghiemThuDT
as
begin
	select madt,
	100.0 * dat / sodt as tyledat,
	100.0 * khdat / sodt as tylekhongdat,
	100.0 * chuahthanh / sodt as tylechuahoanthanh ,
	case
		when dat = sodt then N'GIỎI'
		when dat >= 0.8 * sodt and chuahthanh = 0 then N'KHÁ'
		when dat >= 0.7 * sodt and khdat >= 0.3*sodt and chuahthanh = 0 then N'TRUNG BÌNH'
		when dat <= 0.5 * sodt and chuahthanh <> 0 then 'FAILED'
	end as xeploaidt
	from (select madt, count(*) as sodt,
		  sum(case when ketqua = N'Đạt' then 1 else 0 end) as dat,
		  sum(case when ketqua = N'Không đạt' then 1 else 0 end) as khdat,
		  sum(case when ketqua is NULL then 1 else 0 end) as chuahthanh
		  from THAMGIADT
		  group by madt
		  ) as kqua
end
go
nghiemThuDT
select * from THAMGIADT
select madt, count(*) as sodt,
		  sum(case when ketqua = N'Đạt' then 1 else 0 end) as hoanthanh,
		  sum(case when ketqua = N'Không đạt' then 1 else 0 end) as khthanh,
		  sum(case when ketqua is NULL then 1 else 0 end) as chuahthanh
		  from THAMGIADT
		  group by madt
go
--9. Viết store phân công 1 giáo viên chủ nhiệm 1 đề tài cụ thể với điều kiện: Tại thời điểm phân
--công, giáo viên chỉ được chủ nhiệm tối đa 3 đề tài (kể cả đề tài chưa kết thúc).
create proc phanCongGVCN
	@gvcndt varchar(3),
	@madt varchar(3)
as
begin
	if not exists (select magv from GIAOVIEN where magv = @gvcndt)
	begin 
		raiserror(N'Không tồn tại giáo viên!', 15, 1)
	end
	if not exists (select madt from DETAI where madt = @madt)
	begin 
		raiserror(N'Không tồn tại đề tài!', 15, 1)
	end
	
	if exists (select * from DETAI where madt = @madt and gvcndt = @gvcndt)
	begin
		raiserror(N'Giáo viên đã chủ nhiệm đề tài này!', 15, 1)
	end
	
	if exists (select count(*) from DETAI where gvcndt = @gvcndt group by gvcndt having count(*) >= 3)
	begin
		raiserror(N'Giáo viên đã chủ nhiệm tối đa 3 đề tài!', 15, 1)
	end
	update DETAI
	set gvcndt = @gvcndt
	where madt = @madt
end
go
phanCongGVCN '005', '003' 



		

--10. Viết stored đếm số lượng giảng viên nam, nữ của mỗi đề tài
create proc demNamNu
as
begin
	select count(*), gv.phai, tg.madt from GIAOVIEN gv join THAMGIADT tg
	on gv.magv = tg.magv
	group by gv.phai, tg.madt
end
go
demNamNu


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
declare @hehe int
set @hehe = dbo.demSoKQDat(@madt)
print 'So cong viec co ket qua Dat cua de tai ' + @madt +' la ' + cast(@hehe as varchar(5))

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


