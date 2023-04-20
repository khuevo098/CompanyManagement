#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include"Date.h"
#include<fstream>
using namespace std;
class NHANVIEN
{
private:
	string ID;
	string name;
	Date ngaysinh;
	string diaChi;
	double luong;
public:
	NHANVIEN();
	NHANVIEN(string ID, string name, Date ngaysinh, string diaChi);

	NHANVIEN(const NHANVIEN& nv);
	virtual void nhap();
	virtual void xuat();
	virtual string getID() {
		return ID;
	}
	virtual string getName() {
		return name;
	}
	virtual Date getNgaysinh() {
		return ngaysinh;
	};
	virtual string getDiaChi() {
		return diaChi;
	};
	
	virtual double tongLuong();
};
#endif // !NHANVIEN_H



