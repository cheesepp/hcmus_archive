#pragma once
#ifndef CEBOOK_H
#define CEBOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class CMyDate {
private:
	int ngay;
	int thang;
	int nam;
public:
	CMyDate();
	CMyDate(int, int, int);
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int);
	void setThang(int);
	void setNam(int);
	CMyDate& operator= (const CMyDate&);
	bool operator>(const CMyDate&);
	friend istream& operator>> (istream&, CMyDate&);
	friend ostream& operator<< (ostream&, const CMyDate&);
};


class CEBook {
private:
	string ISBN;
	string ten;
	string tacgia;
	CMyDate date;
	string theLoai;
	string nhaXB;
	long double price;
public:
	CEBook();
	CEBook(string, string, string, CMyDate, string, string, long double);
	CEBook(const CEBook&);
	bool operator>(const CEBook&);
	bool operator>=(const CEBook&);
	bool operator<(const CEBook&);
	bool operator<=(const CEBook&);
	CEBook& operator=(const CEBook&);
	string getISBN() const;
	string getTen() const;
	string getTacGia() const;
	CMyDate getNgayXB() const;
	string getTheLoai() const;
	string getNhaXB() const;
	long double getGia() const;
	void setISBN(string);
	void setTen(string);
	void setTacGia(string);
	void setNgayXB(CMyDate);
	void setTheLoai(string);
	void setNhaXB(string);
	void setGia(long double);
};

#endif // !1
