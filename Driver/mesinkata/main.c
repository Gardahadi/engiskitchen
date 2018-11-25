#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	char c[100];
	scanf("%s",c);
	Kata K= StringToKata("Edelweiss\0");
	PrintKata(K);
	printf("\n");
}
