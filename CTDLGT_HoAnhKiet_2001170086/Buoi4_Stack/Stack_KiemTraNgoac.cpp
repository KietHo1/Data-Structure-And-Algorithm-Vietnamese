#include"Stack_KiemTraNgoac.h"
int kiemTraDauNgoac(char strExp[]){
	StackList st;
	InitStack(st); //Lam cho stack rong
	ItemType x;
	int i = 0;
	while (strExp[i] != '\0'){
		if (strExp[i] == '(' || strExp[i] == '[' || strExp[i] == '{')
		{
			StackNode* p = CreateStackNode(strExp[i]);
			Push(st, p); //Them nut p vao dau Stack
		}
		else if (strExp[i] == ')' || strExp[i] == ']' || strExp[i] == '}')
		{
			if (Pop(st, x) == 0) return 0;
			if (strExp[i] == ')' && x != '(') return 0;
			else if (strExp[i] == ']' && x != '[') return 0;
			else if (strExp[i] == '}' && x != '{') return 0;
		}
		i++;
	}
	return 1; //Chi co mot truong hop duy nhat dung
}

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