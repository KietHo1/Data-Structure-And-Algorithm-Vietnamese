#include"DSLKDon_SinhVien.h"
SNodeKQ *CreateNodeKQ(KetQua x)
{
	SNodeKQ *p = new SNodeKQ;
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat SNode!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//==========================================================
SNode *CreateSNode(ItemType x)
{
	SNode *p = new SNode;
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat SNode!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//==========================================================
void InitSListKQ(SListKQ &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//==========================================================
int IsEmpty(SListKQ sl)
{
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}
//==========================================================
void InitSList(SList &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//==========================================================
int IsEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}
//==========================================================
int InsertTailSlistKQ(SListKQ &sl, SNodeKQ* p)
{
	if (p == NULL) return 0;
	if (IsEmpty(sl) == 1) //danh sach ket qua hoc tap rong
		sl.Head = sl.Tail = p;
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//==========================================================
void NhapDiemKQ(KetQua &x)
{
	printf("\nCho biet ma mon hoc: ");
	flushall();
	gets(x.MaMH);
	printf("Cho biet ten mon hoc: ");
	flushall();
	gets(x.TenMH);
	/*Phát sinh ng?u nhiên s? tín ch?
	srand((unsigned)time(NULL));
	x.SoTC = rand()%5+1;
	printf("So tin chi: %d", x.SoTC);*/
	printf("Cho biet so tin chi: ");
	scanf("%d", &x.SoTC);
	x.Diem.DTL = (rand() % 101 * 0.1); //Phat sinh ngau nhien diem tieu luan
	x.Diem.DCK = (rand() % 101 * 0.1); //Phat sinh ngau nhien diem cuoi ky
	if (x.SoTC <= 2)
	{
		x.Diem.DGK = 0;
		x.Diem.DTB = x.Diem.DTL*0.3 + x.Diem.DCK*0.7;
	}
	else
	{
		x.Diem.DGK = (rand() % 101 * 0.1); //Phat sinh ngau nhien diem giua ky
		x.Diem.DTB = x.Diem.DTL*0.2 + x.Diem.DGK*0.3 + x.Diem.DCK*0.5;
	}
	printf("Diem mon hoc: %.1f\n", x.Diem.DTB);
}
//==========================================================
void NhapDiemSV(SListKQ &sl)
{
	InitSListKQ(sl);
	int sm, kq;
	do
	{
		printf("\nCho biet so luong mon hoc: ");
		scanf("%d", &sm);
	} while (sm <= 0);
	for (int i = 1; i <= sm; i++)
	{
		KetQua x;
		NhapDiemKQ(x);
		SNodeKQ* p = CreateNodeKQ(x);
		kq = InsertTailSlistKQ(sl, p);
		if (kq == 0)
			printf("\nKhong the them ket qua hoc tap nay!");
	}
}
//==========================================================
void NhapTTSV(SinhVien &x)
{
	printf("\nCho biet ma sinh vien: ");
	flushall();
	gets(x.MaSV);
	printf("Cho biet ho va ho lot: ");
	flushall();
	gets(x.HoDem);
	printf("Cho biet ten: ");
	flushall();
	gets(x.Ten);
	NhapDiemSV(x.DiemKQ);
}
//==========================================================
float TinhDTB(SListKQ slkq)
{
	int sotc = 0;
	float td = 0;
	for (SNodeKQ* p = slkq.Head; p; p = p->Next)
	{
		KetQua x = p->Info;
		sotc += x.SoTC;
		td += x.Diem.DTB * x.SoTC;
	}
	return (sotc > 0) ? (td / sotc) : 0;
}
//==========================================================
void XuatKetQua(KetQua x)
{
	printf("%-12s%-35s%-10d%-8.1f%-8.1f%-8.1f%-8.1f", x.MaMH, x.TenMH, x.SoTC,
		x.Diem.DTL, x.Diem.DGK, x.Diem.DCK, x.Diem.DTB);
}
//==========================================================
void XuatDiemKQ(SListKQ slkq)
{
	printf("Ket qua hoc tap nhu sau:");
	int i = 1;
	printf("\n%-5s%-12s%-35s%-10s%-8s%-8s%-8s%-8s", "STT", "MSMH", "TEN MON HOC", "SO TC", "DTL", "DGK", "DCK", "DTB");
	for (SNodeKQ* p = slkq.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", i++);
		XuatKetQua(p->Info);
	}
}
//==========================================================
void XuatTTSV(SinhVien x)
{
	float dtb = TinhDTB(x.DiemKQ);
	printf("%-12s%-23s%-10s%10.1f\n", x.MaSV, x.HoDem, x.Ten, dtb);
	XuatDiemKQ(x.DiemKQ);
}
//==========================================================
int InsertTail(SList &sl, SNode* p)
{
	if (p == NULL) return 0;
	if (IsEmpty(sl) == 1)
		sl.Head = sl.Tail = p;
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//==========================================================
void CreateSList(SList &sl)
{
	int n, kq;
	do
	{
		printf("\nCho biet so luong sinh vien: ");
		scanf("%d", &n);
	} while (n <= 0);
	InitSList(sl);
	for (int i = 1; i <= n; i++)
	{
		SinhVien x;
		NhapTTSV(x);
		SNode* p = CreateSNode(x);
		kq = InsertTail(sl, p);
		if (kq == 0)
			printf("\nKhong the them sinh vien nay!");
	}
}
//==========================================================
void ShowSList(SList sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nKhong co sinh vien nao!");
		return;
	}
	int i = 1;
	printf("\nDANH SACH SINH VIEN: ");
	printf("\n%-5s%-12s%-33s%-10s", "STT", "MA SO SV", "HO VA TEN SINH VIEN", "DTB");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n\n%-5d", i++);
		XuatTTSV(p->Info);
	}
}
//==========================================================
SNode* TimTheoMaSV(SList sl, char pMaSV[])
{
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	if (stricmp(p->Info.MaSV, pMaSV) == 0)
		return p;
	return NULL;
}

//c.Sắp xếp DSSV theo chiều tăng dần theo MaSV.
void sapXepTangDanTheoMaSV(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* tmp;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (strcmp(p->Info.MaSV, q->Info.MaSV) > 0)
			{
				strcpy(tmp->Info.MaSV, p->Info.MaSV);
				strcpy(p->Info.MaSV, q->Info.MaSV);
				strcpy(q->Info.MaSV, tmp->Info.MaSV);
			}
		}
	}
}
void Swap(ItemType &x, ItemType &y){
	ItemType t = x;
	x = y;
	y = t;
}
//d.Sắp xếp DSSV theo chiều tăng dần của tên sinh viên.
void sapXepTangDanTheoTenSV(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* tmp;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (strcmp(p->Info.Ten, q->Info.Ten) > 0)
			{
				strcpy(tmp->Info.Ten, p->Info.Ten);
				strcpy(p->Info.Ten, q->Info.Ten);
				strcpy(q->Info.Ten, tmp->Info.Ten);
			}
		}
	}
}
//e.Thêm một sinh viên sao cho vẫn giữ nguyên thứ tự tăng dần của mã số sinh viên(có kiểm
//tra trùng khóa).

//void sapXepTangDanTheoMaSV(SList &sl)
//{
//	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
//	for (SNode* p = sl.Head; p != NULL; p = p->Next)
//	{
//		SNode* tmp;
//		for (SNode* q = p->Next; q != NULL; q = q->Next){
//			if (strcmp(p->Info.MaSV, q->Info.MaSV) > 0)
//			{
//				strcpy(tmp->Info.MaSV, p->Info.MaSV);
//				strcpy(p->Info.MaSV, q->Info.MaSV);
//				strcpy(q->Info.MaSV, tmp->Info.MaSV);
//			}
//		}
//	}
//}
//void NhapTTSV(SinhVien &x)
//{
//	printf("\nCho biet ma sinh vien: ");
//	flushall();
//	gets(x.MaSV);
//	printf("Cho biet ho va ho lot: ");
//	flushall();
//	gets(x.HoDem);
//	printf("Cho biet ten: ");
//	flushall();
//	gets(x.Ten);
//	NhapDiemSV(x.DiemKQ);
//}
//f.Xóa sinh viên có MaSV = x.
int xoaSVCoMaX(SList &sl, ItemType x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	SNode* q = NULL; //se tro den nut ke truoc p
	while ((p != NULL) && (p->Info.MaSV == x.MaSV))
	{//Vong lap tim nut p chua x, q la nut ke truoc p
		q = p;
		p = p->Next;
	}
	if (p == NULL) //khong tim thay phan tu co khoa bang x
		return 0; //Khong thuc hien duoc
	if (p == sl.Head) //p co khoa bang x la nut dau danh sach
		DeleteHead(sl, x);
	else // xoa nut p co khoa x nam ke sau nut q
		DeleteAfter(sl, q, x);
	return 1; //Thuc hien thanh cong
}
//g.Xóa tất cả các sinh viên có tên là x.
int xoaSVCoTenX(SList &sl, ItemType x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	SNode* q = NULL; //se tro den nut ke truoc p
	while ((p != NULL) && (p->Info.Ten == x.Ten))
	{//Vong lap tim nut p chua x, q la nut ke truoc p
		q = p;
		p = p->Next;
	}
	if (p == NULL) //khong tim thay phan tu co khoa bang x
		return 0; //Khong thuc hien duoc
	if (p == sl.Head) //p co khoa bang x la nut dau danh sach
		DeleteHead(sl, x);
	else // xoa nut p co khoa x nam ke sau nut q
		DeleteAfter(sl, q, x);
	return 1; //Thuc hien thanh cong
}
//h.Tạo danh sách mới từ danh sách đã cho sao cho danh sách mới giảm dần theo điểm kết quả
//học tập.
void sapXepGiamDanTheoDiemKQHT(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (TinhDTB(p->Info.DiemKQ) < TinhDTB(p->Info.DiemKQ))
				min = q;
			if (min != p)
				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
		}
	}
}
void dsGiamDanDiemKQHT(SList &sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nKhong co sinh vien nao!");
		return;
	}
	int i = 1;
	printf("\nDANH SACH SINH VIEN GIAM DAN THEO DIEM KET QUA HOC TAP: ");
	printf("\n%-5s%-12s%-33s%-10s", "STT", "MA SO SV", "HO VA TEN SINH VIEN", "DTB");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		sapXepGiamDanTheoDiemKQHT(sl);
		printf("\n\n%-5d", i++);
		XuatTTSV(p->Info);
	}
}
//i.In danh sách các sinh viên được xếp loại khá(sinh viên xếp loại khá nếu thỏa điều kiện : 7.0
//<= điểm kết quả học tập <= 8.5)
void dsXepLoaiKha(SList &sl)
{
	if (IsEmpty(sl) == 1)
	{
		printf("\nKhong co sinh vien nao!");
		return;
	}
	int i = 1;
	printf("\nDANH SACH SINH VIEN XEP LOAI KHA: ");
	printf("\n%-5s%-12s%-33s%-10s", "STT", "MA SO SV", "HO VA TEN SINH VIEN", "DTB");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (TinhDTB(p->Info.DiemKQ) >= 7.0 && TinhDTB(p->Info.DiemKQ) <= 8.5)
		{
			printf("\n\n%-5d", i++);
			XuatTTSV(p->Info);
		}
	}
}

//j.Cho biết sinh viên có điểm kết quả học tập cao nhất.
SNode* Max_SList(SList &sl)
{

	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* max = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (TinhDTB(q->Info.DiemKQ) > TinhDTB(max->Info.DiemKQ))
				max = q;
			if (max != p)
				Swap(max->Info, p->Info); //Hoan vi thong tin mot nut
		}
		return max;
	}
	return NULL;
}
//k.Cho biết sinh viên có điểm kết quả học tập thấp nhất.
SNode* Min_SList(SList &sl)
{

	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (TinhDTB(q->Info.DiemKQ) < TinhDTB(min->Info.DiemKQ))
				min = q;
			if (min != p)
				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
		}
		return min;
	}
	return NULL;
}

//l.Cho biết sinh viên có điểm kết quả học tập thấp nhất trong số các sinh viên xếp loại giỏi.
void dsXepLoaiGioi(SList &sl, SList sl1)
{
	InitSList(sl1);
	int i = 1;
	
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (TinhDTB(p->Info.DiemKQ) > 8.5)
		{
			printf("\n\n%-5d", i++);
			InsertTail(sl1, p);
		}
	}
	printf("\nDANH SACH CAC SINH VIEN XEP LOAI GIOI: ");
	printf("\n%-5s%-12s%-33s%-10s", "STT", "MA SO SV", "HO VA TEN SINH VIEN", "DTB");
	ShowSList(sl1);
}
//SNode* Min_XepLoaiGioi_SList(SList &sl1)
//{
//
//	if (IsEmpty(sl1) == 1 || sl1.Head == sl1.Tail) return NULL;
//	for (SNode* p = sl1.Head; p != NULL; p = p->Next)
//	{
//		SNode* min = p;
//		for (SNode* q = p->Next; q != NULL; q = q->Next){
//			if (TinhDTB(q->Info.DiemKQ) < TinhDTB(min->Info.DiemKQ))
//				min = q;
//			if (min != p)
//				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
//		}
//		return min;
//	}
//	return NULL;
//}
//SNode* Min_SList(SList &sl)
//{
//
//	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
//	for (SNode* p = sl.Head; p != NULL; p = p->Next)
//	{
//		SNode* min = p;
//		for (SNode* q = p->Next; q != NULL; q = q->Next){
//			if (TinhDTB(q->Info.DiemKQ) < TinhDTB(min->Info.DiemKQ))
//				min = q;
//			if (min != p)
//				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
//		}
//		return min;
//	}
//	return NULL;
//}
//m.Cho biết sinh viên có điểm kết quả học tập gần x nhất(x là số thực).
SNode* DKQHTganxnhat(SList sl, float &x){
	{
		if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
		for (SNode* p = sl.Head; p != NULL; p = p->Next)
		{
			SNode* min = p;
			float mingt = labs(x - TinhDTB(min->Info.DiemKQ));
			for (SNode* q = p->Next; q != NULL; q = q->Next){
				if (labs(x - TinhDTB(q->Info.DiemKQ)) < mingt)
					min = q;
				if (min != p)
					Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
			}
			return min;
		}
		return NULL;
	}
}

int DeleteHead(SList &sl, ItemType &x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
		sl.Tail = NULL;
	x = p->Info; //Lay thong tin cua nut bi huy
	delete p; //Huy nut do p tro den
	return 1; //Thuc hien thanh cong
}

int DeleteTail(SList &sl, ItemType &x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* q = sl.Head;
	SNode* p = sl.Tail;
	if (p == q)
		sl.Head = sl.Tail = NULL;
	else
	{
		while (q->Next != p) //Tim nut ke truoc nut Tail
			q = q->Next;
		sl.Tail = q;
		sl.Tail->Next = NULL;
	}
	x = p->Info; //Lay thong tin cua nut bi huy
	delete p; //Huy nut do p tro den
	return 1; //Thuc hien thanh cong
}

int DeleteAfter(SList &sl, SNode* q, ItemType &x)
{
	if (q == NULL || q->Next == NULL)
		return 0; //Khong thuc hien duoc
	SNode* p = q->Next;
	q->Next = p->Next;
	if (p == sl.Tail)
		sl.Tail = q;
	x = p->Info; //Lay thong tin cua nut bi huy
	delete p; //Huy nut do p tro den
	return 1; //Thuc hien thanh cong
}

int InsertAfter(SList &sl, SNode* q, SNode* p){
	if (q == NULL || p == NULL)
		return 0;
	else
	{
		p->Next = q->Next;
		q->Next = p;
		if (sl.Tail == q)
			sl.Tail = p;
	}
	return 1;
}