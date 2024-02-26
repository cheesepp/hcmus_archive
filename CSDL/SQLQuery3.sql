USE [QLKhoaLuan]
go

create or alter proc themDT
	@madt varchar(5),
	@tendt varchar(100),
	@loaidt varchar(5),
	@nienkhoa int,
	@manganh varchar(5)
as
begin
	if not exists (select MaLoai from Loai_DeTai where MaLoai = @loaidt)
	begin
		raiserror(N'Không tồn tại loại đề tài trên!', 15, 1)
		return 1
	end
	if not exists (select MaNganh from Nganh where MaNganh = @manganh)
	begin
		raiserror(N'Không tồn tại ngành trên!', 15, 1)
		return 1
	end
	
	insert into DeTai_TN(MaDT, TenDT, LoaiDT, NienKhoa, MaNganh)
	values(@madt, @tendt, @loaidt, @nienkhoa, @manganh)
end


		