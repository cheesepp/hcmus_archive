
#include "QLHoaDon.h"

void menu() {

	QLHoaDon list;
	int option;
	cout << "\n================== CHUONG TRINH QUAN LI HOA DON ======================\n";
	do {
		cout << "===================================================================\n";
		cout << "|| Nhap mot trong cac tuy chon sau:                              ||\n";
		cout << "|| 1: Nhap danh sach hoa don                                     ||\n";
		cout << "|| 2: Xuat danh sach hoa don                                     ||\n";
		cout << "|| 3: Tinh trung binh thanh tien moi loai khach hang             ||\n";
		cout << "|| 4: Tim hoa don co so tien lon nhat theo tung doi tuong        ||\n";
		cout << "|| 5: Them khach hang                                            ||\n";
		cout << "|| 6: Ghi khach hang co so luong dien nho hon 150 kwh vao        ||\n";
		cout << "|| tap tin ds_KHSH.dat                                           ||\n";
		cout << "|| 7: Doc tap tin ds_KHSH.dat va xuat ra man hinh                ||\n";
		cout << "|| 0: Thoat chuong trinh                                         ||\n";
		cout << "===================================================================\n";
		cout << "Vui long chon: ";
		cin >> option;

		switch (option) {
		case 1:
		{
			list.inputList();
			list.outputList();
			break;
		}
		case 2:
		{
			list.inputList();
			break;
		}
		case 3: {
			list.avgThanhTien();
			break;

		}

		case 4:
		{
			list.timHDLonNhatMoiDoiTuong();
			break;
		}
		
		case 5:
		{
			KhachHang* kh;
			list.themKH(kh);
			cout << "Them thanh cong!\n";
			break;
		}
		
		case 6:
		{
			list.KHCoSoDienNhoHon150("ds_KHSH.dat");
			break;
		}
		
		case 7:
		{
			list.readFile("ds_KHSH.dat");
			break;
		}
		default:
			cout << "\n================= KET THUC CHUONG TRINH! ===================\n";
		}

	} while (option);

}
int main()
{
    QLHoaDon hd1;
    hd1.inputList();
    hd1.outputList();
	hd1.sapXepLoaiDT();
	hd1.outputList();
   /* KhachHang* p;
    hd1.themKH(p);
    hd1.KHCoSoDienNhoHon150("ds_KHSH.dat");
    QLHoaDon hd2;
    hd2.readFile("ds_KHSH.dat");
    hd2.outputList();*/
	//menu();
    
}
