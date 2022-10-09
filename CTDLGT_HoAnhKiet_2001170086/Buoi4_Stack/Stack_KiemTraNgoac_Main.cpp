#include"Stack_KiemTraNgoac.h"
void main(){
	//char strExp[] = "()(()){([()])}"; //Dung
	//char strExp[] = ")(())"; //Sai
	char strExp[] = "({[])}"; //Sai
	if (kiemTraDauNgoac(strExp) == 1)
		printf("Bieu thuc %s dung ngoac.", strExp);
	else
		printf("Bieu thuc %s sai ngoac.", strExp);
	getch();
}