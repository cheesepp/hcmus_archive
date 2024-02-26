use master
go
CREATE DATABASE QLKHOHANG
GO
USE QLKHOHANG
GO

CREATE TABLE ChungLoai (
MaCL nchar(8),
TenCL nvarchar(20),
SoTHieu int,
TSLNhap int,
TSLXuat int,
PRIMARY KEY (MaCL)
)

CREATE TABLE HangHoa (
MaHangHoa nchar(8),
TenHangHoa nvarchar(50),
ThuongHieu nvarchar(20),
ChungLoai nchar(8),
NgayKiemKe datetime,
TongSoLuong int,
PRIMARY KEY (MaHangHoa),
FOREIGN KEY (ChungLoai) REFERENCES ChungLoai(MaCL)
)

CREATE TABLE NhanVien (
MaNhanVien nchar(8),
TenNhanVien nvarchar(30),
TSLNhap int,
TSLXuat int,
PRIMARY KEY (MaNhanVien)
)

CREATE TABLE PhieuBienNhan (
MaBienNhan nchar(8),
LoaiPhieu nchar(8),
NgayGioXuatPhieu datetime,
MaNhanVien nchar(8),
TongSoLuong int,
PRIMARY KEY (MaBienNhan),
FOREIGN KEY (MaNhanVien) REFERENCES NhanVien
)

CREATE TABLE ChiTietBienNhan (
MaBienNhan nchar(8),
MaHangHoa nchar(8),
SoLuong int,
PRIMARY KEY (MaBienNhan, MaHangHoa),
FOREIGN KEY (MaBienNhan) REFERENCES PhieuBienNhan,
FOREIGN KEY (MaHangHoa) REFERENCES HangHoa
)
GO

INSERT ChungLoai (MaCL, TenCL) VALUES
(N'TV', N'Tivi'),
(N'MG', N'Máy giặt'),
(N'NCĐ', N'Nồi cơm điện')
GO

INSERT HangHoa (MaHangHoa, TenHangHoa, ThuongHieu, ChungLoai) VALUES
(N'TV001', N'Tivi 32 inch', N'Sony', N'TV'),
(N'TV002', N'Tivi 43 inch', N'Samsung', N'TV'),
(N'TV003', N'Tivi 43 inch', N'TCL', N'TV'),
(N'MG001', N'Máy giặt cửa trên 10 kg', N'Panasonic', N'MG'),
(N'MG002', N'Máy giặt cửa ngang 12 kg', N'Toshiba', N'MG'),
(N'NCĐ001', N'Nồi cơm điện 1.8 L', N'Panasonic', N'NCĐ')
GO

INSERT NhanVien (MaNhanVien, TenNhanVien) VALUES
(N'NV001', N'Hòa Thành'),
(N'NV002', N'Minh Trí'),
(N'NV003', N'Trọng Tín'),
(N'NV004', N'Thái Thành')
GO

INSERT PhieuBienNhan (MaBienNhan, LoaiPhieu, NgayGioXuatPhieu, MaNhanVien, TongSoLuong) VALUES
(N'BN0001', N'Nhập', '2022-06-20 08:00', N'NV001', 30),
(N'BN0002', N'Nhập', '2022-06-27 13:30', N'NV002', 10),
(N'BN0003', N'Xuất', '2022-06-30 14:45', N'NV003', -8),
(N'BN0004', N'Nhập', '2022-07-04 09:10', N'NV004', 12),
(N'BN0005', N'Xuất', '2022-07-14 10:20', N'NV002', -21),
(N'BN0006', N'Nhập', '2022-07-24 15:25', N'NV001', 30)
GO

INSERT ChiTietBienNhan VALUES
(N'BN0001', N'TV001', 10),
(N'BN0001', N'NCĐ001', 20),
(N'BN0002', N'MG001', 10),
(N'BN0003', N'TV001', -8),	
(N'BN0004', N'TV003', 12),
(N'BN0005', N'TV003', -5),
(N'BN0005', N'MG001', -6),
(N'BN0005', N'NCĐ001', -10),
(N'BN0006', N'TV002', 15),
(N'BN0006', N'TV001', 5),
(N'BN0006', N'MG001', 10)
GO

--Câu 1: Xuất chủng loại có tổng số lượng nhập kho lớn hơn tổng số lượng nhập kho của chủng loại NCĐ
select tongsoluong
from HangHoa
where TongSoLuong > (select TongSoLuong from HangHoa where ChungLoai = 'NCĐ')

--Câu 2: Xuất nhân viên có xuất kho tất cả các hàng hóa thuộc thương hiệu 'Panasonic'
select distinct MaNhanVien
from PhieuBienNhan r
where not exists (
	select MaHangHoa from HangHoa where ThuongHieu = 'Panasonic'
	except 
	select ctbn.MaHangHoa from ChiTietBienNhan ctbn join PhieuBienNhan s  on s.MaBienNhan = ctbn.MaBienNhan
	where s.MaNhanVien = r.MaNhanVien
) and LoaiPhieu = N'Xuất'

select * from PhieuBienNhan
select * from NhanVien
--Câu 3: viết sp_ThongKe_NhanVien_TSLNhap để kiểm tra tổng số lượng nhập ở bảng phiếu biên nhận và bảng nhân
--viên có giống nhau ko, nếu ko giống thì cần cập nhật lại cột tổng số lượng nhập của bảng nhân viên, nếu có 
--cập nhật thì trả về 1, ngược lại trả về
create or alter proc sp_ThongKe_NhanVien_TSLNhap
		@manv nchar(8)
as
begin
	if not exists (
		select sum(tongsoluong) from PhieuBienNhan where MaNhanVien = @manv
		and LoaiPhieu = N'Nhập'
		having sum(TongSoLuong) = (select TSLNhap from NhanVien where MaNhanVien = @manv)
		)
	begin
		update NhanVien 
		set TSLNhap = (select sum(tongsoluong) from PhieuBienNhan where MaNhanVien = @manv)
		where MaNhanVien = @manv
		return 1
	end
	print (N'Tổng số lượng ở phiếu biên nhận giống với tổng số lượng nhập bên nhân viên')
	return 0
end
go
exec sp_ThongKe_NhanVien_TSLNhap 'NV001'

--Câu 4: viết sp_ThongKe_All_NhanVien_TSLNHAP để cập nhật tổng số lượng nhập của tất cả nhân viên,
--dùng sp_ThongKe_NhanVien_TSLNhap, in ra số nhân viên được cập nhật
create or alter proc sp_ThongKe_All_NhanVien_TSLNHAP
as
begin
	-- Khai bao bien kieu TABLE
	DECLARE @vtable TABLE (MaNhanVien nchar(8))

	-- Nap du lieu vao @vtable
	INSERT INTO @vtable
		SELECT MaNhanVien
		FROM NhanVien

	-- Xac dinh so dong du lieu trong @vtable
	DECLARE @count int;
	SELECT @count = count(*)
		FROM @vtable;

	-- Duyet lan luot tung dong du lieu trong @vtable
	DECLARE @MaGV nchar(10)
	WHILE ( @count > 0 ) -- lap cho den khi moi dong du lieu trong @vtable duoc xu ly het
	BEGIN
		-- Chon ra dong du lieu dau tien trong @vtable
		SELECT TOP 1 @MaGV = vt.MaNhanVien
			FROM @vtable vt, NhanVien nv
			where vt.MaNhanVien = nv.MaNhanVien

		-- Thuc hien xu ly voi cac thong tin duoc chon ra
		exec sp_ThongKe_NhanVien_TSLNhap @MaGV

		-- Xoa dong du lieu tuong ung da thuc hien trong @vtable
		DELETE @vtable WHERE MaNhanVien = @MaGV;

		SET @count = @count -1;
	END
end

go
sp_ThongKe_All_NhanVien_TSLNHAP

select * from PhieuBienNhan
select * from NhanVien