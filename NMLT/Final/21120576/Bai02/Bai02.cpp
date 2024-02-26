#include "PhongBan.h"

int main()
{

    PhongBan dsPB[MAX];
    int soLuongPB;

    //(15đ) Nhập danh sách các phòng ban
    nhapDanhSachPB(dsPB, soLuongPB);

    // Kiểm tra danh sách phòng ban
    xuatDanhSachPB(dsPB, soLuongPB);

    //(15đ) Tìm phòng ban có số lượng nhân viên nhiều nhất.Nếu có
    //nhiều phòng ban cùng số lượng nhân viên thì trả về phòng ban có
    //tên trường phòng dài nhất
    cout << "\n======== PHONG BAN CO SO NHAN VIEN DAI NHAT ==========\n";
    PhongBan foundPB = PBCoSoNVNhieuNhat(dsPB, soLuongPB);
 
    cout << "Phong ban co so luong nhan vien nhieu nhat la: \n";
    xuatPB(foundPB);
    
}

