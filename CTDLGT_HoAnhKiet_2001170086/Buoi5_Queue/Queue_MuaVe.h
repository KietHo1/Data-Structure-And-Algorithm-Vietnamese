#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 15
struct ThongTinNguoiMuaVe
{
	char HoTen[31];
	char CMND[MAXSIZE];
};
typedef ThongTinNguoiMuaVe ItemType;
struct QueueNode
{
	ItemType Info;
	QueueNode* Next;
};
struct Queue
{
	QueueNode* Head;
	QueueNode* Tail;
};
QueueNode* CreateQueueNode(ItemType x);
void InitQueue(Queue &q);
int IsEmpty(Queue q);
int Insert(Queue &q, QueueNode* p);
int Remove(Queue &q, ItemType &x);
long int KiemTraNhapSo();
char* KiemTraCMND();
void NhapTTNguoiMuaVe(ItemType &x);
void XemTTNguoiMuaVe(ItemType x);
void TaoHangDoi(Queue &q);
void XemNoiDungHangDoi(Queue q);
QueueNode* TimNguoiMuaVe_TheoTen(Queue q, char ten[]);