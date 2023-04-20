#pragma once
#ifndef CONGTY_H
#define CONGTY_H
#include"NHANVIEN.h"
#include"NVCONGNHAT.h"
#include"NVSANXUAT.h"
class CONGTY {
private:
    int soLuongNV;
    NHANVIEN** dsNhanVien;

public:
    CONGTY();
    CONGTY(int soNhanVien);
    ~CONGTY();
    CONGTY& operator=(const CONGTY& cty);
    void copy(const CONGTY& cty);
    void nhapCongTy();
    void xuatCongTy();
    void tongLuong();
    void maxLuong();
    double avgLuong();
    void tenNV();
    void idNV();
    void mayBirth();
    void addNV();
    void deleteNV();
    void writeFile();
};
#endif // !CONGTY_H



