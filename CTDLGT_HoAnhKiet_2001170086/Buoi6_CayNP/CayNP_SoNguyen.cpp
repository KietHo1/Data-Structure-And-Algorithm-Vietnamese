#include"CayNP_SoNguyen.h"
TNode* CreateTNode(ItemType x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat nut moi!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
//============================================
void InitBSTree(BSTree &bt)
{ //Initialize BSTree
	bt.Root = NULL;
}
//============================================
int InsertTNode_Left(TNode* &T, TNode* p){
	if (!T || !p)
		return 0;
	if (T->Left) 
		return 0;
	T->Left = p;
	return 1;
}
//============================================
int InsertTNode_Right(TNode* &T, TNode* p){
	if (!T || !p)
		return 0;
	if (T->Right)
		return 0;
	T->Right = p;
	return 1;
}
//============================================
int InsertTNode(TNode* &root, TNode* p)
{//Ham chen 1 nut vao cay NPTK
	if (p == NULL)
		return 0; //Thêm không thành công
	if (root == NULL) //Cay dang rong
	{
		root = p;
		return 1; //Thêm thành công
	}
	if (!root->Left)
		InsertTNode_Left(root, p);
	else if (!root->Right)
		InsertTNode_Right(root, p);
	else
	{
		int rnd = rand() % 2;
		if (rnd == 0)
		{
			InsertTNode(root->Left, p);
		}
		else
		{
			InsertTNode(root->Right, p);
		}
	}
	return 1;
}
//============================================
void CreateBSTreeFromArray(BSTree &bt, ItemType a[], int na)
{//Ham tao cay NPTK tu mang a
	InitBSTree(bt);
	for (int i = 0; i < na; i++)
	{
		TNode* p = CreateTNode(a[i]);
		InsertTNode(bt.Root, p);
	}
}
//============================================
void ShowTNode(TNode* p)
{
	printf("%4d", p->Info);
}
//============================================
void NLR(TNode* root)
{//Ham duyet cay theo thu tu NLR
	if (root == NULL) return;
	ShowTNode(root);
	NLR(root->Left);
	NLR(root->Right);
}
//============================================
void LNR(TNode* root)
{
	if (root == NULL) return;
	LNR(root->Left);
	printf("%4d", root->Info);
	LNR(root->Right);
}
//============================================
void LRN(TNode* root)
{
	if (root == NULL) return;
	LRN(root->Left);
	LRN(root->Right);
	printf("%4d", root->Info);
}
//============================================
TNode* FindTNode(TNode* root, ItemType x)
{
	if (root == NULL) return NULL;
	if (root->Info == x) return root;
	else if (root->Info > x)
		return FindTNode(root->Left, x);
	else
		return FindTNode(root->Right, x);
}
//============================================
TNode* Findtnode(TNode* root, ItemType x)//Viet dang khong de quy
{
	TNode* p = root;
	while (p != NULL)
	{
		if (p->Info == x)
			return p;
		else if (p->Info > x)
			p = p->Left;
		else
			p = p->Right;
	}
	return NULL;
}
//============================================
int IsLeaf(TNode* T)
{ //Tra ve: 1 neu nut la, 0 neu nguoc lai
	if (T == NULL)
		return 0;
	if (T->Left != NULL || T->Right != NULL)
		return 0;
	return 1;
}
int DeleteTNodeLeft(TNode* T, ItemType &x)
{ //Nút con trái của T phải là nút lá
	if (T == NULL)
		return 0; //Xóa không thành công
	TNode* p = T->Left;
	if (p == NULL)
		return 0; //Xóa không thành công
	if (p->Left != NULL || p->Right != NULL) //p không phải nút lá
		return 0; //Xóa không thành công
	T->Left = NULL;
	x = p->Info; //Lấy thông tin của nút bị hủy
	delete p;
	return 1; //Xóa thành công
}
//============================================
int DeleteTNodeRight(TNode* T, ItemType &x)
{ //Nút con phải của T phải là nút lá
	if (T == NULL)
		return 0; //Xóa không thành công
	TNode* p = T->Right;
	if (p == NULL)
		return 0; //Xóa không thành công
	if (p->Left != NULL || p->Right != NULL) //p không phải nút lá
		return 0; //Xóa không thành công
	T->Right = NULL;
	x = p->Info; //Lấy thông tin của nút bị hủy
	delete p;
	return 1; //Xóa thành công
}
//===========================================
TNode* FindTNodeReplace(TNode* &p)
{//Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
	TNode* f = p;
	TNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q; //Lưu nút cha của q
		q = q->Left; //q qua bên trái
	}
	p->Info = q->Info; //Tìm được phần tử thế mạng cho p là q
	if (f == p) //Nếu cha của q là p
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q; //trả về nút q là nút thế mạng cho p
}
//===========================================
int DeleteTNodeX(TNode* &root, ItemType x)
{//Hàm xóa nút có giá trị là x
	if (root == NULL) //Khi cây rỗng
		return 0; //Xóa không thành công
	if (root->Info > x)
		return DeleteTNodeX(root->Left, x);
	else if (root->Info < x)
		return DeleteTNodeX(root->Right, x);
	else
	{ //root->Info = x, tìm nút thế mạng cho root
		TNode* p = root;
		if (root->Left == NULL) //khi cây con không có nhánh trái
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL) //khi cây con không có nhánh phải
		{
			root = root->Left;
			delete p;
		}
		else
		{//khi cây con có cả 2 nhánh, chọn min của nhánh phải để thế mạng
			TNode* q = FindTNodeReplace(p);
			delete q; //Xóa nút q là nút thế mạng cho p
		}
		return 1; //Xóa thành công
	}
}
//===========================================
void DeleteTree(TNode* &root)
{
	if (root == NULL) return;
	DeleteTree(root->Left); //đệ quy xóa cây con trái
	DeleteTree(root->Right);//đệ quy xóa cây con phải
	delete root; //hoặc có thể dùng lệnh DeleteTNode(root);
}
//===========================================
int CountTNode(TNode* root)
{ //Ham dem so nut hien co trong cay
	if (!root) return 0;
	int nl = CountTNode(root->Left); //đệ quy trái
	int nr = CountTNode(root->Right);//đệ quy phải
	return (1 + nl + nr);
}
//===========================================
int CountTNodeIsLeaf(TNode* root)
{ //Ham dem so nut la hien cua cay
	if (!root) return 0;
	if (!root->Left && !root->Right) return 1;
	int nl = CountTNodeIsLeaf(root->Left); //đệ quy trái
	int nr = CountTNodeIsLeaf(root->Right);//đệ quy phải
	return (nl + nr);
}
//===========================================
int CountTNodeIsNoLeaf(TNode* root)
{ //Hàm đếm số nút không phải là nút lá của cây
	if (!root) return 0;
	if (!root->Left && !root->Right) return 0;
	int nl = CountTNodeIsNoLeaf(root->Left); //đệ quy trái
	int nr = CountTNodeIsNoLeaf(root->Right);//đệ quy phải
	return (1 + nl + nr);
}
//===========================================
int CountTNodeMedium(TNode* root)
{ //Hàm đếm số nút không phải là nút lá của cây
	int count1 = CountTNode(root);
	if (count1 <= 2) return 0;
	int count2 = CountTNodeIsLeaf(root);
	return (count1 - count2 - 1);
}
//===========================================
int CountTNodeHaveTwoChild(TNode* root)
{ //Ham dem so nut co du 2 con
	if (!root) return 0;
	if (!root->Left || !root->Right) return 0;
	int nl = CountTNodeHaveTwoChild(root->Left); //đệ quy trái
	int nr = CountTNodeHaveTwoChild(root->Right);//đệ quy phải
	return (1 + nl + nr);
}
//===========================================
int CountTNodeHaveOneChild(TNode* root)
{ //Ham dem so nut chi co 1 con
	if (!root) return 0;
	int nl = CountTNodeHaveOneChild(root->Left); //đệ quy trái
	int nr = CountTNodeHaveOneChild(root->Right);//đệ quy phải
	if ((root->Left && !root->Right) || (!root->Left && root->Right))
		return (1 + nl + nr);
	return (nl + nr);
}
//===========================================
int CountTNodeHaveChildIsLeaf(TNode* root)
{ //Ham dem so nut co con la nut la
	if (!root) return 0;
	int nl = CountTNodeHaveChildIsLeaf(root->Left); //đệ quy trái
	int nr = CountTNodeHaveChildIsLeaf(root->Right);//đệ quy phải
	if (IsLeaf(root->Left) || IsLeaf(root->Right))
		return (1 + nl + nr);
	return (nl + nr);
}
//===========================================
int HighTree(TNode* root)
{ //Ham tinh chieu cao cua cay
	if (!root) return 0;
	int hl = HighTree(root->Left); //đệ quy trái
	int hr = HighTree(root->Right);//đệ quy phải
	if (hl > hr)
		return (1 + hl);
	else
		return (1 + hr);
}
//===========================================
int TNodeMax(TNode* root)
{ //Ham tim nut co gia tri lon nhat cua cay
	TNode* p = root;
	while (p->Right != NULL)
		p = p->Right;
	return (p->Info);
}
//===========================================
int SumTNode(TNode* root)
{ //Ham tinh tong gia tri cac nut hien co trong cay
	if (!root) return 0;
	int suml = SumTNode(root->Left); //đệ quy trái
	int sumr = SumTNode(root->Right);//đệ quy phải
	return (root->Info + suml + sumr);
}
//===========================================
void ShowTNodeOfLevelK(TNode *root, int k)
{
	if (!root) return;
	if (k == 0) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNodeOfLevelK(root->Left, k); //đệ quy trái
	ShowTNodeOfLevelK(root->Right, k);//đệ quy phải
}
//===========================================
void ShowTNodeIsLeafOfLevelK(TNode *root, int k)
{
	if (!root) return;
	if (k == 0 && !root->Left && !root->Right) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
	ShowTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
}
//===========================================
int CountTNodeOfLevelK(TNode* root, int k)
{
	if (!root) return 0;
	if (k == 0) //đến mức cần tìm
		return 1;
	k--; //Mức k giảm dần về 0
	int nl = CountTNodeOfLevelK(root->Left, k); //đệ quy trái
	int nr = CountTNodeOfLevelK(root->Right, k);//đệ quy phải
	return (nl + nr);
}
//===========================================
int CountTNodeIsLeafOfLevelK(TNode *root, int k)
{
	if (!root) return 0;
	if (k == 0 && !root->Left && !root->Right) //đến mức cần tìm
		return 1;
	k--; //Mức k giảm dần về 0
	int nl = CountTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
	int nr = CountTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
	return (nl + nr);
}
//===========================================
int SumTNodeIsLeafOfLevelK(TNode *root, int k)
{
	if (!root) return 0;
	if (k == 0 && !root->Left && !root->Right) //đến mức cần tìm
		return (root->Info);
	k--; //Mức k giảm dần về 0
	int suml = SumTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
	int sumr = SumTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
	return (suml + sumr);
}
//===========================================
int minDistance(TNode* root, ItemType x)
{
	if (!root)
		return -1;
	int min = root->Info;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		if (root->Info == x)
			return x;
		if (mindis > abs(x - root->Info))
		{
			min = root->Info;
			mindis = abs(x - min);
		}
		if (x > root->Info)
			root = root->Right;
		else
			root = root->Left;
	}
	return min;
}
//===========================================
int maxDistance(TNode* root, ItemType x)
{
	if (!root)
		return -1;
	TNode* minLeft = root;
	while (minLeft->Left != NULL) //Tìm nút trái nhất
		minLeft = minLeft->Left;
	TNode* maxRight = root;
	while (maxRight->Right != NULL) //Tìm nút phải nhất
		maxRight = maxRight->Right;
	int dis1 = abs(x - minLeft->Info);
	int dis2 = abs(x - maxRight->Info);
	if (dis1 > dis2)
		return minLeft->Info;
	else
		return maxRight->Info;
}
//===========================================