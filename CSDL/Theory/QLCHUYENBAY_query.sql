use QLChuyenBay
go

-- 1 Cho biết mã số, tên phi công, địa chỉ, điện thoại của các phi công đã
-- từng lái máy bay loại B747.
select manv, tennv, diachi, dthoai
from NHANVIEN
where LOAINV = 1

-- 2 Cho biết mã số và ngày đi của các chuyến bay xuất phát từ sân bay
-- DCA trong khoảng thời gian từ 14 giờ đến 18 giờ.
select cb.macb, ngaydi
from CHUYENBAY cb join PHANCONG pc on cb.MACB = pc.MACB 
where GIODI between '14:00' and '18:00' and sbdi = 'DCA'

-- 3 Cho biết tên những nhân viên được phân công trên chuyến bay có mã
--số 100 xuất phát tại sân bay SLC. Các dòng dữ liệu xuất ra không được
--phép trùng lắp.
select distinct tennv
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV join CHUYENBAY cb on pc.MACB = cb.MACB
where cb.MACB = '100' and cb.SBDI = 'SLC'

-- 4 Cho biết mã loại và số hiệu máy bay đã từng xuất phát tại sân bay MIA.
--Các dòng dữ liệu xuất ra không được phép trùng lắp.

select distinct maloai, sohieu
from LICHBAY lb join CHUYENBAY cb on lb.MACB = cb.MACB
where SBDI = 'MIA'

-- 5 Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của
--tất cả các hành khách đi trên chuyến bay đó. Sắp xếp theo thứ tự tăng
--dần của mã chuyến bay và theo ngày đi giảm dần.
select macb, ngaydi, tenkh, kh.dchi, dthoai
from KHACHHANG kh join DATCHO dc on kh.MAKH = dc.MAKH
where macb in (select macb from CHUYENBAY where SBDI = 'MIA')
order by macb asc, ngaydi desc

-- 6 Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của
--tất cả những nhân viên được phân công trong chuyến bay đó. Sắp xếp
--theo thứ tự tăng dần của mã chuyến bay và theo ngày đi giảm dần.

select pc.MACB, pc.NGAYDI, nv.TENNV, nv.DIACHI, nv.DTHOAI
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV
order by macb asc, ngaydi desc
-- 7 Cho biết mã chuyến bay, ngày đi, mã số và tên của những phi công
--được phân công vào chuyến bay hạ cánh xuống sân bay ORD
select pc.macb, ngaydi, pc.manv, tennv = (select manv from NHANVIEN where MANV = pc.MANV and LOAINV = 1)
from PHANCONG pc join CHUYENBAY cb on pc.MACB = cb.MACB
where cb.SBDEN = 'ORD'

-- 8 Cho biết các chuyến bay (mã số chuyến bay, ngày đi và tên của phi
--công) trong đó phi công có mã 1001 được phân công lái.

select pc.macb, ngaydi, pc.manv, tennv = (select manv from NHANVIEN where MANV = pc.MANV and LOAINV = 1)
from PHANCONG pc join CHUYENBAY cb on pc.MACB = cb.MACB
where pc.MANV = '1001'

-- 9 Cho biết thông tin (mã chuyến bay, sân bay đi, giờ đi, giờ đến,
--ngày đi) của những chuyến bay hạ cánh xuống DEN. Các chuyến bay
--được liệt kê theo ngày đi giảm dần và sân bay xuất phát (SBDI) tăng
--dần.

select cb.macb, sbdi, giodi, gioden, ngaydi
from CHUYENBAY cb join LICHBAY lb on cb.MACB = lb.MACB
where SBDEN = 'DEN'
order by NGAYDI desc, SBDI asc

-- 10 Với mỗi phi công, cho biết hãng sản xuất và mã loại máy bay mà phi
--công này có khả năng bay được. Xuất ra tên phi công, hãng sản xuất
--và mã loại máy bay.
select tennv = (select tennv from NHANVIEN where MANV = pc.MANV and LOAINV = 1), hangsx, lmb.maloai
from LOAIMAYBAY lmb join LICHBAY lb on lmb.MALOAI = lb.MALOAI join PHANCONG pc on pc.MACB = lb.MACB
where pc.MANV in (select manv from KHANANG)

-- 11 Cho biết mã phi công, tên phi công đã lái máy bay trong chuyến bay
--mã số 100 vào ngày 11/01/2000.
select nv.manv, tennv
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV
where pc.MACB = '100' and NGAYDI = '11/01/2000'

-- 12 Cho biết mã chuyến bay, mã nhân viên, tên nhân viên được phân công
--vào chuyến bay xuất phát ngày 10/31/2000 tại sân bay MIA vào lúc
--20:30
select macb, nv.manv, tennv
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV
where ngaydi = '10/31/2000' and pc.macb in (select macb from CHUYENBAY where SBDI = 'MIA')

-- 13 Cho biết thông tin về chuyến bay (mã chuyến bay, số hiệu, mã loại,
--hãng sản xuất) mà phi công "Quang" đã lái.
select macb, sohieu, lmb.maloai, hangsx
from LOAIMAYBAY lmb join LICHBAY lb on lmb.MALOAI = lb.MALOAI
where macb in (
	select macb from PHANCONG cb join NHANVIEN nv on cb.MANV = nv.MANV
	where TENNV like '%Quang%' and LOAINV = 1 
)

-- 14 Cho biết tên của những phi công chưa được phân công lái chuyến bay nào.
select tennv
from NHANVIEN
where manv not in (select manv from PHANCONG) and LOAINV = 1

-- 15 Cho biết tên khách hàng đã đi chuyến bay trên máy bay của hãng "Boeing"
select tenkh
from KHACHHANG
where MAKH in (
	select makh from DATCHO dc join LICHBAY lb on dc.MACB = lb.MACB and dc.NGAYDI = lb.NGAYDI
	where lb.SOHIEU in (
		select sohieu from LOAIMAYBAY where HANGSX = 'Boeing'
	)	
)

-- 16 Cho biết mã các chuyến bay chỉ bay với máy bay số hiệu 10 và mã loại B747.
select cb.macb
from CHUYENBAY cb join LICHBAY lb on cb.MACB = lb.MACB
where lb.SOHIEU = '10' and lb.MALOAI = 'B747'


--                   2.2 GOM NHÓM + HÀM

-- 17 Với mỗi sân bay (SBDEN), cho biết số lượng chuyến bay hạ cánh xuống 
--sân bay đó. Kết quả được sắp xếp theo thứ tự tăng dần của sân bay
--đến.
select sbden, count(distinct macb)
from CHUYENBAY
group by sbden
order by SBDEN asc  

-- 18 Với mỗi sân bay (SBDI), cho biết số lượng chuyến bay xuất phát từ sân
--bay đó, sắp xếp theo thứ tự tăng dần của sân bay xuất phát.
select sbdi, count(distinct macb)
from CHUYENBAY
group by SBDI
order by SBDI asc

-- 19 Với mỗi sân bay (SBDI), cho biết số lượng chuyến bay xuất phát theo
--từng ngày. Xuất ra mã sân bay đi, ngày và số lượng.
select sbdi, ngaydi, count(distinct lb.macb)
from CHUYENBAY cb join LICHBAY lb on cb.MACB = lb.MACB
group by NGAYDI, SBDI

-- 20 Với mỗi sân bay (SBDEN), cho biết số lượng chuyến bay hạ cánh theo
--từng ngày. Xuất ra mã sân bay đến, ngày và số lượng.
select sbden, NGAYDI, count(distinct lb.macb)
from CHUYENBAY cb join LICHBAY lb on cb.MACB = lb.MACB
group by ngaydi, SBDen

-- 21 Với mỗi lịch bay, cho biết mã chuyến bay, ngày đi cùng với số lượng
--nhân viên không phải là phi công của chuyến bay đó.
select pc.macb, lb.NGAYDI, count(distinct manv)
from PHANCONG pc join LICHBAY lb on pc.MACB = lb.MACB
where exists (
	select MANV from PHANCONG pc join LICHBAY lb2 on pc.MACB = lb2.MACB
	where lb.NGAYDI <> lb2.NGAYDI and manv in (select manv from NHANVIEN where LOAINV = 0)
)
group by pc.MACB, lb.NGAYDI

-- 22 Số lượng chuyến bay xuất phát từ sân bay MIA vào ngày 11/01/2000.
select count(distinct cb.macb)
from CHUYENBAY cb join LICHBAY lb on cb.MACB = lb.MACB 
where sbdi = 'MIA' and lb.NGAYDI = '11/01/2000'

-- 23 Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, số lượng nhân
--viên được phân công trên chuyến bay đó, sắp theo thứ tự giảm dần
--của số lượng.
select pc.macb, lb.ngaydi, count(distinct manv)
from PHANCONG pc join LICHBAY lb on pc.MACB = lb.MACB
group by pc.MACB, lb.NGAYDI
order by count(distinct manv) desc

-- 24 Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, cùng với số
--lượng hành khách đã đặt chỗ của chuyến bay đó, sắp theo thứ tự giảm
--dần của số lượng.
select dc.macb, lb.NGAYDI, count(distinct makh) as slkh
from DATCHO dc join LICHBAY lb on dc.MACB = lb.MACB
group by  dc.MACB, lb.NGAYDI
order by count(distinct makh) desc

-- 25 Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, tổng lương của
--phi hành đoàn (các nhân viên được phân công trong chuyến bay), sắp
--xếp theo thứ tự tăng dần của tổng lương.
select macb, ngaydi, sum(luong) tongluong
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV
group by macb, ngaydi
order by sum(luong) asc

-- 26 Cho biết lương trung bình của các nhân viên không phải là phi công.
select avg(luong) luongtb
from NHANVIEN where LOAINV = 0

-- 27 Cho biết mức lương trung bình của các phi công.
select avg(luong) luongtb
from NHANVIEN where LOAINV = 1

-- 28 Với mỗi loại máy bay, cho biết số lượng chuyến bay đã bay trên loại
--máy bay đó hạ cánh xuống sân bay ORD. Xuất ra mã loại máy bay, số
--lượng chuyến bay.
select maloai, count(distinct cb.macb) as soluongcb
from CHUYENBAY cb join LICHBAY lb on cb.macb = lb.macb where SBDEN = 'ORD'
group by maloai

-- 29 Cho biết sân bay (SBDI) và số lượng chuyến bay có nhiều hơn 2
--chuyến bay xuất phát trong khoảng 10 giờ đến 22 giờ.
select sbdi, count(distinct macb) as slcb
from CHUYENBAY 
where GIODI between '10:00' and '22:00'
group by sbdi
having count(distinct macb) > 2

-- 30 Cho biết tên phi công được phân công vào ít nhất 2 chuyến bay trong
--cùng một ngày.
select tennv
from NHANVIEN
where manv in (
	select manv from PHANCONG pc join LICHBAY lb on pc.MACB = lb.MACB
	group by manv, lb.NGAYDI
	having count(pc.macb) >= 2
)

-- 31 Cho biết mã chuyến bay và ngày đi của những chuyến bay có ít hơn 3
--hành khách đặt chỗ.
select dc.macb, lb.ngaydi
from LICHBAY lb join DATCHO dc on lb.MACB = dc.MACB
group by dc.macb, lb.ngaydi
having count(distinct dc.MACB) < 3

-- 32 Cho biết số hiệu máy bay và loại máy bay mà phi công có mã 1001
--được phân công lái trên 2 lần.
select sohieu, maloai
from LICHBAY lb join PHANCONG pc on lb.MACB = pc.MACB
where manv = '1001' and manv in (select manv from NHANVIEN where LOAINV = 1)
group by sohieu, maloai
having count(distinct pc.MANV) > 2

-- 33 Với mỗi hãng sản xuất, cho biết số lượng loại máy bay mà hãng đó đã
--sản xuất. Xuất ra hãng sản xuất và số lượng.
select hangsx, count(distinct maloai)
from LOAIMAYBAY
group by hangsx

--							2.3 TRUY VẤN LỒNG + HÀM

-- 34 Cho biết hãng sản xuất, mã loại và số hiệu của máy bay đã được sử
--dụng nhiều nhất.
select hangsx, lmb.maloai
from LOAIMAYBAY lmb join LICHBAY lb on lb.MALOAI = lmb.MALOAI
group by hangsx
having count(distinct lmb.MALOAI) >= all (
	select count(distinct lmb.MALOAI) from LOAIMAYBAY lmb join LICHBAY lb on lb.MALOAI = lmb.MALOAI
	group by hangsx
)

-- 35 Cho biết tên nhân viên được phân công đi nhiều chuyến bay nhất.
select tennv
from NHANVIEN nv join PHANCONG pc on nv.MANV = pc.MANV
group by tennv
having count(distinct pc.manv) >= all (
	select count(distinct pc2.manv) from NHANVIEN nv2 join PHANCONG pc2 on nv2.MANV = pc2.MANV
	group by tennv
)

-- 36 Cho biết thông tin của phi công (tên, địa chỉ, điện thoại) lái nhiều
--chuyến bay nhất.
select tennv, diachi, dthoai
from NHANVIEN
where LOAINV = 1
group by tennv, diachi, dthoai
having count(distinct manv) >= all (
	select count(distinct pc.manv) from PHANCONG pc join NHANVIEN nv on pc.MANV = nv.MANV
	group by tennv, diachi, dthoai
)

-- 37 Cho biết sân bay (SBDEN) và số lượng chuyến bay của sân bay có ít
--chuyến bay đáp xuống nhất.
select sbden, count(distinct macb)
from CHUYENBAY
group by sbden
having count(distinct macb) <= all (
	select count(distinct macb) from CHUYENBAY group by sbden
)

-- 38 Cho biết sân bay (SBDI) và số lượng chuyến bay của sân bay có nhiều
--chuyến bay xuất phát nhất.
select sbdi, count(distinct macb)
from CHUYENBAY
group by sbdi
having count(distinct macb) >= all (
	select count(distinct macb) from CHUYENBAY group by sbdi
)

-- 39 Cho biết tên, địa chỉ, và điện thoại của khách hàng đã đi trên nhiều
--chuyến bay nhất.
select tenkh, dchi, dthoai
from KHACHHANG
group by tenkh, dchi, dthoai
having count(distinct makh) >= all (
	select count(distinct kh.makh) from DATCHO dc join KHACHHANG kh on dc.MAKH = kh.MAKH 
	group by tenkh, dchi, dthoai
)

