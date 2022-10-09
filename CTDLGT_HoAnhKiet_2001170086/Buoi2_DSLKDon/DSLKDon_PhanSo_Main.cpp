#include"DSLKDon_PhanSo.h"
void ShowMenu(){
	printf("\n************************************************");
	printf("\n*                 MENU                         *");
	printf("\n*-----------------------------------------------");
	printf("\n* 1. Tao danh sach phan so tu dong(ngau nhien) *");
	printf("\n* 2. Xuat noi dung danh sach phan so           *");
	printf("\n* 3. Tinh tong danh sach phan so               *");
	printf("\n* 4. Tim mot nut chua gia tri x bat ky         *");
	printf("\n* 5. Them mot phan so vao dau danh sach        *");
	printf("\n* 6. Them mot phan so vao cuoi danh sach       *");
	printf("\n* 7. Them phan so p vao sau phan so q          *");
	printf("\n* 8. Xoa phan so o dau danh sach               *");
	printf("\n* 9. Xoa phan so o cuoi danh sach              *");
	printf("\n* 10. Xoa phan so p dang sau phan so q         *");
	printf("\n* 11. Xoa toan bo danh sach                    *");
	printf("\n* 12. Tinh tich danh sach phan so              *");
	printf("\n* 0. Thoat chuong trinh                        *");
	printf("\n************************************************");
}
//===============================================================
void Process(){
	ItemType X, Y;
	ItemType kq;
	int kqua;
	SNode *P, *Q;
	int luaChon;
	SList sl;
	initList(sl);
	do
	{
		ShowMenu();
		do
		{
			printf("\nHay chon mot chuc nang (0->5): ");
			scanf("%d", &luaChon);
		} while (luaChon < 0 || luaChon > 12);
		switch (luaChon)
		{
		case 1:
			initList(sl);
			CreateAutoSList(sl);
			ShowSList(sl);
			break;
		case 2:
			ShowSList(sl);
			break;
		case 3:
			kq = tinhTongSList(sl);
			printf("\n Tong cua danh sach la: ");
			XuatPhanSo(kq);
			break;
		case 4:
			NhapPhanSo(X);
			P = FindSNode(sl, X); //tim nut p chua gia tri x
			if (P == NULL)
			{
				printf("\nKhong tim thay nut nao co gia tri bang ");
				XuatPhanSo(X);
			}
			else
			{
				printf("\nTon tai nut co gia tri bang ");
				ShowSNode(P);
			}
			break;
		case 5:
			printf("\nCho biet gia tri nut muon them dau danh sach: ");
			NhapPhanSo(X);
			P = CreateSNode(X);
			kqua = InsertHead(sl, P);
			if (kqua == 0)
				printf("\nKhong thuc hien duoc viec them vao dau danh sach!");
			else
				ShowSList(sl);
			break;
		case 6:
			printf("\nCho biet gia tri nut muon them cuoi danh sach: ");
			NhapPhanSo(X);
			P = CreateSNode(X);
			kqua = InsertTail(sl, P);
			if (kqua == 0)
				printf("\nKhong thuc hien duoc viec them vao cuoi danh sach!");
			else
				ShowSList(sl);
			break;
		case 7:
			printf("\nNhap mot phan so x bat ky muon them: ");
			NhapPhanSo(X);
			P = CreateSNode(X);
			printf("Nhap phan so nut ke truoc: ");
			NhapPhanSo(Y);

			Q = FindSNode(sl, Y);
			kqua = InsertAfter(sl, Q, P);
			if (kqua == 0)
				printf("Khong thuc hien duoc viec them node q vao sau node p!");
			else
				ShowSList(sl);
			break;
		case 8:
			kqua = DeleteHead(sl, X);
			if (kqua == 1)
			{
				printf("Thong tin cua danh sach la: ");
				ShowSList(sl);
				printf("\nGia tri cua nut dau vua bi xoa la: %d/%d", X.Tuso, X.Mauso);
			}
			else
				printf("Xoa nut dau khong thanh cong!");
			break;
		case 9:
			kqua = DeleteTail(sl, X);
			if (kqua == 1)
			{
				printf("Thong tin cua danh sach la: ");
				ShowSList(sl);
				printf("\nGia tri cua nut cuoi vua bi xoa la: %d/%d", X.Tuso, X.Mauso);
			}
			else
				printf("Xoa nut cuoi khong thanh cong!");
			break;
		case 10:
			printf("\nNhap mot phan so x bat ky muon xoa: ");
			NhapPhanSo(X);
			printf("Nhap phan so nut ke truoc: ");
			NhapPhanSo(Y);
			Q = FindSNode(sl, Y);
			kqua = DeleteAfter(sl, Q, X);
			if (kqua == 0)
				printf("Khong thuc hien duoc viec nut p dang sau nut q!");
			else
				ShowSList(sl);
			break;
		case 11:
			kqua = DeleteSList(sl);
			if (kqua == 1)
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
			kq = tinhTichSList(sl);
			printf("\n Tich cua danh sach la: ");
			XuatPhanSo(kq);
			break;
		}
	} while (luaChon != 0);
}
void main()
{
	Process();
}