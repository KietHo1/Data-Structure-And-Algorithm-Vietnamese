#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef int ItemType;
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
SNode* CreateSNode(ItemType x); //Them x vao nut moi trong danh sach
void ShowSNode(SNode* p); //Hien thi mot node ra man hinh
int InsertHead(SList &sl, SNode* p); //Them node p vao dau danh sach
void CreateAutoSList(SList &sl); //Tao danh sach lien ket don tu dong
void ShowSList(SList sl); //Hien thi mot danh sach lien ket don ra man hinh
SNode* FindSNode(SList sl, ItemType x); //Tim node trong danh sach co gia tri la x
int InsertAfter(SList &sl, SNode* q, SNode* p); //Them node p vao sau node q
int InsertTail(SList &sl, SNode* p); //Them node p vao cuoi danh sach
int DeleteHead(SList &sl, ItemType &x); //Xoa node dau
int DeleteTail(SList &sl, ItemType &x); //Xoa node cuoi
int DeleteAfter(SList &sl, SNode* q, ItemType &x); //Xoa nut sau nut q cua danh sach
int DeleteSNodeX(SList &sl, ItemType x); //Xoa nut co gia tri x cua danh sach
void Swap(ItemType &x, ItemType &y); //Hoan vi thong tin 2 bien
int DeleteSList(SList &sl); //Xoa toan bo danh sach
ItemType TinhTong(ItemType p1, ItemType p2);
ItemType tinhTongSList(SList sl);
void tachChanLe(SList &sl, SList &sl1, SList &sl2);
int xoaLonHonX(SList &sl, ItemType x);
int xoaChanX(SList &sl);
void SelectionSort_Ascending_SList(SList &sl); //Sap xep tang dan
void SelectionSort_Descending_SList(SList &sl); //Sap xep giam dan
void Swap(ItemType &x, ItemType &y); //Hoan vi
int kiemtraSNT(ItemType &n); //Kiem tra so nguyen to
int demSNT(SList &sl); //Dem so nguyen to trong danh sach lien ket
int checkChinhPhuong(ItemType &x); //Kiem tra so chinh phuong
int tongChinhPhuong(SList &sl); //Tinh tong cac so chinh phuong co trong danh sach lien ket
int demLonHonGapDoi(SList sl); //Cho biết trong dskl có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó
SNode* Min_SList(SList &sl);
SNode* Max_SList(SList &sl);