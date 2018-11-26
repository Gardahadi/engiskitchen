/*
NIM/Nama  : 13517147/Rika Dewi
Nama file : P00_13517147_01a.c
Topik     : Review konsep dasar
Tanggal   : 9 September 2018
Deskripsi : ADT Point
*/

//Program DriverPoint

#include <stdio.h>
#include "point.h"

int main (){

	//KAMUS
    POINT P, P1;
    float x,y;
	//ALGORITMA
    scanf("%f %f", &x, &y);
    P = MakePOINT(x,y);
	BacaPOINT (&P1);
    TulisPOINT(P);
    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    if (Equivalen(P,P1)){printf("SAMA\n");}
    if (NEquivalen(P,P1)){printf("BEDA\n");}
    if (IsOrigin(P)){printf("Origin\n");} else {printf("Not Origin\n");}
    if (IsOnSbX(P)){printf("X\n");} else {printf("Not X\n");}
    if (IsOnSbY(P)){printf("Y\n");} else {printf("Not Y\n");}
    printf("%d\n", Kuadran(P));
    TulisPOINT(NextX(P));
    printf("\n");
    TulisPOINT(NextY(P));
    printf("\n");
    scanf("%f %f", &x, &y);
    TulisPOINT(PlusDelta(P,x,y));
    printf("\n");
    TulisPOINT(MirrorOf(P, true));
    printf("\n");
    TulisPOINT(MirrorOf(P, false));
    printf("\n");
    printf("%f\n", Jarak0(P));
    printf("%f\n", Panjang(P,P1));
    scanf("%f %f", &x, &y);
    Geser (&P1, x, y);
    TulisPOINT(P1);
    printf("\n");
    GeserKeSbX(&P);
    TulisPOINT(P);
    printf("\n");
    GeserKeSbY(&P1);
    TulisPOINT(P1);
    printf("\n");
    BacaPOINT (&P);
	TulisPOINT(P);
	printf("\n");
    Mirror(&P, true);
    TulisPOINT(P);
    printf("\n");
    Mirror(&P, false);
    TulisPOINT(P);
    printf("\n");
    scanf("%f", &x);
    Putar(&P, x);
    TulisPOINT(P);
    printf("\n");

	return 0;
}
