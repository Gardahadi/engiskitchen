#include "restoran.h"
#include <stdio.h>


ROOM ArrRoom[5];

void loadMap(){
    STARTKATA(0);
    int i,j,k;
    i = 1;
    while (i<=4){
        j=1;
        while(j<=12){
            k = 1;
            while(k<=CKata.Length){
                Elmt(ArrRoom[i].RoomBoard,j,k) = CKata.TabKata[k];
                k++;
            }
            j++;
        }
        NBrsEff(ArrRoom[i].RoomBoard) = 12;
        NKolEff(ArrRoom[i].RoomBoard) = 12;
        i++;
        ADVKATA();
    }
}


int main(){
    loadMap();
    int i;
    i=1;
    while (i<=4){
        TulisMATRIKS(ArrRoom[i].RoomBoard);
        printf("\n");
        i++;
    }
    return 0;
}