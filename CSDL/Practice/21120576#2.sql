use master
go

drop database QLDeTai
go

create database QLDeTai
go 

use QLDeTai
go

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
values ('003', N'Nguyễn Ngọc Ánh', 2200.0, N'Nữ', '1960/06/20', N'12/21 Võ Văn Ngân, Thủ Đức, TP HCM', NULL, NULL)
 


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
values ('001', '002', 1, 0.0, NULL)
 

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
 

alter table THAMGIADT 
drop constraint CK__THAMGIADT__ketqu__4222D4EF

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