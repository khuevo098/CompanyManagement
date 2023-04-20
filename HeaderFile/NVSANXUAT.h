#pragma once
#ifndef NVSANXUAT_H
#define NVSANXUAT_H
#include"NHANVIEN.h"
class NVSANXUAT :public NHANVIEN
{
private:
	int soSanPham;

public:
	NVSANXUAT();
	NVSANXUAT(string ID, string name, Date ngaysinh, string diaChi, int soSanPham);
	NVSANXUAT(const NVSANXUAT& nvsanxuat);
	void nhap();
	void xuat();
	int getSoSP() {
		return soSanPham;
	}
	double tongLuong();
};
#endif // !NVCONGNHAT_H
