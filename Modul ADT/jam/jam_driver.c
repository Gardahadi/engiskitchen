/*
NIM/Nama  : 13517147/Rika Dewi
Nama file : P00_13517147_01a.c
Topik     : Review konsep dasar
Tanggal   : 9 September 2018
Deskripsi : Driver ADT Jam
*/

//Program DriverJam

#include "jam.h"
#include <stdio.h>

int main (){

	//KAMUS
    long n;
    JAM J,J1;
	//ALGORITMA
    BacaJAM(&J);
    TulisJAM(J);
	printf("\n");
    printf("%ld\n", JAMToDetik(J));
    scanf("%ld", &n);
    TulisJAM(DetikToJAM(n));
	printf("\n");
    BacaJAM(&J1);
    if (JEQ(J,J1)){printf("SAMA\n");}
    if (JNEQ(J,J1)){printf("BEDA\n");}
    if (JLT(J,J1)){printf("J1 besar\n");}else{printf("J besar\n");}
    if (JGT(J,J1)){printf("J besar\n");}else{printf("J1 besar\n");}
    TulisJAM(NextDetik(J));
    scanf("%ld", &n);
    TulisJAM(NextNDetik(J,n));
	printf("\n");
    TulisJAM(PrevDetik(J));
	printf("\n");
    scanf("%ld", &n);
    TulisJAM(PrevNDetik(J,n));
	printf("\n");
    printf("%ld\n", Durasi(J,J1));
	return 0;
}
