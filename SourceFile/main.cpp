#include"NHANVIEN.h"
#include"NVCONGNHAT.h"
#include"NVSANXUAT.h"
#include"CONGTY.h"
int main() {
    int slNV;
    cout << "Nhap so luong nhan vien: ";
    cin >> slNV;
    CONGTY cty(slNV);
    cty.nhapCongTy();
    int choice;
    cout << endl;
    cout << "MENU" << endl;
    cout << "1. Xuat danh sach cac nhan vien" << endl;
    cout << "2. Tinh tong tien luong cua tat ca nhan vien" << endl;
    cout << "3. Tim nhan vien co luong cao nhat" << endl;
    cout << "4. Tinh luong trung binh trong cong ty" << endl;
    cout << "5. Nhap vao ten, tim nhan vien tuong ung" << endl;
    cout << "6. Nhap vao ma, tim nhan vien tuong ung" << endl;
    cout << "7. Co bao nhieu nhan vien sinh trong thang 5" << endl;
    cout << "8. Them mot nhan vien vao danh sach" << endl;
    cout << "9. Xoa mot nhan vien khoi danh sach" << endl;
    cout << "10. Ghi tat ca cac nhan vien co luong nho hon luong trung binh cua cong ty len tap tin 'emp_LowerAvgSalary.dat'" << endl;
    cout << "0. Thoat" << endl;
    cout << endl;
    do {
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "------------------------------------------------" << endl;
            cout << "DANH SACH NHAN VIEN" << endl;
            cty.xuatCongTy();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 2:
            cty.tongLuong();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 3:
            cty.maxLuong();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 4:
            cout << "Luong trung binh cua cong ty: " << cty.avgLuong() << endl;
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 5:
            cty.tenNV();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 6:
            cty.idNV();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 7:
            cty.mayBirth();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 8:
            cty.addNV();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 9:
            cty.deleteNV();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 10:
            cty.writeFile();
            cout << "-------------------------------------------------------------" << endl;
            break;
        case 0:
            cout << "Thoat chuong trinh..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please enter a number from 0-10.";
            break;
        }
    } while (choice != 0);

    return 0;
}
