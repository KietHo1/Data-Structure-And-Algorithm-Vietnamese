#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FALSE 0
#define NULLKEY -1
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
struct HashNode
{//Định nghĩa kiểu dữ liệu cho 1 nút của Bảng băm
	int Key;
	int Next;
};
int HashFunction(int Key);
void InitHashTable();
int Insert(int k);
void Traverse();
int Search(int k);
int IsEmpty();
int GetEmpty();
void ViewTable();
//void Remove(int k);
//void Clear();