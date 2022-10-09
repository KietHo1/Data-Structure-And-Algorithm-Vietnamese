#include"DSLKDon_SoNguyen.h"
void ShowMenu(){
	printf("\n************************************************");
	printf("\n*                 MENU                         *");
	printf("\n*-----------------------------------------------");
	printf("\n*  1. Tao nut moi va xuat ra noi dung           *");
	printf("\n*  2. Tao danh sach tu dong(ngau nhien)         *");
	printf("\n*  3. Xuat noi dung danh sach                   *");
	printf("\n*  4. Them node vao dau danh sach               *");
	printf("\n*  5. Them node vao cuoi danh sach              *");
	printf("\n*  6. Them nut p chua x vao sau nut q chua y    *");
	printf("\n*  7. Tim mot nut chua gia tri x bat ky         *");
	printf("\n*  8. Xoa node dau                              *");
	printf("\n*  9. Xoa node cuoi                             *");
	printf("\n* 10. Xoa nut p chua x dang sau nut q           *");
	printf("\n* 11. Xoa toan bo danh sach                     *");
	printf("\n* 12. Tong toan bo danh sach                    *");
	printf("\n* 13.Tu sl tao 2 danh sach moi: sl1 chua cac so *");
	printf("\n     chan, sl2 chua cac so le.                  *");
	printf("\n* 0. Thoat chuong trinh                         *");
	printf("\n*************************************************");
}
//===============================================================
void Process(){
	ItemType X, Y, kqua;
	SNode *P, *Q;
	int luaChon, kq;
	SList sl, sl1, sl2;
	initList(sl);
	do
	{
		ShowMenu();
		do
		{
			printf("\nHay chon mot chuc nang (0->13): ");
			scanf("%d", &luaChon);
		} while (luaChon < 0 || luaChon > 13);
		switch (luaChon)
		{
		case 1:
			printf("\nNhap mot so nguyen bat ky: ");
			scanf("%d", &X);
			P = CreateSNode(X);
			printf("\nNoi dung nut moi vua tao la: ");
			ShowSNode(P);
			break;
		case 2:
			initList(sl);
			CreateAutoSList(sl);
			ShowSList(sl);
			break;
		case 3:
			ShowSList(sl);
			break;
		case 4:
			printf("\nCho biet gia tri nut muon them dau danh sach: ");
			scanf("%d", &X);
			P = CreateSNode(X);
			kq = InsertHead(sl, P);
			if (kq == 0)
				printf("\nKhong thuc hien duoc viec them vao dau danh sach!");
			else
				ShowSList(sl);
			break;
		case 5:
			printf("\nCho biet gia tri nut muon them cuoi danh sach: ");
			scanf("%d", &X);
			P = CreateSNode(X);
			kq = InsertTail(sl, P);
			if (kq == 0)
				printf("\nKhong thuc hien duoc viec them vao cuoi danh sach!");
			else
				ShowSList(sl);
			break;
		case 6:
			printf("\nNhap mot so nguyen x bat ky muon them: ");
			scanf("%d", &X);
			printf("Nhap mot gia tri nut ke truoc: ");
			scanf("%d", &Y);
			P = CreateSNode(X);
			Q = FindSNode(sl, Y);
			kq = InsertAfter(sl, Q, P);
			if (kq == 0)
				printf("Khong thuc hien duoc viec them node q vao sau node p!");
			else
				ShowSList(sl);
			break;
		case 7:
			printf("\nNhap mot so nguyen x bat ky muon tim: ");
			scanf("%d", &X);
			P = FindSNode(sl, X);
			if (P == NULL)
				printf("\nKhong tim thay nut nao co gia tri bang %d", X);
			else
				printf("\nTon tai nut co gia tri bang: %d", X);
			break;
		case 8:
			kq = DeleteHead(sl, X);
			if (kq == 1)
			{
				printf("Thong tin cua danh sach la: ");
				ShowSList(sl);
				printf("\nGia tri cua nut dau vua bi xoa la: %d", X);
			}
			else
				printf("Xoa nut dau khong thanh cong!");
			break;
		case 9:
			kq = DeleteTail(sl, X);
			if (kq == 1)
			{
				printf("Thong tin cua danh sach la: ");
				ShowSList(sl);
				printf("\nGia tri cua nut cuoi vua bi xoa la: %d", X);
			}
			else
				printf("Xoa nut cuoi khong thanh cong!");
			break;
		case 10:
			printf("\nNhap mot so nguyen x bat ky muon xoa: ");
			scanf("%d", &X);
			printf("Nhap mot gia tri nut ke truoc: ");
			scanf("%d", &Y);
			Q = FindSNode(sl, Y);
			kq = DeleteAfter(sl, Q, X);
			if (kq == 0)
				printf("Khong thuc hien duoc viec nut p dang sau nut q!");
			else
				ShowSList(sl);
			break;
		case 11:
			kq = DeleteSList(sl);
			if (kq == 1)
			{
				printf("\nXoa toan bo danh sach thanh cong!");
				ShowSList(sl);
			}
			else
			{
				printf("Xoa toan bo danh sach khong thanh cong!");
				ShowSList(sl);
			}
			break;
		case 12:
			kqua = tinhTongSList(sl);
			printf("\n Tong cua danh sach la: %d", kqua);
			break;
		case 13:
			tachChanLe(sl, sl1, sl2);
		}
	} while (luaChon != 0);
}
void main(){
	Process();
}