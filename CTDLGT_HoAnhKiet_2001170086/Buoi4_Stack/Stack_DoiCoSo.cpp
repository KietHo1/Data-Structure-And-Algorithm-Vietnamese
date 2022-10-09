#include"Stack_DoiCoSo.h"
void ShowStackList(StackList sl){
	if (IsEmpty(sl) == 1)
		printf("\nStack rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (StackNode* p = sl.Top; p != NULL; p = p->Next){
		ShowStackNode(p);
		printf(" ");
	}
}
void ShowStackNode(StackNode* p){
	printf("%4d", p->Info);
}
void Stack_DoiCoSo(int n, int a){
	//Đổi n từ hệ 10 sang hệ a
	StackList st;
	InitStack(st);
	int tmp = n;
	ItemType x;
	while (tmp > 0){
		x = tmp % a; //Lay phan tu so du
		StackNode *p = CreateStackNode(x);
		ShowStackNode(p);
		Push(st, p); //Them nut p vao dau Stack st
		tmp = tmp / a; //Lay phan nguyen
	}
	printf("\nKet qua doi %d tu he 10 sang he %d la: ", n, a);
	while (Pop(st, x) == 1){
		switch (x)
		{
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		case 13:
			printf("D");
			break;
		case 14:
			printf("E");
			break;
		case 15:
			printf("F");
			break;
		default:
			printf("%d", x);
			break;
		}
	}
}
StackNode* CreateStackNode(ItemType x)
{
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("Không đủ bộ nhớ để cấp phát!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void InitStack(StackList &s)
{ //Initialize Stack
	s.Top = NULL;
}
int IsEmpty(StackList s) //Stack có rỗng hay không
{
	if (s.Top == NULL)
		return 1; //Nếu Stack rỗng
	else
		return 0; //Nếu Stack không rỗng
}
int Push(StackList &s, StackNode* p)
{
	if (p == NULL)
		return 0; //Không thực hiện được
	if (IsEmpty(s) == 1)
		s.Top = p;
	else
	{
		p->Next = s.Top;
		s.Top = p;
	}
	return 1; //Thực hiện thành công
}
int Pop(StackList &s, ItemType &x)
{
	if (IsEmpty(s) == 1) //Stack rỗng
		return 0; //Không thực hiện được
	StackNode* p = s.Top;
	s.Top = s.Top->Next;
	x = p->Info; //Lấy thông tin của nút ở đỉnh Stack
	delete p; //Hủy nút do p trỏ đến
	return 1; //Thực hiện thành công
}
int Top(StackList s, ItemType &x)
{
	if (IsEmpty(s) == 1) //Stack rỗng
		return 0; //Không thực hiện được
	x = s.Top->Info; //Lấy thông tin của nút ở đỉnh Stack
	return 1; //Thực hiện thành công
}