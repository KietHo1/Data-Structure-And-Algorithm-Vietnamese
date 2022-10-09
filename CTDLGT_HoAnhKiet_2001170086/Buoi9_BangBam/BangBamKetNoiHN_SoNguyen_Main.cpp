#include"BangBamKetNoiHN_SoNguyen.h"
// ShowMenu chương trình
void ShowMenu()
{
	printf("\n**************************************************");
	printf("\n*                      MENU                      *");
	printf("\n*------------------------------------------------*");
	printf("\n* 1: Them mot nut vao bang                       *");
	printf("\n* 2: Them ngau nhien nhieu nut vao bang bam      *");
	printf("\n* 3: Xoa toan bo bang bam                        *");
	printf("\n* 4: Duyet bang bam                              *");
	printf("\n* 5: Tim kiem tren bang bam                      *");
	printf("\n* 0: Ket thuc chuong trinh                       *");
	printf("\n**************************************************");
}
//===================================================================
// Hàm xử lý chính của chương trình
void Process()
{
	int b, Key, i, n, SelectFunction;
	char c;
	InitHashTable();
	do
	{
		ShowMenu();
		printf("\n Chuc nang ban chon: ");
		scanf("%d", &SelectFunction);
		switch (SelectFunction)
		{
		case 1:
			printf("\n Them mot nut vao trong bang bam");
			printf("\n Nhap gia tri khoa cua nut can them vao: ");
			scanf("%d", &Key);
			Insert(Key);
			break;
		case 2:
			printf("\n Them mot bang ngau nhien nhieu nut vao bang");
			printf("\n So nut ban muon them: ");
			scanf("%d", &n);
			srand(unsigned(time(NULL)));
			for (i = 0; i < n; i++)
			{
				Key = rand() % 200; // 1 số ngẫu nhiên thuộc [0, 99]
				Insert(Key);
			}
			break;
		case 3:
			InitHashTable();
			break;
		case 4:
			printf("\n Duyet Bang Bam");
			ViewTable();
			break;
		case 5:
			printf("\n Tim kiem mot khoa tren bang bam");
			printf("\n Khoa can tim: ");
			scanf("%d", &Key);
			b = Search(Key);
			if (b == -1)
				printf("\n Khong thay");
			else
				printf("\n Tim thay trong bucket %d", b);
			break;
		}
	} while (SelectFunction != 0);
}
//===================================================================
// Chương trình chính
void main()
{
	Process();
	getch();
}