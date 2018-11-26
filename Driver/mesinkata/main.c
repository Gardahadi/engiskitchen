#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	char c[100];
	scanf("%s",c);
	Kata K= StringToKata("Edelweiss\0");
	PrintKata(K);
	Kata K2 = StringToKata("13567\0");
	int i = KataToInt(K2);
	printf("\n%s\n",KataToString(K2));
	printf("%d\n",i);
	printf("\n");
}
