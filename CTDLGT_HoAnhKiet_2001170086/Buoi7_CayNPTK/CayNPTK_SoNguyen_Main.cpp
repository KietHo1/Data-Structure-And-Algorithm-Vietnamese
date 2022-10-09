#include"CayNPTK_SoNguyen.h"
void ShowMenu()
{
	printf("\n************************************************************************");
	printf("\n*                                  MENU                                *");
	printf("\n*----------------------------------------------------------------------*");
	printf("\n* 1. Tao cay NPTK tu mang                                              *");
	printf("\n* 2. Duyet cay theo NLR                                                *");
	printf("\n* 3. Tim kiem mot nut bat ky                                           *");
	printf("\n* 4. Tinh chieu cao cua cay                                            *");
	printf("\n* 5. Dem so nut la o muc k                                             *");
	printf("\n* 6. Dem so nut hien co cua cay                                        *");
	printf("\n* 7. Dem so nut la hien co cua cay                                     *");
	printf("\n* 8. Tao cay NPTK tu file                                              *");
	printf("\n* 9. Dem so nut khong phai la nut la cua cay                           *");
	printf("\n* 10. Dem so nut co du 2 nut con cua cay                               *");
	printf("\n* 11. Dem so nut chi co 1 nut con cua cay                              *");
	printf("\n* 12. So nut co con la nut la cua cay                                  *");
	printf("\n* 13. Nut co gia tri lon nhat cua cay                                  *");
	printf("\n* 14. Tong gia tri cac nut hien co cua cay                             *");
	printf("\n* 15. Hien thi cac nut o muc k cua cay                                 *");
	printf("\n* 16. Hien thi cac nut la o muc k cua cay                              *");
	printf("\n* 17. So luong nut o muc k cua cay                                     *");
	printf("\n* 18. Tong cac nut la o muc k cua cay                                  *");
	printf("\n* 19. Nut co khoang cach ve gia tri gan nhat voi phan tu x trong cay   *");
	printf("\n* 20. Nut co khoang cach ve gia tri xa nhat voi phan tu x trong cay    *");
	printf("\n* 21. Xoa toan bo cay                                                  *");
	printf("\n* 22. Xoa nut co gia tri duoc nhap tu ban phim                         *");
	printf("\n* 0. Thoat chuong trinh                                                *");
	printf("\n************************************************************************");
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
		printf("\nBan hay chon mot chuc nang (tu 0 -> 22): ");
		scanf("%d", &SelectFunction);
		switch (SelectFunction)
		{
		case 1:
			CreateBSTreeFromArray(bt, a, n);
			break;
		case 2:
		{
				  int b = NLR(bt.Root);
				  if (b == 0)
					  printf("Cay rong!");
				  else
				  {
				  }
				  break; 
		}
			
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
		case 6:
			count = CountTNode(bt.Root);
			printf("\nSo luong nut hien co cua cay la: %d", count);
			break;
		case 7:
			count = CountTNodeIsLeaf(bt.Root);
			printf("\nSo luong nut la hien co cua cay la: %d", count);
			break;
		case 8:
			createBSTree_FromFile(bt, FILENAME);
			printf("\nNoi dung cua cay nhi phan: ");
			NLR(bt.Root);
			break;
		case 9:
			count = CountTNodeIsNoLeaf(bt.Root);
			printf("\nSo luong nut khong phai la nut la hien co cua cay la: %d", count);
			break;
		case 10:
			count = CountTNodeHaveTwoChild(bt.Root);
			printf("\nSo nut co du 2 nut con cua cay la: %d", count);
			break;
		case 11:
			count = CountTNodeHaveOneChild(bt.Root);
			printf("\nSo nut chi co 1 nut con cua cay la: %d", count);
			break;
		case 12:
			count = CountTNodeHaveChildIsLeaf(bt.Root);
			printf("\nSo nut co con la nut la cua cay la: %d", count);
			break;
		case 13:
			max = TNodeMax(bt.Root);
			printf("\nNut co gia tri lon nhat cua cay la: %d", max);
			break;
		case 14:
			sum = SumTNode(bt.Root);
			printf("\nTong gia tri cac nut hien co trong cay la: %d", sum);
			break;
		case 15:
			printf("\nNhap muc k cua cay can hien thi: ");
			scanf("%d", &k);
			ShowTNodeOfLevelK(bt.Root, k);
			break;
		case 16:
			printf("\nNhap muc k cua cay can hien thi: ");
			scanf("%d", &k);
			ShowTNodeIsLeafOfLevelK(bt.Root, k);
			break;
		case 17:
			printf("\nCho biet cap muon dem noi dung nut la: ");
			scanf("%d", &k);
			count = CountTNodeOfLevelK(bt.Root, k);
			printf("\nSo luong nut o muc %d la: %d", k, count);
			break;
		case 18:
			printf("\nCho biet cap muon tinh tong cac nut la: ");
			scanf("%d", &k);
			sum = SumTNodeIsLeafOfLevelK(bt.Root, k);
			printf("\nTong cac nut la o muc %d la: %d", k, sum);
			break;
		case 19:
			printf("\nNhap phan tu x trong cay: ");
			scanf("%d", &x);
			min = minDistance(bt.Root, x);
			p = FindTNode(bt.Root, x);
			if (min == -1 || p == NULL)
				printf("Khong thuc hien duoc!");
			else
				printf("\nNut co khoang cach ve gia tri gan nhat voi phan tu %d trong cay la: %d", x, min);
			break;
		case 20:
			printf("\nNhap phan tu x trong cay: ");
			scanf("%d", &x);
			max = maxDistance(bt.Root, x);
			p = FindTNode(bt.Root, x);
			if (max == -1 || p == NULL)
				printf("Khong thuc hien duoc!");
			else
				printf("\nNut co khoang cach ve gia tri xa nhat voi phan tu %d trong cay la: %d", x, max);
			break;
		case 21:
		{
				   int t = DeleteTree1(bt.Root, x);
				   if (t == 0)
					   printf("Xoa khong thanh cong!");
				   else
				   {
					   printf("\nXoa thanh cong!");
				   }
				   break;
		}
		case 22:
			printf("\nNhap gia tri nut can xoa: ");
			scanf("%d", &x);
			int t = DeleteTNodeX(bt.Root, x);
			if (t == 0)
				printf("Xoa khong thanh cong!");
			else
				printf("Xoa thanh cong!");
			break;
		}
	} while (SelectFunction != 0);
}
//===========================================
void main()
{
	Process();
}