#include"BangBamKetNoiTT_SoNguyen.h"
HashNode* bucket[MAXSIZE];
//===================================================================
int HashFunction(int Key)
{
	return (Key % MAXSIZE);
}
//===================================================================
// Khoi tao bang bam
void InitHashTable()
{ //Initialize HashTable
	for (int b = 0; b < MAXSIZE; b++)
		bucket[b] = NULL;
}
//===================================================================
// Xoa mot nut trong bo nho
void DeleteHashNode(HashNode* p)
{
	delete p;
}
//===================================================================
// Kiem tra mot bucket co phai Empty?
int IsEmptyBucket(int b)
{
	if (bucket[b] == NULL)
		return TRUE;
	else
		return FALSE;
}
//===================================================================
// Kiem tra toan bo bang bam co NULL hay khong
int IsEmpty()
{
	for (int b = 0; b < MAXSIZE; b++)
	if (bucket[b] != NULL)
		return FALSE;
	return TRUE;
}
//===================================================================
// Traverse tren tung bucket
void TraverseBucket(int b)
{
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		printf("%4d", p->Key);
		p = p->Next;
	}
}
//===================================================================
// Duyet qua bang bam
void Traverse()
{
	for (int b = 0; b < MAXSIZE; b++)
	{
		printf("\n Bucket[%d]=", b);
		TraverseBucket(b);
	}
}
//===================================================================
// Xoa tren mot bucket
void ClearBucket(int b)
{
	HashNode* q = NULL;
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		q = p;
		p = p->Next;
		DeleteHashNode(q);
	}
	bucket[b] = NULL;
}
//===================================================================
// Xoa toan bo bang bam
void Clear()
{
	for (int b = 0; b < MAXSIZE; b++)
	{
		ClearBucket(b);
	}
}
//===================================================================
// Them mot nut vao dau bucket
void Push(int b, int x)
{
	HashNode* p = new HashNode;
	p->Key = x;
	p->Next = bucket[b];
	bucket[b] = p;
}
//===================================================================
// Xoa mot nut o dau bucket
int Pop(int b)
{
	if (IsEmptyBucket(b))
	{
		printf("Bucket %d bi rong, khong xoa duoc", b);
		return 0;
	}
	HashNode* p = bucket[b];
	int k = p->Key;
	bucket[b] = p->Next;
	DeleteHashNode(p);
	return k;
}
//===================================================================
// Tac vu them vao bucket mot nut moi sau nut p
int InsertAfter(HashNode* p, int k)
{
	if (p == NULL)
	{
		printf("Khong them vao HashNode moi duoc!");
		return 0; //Thực hiện không thành công
	}
	else
	{
		HashNode* q = new HashNode;
		q->Key = k;
		q->Next = p->Next;
		p->Next = q;
	}
	return 1; //Thực hiện thành công
}
//===================================================================
// Tac vu nay chi su dung khi them vao mot bucket co thu tu
void Place(int b, int k)
{
	HashNode *p, *q;
	q = NULL;
	for (p = bucket[b]; p != NULL && k > p->Key; p = p->Next)
		q = p;
	if (q == NULL)
		Push(b, k);
	else
		InsertAfter(q, k);
}
//===================================================================
// Them mot nut co khoa k vao trong bang bam
void Insert(int k)
{
	int b;
	b = HashFunction(k);
	Place(b, k);
}
//===================================================================
// Tac vu tim kiem mot khoa trong bang bam
int Search(int k)
{
	int b = HashFunction(k);
	HashNode* p = bucket[b];
	while (p != NULL && k > p->Key)
		p = p->Next;
	if (p == NULL || k != p->Key)
		return -1;
	else
		return b;
}
//===================================================================
// Xoa mot nut ngay sau nút p
int DeleteAfter(HashNode* p)
{
	HashNode* q;
	int k;
	if (p == NULL || p->Next == NULL)
	{
		printf("\n Khong xoa HashNode duoc");
		return 0;
	}
	q = p->Next;
	k = q->Key;
	p->Next = q->Next;
	DeleteHashNode(q);
	return k;
}
//===================================================================
// Xoa mot phan tu co khoa k ra khoi bang bam
void Remove(int k)
{
	int b;
	HashNode *p, *q;
	b = HashFunction(k);
	p = bucket[b];
	q = p;
	while (p != NULL && p->Key != k)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		printf("\n Khong co HashNode co khoa la: %d", b);
	else if (p == bucket[b])
		Pop(b);
	else
		DeleteAfter(q);
}
//===================================================================