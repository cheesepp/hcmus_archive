USE [QLBanHang]
GO
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH001     ', N'Nguyễn Văn A', N'Nam       ', N'0987654321', N'Số 1, Đường Hoàng Văn Thụ, Hà Nội')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH002     ', N'Trần Thị B', N'Nữ        ', N'0909123456', N'Số 2, Đường Lê Văn Lương, Thanh Xuân, Hà Nội')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH003     ', N'Lê Minh C', N'Nam       ', N'0918457392', N'Số 3, Đường Hoàng Diệu, Hải Phòng')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH004     ', N'Phạm Thúy D', N'Nữ        ', N'0987456321', N'Số 4, Đường Lạc Long Quân, TP. Hồ Chí Minh')
GO
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD001     ', N'2022-01-01', N'	KH001    ')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD002     ', N'2022-01-02', N'KH002     ')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD003     ', N'2022-01-03', N'KH003     ')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD004	    ', N'2022-01-04', N'KH004
   ')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD005     ', N'2022-01-05', N'KH005     ')
GO
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP006     ', N'Bánh gạo  ', N'2022-01-06', 8000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP007     ', N'Trà       ', N'2022-01-07', 12000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP008     ', N'Cà phê sữa', N'2022-01-08', 20000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP009     ', N'Bánh quy nhân đậu', N'2022-01-09', 10000)
GO
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD001     ', N'SP006     ', N'2         ', 5000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD002     ', N'SP007     ', N'1         ', 15000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD003     ', N'SP008     ', N'5         ', 20000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD004     ', N'SP009     ', N'3         ', 10000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD005     ', N'SP010     ', N'3         ', 5000)
GO
