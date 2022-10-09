#include"Queue_MuaVe.h"
void ShowMenu()
{
	printf("\n**********************************************");
	printf("\n* MENU *");
	printf("\n*--------------------------------------------*");
	printf("\n* 1. Tao hang doi *");
	printf("\n* 2. Xem noi dung hang doi *");
	printf("\n* 3. Them nguoi xep hang vao hang doi *");
	printf("\n* 4. Goi nguoi trong hang doi mua ve *");
	printf("\n* 5. Tim thong tin nguoi mua ve *");
	printf("\n* 0. Thoat chuong trinh *");
	printf("\n**********************************************");
}
//===========================================
void Process()
{
	Queue Q;
	ItemType X;
	int luaChon;
	int kq;
	QueueNode* P;
	do
	{
		ShowMenu();
		do
		{
			printf("\nBan hay chon mot chuc nang: ");
			luaChon = KiemTraNhapSo();
		} while (luaChon < 0 || luaChon > 5);
		switch (luaChon)
		{
		case 1:
			InitQueue(Q);
			TaoHangDoi(Q);
			break;
		case 2:
			XemNoiDungHangDoi(Q);
			break;
		case 3:
			printf("\nNhap thong tin nguoi mua ve");
			NhapTTNguoiMuaVe(X);
			P = CreateQueueNode(X);
			kq = Insert(Q, P);
			if (kq == 1)
				printf("\nThem thanh cong!");
			else
				printf("\nThem khong thanh cong!");
			break;
		case 4:
			kq = Remove(Q, X);
			if (kq == 1)
			{
				printf("\nThong tin nguoi vua ra khoi hang doi\n");
				XemTTNguoiMuaVe(X);
			}
			else
				printf("\nHang doi rong!");
			break;
		case 5:
			char ten[30];
			printf("\nCho biet Ho va ten nguoi mua ve: ");
			fflush(stdin);
			gets(ten);
			P = TimNguoiMuaVe_TheoTen(Q, ten);
			if (P)
			{
				printf("\nThong tin nguoi can tim la: \n");
				XemTTNguoiMuaVe(P->Info);
			}
			else
				printf("\nKhong tim thay nguoi nao co ten %s", ten);
			break;
		}
	} while (luaChon != 0);
}
//===========================================
void main()
{
	Process();
}