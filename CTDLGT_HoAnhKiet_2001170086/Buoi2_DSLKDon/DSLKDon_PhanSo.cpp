#include"DSLKDon_PhanSo.h"
void initList(SList &sl){
	//Khoi tao danh sach rong
	sl.Head = NULL;
	sl.Tail = NULL;
}

int IsEmpty(SList sl){
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}

SNode* CreateSNode(ItemType x){
	SNode* p = new SNode;
	if (p == NULL){
		printf("\nKhong the cap nhat nut moi!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void KiemTraDoiDau(PhanSo &ps){
	if (ps.Mauso < 0){
		ps.Tuso *= -1;
		ps.Mauso *= -1;
	}
}

int TimUCLN(int x, int y){
	if (x == 0 && y == 0)
		return 1;
	x = abs(x);
	y = abs(y);
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}

void RutGonPhanSo(ItemType &ps){
	KiemTraDoiDau(ps);
	int UCLN = TimUCLN(ps.Tuso, ps.Mauso);
	ps.Tuso /= UCLN;
	ps.Mauso /= UCLN;
}

void XuatPhanSo(ItemType ps){
	printf("%d/%d", ps.Tuso, ps.Mauso);
}

void ShowSNode(SNode *p){
	XuatPhanSo(p->Info);
}

int InsertHead(SList &sl, SNode* p){
	if (p == NULL)
		return 0;
	if (IsEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}

void CreatePhanSo(ItemType &ps)
{
	ps.Tuso = rand() % (99) + 1;
	ps.Mauso = rand() % (99) + 1; //tu so va mau so khac khong
}

void CreateAutoSList(SList &sl){
	int n;
	do
	{
		printf("\nCho biet so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		PhanSo ps;
		int kq;
		CreatePhanSo(ps);
		RutGonPhanSo(ps);
		SNode* p = CreateSNode(ps);
		kq = InsertTail(sl, p);
		if (kq == 0){
			printf("\nKhong them duoc phan so!");
			XuatPhanSo(p->Info);
		}
	}
}

void ShowSList(SList sl){
	if (IsEmpty(sl) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		ShowSNode(p);
		printf(" ");
	}
}

int SoSanhPhanSo(PhanSo p1, PhanSo p2){
	int kq = (p1.Tuso * p2.Mauso) - (p2.Tuso * p1.Mauso);
	if (kq > 0)
		return 1; // p1 lon hon p2
	else if (kq < 0)
		return -1; // p1 nho hon p2
	else
		return 0; // p1 bang p2
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

int InsertTail(SList &sl, SNode* p){
	if (p == NULL)
		return 0;
	if (IsEmpty(sl) == 1){
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}

PhanSo TinhTong(PhanSo p1, PhanSo p2){
	PhanSo kq = { 0, 1 };
	kq.Tuso = p1.Tuso * p2.Mauso + p2.Tuso * p1.Mauso;
	kq.Mauso = p1.Mauso * p2.Mauso;
	RutGonPhanSo(kq);
	return kq;
}


PhanSo TinhTich(PhanSo p1, PhanSo p2){
	PhanSo kq = { 1, 1 };
	kq.Tuso = p1.Tuso *  p2.Tuso;
	kq.Mauso = p1.Mauso * p2.Mauso;
	RutGonPhanSo(kq);
	return kq;
}

PhanSo tinhTongSList(SList sl){
	PhanSo kq = { 0, 1 };
	if (IsEmpty(sl) == 1)
		return kq;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		kq = TinhTong(p->Info, kq);
	}
	return kq;
}

void NhapPhanSo(ItemType &x)
{
	do
	{
		printf("\nNhap tu so: ");
		scanf("%d", &x.Tuso);
	} while (x.Tuso == 0);
	do
	{
		printf("Nhap mau so: ");
		scanf("%d", &x.Mauso);
	} while (x.Mauso == 0);
	RutGonPhanSo(x);
}

//d.Tính tích các phân số.
PhanSo tinhTichSList(SList sl){
	PhanSo kq = { 1, 1 };
	if (IsEmpty(sl) == 1)
		return kq;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		kq = TinhTich(kq, p->Info);
	}
	return kq;
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

int DeleteSNodeX(SList &sl, ItemType x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	SNode* q = NULL; //se tro den nut ke truoc p
	while ((p != NULL) && (p->Info.Tuso == x.Tuso) && (p->Info.Mauso == x.Mauso))
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

void SelectionSort_Ascending_SList(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (SoSanhPhanSo(q->Info, min->Info) == -1)
				min = q;
			if (min != p)
				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
		}
	}
}

void Swap(ItemType &x, ItemType &y){
	ItemType t = x;
	x = y;
	y = t;
}

int DeleteSList(SList &sl)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	while (sl.Head != NULL)
	{
		SNode* p = sl.Head;
		sl.Head = sl.Head->Next;
		delete p; //Hoac DeleteSNode(p);
	}
	sl.Tail = NULL;
	return 1; //Thuc hien thanh cong
}

//e.Cho biết phân số lớn nhất, phân số nhỏ nhất.
SNode* Min_SList(SList &sl)
{

	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (SoSanhPhanSo(q->Info, min->Info) == -1)
				min = q;
			if (min != p)
				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
		}
		return min;
	}
	return NULL;
}
SNode* Max_SList(SList &sl)
{

	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* max = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (SoSanhPhanSo(q->Info, max->Info) == 1)
				max = q;
			if (max != p)
				Swap(max->Info, p->Info); //Hoan vi thong tin mot nut
		}
		return max;
	}
	return NULL;
}

//f.Tăng mỗi phân số của danh sách lên 1 đơn vị
ItemType tang1DonVi(ItemType p1){
	p1.Tuso = p1.Tuso + p1.Mauso;
	p1.Mauso = p1.Mauso;
	return p1;
}
void ShowSListTang1(SList sl){
	if (IsEmpty(sl) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		tang1DonVi(p->Info);
		ShowSNode(p);
		printf(" ");
	}
}

//g.Xuất các phân số lớn hơn 1 trong danh sách liên kết
int kiemTraLonHon1(ItemType &p){
	if (p.Tuso < p.Mauso) return 0;
	else if (p.Tuso == p.Mauso) return 0;
	else
		return 1;
}
void ShowSListLon1(SList sl){
	if (IsEmpty(sl) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		if (kiemTraLonHon1(p->Info) == 1){
			ShowSNode(p);
			printf(" ");
		}
	}
}

//h.Viết hàm trả về SNode chứa phân số p trong danh sách liên kết.Nếu không có p trong
//DSLK thì trả về NULL
SNode* FindSNode(SList sl, PhanSo x){
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		if (SoSanhPhanSo(p->Info, x) == 0)
			return p;
	}
	return NULL;
}