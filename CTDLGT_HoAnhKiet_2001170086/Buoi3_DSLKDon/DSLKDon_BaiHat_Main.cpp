#include"DSLKDon_BaiHat.h"
void ShowMenu(){
	printf("\n****************************************************");
	printf("\n*                 MENU                             *");
	printf("\n*---------------------------------------------------");
	printf("\n* 1. Tao danh sach bai hat (doc tu file)           *");
	printf("\n* 2. Xuat thong tin danh sach bai hat              *");
	printf("\n* 3. Tim thong tin bai hat                         *");
	printf("\n* 4. Tinh tong thoi gian nghe het tat ca bai hat   *");
	printf("\n* 0. Thoat chuong trinh                            *");
	printf("\n****************************************************");
}

void Process(){
	SList sl;
	int luaChon;
	SNode *p;
	char tenBH[45];
	initList(sl);
	do
	{
		ShowMenu();
		do
		{
			printf("\nHay chon mot chuc nang (0->4): ");
			scanf("%d", &luaChon);
		} while (luaChon < 0 || luaChon > 4);
		switch (luaChon)
		{
		case 1:
			docDanhSachBH(FILENAME, sl);
			printf("\nThong tin cua danh sach cac bai hat la: ");
			xuatDanhSachBH(sl);
			break;
		case 2:
			printf("\nThong tin cua danh sach cac bai hat la: ");
			xuatDanhSachBH(sl);
			break;
		case 3:
			printf("\nThong tin cua danh sach cac bai hat la: ");
			fflush(stdin);
			gets(tenBH);
			p = timBaiHat(sl, tenBH);
			if (p != NULL)
			{
				printf("\nThong tin cua bai hat muon tim: \n");
				xuatThongTinBH(p->Info);
			}
			else
				printf("\nKhong tim thay bai hat!");
			break;
		case 4:
			int tong = tinhTongTHgianSList(sl);
			printf("Tong thoi gian cua danh sach bai hat la: %d", tong);
			break;
		}
	} while (luaChon != 0);
}

void main(){
	Process();
}