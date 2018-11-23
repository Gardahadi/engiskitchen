#include <stdio.h>
#include <stdlib.h>
#include "../restoran.h"
#include "../Functions/PlaceCust.c"

int main(){
    MATRIKS M;
    int i,j;
    CUSTOMER C1,C2,C3,C4;
    CQUEUE Q;
    Kata Makanan1,Makanan2,Makanan3,Makanan4;
    PLAYER P;
    TABLE TableArray[2];
    char input;

    P.Pos.nRoom = 1;
    P.Pos.x = 2;
    P.Pos.y = 1;

    TableArray[0].IsFull = false;
    TableArray[0].Kapasitas = 4;
    TableArray[0].PosMeja.nRoom = 1;
    TableArray[0].PosMeja.x = 2;
    TableArray[0].PosMeja.y = 3;

    TableArray[1].IsFull = false;
    TableArray[1].Kapasitas = 2;
    TableArray[1].PosMeja.nRoom = 1;
    TableArray[1].PosMeja.x = 7;
    TableArray[1].PosMeja.y = 3;

    /* --------
       -X------
       X1X--X2X
       -X------
       --------
       --------
       --------
       -------- */


    Makanan1 = StringToKata("Burger\0");
    Makanan2 = StringToKata("Ayam\0");
    Makanan3 = StringToKata("Kupat\0");
    Makanan4 = StringToKata("Lontong\0");

    C1.IsStar = false;
    C1.Jumlah = 4;
    C1.Kesabaran = 20;
    C1.Makanan.Nama = Makanan1;
    C1.Makanan.Harga = 100;

    C2.IsStar = true;
    C2.Jumlah = 4;
    C2.Kesabaran = 10;
    C2.Makanan.Nama = Makanan2;
    C2.Makanan.Harga = 100;

    C3.IsStar = false;
    C3.Jumlah = 2;
    C3.Kesabaran = 25;
    C3.Makanan.Nama = Makanan3;
    C3.Makanan.Harga = 100;

    C4.IsStar = false;
    C4.Jumlah = 4;
    C4.Kesabaran = 30;
    C4.Makanan.Nama = Makanan4;
    C4.Makanan.Harga = 100;

    CreateEmptyCQ(&Q, 10);

    AddCustomerToQueue(&Q,C1);
    AddCustomerToQueue(&Q,C2);
    AddCustomerToQueue(&Q,C3);
    AddCustomerToQueue(&Q,C4);

    for (int k=0; k<Tail(Q); k++){
        print("d\n", Q.T[k].Jumlah);
    }

    MakeMATRIKS(8,8,&M);

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            M.Mem[i][j] = 'A';
        }
    }
    M.Mem[2][2] = 'X';
    M.Mem[1][3] = 'X';
    M.Mem[3][3] = 'X';
    M.Mem[2][4] = 'X';
    M.Mem[6][3] = 'X';
    M.Mem[8][3] = 'X';
    M.Mem[TableArray[0].PosMeja.x][TableArray[0].PosMeja.y] = '1';
    M.Mem[TableArray[1].PosMeja.x][TableArray[1].PosMeja.y] = '7';
    M.Mem[P.Pos.x][P.Pos.y] = 'P';

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c",M.Mem[i][j]);
        }
    }

    scanf("%c",&input);
    while(input != 'e'){
        if (input == 'p'){
            Place();
        }
        else if (input == 'o'){
            GetOrder();
        }
        else{
            printf("input tidak valid\n");
        }
        scanf("%c",&input);
    }
}
