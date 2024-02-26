-- 22. Cho biết số lượng khách hàng của từng phái.
select phai, count(maKH) soKH
from KHACHHANG
group by phai

-- 23. Cho biết số lượng khách hàng ở từng tỉnh thành.
select diachi, count(maKH) soKH
from KHACHHANG
group by diachi

-- 24. Cho biết Tỉnh thành có nhiều khách hàng nhất.
select diachi, count(maKH) soKH
from KHACHHANG
group by diachi
having count(maKH) >= all (select count(maKH) from KHACHHANG group by diachi)

-- 25. Cho tên, địa chỉ, điện thoại biết khách hàng cao tuổi nhất.
select hoten, diachi, dienthoai
from KHACHHANG
where namsinh = (select min(namsinh) from KHACHHANG)

-- 26. Cho biết số lượng khách hàng sinh ra trong từng năm.
select namsinh, count(maKH) soKH
from KHACHHANG
group by namsinh

-- 27. Cho biết mã khách hàng của những khách hàng chưa từng mua hàng. 
select kh.maKH
from KHACHHANG kh left join HOADON hd on kh.maKH = hd.maKH
where maHD is null

-- 28. Cho biết mã khách hàng và tên của những khách hàng chưa từng mua hàng.
select kh.maKH, hoten
from KHACHHANG kh left join HOADON hd on kh.maKH = hd.maKH
where hd.maHD is null

--- 29. Cho biết mã khách hàng và số lần mua hàng của khách hàng đó.
select kh.maKH, count(hd.maHD) soLanMua
from KHACHHANG kh left join HOADON hd on kh.maKH = hd.maKH
group by kh.maKH

-- 30. Cho biết mã khách hàng, tên và số lần mua hàng của mỗi khách hàng.
select kh.maKH, kh.hoten, count(hd.maHD) soLanMua
from KHACHHANG kh left join HOADON hd on kh.maKH = hd.maKH
group by kh.maKH, kh.hoten

-- 31. Cho biết mã khách hàng của khách hàng đã mua hàng nhiều lần nhất.
select maKH
from HOADON
group by maKH
having count(maHD) >= all(select count(maHD) from HOADON group by maKH)

-- 32. Cho biết mã khách hàng và tên của những khách hàng đã mua hàng nhiều lần nhất.
select kh.maKH, kh.hoten
from KHACHHANG kh join HOADON hd on kh.maKH = hd.maKH
group by kh.maKH, kh.hoten
having count(hd.maHD) >= all (select count(hd.maHD) from HOADON group by maKH, hoten)
