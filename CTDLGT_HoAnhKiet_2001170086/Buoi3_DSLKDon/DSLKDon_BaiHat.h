#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define FILENAME "dsBaiHat.txt"

struct BaiHat
{
	char tenBH[51], tenTG[41], tenCS[41];
	int thoiLuong;
};

typedef BaiHat ItemType;

struct SNode{
	ItemType Info;
	SNode* Next;
};

struct SList{
	SNode* Head;
	SNode* Tail;
};

void docThongTinBH(FILE *fi, ItemType &x); //Doc thong tin mot bai hat
void xuatThongTinBH(ItemType x); //Xuat thong tin mot bai hat
void docDanhSachBH(char filename[], SList &sl); //Doc mot danh sach bai hat
void xuatDanhSachBH(SList sl); //Xuat mot danh sach bai hat
SNode* CreateSNode(ItemType x); //Them x vao nut moi trong danh sach
void ShowSNode(SNode* p); //Hien thi mot node ra man hinh
void initList(SList &sl); //Khoi tao danh sach rong
int IsEmpty(SList sl); //Kiem tra danh sach rong
void ShowSList(SList sl); //Hien thi mot danh sach lien ket don ra man hinh
int InsertHead(SList &sl, SNode* p); //Them node p vao dau danh sach
int DeleteHead(SList &sl, ItemType &x); //Xoa node dau
SNode* timBaiHat(SList sl, char tenBH[]); //Tim bai hat
int tinhTongTHgianSList(SList sl); //Tinh tong thoi gian cua danh sach bai hat
void sapXepTheoTenBH(SList sl); //Sap xep theo thu tu chu cai
void sapXepTheoTenCS(SList sl); //Sap xep giam dan theo ten ca si
void Swap(ItemType &x, ItemType &y); //Hoan vi