#include"Queue_SoNguyen.h"
void ShowMenu(){
	printf("\n**************************************************");
	printf("\n                      MENU                        ");
	printf("\n--------------------------------------------------");
	printf("\n* 1. Tao hang doi(ngau nhien)                    *");
	printf("\n* 2. Xem noi dung hang doi                       *");
	printf("\n* 3. Them so nguyen vao hang doi                 *");
	printf("\n* 4. Xoa so nguyen khoi hang doi                 *");
	printf("\n* 5. Tim so nguyen trong hang doi                *");
	printf("\n* 6. Xem gia tri phan tu o dau hang doi          *");
	printf("\n* 7. Xem gia tri phan tu o cuoi hang doi         *");
	printf("\n* 8. Xoa toan bo hang doi va xem noi dung        *");
	printf("\n* 0. Thoat chuong trinh                          *");
	printf("\n**************************************************");
}
void Process(){
	Queue Q;
	ItemType X, Y;
	int luaChon;
	int kq;
	QueueNode* P;
	initQueue(Q);
	do
	{
		ShowMenu();
		do
		{
			printf("\nBan hay chon mot chuc nang: ");
			scanf("%d", &luaChon);
		} while (luaChon < 0 || luaChon > 8);
		switch (luaChon)
		{
		case 1:
			initQueue(Q);
			CreateAutoQueueList(Q);
			break;
		case 2:
			ShowQueueList(Q);
			break;
		case 3:
			printf("Nhap so nguyen moi vao hang doi: ");
			scanf("%d", &X);
			P = CreateQueueNode(X);
			kq = Insert(Q, P);
			if (kq == 1)
				printf("\nThem thanh cong!");
			else
				printf("Them khong thanh cong!");
			break;
		case 4:
			kq = Remove(Q, X);
			if (kq == 1){
				printf("\nSo nguyen vua xoa ra khoi hang doi\n");
				printf("%d", X);
			}
			else
				printf("\nHang doi rong!");
			break;
		case 5:
			ItemType Y;
			printf("\nCho biet so nguyen can tim: ");
			scanf("%d", &Y);
			P = FindQueueNode(Q, Y);
			if (P != NULL)
			{
				printf("So nguyen can tim la: \n");
				printf("%d", Y);
			}
			else
				printf("Khong tim thay so nguyen can tim!");
			break;
		case 6:
			kq = Head(Q, X);
			if (kq == 1){
				printf("\nGia tri phan tu o dau hang doi: \n");
				printf("%d", X);
			}
			else
				printf("\nKhong xem duoc gia tri phan tu o dau hang doi!");
			break;
		case 7:
			kq = Tail(Q, X);
			if (kq == 1){
				printf("\nGia tri phan tu o cuoi hang doi: \n");
				printf("%d", X);
			}
			else
				printf("\nKhong xem duoc gia tri phan tu o cuoi hang doi!");
			break;
		case 8:
			printf("\nDanh sach hang doi vua xoa la: ");
			DeleteSList(Q, Y);
		}
	} while (luaChon != 0);
}
void main(){
	Process();
	getch();
}