use master
go

create database QLDULICH3
go
use QLDULICH3
go

create table TINH_TP (
  quocgia nvarchar(10),
  matinhthanh nvarchar(10),
  tentt nvarchar(30),
  sodan int check (sodan > 0),
  dientich decimal,
  diemDLuathichnhat char(10),
  constraint PK_TINH_TP primary key (matinhthanh, quocgia)
);

create table QUOC_GIA (
  maqg nvarchar(10),
  tenqg nvarchar(10) UNIQUE,
  thudo nvarchar(10),
  constraint PK_QUOCGIA primary key(maqg)
);

create table DIEM_DL (
  madiadiem char(10),
  tendiadiem nvarchar(50),
  tinhtp nvarchar(10),
  quocgia nvarchar(10),
  dacdiem nvarchar(100),
  
  constraint PK_DIEM_DL primary key (madiadiem, tinhtp, quocgia)
);


alter table TINH_TP
add constraint FK_TinhTP_QuocGia
foreign key (quocgia)
references QUOC_GIA(maqg);

alter table TINH_TP
add constraint FK_TinhTP_DiemDL
foreign key (diemDLuathichnhat,matinhthanh,quocgia)
references DIEM_DL(madiadiem,tinhtp, quocgia);

alter table DIEM_DL
add constraint FK_DiemDL_TinhTP
foreign key (tinhtp, quocgia)
references TINH_TP( matinhthanh, quocgia);

alter table QUOC_GIA
add constraint FK_QuocGia_TinhTP
foreign key (thudo, maqg)
references TINH_TP(matinhthanh, quocgia);

insert into QUOC_GIA (maqg, tenqg, thudo)
values ('QG001', N'Việt Nam', null)

insert into QUOC_GIA (maqg, tenqg, thudo)
values ('QG002', N'Nhật Bản', null)

insert into TINH_TP (quocgia, matinhthanh, tentt, sodan, dientich, diemDLuathichnhat)
values ('QG001', 'TT001', N'Hà Nội', 2500000, 927.39, null)

insert into TINH_TP (quocgia, matinhthanh, tentt, sodan, dientich, diemDLuathichnhat)
values ('QG001', 'TT002', N'Huế', 5344000, 5009.00, null)

insert into TINH_TP (quocgia, matinhthanh, tentt, sodan, dientich, diemDLuathichnhat)
values ('QG002', 'TT001', N'Tokyo', 12084000, 2187.00, null)

insert into TINH_TP (quocgia, matinhthanh, tentt, sodan, dientich, diemDLuathichnhat)
values ('QG002', 'TT002', N'Osaka', 18000000, 22196, null)

insert into DIEM_DL (madiadiem, tendiadiem, tinhtp, quocgia, dacdiem)
values ('DD001', N'Văn Miếu', 'TT001', 'QG001', N'Di tích cổ')

insert into DIEM_DL (madiadiem, tendiadiem, tinhtp, quocgia, dacdiem)
values ('DD001', N'Hoàng Lăng', 'TT002', 'QG001', N'Di tích cổ')

insert into DIEM_DL (madiadiem, tendiadiem, tinhtp, quocgia, dacdiem)
values ('DD001', N'Núi Fuji', 'TT001', 'QG002', N'Núi lửa ngưng hoạt động cao nhất nhật bản')

insert into DIEM_DL (madiadiem, tendiadiem, tinhtp, quocgia, dacdiem)
values ('DD001', N'Minami', 'TT002', 'QG002', N'Quê hương của cây cầu Shinsaibashi')

insert into DIEM_DL (madiadiem, tendiadiem, tinhtp, quocgia, dacdiem)
values ('DD002', N'Lâu đài Osaka', 'TT002', 'QG002', N'Chứa bảo tàng thông tin lịch sử của lâu đài và Toyotomi Hideyoshi')

update QUOC_GIA
set thudo = 'TT001'
where maqg = 'QG001'

update QUOC_GIA
set thudo = 'TT002'
where maqg = 'QG002'

update TINH_TP
set diemDLuathichnhat = 'DD001'
where quocgia = 'QG001' and matinhthanh = 'TT001'

update TINH_TP
set diemDLuathichnhat = 'DD001'
where quocgia = 'QG002' and matinhthanh = 'TT002'