#include<stdio.h>
#include<conio.h>
typedef int ItemType; //Định nghĩa kiểu dữ liệu của một phần tử
struct StackNode
{//Định nghĩa kiểu dữ liệu cho 1 nút của Stack là StackNode
	ItemType Info;
	StackNode* Next;
};
struct StackList
{//Định nghĩa kiểu dữ liệu cho Stack
	StackNode* Top;
};
void ShowStackList(StackList sl);
StackNode* CreateStackNode(ItemType x);
void InitStack(StackList &s);
int IsEmpty(StackList s);
int Push(StackList &s, StackNode* p);
int Pop(StackList &s, ItemType &x);
int Top(StackList s, ItemType &x);
void ShowStackNode(StackNode* p);
long int Stack_TinhGiaiThua(int n);