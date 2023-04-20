#include "NHANVIEN.h"
NHANVIEN::NHANVIEN() {
	ID = "00000000";
	name = "XXX XXX XXX";
	
	diaChi = "XXX";
	this->luong = 0;
}
NHANVIEN::NHANVIEN(string ID, string name, Date ngaysinh, string diaChi) {
	this->ID = ID;
	this->name = name;
	this->ngaysinh = ngaysinh;
	this->diaChi = diaChi;
	this->luong = 0;
}
NHANVIEN::NHANVIEN(const NHANVIEN& nv) {
	this->ID = nv.ID;
	this->name = nv.name;
	this->ngaysinh = nv.ngaysinh;
	this->diaChi = nv.diaChi;
	this->luong = nv.luong;
}
void NHANVIEN::nhap() {
	cin.ignore();
	cout << "Nhap ID: ";
	getline(cin, ID);
	while (ID.size() != 8) {
		cout << "Nhap ID: ";
		getline(cin, ID);
	}
	cout << "Nhap ho ten: ";
	getline(cin, name);
	cout << "Ngay sinh (dd/mm/yyyy): ";
	cin >> ngaysinh;
	cout << "Nhap dia chi: ";
	cin.ignore();
	getline(cin, diaChi);
}
void NHANVIEN::xuat() {
	cout << "ID: " << ID << endl;
	cout << "Ho ten: " << name << endl;
	cout << "Ngay sinh: " << ngaysinh << endl;
	cout << "Dia chi: " << diaChi << endl;
}

double NHANVIEN::tongLuong() {
	return luong;
}

