#include"Stack_ThapHaNoi.h"
void main(){
	int a = 1;
	int b = 2;
	int c = 3;
	int n;
	printf("Nhap so dia: ");
	scanf("%d", &n);
	printf("Thu tu dich chuyen cac vi tri A B C la: \n");
	Stack_HaNoiTower(n, a, b, c);
	getch();
}