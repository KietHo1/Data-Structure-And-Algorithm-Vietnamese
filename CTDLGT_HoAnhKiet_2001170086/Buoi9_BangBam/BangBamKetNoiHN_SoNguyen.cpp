#include"BangBamKetNoiHN_SoNguyen.h"
HashNode HashTable[MAXSIZE];
int avail;
int HashFunction(int Key)
{
	return (Key % MAXSIZE);
}
void InitHashTable()
{ //Initialize HashTable
	for (int i = 0; i < MAXSIZE; i++)
	{
		HashTable[i].Key = NULLKEY;
		HashTable[i].Next = -1;
	}
	avail = MAXSIZE - 1;
}
// Kiem tra bang bam co rong hay khong?
int IsEmpty()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (HashTable[i].Key != NULLKEY)
			return FALSE;
	}
	return TRUE;
}
// Tim mot khoa co trong bang bam hay khong, tim thay tra ve dia chi
// khong thay tra ve MAXSIZE
int Search(int k)
{
	int i = HashFunction(k);
	while (k != HashTable[i].Key && i != -1)
		i = HashTable[i].Next;
	if (k == HashTable[i].Key)
		return i;
	else
		return MAXSIZE;
}
// Chon nut con trong phia duoi bang hash de cap nhat khi xay ra xung dot
int GetEmpty()
{
	while (HashTable[avail].Key != NULLKEY)
		avail--;
	return avail;
}
// Them mot nut co khoa k vao bang bam
int Insert(int k)
{
	int i, j;
	i = Search(k);
	if (i != MAXSIZE)
	{
		printf("\n khoa %d bi trung, khong them vao duoc", k);
		return i; //Thực hiện không thành công
	}
	i = HashFunction(k);
	while (HashTable[i].Next >= 0)
		i = HashTable[i].Next;
	if (HashTable[i].Key == NULLKEY)
		j = i; //khong co su dung do, first time
	else
	{
		j = GetEmpty();
		if (j < 0)
		{
			printf("\n Bang bam bi day khong them vao duoc");
			return j; //Thực hiện không thành công
		}
		else
			HashTable[i].Next = j;
	}
	HashTable[j].Key = k;
	return j; //Thực hiện thành công
}
// Xem chi tiet thong tin bang bam
void ViewTable()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("\n table[%2d]: %4d %4d", i, HashTable[i].Key,
			HashTable[i].Next);
	}
}
////===================================================================
//// Xoa tren mot bucket
//void ClearBucket(int i)
//{
//	HashNode q;
//	HashNode p = HashTable[i];
//	while (p.Next != -1)
//	{
//		q.Key = p.Key;
//		q = p;
//		DeleteHashNode(q);
//	}
//	HashTable[b] = NULL;
//}
////===================================================================
//// Xoa toan bo bang bam
//void Clear()
//{
//	for (int b = 0; b < MAXSIZE; b++)
//	{
//		ClearBucket(b);
//	}
//}
////===================================================================
//// Xoa mot nut trong bo nho
//void DeleteHashNode(HashNode* p)
//{
//	delete p;
//}