#include"DSLKDon_BaiHat.h"

void docThongTinBH(FILE *fi, ItemType &x){
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.tenBH, &x.tenTG, &x.tenCS, &x.thoiLuong);
}

void xuatThongTinBH(ItemType x){
	printf("%-30s%-25s%-25s%-10d", x.tenBH, x.tenTG, x.tenCS, x.thoiLuong);
}

void docDanhSachBH(char fileName[], SList &sl){
	FILE *fi = fopen(fileName, "rt");
	if (fi == NULL){
		printf("Loi doc file!");
		getch();
		return;
	}
	initList(sl);
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		ItemType x;
		docThongTinBH(fi, x);
		SNode *p = CreateSNode(x);
		InsertHead(sl, p); //Them nut p vao dau danh sach sl
	}
	fclose(fi);
}

void xuatDanhSachBH(SList sl){
	if (IsEmpty(sl) == 1){
		printf("Danh sach rong!");
		return;
	}
	printf("\n%-5s%-30s%-25s%-25s%-10s", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SI", "THOI LUONG");
	int stt = 1;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (p == NULL) return;
		printf("\n%-5d", stt++);
		xuatThongTinBH(p->Info);
	}
}

SNode* timBaiHat(SList sl, char tenBH[]){
	if (IsEmpty(sl) == 1){
		return NULL;
	}
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(tenBH, p->Info.tenBH) == 0)
			return p;
	}
	return NULL; //Khong co thong tin cua bai hat muon tim
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

void ShowSNode(SNode *p){
	xuatThongTinBH(p->Info);
}

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

void ShowSList(SList sl){
	if (IsEmpty(sl) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		ShowSNode(p);
		printf(" ");
	}
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


int tinhTongTHgianSList(SList sl){
	int tg = 0;
	if (IsEmpty(sl) == 1)
		return tg;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		tg = tg + p->Info.thoiLuong;
	}
	return tg;
}

//g.Sắp xếp các bài hat trong playlist theo thứ tự từ điển của tên bài hát
void sapXepTheoTenBH(SList sl){
	SNode* tmp;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (strcmp(p->Info.tenBH, q->Info.tenBH) > 0)
			{
				strcpy(tmp->Info.tenBH, p->Info.tenBH);
				strcpy(p->Info.tenBH, q->Info.tenBH);
				strcpy(q->Info.tenBH, tmp->Info.tenBH);
			}
		}
	}
}

//h.Sắp xếp các bài hát thứ tự giảm dần của tên ca sĩ
void sapXepTheoTenCS(SList sl){
	SNode* tmp;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (strcmp(p->Info.tenCS, q->Info.tenCS) < 0)
			{
				strcpy(tmp->Info.tenCS, p->Info.tenCS);
				strcpy(p->Info.tenCS, q->Info.tenCS);
				strcpy(q->Info.tenCS, tmp->Info.tenCS);
			}
		}
	}
}
//i.Đưa một bài hát trong playlist lên đầu
//void DoiChoBaiHatLenDau(SList &sl, char *tenbh){
//	SNode* bhat = timBaiHat(sl, tenbh);
//	if (IsEmpty(sl) == 1 || (sl.Head = sl.Tail)) return;
//	for (SNode* p = sl.Head; p != NULL; p = p->Next){
//		Swap(sl.Head->Info, bhat->Info);
//	}
//}
void Swap(ItemType &x, ItemType &y){
	ItemType t = x;
	x = y;
	y = t;
}