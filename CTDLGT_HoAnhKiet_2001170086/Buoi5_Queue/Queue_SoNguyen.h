#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef int ItemType;
struct QueueNode{
	ItemType Info;
	QueueNode* Next;
};

struct Queue{
	QueueNode* Head;
	QueueNode* Tail;
};

void initQueue(Queue &qu);
int IsEmpty(Queue qu);
QueueNode* CreateQueueNode(ItemType x);
void CreateAutoQueueList(Queue &qu);
void ShowQueueNode(QueueNode* p);
void ShowQueueList(Queue qu);
QueueNode* FindQueueNode(Queue qu, ItemType x);
int Insert(Queue &qu, QueueNode* p);
int Remove(Queue &qu, ItemType &x);
int DeleteSList(Queue &qu, ItemType X);
int Head(Queue qu, ItemType &x);
int Tail(Queue qu, ItemType &x);