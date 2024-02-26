//#include <iostream>
//
//#include <string>
//
//#include <sstream>
//#include <cstring>
//
//using namespace std;
//
//int main() {
//
//    string init_string = "Welcome, to, Simplilearn";
//
//    // Creating stringstream object
//
//    stringstream ss(init_string);
//
//    cout << "This, is, a, StringStream, object\n";
//
//    // Array to store returned words
//
//    string ret_words[5];
//
//    string buf;
//    
//    int x = 0;
//    while (!ss.eof()) {
//        getline(ss, buf, ',');
//        cout << buf << endl;
//    }
//   /* while (ss >> buf) {
//
//        ret_words[x] = buf;
//
//        cout << "The Buffer: " << buf << endl;
//
//        x++;
//
//    }*/
//
//    // Printing the string
//
//    //cout << "Printing the array of strings\n";
//
//    //for (int y = 0; y < x; y++) {
//
//    //    cout << ret_words[y] << endl;
//
//    //}
//
//    return 0;
//
//}

//#include <iostream>
//using namespace std;
//class MyFloat {
//protected:
//	char* mData;
//public:
//	MyFloat(float v) {
//		mData = new char[10];
//		snprintf(mData, sizeof(mData), "%f", v);
//	}
//	operator char* () const {
//		return mData;
//	}
//	static MyFloat ValueOf(float value) {
//		MyFloat temp(value);
//		return temp;
//	}
//};
//
//int main() {
//	MyFloat hehe(9);
//	char* e = hehe;
//	cout << e << endl;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Bike {
private:
	char* brand; // hiệu xe 
public:
	Bike() {
		brand = new char[10];
	}
	Bike(const char* t) {
		brand = new char[10];
		strcpy(brand, t);
	}
 	virtual void move(int t1) {
		cout << brand << ":" << t1 * 12 << " ";
	}
	virtual ~Bike() {
		delete brand;
		cout << "destructed!";
		cout << brand;
	}
};
class EBike : public Bike {
public: 
	EBike(const char* t) : Bike(t) {}
	void move(int t2) {
	Bike::move(t2 * 2);
}
	~EBike() {
		cout << "hehe";
	}
};

void display(Bike& a, EBike& b) {
	a.move(2);
	b.move(2);
}
int main() {
	EBike b1("thu");
	EBike b2("thu2");

	display(b1, b2);
	return 0;
}