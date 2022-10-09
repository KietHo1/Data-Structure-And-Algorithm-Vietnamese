#include"Queue_SoNguyen.h"
void initQueue(Queue &qu){
	//Khoi tao danh sach rong
	qu.Head = NULL;
	qu.Tail = NULL;
}

int IsEmpty(Queue qu){
	if (qu.Head == NULL)
		return 1;
	else
		return 0;
}

QueueNode* CreateQueueNode(ItemType x){
	QueueNode* p = new QueueNode;
	if (p == NULL){
		printf("Khong the cap nhat nut moi!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void ShowQueueNode(QueueNode* p){
	printf("%4d", p->Info);
}

void CreateAutoQueueList(Queue &qu){
	int n, kq;
	do
	{
		printf("\nCho biet so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		ItemType x = (rand() % 99) + 1;
		QueueNode* p = CreateQueueNode(x);
		kq = Insert(qu, p);
		if (kq == 0)
			printf("\nKhong them duoc nut moi!");
	}
}

void ShowQueueList(Queue qu){
	if (IsEmpty(qu) == 1)
		printf("\nDanh sach rong!");
	printf("\nNoi dung cua danh sach la: ");
	for (QueueNode* p = qu.Head; p != NULL; p = p->Next)
		ShowQueueNode(p);
}

QueueNode* FindQueueNode(Queue qu, ItemType x){
	for (QueueNode* p = qu.Head; p != NULL; p = p->Next){
		if (p->Info == x)
			return p;
	}
	return NULL;
}

int Insert(Queue &qu, QueueNode* p){
	if (p == NULL)
		return 0;
	if (IsEmpty(qu) == 1){
		qu.Head = p;
	}
	else
		qu.Tail->Next = p;
	qu.Tail = p;
	return 1;
}

int Remove(Queue &qu, ItemType &x)
{
	if (IsEmpty(qu) == 1)
		return 0; //Khong thuc hien duoc
	QueueNode* p = qu.Head;
	qu.Head = qu.Head->Next;
	if (qu.Head == NULL)
		qu.Tail = NULL;
	x = p->Info; //Lay thong tin cua nut bi huy
	delete p; //Huy nut do p tro den
	return 1; //Thuc hien thanh cong
}

int DeleteSList(Queue &qu, ItemType X)
{
	if (IsEmpty(qu) == 1)
		return 0; //Khong thuc hien duoc
	while (qu.Head != NULL)
	{
		QueueNode* p = qu.Head;
		X = p->Info;
		printf("%4d", X);
		qu.Head = qu.Head->Next;
		delete p; //Hoac DeleteSNode(p);
	}
	qu.Tail = NULL;
	return 1; //Thuc hien thanh cong
}

int Head(Queue qu, ItemType &x){
	if (IsEmpty(qu) == 1)
		return 0;
	x = qu.Head->Info;
	return 1;
}

int Tail(Queue qu, ItemType &x){
	if (IsEmpty(qu) == 1)
		return 0;
	x = qu.Tail->Info;
	return 1;
}