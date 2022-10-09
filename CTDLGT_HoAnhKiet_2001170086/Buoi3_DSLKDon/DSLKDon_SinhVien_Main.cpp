#include"DSLKDon_SinhVien.h"
void ShowMenu()
{
	printf("\n********************************************");
	printf("\n*                  MENU                    *");
	printf("\n*------------------------------------------*");
	printf("\n* 1. Nhap thong tin sinh vien va diem      *");
	printf("\n* 2. Xuat thong tin sinh vien va diem      *");
	printf("\n* 3. Tim thong tin sinh vien               *");
	printf("\n* 0. Thoat chuong trinh                    *");
	printf("\n********************************************");
}

void Process()
{
	ItemType x, y;
	KeyType masv[11];
	SNode *p, *q;
	int SelectFunction;
	SList sl;
	InitSList(sl);
	do
	{
		ShowMenu();
		printf("\nVui long chon mot chuc nang: ");
		scanf("%d", &SelectFunction);
		switch (SelectFunction)
		{
		case 1:
			CreateSList(sl);
			ShowSList(sl);
			break;
		case 2:
			ShowSList(sl);
			break;
		case 3:
			printf("\nCho biet ma so sinh vien muon tim: ");
			flushall();
			gets(masv);
			q = TimTheoMaSV(sl, masv);
			if (q)
				XuatTTSV(q->Info);
			else
				printf("\nKhong co sinh vien nao co ma so %s", masv);
		}
	} while (SelectFunction != 0);
}

void main()
{
	Process();
}