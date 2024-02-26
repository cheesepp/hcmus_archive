#include <iostream>
using namespace std;

class ATM {
private:
	int to500 = 10;
	int to200 = 20;
	int to100 = 10;
	int to50 = 2;
	long tongTien = 10100000;
public:
	ATM();
	void rutTien();
};

ATM::ATM() {

}

void ATM::rutTien() {

	int soTien50DaRut = 0;
	int soTien100DaRut = 0;
	int soTien200DaRut = 0;
	int soTien500DaRut = 0;

	while (1) {

		long tien;
		cout << "Nhap so tien muon rut: ";
		cin >> tien;

		try {

			if (tien < 850000) {
				throw "So tien phai it nhat 850000 vnd!\n";
			}

			if (to50 == 0) {
					throw "Da het to tien 50!\n";
			}

			if (to100 == 0) {
				throw "Da het to tien 100!\n";
			}
			
			if (to200 == 0) {
				throw "Da het to tien 200!\n";
			}	
			
			if (to500 == 0) {
				throw "Da het to tien 500!\n";
			}

			if (tien > tongTien) {
				throw "ATM khong du so tien de rut!\n";
			}

			if (tien - 50000 >= 0 && to50) {
				tien -= 50000;
				to50--;
				soTien50DaRut++;
			}

			while (tien != 0) {

				if (tien < 50000) {
					throw "ATM khong du so tien de rut!\n";
				}

				while (tien - 500000 >= 0 && to500) {
					tien -= 500000;
					to500--;
					soTien500DaRut++;
				}


				while (tien - 200000 >= 0 && to200) {
					tien -= 200000;
					to200--;
					soTien200DaRut++;
				}

				while (tien - 100000 >= 0 && to100) {
					tien -= 100000;
					to100--;
					soTien100DaRut++;
				}

				if(tien % 100000 != 0) {

					while (tien - 50000 >= 0 && to50) {
						tien -= 50000;
						to50--;
						soTien50DaRut++;
					}
				
				}


			}

			tongTien = tongTien - tien;
		}
		catch (const char* e) {
			cout << e;
			break;
		}

		if (soTien50DaRut != 0 && soTien100DaRut != 0 && soTien200DaRut != 0 && soTien500DaRut != 0) {
			cout << "So tien 50000 da rut: " << soTien50DaRut << endl;
			cout << "So tien 100000 da rut: " << soTien100DaRut << endl;
			cout << "So tien 200000 da rut: " << soTien200DaRut << endl;
			cout << "So tien 500000 da rut: " << soTien500DaRut << endl;

			soTien50DaRut = 0;
			soTien100DaRut = 0;
			soTien200DaRut = 0;
			soTien500DaRut = 0;
		}


	}


}
int main() {


	ATM atm;

	atm.rutTien();

	return 0;
}