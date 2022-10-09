#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct DiemMH
{
	float DTL;
	float DGK;
	float DCK;
	float DTB;
};

typedef char KeyType;

struct KetQua
{
	KeyType MaMH[11];
	KeyType TenMH[50];
	int SoTC;
	DiemMH Diem;
};

struct SNodeKQ
{
	KetQua Info;
	SNodeKQ *Next;
};

struct SListKQ
{
	SNodeKQ *Head;
	SNodeKQ *Tail;
};

struct SinhVien
{
	KeyType MaSV[11];
	KeyType HoDem[25];
	KeyType Ten[8];
	SListKQ DiemKQ;
};

typedef SinhVien ItemType;

struct SNode
{
	ItemType Info;
	SNode *Next;
};
struct SList
{
	SNode *Head;
	SNode *Tail;
};

SNodeKQ *CreateNodeKQ(KetQua x);
SNode *CreateSNode(ItemType x);
void InitSListKQ(SListKQ &sl);
int IsEmpty(SListKQ sl);
void InitSList(SList &sl);
int IsEmpty(SList sl);
void NhapDiemKQ(KetQua &x);
void NhapDiemSV(SListKQ &sl);
void NhapTTSV(SinhVien &x);
float TinhDTB(SListKQ slkq);
void XuatKetQua(KetQua x);
void XuatDiemKQ(SListKQ slkq);
void XuatTTSV(SinhVien x);
int InsertTail(SList &sl, SNode* p);
void CreateSList(SList &sl);
void ShowSList(SList sl);
SNode* TimTheoMaSV(SList sl, char pMaSV[]);
void sapXepTangDanTheoMaSV(SList &sl); // Tang dan theo masv
void Swap(ItemType &x, ItemType &y); //Hoan vi
void sapXepTangDanTheoTenSV(SList &sl); //Tang dan theo tensv
int DeleteHead(SList &sl, ItemType &x); //Xoa node dau
int DeleteTail(SList &sl, ItemType &x); //Xoa node cuoi
int DeleteAfter(SList &sl, SNode* q, ItemType &x); //Xoa nut sau nut q cua danh sach
int InsertAfter(SList &sl, SNode* q, SNode* p); //Them node p vao sau node q
int InsertTail(SList &sl, SNode* p); //Them node p vao cuoi danh sach
int xoaSVCoMaX(SList &sl, ItemType x);
int xoaSVCoTenX(SList &sl, ItemType x);
void sapXepGiamDanTheoDiemKQHT(SList &sl);
void dsGiamDanDiemKQHT(SList sl);
void dsXepLoaiKha(SList &sl);
SNode* Max_SList(SList &sl); //Diem ket qua hoc tap cao nhat
SNode* Min_SList(SList &sl); //Diem ket qua hoc tap thap nhat
void dsXepLoaiGioi(SList &sl, SList sl1);
/*SNode* Min_XepLoaiGioi_SList(SList &sl1);*/ //Cho biết sinh viên có điểm kết quả học tập thấp nhất trong số các sinh viên xếp loại giỏi.
SNode* DKQHTganxnhat(SList sl, float &x); //Cho biết sinh viên có điểm kết quả học tập gần x nhất(x là số thực).