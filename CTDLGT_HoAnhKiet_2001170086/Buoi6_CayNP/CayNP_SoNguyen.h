#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ItemType; //Định nghĩa kiểu dữ liệu của một phần tử
struct TNode
{//Định nghĩa kiểu dữ liệu cho 1 nút của cây nhị phân là TNode
	ItemType Info;
	TNode* Left;
	TNode* Right;
};
struct BSTree
{//Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
	TNode* Root;
};
TNode* CreateTNode(ItemType x);
void InitBSTree(BSTree &bt);
int InsertTNode(TNode* &root, TNode* p);
void CreateBSTreeFromArray(BSTree &bt, ItemType a[], int na);
void ShowTNode(TNode* p);
void NLR(TNode* root);
TNode* FindTNode(TNode* root, ItemType x);
TNode* Findtnode(TNode* root, ItemType x);
int HighTree(TNode* root);
int CountTNodeIsLeafOfLevelK(TNode *root, int k);
int InsertTNode_Left(TNode* &T, TNode* p);
int InsertTNode_Right(TNode* &T, TNode* p);