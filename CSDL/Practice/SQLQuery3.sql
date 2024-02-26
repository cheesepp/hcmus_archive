use QLKhoaLuan
go

select * from LichBaoVe
select * from GiaoVien
create or alter proc tongKet
as
begin
	select MaSV, 
	(case when Diem_PB <= 8 then tongct + tonguv + Diem_HD - 0.5 else tongct + tonguv + Diem_HD + 0.5 end) as tong
	from (
		select distinct MaSV, 
		(case when CDKH = 'PSG-TS' then Diem_CT * 1.5 else Diem_CT * 1.2 end) as tongct,
		(case when CDKH = 'PSG-TS' then DIEM_UV + 3 else DIEM_UV + 1.5 end) as tonguv,
		Diem_PB, 
		Diem_HD
		from LichBaoVe lbv join HoiDong hd on lbv.Nam = hd.Nam and lbv.MaNganh = hd.MaNganh
		and lbv.Dot_BV = hd.Dot_BV join GiaoVien gv on gv.MaGV = hd.ChuTichHD or gv.MaGV = hd.UyVien
		or gv.MaGV = hd.ThuKy
	) as tongDiem
end
go
tongKet

--cho biết giáo viên nào của ngành Hệ thống thông tin
--đã tham gia tất cả hội đồng bảo vệ Năm 2021  của loại đề tài Dự án tốt nghiệp
select * from GiaoVien
select * from Loai_DeTai
select * from Nganh
select * from HoiDong
select * from DeTai_TN
select * from LichBaoVe

select MaGV
from GIAOVIEN r join Nganh n on r.MaNganh = n.MaNganh
where TenNganh = N'Hệ thống thông tin'
and
not exists (
	select  hd.Dot_BV from HoiDong hd join LichBaoVe lbv on hd.Dot_BV = lbv.Dot_BV and hd.Nam = lbv.Nam and hd.MaNganh = lbv.MaNganh
	where hd.Nam = 2021 and lbv.MaDT in (select MaDT from DeTai_TN where LoaiDT = 'DATN') and hd.MaNganh = 'HTTT'
	except 
	select Dot_BV from HoiDong where UyVien = r.MaGV or ChuTichHD = r.MaGV or ThuKy = r.MaGV
)

select MaGV
from GIAOVIEN r join Nganh n on r.MaNganh = n.MaNganh
where TenNganh = N'Hệ thống thông tin'
and
not exists (
	select  hd.Dot_BV from HoiDong hd join LichBaoVe lbv on hd.Dot_BV = lbv.Dot_BV and hd.Nam = lbv.Nam and hd.MaNganh = lbv.MaNganh
	where hd.Nam = 2021 and lbv.MaDT in (select MaDT from DeTai_TN where LoaiDT = 'DATN') and hd.MaNganh = 'HTTT'
	and hd.Dot_BV not in (
	select Dot_BV from HoiDong where UyVien = r.MaGV or ChuTichHD = r.MaGV or ThuKy = r.MaGV)
)

select MaGV
from GIAOVIEN r join Nganh n on r.MaNganh = n.MaNganh
where TenNganh = N'Hệ thống thông tin'
and
not exists (
	select  hd.Dot_BV from HoiDong hd join LichBaoVe lbv on hd.Dot_BV = lbv.Dot_BV and hd.Nam = lbv.Nam and hd.MaNganh = lbv.MaNganh
	where hd.Nam = 2021 and lbv.MaDT in (select MaDT from DeTai_TN where LoaiDT = 'DATN') and hd.MaNganh = 'HTTT'
	and not exists (
	select Dot_BV from HoiDong s where UyVien = r.MaGV or ChuTichHD = r.MaGV or ThuKy = r.MaGV and hd.Dot_BV = s.Dot_BV)
)




