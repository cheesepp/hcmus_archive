
create table  LopHoc(
  malop varchar(8),
  tenlop nvarchar(50),
  loptruong varchar(8),
  siso int,
  phong varchar(8),
  constraint PK_LopHoc primary key (malop)
)

create table ToHT(
  IDLop varchar(8),
  stt varchar(8),
  tento nvarchar(20),
  totruong varchar(8),
  constraint PK_ToHT primary key (IDLop, stt)
  )
  
create table HocVien (
  mahv varchar(8),
  hoten nvarchar(50),
  ngsinh date,
  phai nvarchar(5) check ((phai) in (N'Nam', N'Nữ')),
  IDLop varchar(8),
  IDTo varchar(8),
  constraint PK_HocVien primary key (mahv)
)

alter table ToHT
add constraint FK_ToHT_LopHoc
foreign key (IDLop)
references LopHoc(malop)

alter table HocVien
add constraint FK_HocVien_LopHoc
foreign key (IDLop)
references LopHoc(malop)

alter table HocVien
add constraint FK_HocVien_ToHT
foreign key (IDLop, IDTo)
references ToHT(IDLop, stt)

alter table LopHoc
add constraint FK_LopHoc_HocVien
foreign key (loptruong)
references HocVien(mahv)

alter table ToHT
add constraint FK_ToHT_HocVien
FOREIGN key (totruong)
REFERENCES HocVien(mahv)

insert into LopHoc(malop, tenlop, loptruong, siso, phong)
values('LH011', N'Lớp một 1', NULL, 2, 'P01')
insert into LopHoc(malop, tenlop, loptruong, siso, phong)
values('LH012', N'Lớp một 2', NULL, 2, 'P02')
insert into LopHoc(malop, tenlop, loptruong, siso, phong)
values('LH013', N'Lớp một 3', NULL, 0, 'P03')

insert into ToHT(IDLop, stt, tento, totruong)
values('LH011', '1', N'Tổ 1', NULL)
insert into ToHT(IDLop, stt, tento, totruong)
values('LH012', '1', N'Tổ 1', NULL)
insert into ToHT(IDLop, stt, tento, totruong)
values('LH012', '2', N'Tổ 2', NULL)

insert into HocVien(mahv, hoten, ngsinh, phai, IDLop, IDTo)
values('HV01', N'Bảo Duy', '2015-01-12', 'Nam', 'LH012', '1')
insert into HocVien(mahv, hoten, ngsinh, phai, IDLop, IDTo)
values('HV02', N'Kiều Linh', '2015-05-04', N'Nữ', 'LH012', '1')
insert into HocVien(mahv, hoten, ngsinh, phai, IDLop, IDTo)
values('HV06', N'Mai Anh', '2015-01-01', N'Nữ', 'LH012', '2')
insert into HocVien(mahv, hoten, ngsinh, phai, IDLop, IDTo)
values('HV03', N'Trúc An', '2015-07-15', N'Nữ', 'LH011', '1')
insert into HocVien(mahv, hoten, ngsinh, phai, IDLop, IDTo)
values('HV04', N'Gia Hào', '2015-09-28', 'Nam', 'LH012', '1')

-- cau 1
select *
from LopHoc
where siso = 0

-- cau 2
