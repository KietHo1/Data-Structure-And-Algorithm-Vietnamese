#include"Stack_ThapHaNoi.h"
ItemType SaoChepStackNode(int SoDia, int Nguon, int Dich)
{
	ItemType temp;
	temp.SoDia = SoDia;
	temp.Nguon = Nguon;
	temp.Dich = Dich;
	return temp;
}
void Stack_HaNoiTower(int n, int A, int B, int C)
{
	int solan = 0;
	ItemType x, y;
	StackNode* p;
	StackList st;
	InitStack(st);
	y = SaoChepStackNode(n, A, C);
	p = CreateStackNode(y);
	Push(st, p);
	while (!IsEmpty(st))
	{
		Pop(st, x); //Biến x có 3 phan: {n, Nguon, Dich}
		if (x.SoDia == 1)
			printf("\nLan %2d: Chuyen tu cot %d den cot %d", ++solan, x.Nguon, x.Dich);
			/*printf("\nSo lan can chuyen dia la: %d", ++solan);*/
		else
		{
			int temp = 6 - (x.Nguon + x.Dich);
			y = SaoChepStackNode(x.SoDia - 1, temp, x.Dich);
			p = CreateStackNode(y);
			Push(st, p);
			y = SaoChepStackNode(1, x.Nguon, x.Dich);
			p = CreateStackNode(y);
			Push(st, p);
			y = SaoChepStackNode(x.SoDia - 1, x.Nguon, temp);
			p = CreateStackNode(y);
			Push(st, p);
		}
	}
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