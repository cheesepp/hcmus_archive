#include "QLPhim.h"

QLPhim::QLPhim(int n)
{
	ds_Phim.setSz(n);
}

QLPhim::QLPhim()
{

}

void QLPhim::input()
{
	int n;
	cout << "Nhap so luong phim: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		ds_Phim[i] = new Phim();
	}
	for (int i = 0; i < n; i++) {
		ds_Phim[i]->input();
		ds_Phim.push(ds_Phim[i]);
	}
}

void QLPhim::output()
{
	for (int i = 0; i < ds_Phim.getSz(); i++) {
		ds_Phim[i]->output();
	}
}

void QLPhim::sapXepNamSX()
{
	for (int i = 0; i < ds_Phim.getSz() - 1; i++) {
		for (int j = i + 1; j < ds_Phim.getSz(); j++) {
			if (ds_Phim[i]->getNamSX() > ds_Phim[j]->getNamSX()) {
				Phim temp;
				temp = *ds_Phim[i];
				*ds_Phim[i] = *ds_Phim[j];
				*ds_Phim[j] = temp;
			}
		}
	}
}

void QLPhim::themPhim(Phim* p)
{
	
    ds_Phim.setSz(ds_Phim.getSz() + 1);
    int greaterIndex = -1;
    for (int i = 0; i < ds_Phim.getSz() - 1; i++) {
        if (p[i].getNamSX() >= ds_Phim[i]->getNamSX()) {

            greaterIndex = i - 1;
        }
    }
    
    for (int i = greaterIndex + 1; i < ds_Phim.getSz() - 1; i++) {
        ds_Phim[i + 1] = ds_Phim[i];
    }
    ds_Phim[greaterIndex + 1] = p;
}

void QLPhim::ghiDanhSachPhim(string tenFile) {
    ofstream file(tenFile, ios::binary);
    if (file.is_open()) {  
        int size = ds_Phim.getSz();
        file.write(reinterpret_cast<const char*>(&size), sizeof(int));

        for (int i = 0; i < ds_Phim.getSz(); i++) {
            file.write(reinterpret_cast<const char*>(ds_Phim[i]), sizeof(Phim));
        }

        file.close();
        cout << "Ghi danh sach phim thanh cong.\n";
    }
    else {
        cout << "Khong the mo file de ghi.\n";
    }
}

void QLPhim::docDanhSachPhim(string tenFile) {
    ifstream file(tenFile, ios::binary);
    if (file.is_open()) {
        
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(int));

        for (int i = 0; i < size; i++) {
            Phim* phim = new Phim();
            file.read(reinterpret_cast<char*>(phim), sizeof(Phim));
            ds_Phim.push(phim);
        }

        file.close();
        cout << "Doc danh sach phim thanh cong.\n";
    }
    else {
        cout << "Khong the mo file de doc.\n";
    }
}

void QLPhim::xoaPhimHBO(string tenFile) {
    for (int i = 0; i < ds_Phim.getSz(); i++) {
        if (strcmp(ds_Phim[i]->getTheLoai(), "HBO") == 0) {
            ds_Phim.erase(i);
        }
    }
    ghiDanhSachPhim(tenFile);
}
