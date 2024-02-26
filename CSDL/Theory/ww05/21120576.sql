-- câu 1 Cho biết mã sản phẩn, tên, giá tiền, và đơn vị tính của những sản phẩm có giá trên 100 (nghìn) đồng.
select masp, tensp, giatien, donvitinh
from SanPham
where giatien > 100

-- câu 2 Cho biết những sản phẩm có loại là “Đồ dùng”.
select *
from SanPham
join LoaiSanPham on SanPham.maloai = LoaiSanPham.maloai
where LoaiSanPham.tenloai = N'Đồ dùng'

-- câu 3 Cho biết tên và giá tiền của các sản phẩm “Bàn chải đánh răng”.
select tensp, giatien
from SanPham
where tensp like N'%Bàn chải đánh răng%'

-- câu 4 Cho biết tên sản phẩm và tên loại sản phẩm.
select SanPham.tensp, LoaiSanPham.tenloai
from SanPham
join LoaiSanPham on SanPham.maloai = LoaiSanPham.maloai

-- câu 5 Cho biết tên sản phẩm và tên loại sản phẩm của những sản phẩm có số lượng tồn > 50.
select SanPham.tensp, LoaiSanPham.tenloai
from SanPham
join LoaiSanPham on SanPham.maloai = LoaiSanPham.maloai
where SanPham.soluongton > 50

-- câu 6 Cho biết những sản phẩm có đơn vị tính là “túi”.
select *
from SanPham
where donvitinh = N'túi'

-- câu 7 Cho biết tên loại sản phẩm của mặt hàng “Bột giặt Omo”.
select LoaiSanPham.tenloai
from SanPham
join LoaiSanPham on SanPham.maloai = LoaiSanPham.maloai
where SanPham.tensp = N'Bột giặt Omo'

-- câu 8 Cho biết tên của sản phẩm có giá thấp nhất.
select tensp, min(giatien)
from SanPham

-- câu 9 Cho biết tên của sản phẩm có giá cao nhất.
select tensp, max(giatien)
from SanPham