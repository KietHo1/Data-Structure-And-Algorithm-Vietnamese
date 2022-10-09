#include"Stack_TinhGiaiThua.h"
void main(){
	int n;
	printf("Nhap so nguyen duong de tinh giai thua: ");
	scanf("%d", &n);
	long int giaithua = Stack_TinhGiaiThua(n);
	printf("Ket qua cua %d! la: %ld", n, giaithua);
	getch();
}