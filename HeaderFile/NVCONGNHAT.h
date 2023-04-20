#pragma once
#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H
#include"NHANVIEN.h"
class NVCONGNHAT:public NHANVIEN
{
private:
	double soNgay;

public:
	NVCONGNHAT();
	NVCONGNHAT(string ID, string name, Date ngaysinh, string diaChi, double soNgay);
	NVCONGNHAT(const NVCONGNHAT& nvcongnhat);
	void nhap();
	void xuat();

	double getSoNgay() {
		return soNgay;
	};
	double tongLuong();
};
#endif // !NVCONGNHAT_H




