use master
go

create database QLCLBCovua
go

use QLCLBCovua

create table CLB(
	IDCLB varchar(10),
	TenCLB nvarchar(50),
	Diachi nvarchar(40),
	
	constraint PK_CLB primary key (IDCLB)
)

create table DOI(
	IDCLB varchar(10),
	IDDoi varchar(10),
	TenDOI nvarchar(30),
	IDDoiTruong varchar(10),

	constraint PK_DOI primary key (IDDoi, IDCLB)
)

create table HOIVIEN (
	IDCLB varchar(10),
	IDHoiVien varchar(10),
	TenHV nvarchar(30),
	Ngaysinh datetime,
	IDDoi varchar(10),
	IDBanCungTapLuyeb varchar(10),
	
	constraint PK_HOIVIEN primary key (IDHoiVien, IDCLB)
)