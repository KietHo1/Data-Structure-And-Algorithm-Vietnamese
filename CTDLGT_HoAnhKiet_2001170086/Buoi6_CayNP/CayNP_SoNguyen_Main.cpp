#include"CayNP_SoNguyen.h"
void ShowMenu()
{
	printf("\n**********************************************");
	printf("\n*                   MENU                     *");
	printf("\n*--------------------------------------------*");
	printf("\n* 1. Tao cay NPTK tu mang                    *");
	printf("\n* 2. Duyet cay theo NLR                      *");
	printf("\n* 3. Tim kiem mot nut bat ky                 *");
	printf("\n* 4. Tinh chieu cao cua cay                  *");
	printf("\n* 5. Dem so nut la o muc k                   *");
	printf("\n* 0. Thoat chuong trinh                      *");
	printf("\n**********************************************");
}
//===========================================
void Process()
{
	int SelectFunction;
	BSTree bt;
	TNode *p;
	ItemType x;
	ItemType a[] = { 10, 8, 9, 5, 4, 17, 15, 16, 20, 11, 12, 13, 19, 7, 25, 6 };
	int n = 16;
	int k, high, count, sum, min, max;
	InitBSTree(bt);
	do
	{
		ShowMenu();
		printf("\nBan hay chon mot chuc nang (tu 0 -> 5): ");
		scanf("%d", &SelectFunction);
		switch (SelectFunction)
		{
		case 1:
			CreateBSTreeFromArray(bt, a, n);
			break;
		case 2:
			printf("\nXem noi dung cua cay bang phep duyệt NLR: ");
			NLR(bt.Root);
			break;
		case 3:
			printf("\nCho biet gia tri nut muon tim: ");
			scanf("%d", &x);
			p = FindTNode(bt.Root, x);
			if (p != NULL)
				printf("\nNut muon tim %d co trong cay.", x);
			else
				printf("\nNut muon tim %d khong co trong cay.", x);
			break;
		case 4:
			high = HighTree(bt.Root);
			printf("\nChieu cao cua cay la: %d", high);
			break;
		case 5:
			printf("\nCho biet cap muon dem noi dung nut la: ");
			scanf("%d", &k);
			count = CountTNodeIsLeafOfLevelK(bt.Root, k);
			printf("\nSo luong nut la muc %d la: %d", k, count);
			break;
		}
	} while (SelectFunction != 0);
}
//===========================================
void main()
{
	Process();
}