use master
go 

create database QLCHUYENBAY
go

use QLCHUYENBAY
go

create table KHACHHANG(
	maKH varchar(3),
	tenKH nvarchar(15),
	diachi nvarchar(50),
	sodt char(12),

	constraint PK_KhachHang primary key (maKH)
)

create table NHANVIEN (
	maNV varchar(3),
	tenNV nvarchar(15),
	diachi nvarchar(50),
	luong decimal(10, 2),
	sodt char(12),
	loaiNV int check((loaiNV) in (0,1))

	constraint PK_NhanVien primary key (maNV)
)

create table LOAIMB(
	maloai varchar(15),
	hangsx nvarchar(20),

	constraint PK_LoaiMB primary key (maloai)
)

create table MAYBAY(
	sohieu int,
	maloai varchar(15),

	constraint PK_MayBay primary key (sohieu, maloai)
)

create table CHUYENBAY (
	macb varchar(4),
	sbdi varchar(3),
	sbden varchar(3),
	giodi time,
	gioden time,

	constraint PK_ChuyenBay primary key (macb)
)

create table LICHBAY (
	ngaydi date,
	macb varchar(4),
	sohieu int, 
	maloai varchar(15),

	constraint PK_LichBay primary key (ngaydi, macb)
)

create table DATCHO (
	maKH varchar(3),
	ngaydi date,
	macb varchar(4),

	constraint PK_DatCho primary key (maKH, ngaydi, macb)
)

create table KHANANG (
	maNV varchar(3),
	maloai varchar(15),

	constraint PK_KhaNang primary key (maNV, maloai)
)

create table PHANCONG (
	maNV varchar(3),
	ngaydi date,
	macb varchar(4),

	constraint PK_PhanCong primary key (maNV, ngaydi, macb)
)

------ TAO KHOA NGOAI

alter table MAYBAY
add constraint FK_MayBay_LoaiMB
foreign key (maloai)
references LOAIMB(maloai)

alter table LICHBAY
add constraint FK_LichBay_ChuyenBay
foreign key (macb)
references CHUYENBAY(macb)

alter table DATCHO
add constraint FK_DatCho_KhachHang
foreign key (maKH)
references KHACHHANG(maKH)

alter table DATCHO
add constraint FK_DatCho_LichBay
foreign key (ngaydi, macb)
references LICHBAY(ngaydi, macb)

alter table KHANANG
add constraint FK_KhaNang_NhanVien
foreign key (maNV)
references NHANVIEN(maNV)

alter table KHANANG
add constraint FK_KhaNang_LoaiMB
foreign key (maloai)
references LOAIMB(maloai)

alter table PHANCONG
add constraint FK_PhanCong_NhanVien
foreign key (maNV)
references NHANVIEN(maNV)

alter table PHANCONG
add constraint FK_PhanCong_LB
foreign key (ngaydi, macb)
references LICHBAY(ngaydi, macb)

alter table LICHBAY
add constraint FK_LB_MB
foreign key (sohieu, maloai)
references MAYBAY(sohieu, maloai)

--- THEM BO
insert into NHANVIEN
values ('1006', N'Chi', '12/6 Nguyen Kiem', '8120012', 150000, 0)

insert into NHANVIEN
values ('1005', N'Giao', '65 Nguyen Thai Son', '8324467', 500000, 0)

insert into NHANVIEN
values ('1001', N'Huong', '8 Dien Bien Phu', '8330733', 500000, 1)

insert into NHANVIEN
values ('1002', 'Phong', '1 Ly Thuong Kiet', '8308117', 450000, 1)

insert into NHANVIEN
values ('1004', N'Phuong', '351 Lac Long Quan', '8308155', 250000, 0)

insert into NHANVIEN
values ('1003', N'Quang', '78 Truong Dinh', '8324461', 350000, 1)

insert into NHANVIEN
values ('1007', N'Tam', '36 Nguyen Van Cu', '8458188', 500000, 0)


-- KHACH HANG
insert into KHACHHANG
values ('0009', N'Nga', '223 Nguyen Trai', '8932320')

insert into KHACHHANG
values ('0101', 'Anh', '567 Tran Phu', '8826729')

insert into KHACHHANG
values ('0045', 'Thu', '285 Le Loi', '8932203')

insert into KHACHHANG
values ('0012', 'Ha', '435 Quang Trung', '8933232')

insert into KHACHHANG
values ('0238', 'Hung', '456 Pasteur', '9812101')
insert into KHACHHANG
values ('0397', 'Thanh', '234 Le Van Si', '8952943')
insert into KHACHHANG
values ('0582', 'Mai', '789 Nguyen Du', null)
insert into KHACHHANG
values ('0934', 'Minh', '678 Le Lai', null)
insert into KHACHHANG
values ('0091', 'Hai', '345 Hung Vuong', '8893223')

insert into KHACHHANG
values ('0314', 'Phuong', '395 Vo Van Tan', '8232320')
insert into KHACHHANG
values ('0613', 'Vu', '348 CMT8', '8343232')
insert into KHACHHANG
values ('0586', 'Son', '123 Bach Dang', '8556223')
insert into KHACHHANG
values ('0422', 'Tien', '75 Nguyen Thong', '8332222')






