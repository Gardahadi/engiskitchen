#include <stdio.h>
#include <stdlib.h>
#include "Order.h"
#include "basetype.h"
#include "mesinkata.h"

int main(){
    TabOrder T;
    int i;
    Kata Makanan1,Makanan2,Makanan3,Makanan4;

    MakeEmptyOrder(&T);
    printf("%d\n", NeffOrd(T));

    NeffOrd(T) = 4;
    Makanan1 = StringToKata("Burger\0");
    Makanan2 = StringToKata("Ayam\0");
    Makanan3 = StringToKata("Kupat\0");
    Makanan4 = StringToKata("Lontong\0");


    T.TOrd[1].CustomerOrder.Nama = Makanan1;
    T.TOrd[2].CustomerOrder.Nama = Makanan2;
    T.TOrd[3].CustomerOrder.Nama = Makanan3;
    T.TOrd[4].CustomerOrder.Nama = Makanan4;

    i = NbElmtOrder(T);
    printf("%d\n", i);

    printf("GetFirstIdxOrder = ");
    printf("%d\n", GetFirstIdxOrder(T));

    printf("Is Order Empty?\n");
    if (IsEmptyOrder(T)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    printf("\n");

    printf("Is Order Full?\n");
    if(IsFullOrder(T)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    printf("\n");

    return 0;
}
