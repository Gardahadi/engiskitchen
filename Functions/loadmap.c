#include "restoran.h"

void loadMap(){
    STARTKATA(0);
    int i,j,k;
    i = 1;
    while (i<=4){
        j=1;
        while(j<=12){
          k = 1;
            while(k<=12){
                Elmt(ArrRoom[i].RoomBoard,j,k) = CKata.TabKata[k];
                k++;
            }
            ADVKATA();
            j++;
        }
        NBrsEff(ArrRoom[i].RoomBoard) = 12;
        NKolEff(ArrRoom[i].RoomBoard) = 12;
        i++;
    }
}
