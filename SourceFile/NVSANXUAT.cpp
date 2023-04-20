#include "NVSANXUAT.h"

NVSANXUAT::NVSANXUAT()
	:NHANVIEN(), soSanPham(0) {};

NVSANXUAT::NVSANXUAT(string ID, string name, Date ngaysinh, string diaChi, int soSanPham)
	:NHANVIEN(ID, name, ngaysinh, diaChi), soSanPham(soSanPham) {};


NVSANXUAT::NVSANXUAT(const NVSANXUAT& nvsanxuat) :NHANVIEN(nvsanxuat) {
	this->soSanPham = nvsanxuat.soSanPham;
}
void NVSANXUAT::nhap() {
	NHANVIEN::nhap();
	cout << "Nhap so san pham da lam: ";
	cin >> soSanPham;
}

void NVSANXUAT::xuat() {
	NHANVIEN::xuat();
	cout << "Nhap so san pham da lam: " << soSanPham << endl;
	cout << "Tong luong: " << fixed << setprecision(2) << tongLuong() << endl;
}

double NVSANXUAT::tongLuong() {
	return NHANVIEN::tongLuong() + 20000 * soSanPham;
}
