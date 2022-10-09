#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

struct PhanSo{
	int Tuso;
	int Mauso;
};
typedef PhanSo ItemType;
struct SNode{
	ItemType Info;
	SNode* Next;
};

struct SList{
	SNode* Head;
	SNode* Tail;
};

void initList(SList &sl); //Khoi tao danh sach rong
int IsEmpty(SList sl); //Kiem tra danh sach rong
SNode* CreateSNode(PhanSo x); //Them x vao nut moi trong danh sach
void ShowSNode(SNode* p); //Hien thi mot node ra man hinh
int InsertHead(SList &sl, SNode* p); //Them node p vao dau danh sach
void CreateAutoSList(SList &sl); //Tao danh sach lien ket don tu dong
void ShowSList(SList sl); //Hien thi mot danh sach lien ket don ra man hinh
SNode* FindSNode(SList sl, PhanSo x); //Tim node trong danh sach co gia tri la x
int InsertAfter(SList &sl, SNode* q, SNode* p); //Them node p vao sau node q
int InsertTail(SList &sl, SNode* p); //Them node p vao cuoi danh sach
void KiemTraDoiDau(PhanSo &ps); //Kiem tra doi dau
int TimUCLN(int x, int y); // Tim uoc chung lon nhat cua x va y
void RutGonPhanSo(PhanSo &ps); // Rut gon phan so
void NhapPhanSo(ItemType &x);
void XuatPhanSo(PhanSo ps); //Xuat phan so ra man hinh
int SoSanhPhanSo(PhanSo p1, PhanSo p2); //So sanh 2 phan so
PhanSo TinhTong(PhanSo p1, PhanSo p2); // Tong 2 phan so p1 va p2
PhanSo TinhTich(PhanSo p1, PhanSo p2); // Tich 2 phan so p1 va p2
PhanSo tinhTongSList(SList sl);
PhanSo tinhTichSList(SList sl);
int DeleteHead(SList &sl, ItemType &x); //Xoa node dau
int DeleteTail(SList &sl, ItemType &x); //Xoa node cuoi
int DeleteAfter(SList &sl, SNode* q, ItemType &x); //Xoa nut sau nut q cua danh sach
int DeleteSNodeX(SList &sl, ItemType x); //Xoa nut co gia tri x cua danh sach
void SelectionSort_Ascending_SList(SList &sl); //Sap xep danh sach tang dan
void Swap(ItemType &x, ItemType &y); //Hoan vi thong tin 2 bien
int DeleteSList(SList &sl); //Xoa toan bo danh sach
ItemType tang1DonVi(ItemType p1); //Tang moi phan so 1 don vi
void ShowSListTang1(SList sl); //Xuat danh sach cac phan so da tang 1 don vi
int kiemTraLonHon1(ItemType &p); //Kiem tra mot phan so co lon hon 1 hay khong?
void ShowSListLon1(SList sl); //Xuat danh sach cac phan so lon hon 1