#pragma once
#ifndef CONGTY_H
#define CONGTY_H
#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVCongNhat.h"
#include <string>
#include <sstream>
class CongTy {
private:
	NhanVien** list;
	int sz = 0;
	int capacity = 100;
public:
	CongTy();
	CongTy(const CongTy&);
	~CongTy();
	CongTy& operator= (const CongTy&);
	void input();
	void print() const;
	long sumSalary();
	void maxSalary();
	float avgSalary();
	void findEmpById(char* id);
	void findEmpByName(char* name);
	void findEmpBornMonth5();
	void addEmployee();
	void deleteEmployee();
	void writeListEmp(string);
	void readListEmp(string);
	void empWhoseSalaryLessThanAvg(string);
};

#endif // !CONGTY_H
