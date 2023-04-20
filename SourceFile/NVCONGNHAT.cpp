#include "NVCONGNHAT.h"

NVCONGNHAT::NVCONGNHAT()
	:NHANVIEN(),soNgay(0) {}


NVCONGNHAT::NVCONGNHAT(string ID, string name, Date ngaysinh, string diaChi, double soNgay)
	:NHANVIEN(ID, name, ngaysinh, diaChi), soNgay(soNgay) {}


NVCONGNHAT::NVCONGNHAT(const NVCONGNHAT& nvcongnhat) :NHANVIEN(nvcongnhat) {
	this->soNgay = nvcongnhat.soNgay;
}
void NVCONGNHAT::nhap() {
	NHANVIEN::nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> soNgay;
}
void NVCONGNHAT::xuat() {
	NHANVIEN::xuat();
	cout << "So ngay lam viec: " << soNgay << endl;
	cout << "Tong luong: " << fixed << setprecision(2) << tongLuong() << endl;
	
}
double NVCONGNHAT::tongLuong() {
	return NHANVIEN::tongLuong() + soNgay * 300000;
}