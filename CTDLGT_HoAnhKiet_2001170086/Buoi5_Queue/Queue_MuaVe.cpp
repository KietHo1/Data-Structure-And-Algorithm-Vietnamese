#include"Queue_MuaVe.h"
//===========================================
QueueNode* CreateQueueNode(ItemType x)
{
	QueueNode* p = new QueueNode;
	if (p == NULL)
		return NULL;
	p->Info = x;
	p->Next = NULL;
	return p;
}
//===========================================
void InitQueue(Queue &q)
{ //Initialize Queue
	q.Head = NULL;
	q.Tail = NULL;
}
//===========================================
int IsEmpty(Queue q)
{
	if (q.Head == NULL)
		return 1;
	else
		return 0;
}
//===========================================
int Insert(Queue &q, QueueNode* p)
{
	if (p == NULL) return 0;
	if (IsEmpty(q) == 1)
		q.Head = p;
	else
		q.Tail->Next = p;
	q.Tail = p;
	return 1;
}
//===========================================
int Remove(Queue &q, ItemType &x)
{
	if (IsEmpty(q) == 1)
		return 0;
	QueueNode* p = q.Head;
	q.Head = q.Head->Next;
	if (q.Head == NULL)
		q.Tail == NULL;
	x = p->Info;
	delete p;
	return 1;
}
//===========================================
long int KiemTraNhapSo()
{ //Chỉ cho nhập số, kết thúc khi nhấn phím Enter
	long int n;
	int i = 0;
	char num[MAXSIZE], getnum;
	while ((getnum = getch()) != 13)
	{//13 la Enter
		if (getnum >= '0' && getnum <= '9' && i < MAXSIZE)
		{
			num[i++] = getnum;
			putchar(getnum);
		}
	}
	num[i] = '\0';
	n = atol(num); //atol: chuyen chuoi sang so nguyen
	return n;
}
//===========================================
char* KiemTraCMND()
{ //Chỉ cho nhập số, kết thúc khi nhấn phím Enter
	int i = 0;
	char num[MAXSIZE], getnum;
	while ((getnum = getch()) != 13)
	{//13 la Enter
		if (getnum >= '0' && getnum <= '9' && i < MAXSIZE - 1)
		{
			num[i++] = getnum;
			putchar(getnum); //printf("%c", getnum);
		}
	}
	num[i] = '\0';
	return num;
}
//===========================================
void NhapTTNguoiMuaVe(ItemType &x)
{
	printf("\nNhap ho va ten cua nguoi mua ve: ");
	fflush(stdin);
	gets(x.HoTen);
	printf("Nhap so CMND cua nguoi mua ve: ");
	fflush(stdin);
	strcpy(x.CMND, KiemTraCMND());
}
//===========================================
void XemTTNguoiMuaVe(ItemType x)
{
	printf("%-30s%-7s", x.HoTen, x.CMND);
}
//===========================================
void TaoHangDoi(Queue &q)
{
	int n;
	ItemType x;
	QueueNode* p;
	do
	{
		printf("\nCho biet so luong nguoi xep hang mua ve: ");
		n = KiemTraNhapSo();
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		NhapTTNguoiMuaVe(x);
		p = CreateQueueNode(x);
		Insert(q, p);
	}
}
//===========================================
void XemNoiDungHangDoi(Queue q)
{
	if (IsEmpty(q) == 1)
	{
		printf("\nKhong co nguoi nao dang xep hang.");
		return;
	}
	int stt = 1;
	ItemType x;
	printf("\nDANH SACH NGUOI XEP HANG MUA VE TRONG HANG DOI");
	printf("\n%-5s%-30s%-7s", "STT", "HO VA TEN NGUOI XEP HANG", "SO CMND");
	QueueNode* p = q.Head;
	while (p != NULL)
	{
		printf("\n%-5d", stt++);
		x = p->Info;
		XemTTNguoiMuaVe(x);
		p = p->Next;
	}
}
//===========================================
QueueNode* TimNguoiMuaVe_TheoTen(Queue q, char ten[])
{
	QueueNode* p = q.Head;
	while (p != NULL)
	{
		if (strcmpi(p->Info.HoTen, ten) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}
//===========================================