#include"Stack_DoiCoSo.h"
void main(){
	int n;
	printf("Nhap mot so duong bat ky: ");
	scanf("%d", &n);
	int a;
	printf("Nhap co so: ");
	scanf("%d", &a);
	Stack_DoiCoSo(n, a);
	getch();
}