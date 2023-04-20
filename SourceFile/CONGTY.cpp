#include "CONGTY.h"

CONGTY::CONGTY() {
	this->soLuongNV = 0;
    this->dsNhanVien = new NHANVIEN * [soLuongNV];
}
CONGTY::CONGTY(int soLuongNV) {
	this->soLuongNV = soLuongNV;
	this->dsNhanVien = new NHANVIEN*[soLuongNV];
}

void CONGTY::nhapCongTy() {
    for (int i = 0; i < soLuongNV; i++) {
        int loaiNV;
        cout << "Nhap loai nhan vien (1: San xuat, 2: Cong nhat): ";
        cin >> loaiNV;
        while (loaiNV != 1 && loaiNV != 2) {
            cout << "Nhap loai nhan vien (1: San xuat, 2: Cong nhat): ";
            cin >> loaiNV;
        }
        string maNV, hoTen, diaChi;
        Date ngaySinh;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> maNV;

        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Ngay sinh (dd/mm/yyyy): ";
        cin >> ngaySinh;

        cout << "Dia chi: ";
        cin.ignore();
        getline(cin, diaChi);

        if (loaiNV == 1) {
            int soSanPham;
            cout << "Nhap so san pham: ";
            cin >> soSanPham;
            dsNhanVien[i] = new NVSANXUAT(maNV, hoTen, ngaySinh, diaChi, soSanPham);

        }
        else if (loaiNV == 2) {
            int soNgay;
            cout << "Nhap so ngay lam viec: ";
            cin >> soNgay;
            dsNhanVien[i] = new NVCONGNHAT(maNV, hoTen, ngaySinh, diaChi, soNgay);
        }
    }
}

void CONGTY::xuatCongTy() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    for (int i = 0; i < soLuongNV; i++) {
        cout << "Nhan vien thu " << i + 1 << ":" << endl;
        dsNhanVien[i]->xuat();
        cout << endl;
    }
}
CONGTY& CONGTY::operator=(const CONGTY& ct) {
    if (this == &ct) {
        return *this;
    }
    if (dsNhanVien != NULL) {
        for (int i = 0; i < soLuongNV; i++) {
            delete dsNhanVien[i];
        }
        delete[] dsNhanVien;
    }
    soLuongNV = ct.soLuongNV;
    dsNhanVien = new NHANVIEN * [soLuongNV];
    for (int i = 0; i < soLuongNV; i++) {
        if (typeid(*(ct.dsNhanVien[i])) == typeid(NVSANXUAT)) {
            dsNhanVien[i] = new NVSANXUAT(*(dynamic_cast<NVSANXUAT*>(ct.dsNhanVien[i])));
        }
        else {
            dsNhanVien[i] = new NVCONGNHAT(*(dynamic_cast<NVCONGNHAT*>(ct.dsNhanVien[i])));
        }
    }
    return *this;
}

void CONGTY::tongLuong() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    double sumLuong = 0;
    for (int i = 0; i < soLuongNV; i++)
    {
        sumLuong += dsNhanVien[i]->tongLuong();
    }
    cout << "Tong luong cua cong ty: " << sumLuong << endl;
}
void CONGTY::maxLuong() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    double maxLuong = 0;
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->tongLuong() > maxLuong) {
            maxLuong = dsNhanVien[i]->tongLuong();
        }
    }
    cout << "Nhan vien co luong cao nhat cong ty: " << endl;
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->tongLuong() == maxLuong) {
            dsNhanVien[i]->xuat();
        }
    }
}
double CONGTY::avgLuong() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return 0;
    }
    double sumLuong = 0;
    for (int i = 0; i < soLuongNV; i++)
    {
        sumLuong += dsNhanVien[i]->tongLuong();
    }
    return sumLuong / double(soLuongNV);
}
void CONGTY::tenNV() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    string name;
    bool check = false;
    cout << "Nhap ten nhan vien can tim kiem: ";
    cin.ignore();
    getline(cin, name);
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->getName() == name) {
            dsNhanVien[i]->xuat();
            check = true;
        }
    }
    if (check == false) {
        cout << "Khong tim thay nhan vien!" << endl;
    }
}
void CONGTY::idNV() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    string id;
    bool check = false;
    cout << "Nhap ten nhan vien can tim kiem: ";
    cin.ignore();
    getline(cin, id);
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->getID() == id) {
            dsNhanVien[i]->xuat();
            check = true;
        }
    }
    if (check == false) {
        cout << "Khong tim thay nhan vien!" << endl;
    }
}
void CONGTY::mayBirth() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    bool check = false;
    cout << "Nhung nhan vien sinh vao thang Nam: " << endl;
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->getNgaysinh().getMonth() == 5) {
            dsNhanVien[i]->xuat();
            check = true;
        }
    }
    if (check == false) {
        cout << "Khong co nhan vien nao sinh vao thang 5" << endl;
    }
}

void CONGTY::copy(const CONGTY& cty) {
    for (int i = 0; i < cty.soLuongNV; i++) {
        if (typeid(*(cty.dsNhanVien[i])) == typeid(NVSANXUAT)) {
            this->dsNhanVien[i] = new NVSANXUAT(*(dynamic_cast<NVSANXUAT*>(cty.dsNhanVien[i])));
        }
        else {
            this->dsNhanVien[i] = new NVCONGNHAT(*(dynamic_cast<NVCONGNHAT*>(cty.dsNhanVien[i])));
        }
    }
}
void CONGTY::addNV() {
    int loaiNV;
    
    soLuongNV += 1;
    int tempIndex = soLuongNV;
    NHANVIEN** temp = (NHANVIEN**)realloc(dsNhanVien, (soLuongNV) * sizeof(NHANVIEN*));
    dsNhanVien = temp;
    cout << "Nhap loai nhan vien (1: San xuat, 2: Cong nhat): ";
    cin >> loaiNV;
    while (loaiNV != 1 && loaiNV != 2) {
        cout << "Nhap loai nhan vien (1: San xuat, 2: Cong nhat): ";
        cin >> loaiNV;
    }
    string maNV, hoTen, diaChi;
    Date ngaySinh;
    cout << "Nhap thong tin nhan vien can them " << endl;
    cout << "ID: ";
    cin >> maNV;

    cout << "Ho ten: ";
    cin.ignore();
    getline(cin, hoTen);

    cout << "Ngay sinh (dd/mm/yyyy): ";
    cin >> ngaySinh;

    cout << "Dia chi: ";
    cin.ignore();
    getline(cin, diaChi);

    if (loaiNV == 1) {
        int soSanPham;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        dsNhanVien[tempIndex-1] = new NVSANXUAT(maNV, hoTen, ngaySinh, diaChi, soSanPham);

    }
    else if (loaiNV == 2) {
        int soNgay;
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgay;
        dsNhanVien[tempIndex-1] = new NVCONGNHAT(maNV, hoTen, ngaySinh, diaChi, soNgay);
    }
    cout << "Them nhan vien thanh cong" << endl;
}
void CONGTY::deleteNV() {
    bool check = false;
    string id;
    cout << "Nhap ID nhan vien can xoa: ";
    cin.ignore();
    getline(cin, id);
    for (int i = 0; i < soLuongNV; i++)
    {
        if (dsNhanVien[i]->getID() == id) {
            for (int j = i; j < soLuongNV - 1; j++)
            {
                dsNhanVien[j] = dsNhanVien[j+1];
            }
            check = true;
            soLuongNV -= 1;
            break;
        }
    }
    NHANVIEN **temp = (NHANVIEN**)realloc(dsNhanVien, (soLuongNV) * sizeof(NHANVIEN*));
    dsNhanVien = temp;
    if (check == false) {
        cout << "Khong tim thay ID trung khop de xoa" << endl;
    }
    else {
        cout << "Xoa nhan vien thanh cong!" << endl;
    }
}
void CONGTY::writeFile() {
    if (soLuongNV == 0) {
        cout << "Danh sach nhan vien trong" << endl;
        return;
    }
    ofstream file;
    int count = 0;
    file.open("emp_LowerAvgSalary.dat", ios::out);
    if (file.is_open()) {
        double avgLuong = this->avgLuong();
        file << "Luong trung binh cua cong ty: " << fixed << setprecision(2) << avgLuong << endl;
        file << endl;
        for (int i = 0; i < soLuongNV; i++)
        {
            if (dsNhanVien[i]->tongLuong() < avgLuong) {
                file << "Nhan vien " << ++count << endl;
                file << "ID: " << dsNhanVien[i]->getID() << endl;
                file << "Ho ten: " << dsNhanVien[i]->getName() << endl;
                file << "Ngay sinh: " << dsNhanVien[i]->getNgaysinh().getDay() << "/" << dsNhanVien[i]->getNgaysinh().getMonth() << "/" << dsNhanVien[i]->getNgaysinh().getYear() << endl;
                file << "Dia chi: " << dsNhanVien[i]->getDiaChi() << endl;
                file << "Tong luong: " << fixed << setprecision(2) << dsNhanVien[i]->tongLuong() << endl;
                file << endl;
            }
        }
    }
    cout << "Ghi file thanh cong" << endl;
    file.close();
}


CONGTY::~CONGTY() {
    for (int i = 0; i < soLuongNV; i++) {
        delete dsNhanVien[i];
    }
    delete[] dsNhanVien;
}