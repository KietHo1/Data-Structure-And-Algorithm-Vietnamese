#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FILENAME "dsSoNguyen.txt"
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
int NLR(TNode* root);
TNode* FindTNode(TNode* root, ItemType x);
TNode* Findtnode(TNode* root, ItemType x);
int HighTree(TNode* root);
int CountTNodeIsLeafOfLevelK(TNode *root, int k);
int InsertTNode_Left(TNode* &T, TNode* p);
int InsertTNode_Right(TNode* &T, TNode* p);
int IsLeaf(TNode* T);
int CountTNode(TNode* root);
int CountTNodeIsLeaf(TNode* root);
void createBSTree_FromFile(BSTree &bst, char fileName[]);
int CountTNodeIsNoLeaf(TNode* root);
int CountTNodeHaveTwoChild(TNode* root);
int CountTNodeHaveOneChild(TNode* root);
int CountTNodeHaveChildIsLeaf(TNode* root);
int TNodeMax(TNode* root);
int SumTNode(TNode* root);
void ShowTNodeOfLevelK(TNode *root, int k);
void ShowTNodeIsLeafOfLevelK(TNode *root, int k);
int CountTNodeOfLevelK(TNode* root, int k);
int SumTNodeIsLeafOfLevelK(TNode *root, int k);
int minDistance(TNode* root, ItemType x);
int maxDistance(TNode* root, ItemType x);
int DeleteTree(TNode* &root);
int DeleteTNodeX(TNode* &root, ItemType x);
int DeleteTree1(TNode* &root, ItemType &X);