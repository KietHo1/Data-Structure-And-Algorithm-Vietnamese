#ifndef BangBam_SoNguyen_h
#define BangBam_SoNguyen_h
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
struct HashNode
{//Định nghĩa kiểu dữ liệu cho 1 nut của Bảng băm
	int Key;
	HashNode *Next;
};

//typedef HashNode *HashTable[MAXSIZE];
void InitHashTable();
void Insert(int k);
void Remove(int k);
void Clear();
void Traverse();
int Search(int k);
#endif