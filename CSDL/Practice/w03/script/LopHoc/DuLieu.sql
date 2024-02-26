USE [QLLopHoc]
GO
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (14323, N'Lê Trung Quân', N'nam       ', N'14/3/1980 ', N'TPHCM     ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (14324, N'Trần Thị Dung', N'nữ        ', N'15/3/1981 ', N'Đà Nẵng   ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (14325, N'Phạm Văn Hậu', N'nam       ', N'16/4/1972 ', N'TPHCM     ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (14326, N'Lê Kim Hùng', N'nữ        ', N'17/5/1971 ', N'Huế       ')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (14327, N'Nguyễn Tuấn Nam', N'nam       ', N'17/6/1985 ', N'TPHCM     ')
GO
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (21120500, N'Nguyễn Ngọc Tự', N'nam       ', N'18/6/2003 ', N'TPHCM     ', N'21CTT1    ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (21120501, N'Nguyễn Tấn Hoàng Phước', N'nam       ', N'18/4/2003 ', N'TPHCM     ', N'21CTT2    ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (21120502, N'Trần Hồng Nghi', N'nữ        ', N'20/2/2002 ', N'Huế       ', N'21CTT3    ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (21120503, N'Phạm Thị Nhung', N'nữ        ', N'20/3/2003 ', N'Đà Nẵng   ', N'21CTT4    ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (21120504, N'Bùi Thị Thanh Bình', N'nữ        ', N'18/01/2002', N'Kon Tum   ', N'21CTT5    ')
GO
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'21CTT1    ', N'Công nghệ thông tin    ', N'1990      ', 14323, 21120500)
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'21CTT2    ', N'Sinh Học  ', N'1990      ', 14324, 21120501)
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'21CTT3    ', N'Hóa Học   ', N'1990      ', 14327, 21120502)
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'21CTT4    ', N'Vật lí    ', N'1990      ', 14325, 21120503)
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [lop_tr]) VALUES (N'21CTT5    ', N'Toán Học', N'1990      ', 14326, NULL)
GO
