#define _CRT_SECURE_NO_WARNINGS
#include "SinhVien.h"
#include "QLSinhVien.h"
int main() {
	QLSinhVien list;
	list.ReadFile("INPUT.txt");
	list.WriteFile("OUTPUT.txt");
	cout << endl;
	list.SVNhoHonDTBLop("DUOITB.txt");
	SinhVien sv;
	sv.Nhap();
	list.ThemSV("OUTPUT.txt", sv);

	return 0;
}

//int main() {
//    // lấy thời gian hiện tại
//    time_t now = time(0);
//
//    // định dạng thời gian theo chuỗi ký tự
//    char* dt = ctime(&now);
//
//    // định dạng thời gian theo định dạng khác
//    std::tm* ptm = std::localtime(&now);
//    std::cout << "Ngày hien tai: " << ptm->tm_mday
//        << "/" << ptm->tm_mon + 1
//        << "/" << ptm->tm_year + 1900 << std::endl;
//    return 0;
//}