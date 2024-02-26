CREATE TABLE DOIBONG (
  madoi varchar(3),
  tendoi nvarchar(50),
  constraint PK_DoiBong primary key (madoi)
);

CREATE TABLE TRANDAU (
  matd varchar(3),
  madoi1 varchar(3),
  madoi2 varchar(3),
  sanvd nvarchar(50),
  ngaytd date,
  thanhpho nvarchar(50),
  constraint diff_doi1_doi2 check (madoi2 <> madoi1),
  constraint PK_TranDau primary key (matd)
);

CREATE TABLE THAMGIA (
  matd varchar(3),
  madoi varchar(3),
  maso varchar(3),
  phutvaosan int,
  phutroisan int,
  vtthidau nvarchar(20),
  hoten nvarchar(50),
  ngsinh date,
  
  constraint PK_ThamGia primary key (maso, madoi)
);

alter table TRANDAU
add constraint FK_TranDau_DoiBong1
foreign key (madoi1)
references DOIBONG(madoi)

alter table TRANDAU
add constraint FK_TranDau_DoiBong2
foreign key (madoi2)
references DOIBONG(madoi)

alter table THAMGIA
add constraint FK_ThamGia_DoiBong
foreign key (madoi)
references DOIBONG(madoi)

select *
from THAMGIA
where vtthidau = N'Hậu vệ' and matd = (
          select matd 
          from TRANDAU 
          where madoi1 = select (madoi from DOIBONG where tendoi = N'VIỆT NAM')
          and madoi2 =  select (madoi from DOIBONG where tendoi = N'THÁI')
          and ngaytd = '30/04/2022')
          
select *
from THAMGIA ct
where count(distinct matd) >= all (count(distinct matd) from TRANDAU td 
where ct.madoi = td.madoi1 or ct.madoi = td.madoi2)
group by ct.maso, ct.madoi