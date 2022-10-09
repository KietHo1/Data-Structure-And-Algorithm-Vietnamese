#include"DSLKDon_SoNguyen.h"
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
		printf("Khong the cap nhat nut moi!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void ShowSNode(SNode* p){
	printf("%4d", p->Info);
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

void CreateAutoSList(SList &sl){
	int n, kq;
	do
	{
		printf("\nCho biet so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		ItemType x = (rand() % 99) + 1;
		SNode* p = CreateSNode(x);
		kq = InsertHead(sl, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi!");
	}
}

void ShowSList(SList sl){
	if (IsEmpty(sl) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		ShowSNode(p);
}

SNode* FindSNode(SList sl, ItemType x){
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		if (p->Info == x)
			return p;
	}
	return NULL;
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
	while ((p != NULL) && (p->Info != x))
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

ItemType TinhTong(ItemType p1, ItemType p2){
	ItemType kq = { 0 };
	kq = p1 + p2;
	return kq;
}

ItemType tinhTongSList(SList sl){
	ItemType kq = { 0 };
	if (IsEmpty(sl) == 1)
		return kq;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		kq = TinhTong(p->Info, kq);
	}
	return kq;
}

void tachChanLe(SList &sl, SList &sl1, SList &sl2){
	initList(sl1);
	initList(sl2);
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		if (p->Info % 2 == 0)
			InsertTail(sl1, p);
		else
			InsertTail(sl2, p);
	}
	printf("\nDanh sach chua cac so chan: ");
	ShowSList(sl1);
	printf("\nDanh sach chua cac so le: ");
	ShowSList(sl2);
}

//c.Viết hàm xóa các phần tử lớn hơn x trong dslk
int xoaLonHonX(SList &sl, ItemType x)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	SNode* q = NULL; //se tro den nut ke truoc p
	while ((p != NULL) && (p->Info > x))
	{//Vong lap tim nut p chua x, q la nut ke truoc p
		q = p;
		p = p->Next;
	}
	if (p == NULL) //khong tim thay phan tu co khoa bang x
		return 0; //Khong thuc hien duoc
	if (p == sl.Head) //p co khoa bang x la nut dau danh sach
		DeleteHead(sl, x);
	else // xoa nut p co khoa x nam ke sau nut q
		DeleteAfter(sl, q, x);ê
	return 1; //Thuc hien thanh cong
}
//d.Viết hàm xóa các phần tử chẵn trong dslk
int xoaChanX(SList &sl)
{
	if (IsEmpty(sl) == 1)
		return 0; //Khong thuc hien duoc
	SNode* p = sl.Head;
	SNode* q = NULL; //se tro den nut ke truoc p
	while ((p != NULL) && (p->Info % 2 == 0))
	{//Vong lap tim nut p chua x, q la nut ke truoc p
		q = p;
		p = p->Next;
	}
	if (p == NULL) //khong tim thay phan tu co khoa bang x
		return 0; //Khong thuc hien duoc
	if (p == sl.Head) //p co khoa bang x la nut dau danh sach
		DeleteHead(sl, p->Info);
	else // xoa nut p co khoa x nam ke sau nut q
		DeleteAfter(sl, q, p->Info);
	return 1; //Thuc hien thanh cong
}

//e.Sắp xếp dslk tăng dần, giảm dần
void SelectionSort_Ascending_SList(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (q->Info < min->Info)
				min = q;
			if (min != p)
				Swap(min->Info, p->Info); //Hoan vi thong tin mot nut
		}
	}
}
void SelectionSort_Descending_SList(SList &sl)
{
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* max = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (q->Info > max->Info)
				max = q;
			if (max != p)
				Swap(max->Info, p->Info); //Hoan vi thong tin mot nut
		}
	}
}
void Swap(ItemType &x, ItemType &y){
	ItemType t = x;
	x = y;
	y = t;
}

//f.Cho biết trong dslk có bao nhiêu số nguyên tố
int kiemtraSNT(ItemType &n){
	double x = n;
	if (n < 2){
		printf("\n%d khong phai so nguyen to", n);
		return 0;
	}
	int count = 0;
	for (int i = 2; i <= sqrt(x); i++){
		if (n % i == 0){
			count++;
		}
	}
	if (count == 0)
		return 1;
	else
		return 0;
}
int demSNT(SList &sl){
	int dem = 0;
	if (IsEmpty(sl) == 1) return 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (kiemtraSNT(p->Info) == 1)
			dem++;
	}
	return dem;
}

//g.Tính tổng các số chính phương trong dslk
int checkChinhPhuong(ItemType &x){
	double n = x;
	int sqr = sqrt(n);
	if (sqr*sqr == x)
		return 1;
	else
		return 0;
}
int tongChinhPhuong(SList &sl){
	int tong = 0;
	if (IsEmpty(sl) == 1) return 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (checkChinhPhuong(p->Info) == 1)
			tong += p->Info;
	}
	return tong;
}
//h.Tìm phần tử nhỏ nhất, phần tử lớn nhất trong dslk
SNode* Min_SList(SList &sl)
{
	
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return NULL;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* min = p;
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (q->Info < min->Info)
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
			if (q->Info > max->Info)
				max = q;
			if (max != p)
				Swap(max->Info, p->Info); //Hoan vi thong tin mot nut
		}
		return max;
	}
	return NULL;
}

//i.Cho biết trong dskl có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó
int demLonHonGapDoi(SList sl){
	int dem = 0;
	if (IsEmpty(sl) == 1 || sl.Head == sl.Tail) return 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next){
			if (p->Info > 2 * q->Info)
				dem++;
		}
	}
	return dem;
}