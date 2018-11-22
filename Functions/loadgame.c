//Author : Nur Alam Hasabie 1317096
//File saveload.c
//Function to save and load data dari file eksternal

#include "../restoran.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNGSI DAN PROSEDUR IMPLEMENTASI****/
//Procedure untuk menyimpan data ke file eksternal
//Format file eksternal ada di readme
void Load ();
/**FUNGSI DAN PROSEDUR PEMBANTU**/
/*PENCACAHAN FUNGSI UNTUK MODULARITAS PROGRAM*/
void LoadNomorSimulasi();
void LoadTime();
void LoadDataPlayer();
void LoadHand();
void LoadDataRestoran();
void LoadTickTime();
void LoadTray();
void LoadCustomerQueue();
void LoadOrderArray();
void LoadTable();
void LoadResep();


/*IMPLEMENTATION*/

void Load(){
    STARTKATA(1);
    LoadNomorSimulasi();
    LoadTime();
    LoadDataPlayer();
    LoadDataRestoran();
}

void LoadNomorSimulasi(){
    printf("Nomor simulasi : %d\n",KataToInt(CKata));
}

void LoadTime(){
    ADVKATA();
    printf("Waktu : %d\n",KataToInt(CKata));
}

void LoadDataPlayer(){
    //Money
    ADVKATA();
    player().Money = KataToInt(CKata);
    printf("Uang Pemain : %ld \n",player().Money);
    //Life
    ADVKATA();
    player().Life = KataToInt(CKata);
    printf("Nyawa Pemain : %d  \n",player().Life);
    //Posisi
    //X
    ADVKATA();
    absis() = KataToInt(CKata);
    printf("absis Pemain : %d  \n",absis());
    //Y
    ADVKATA();
    ordinat() = KataToInt(CKata);
    printf("ordinat Pemain : %d  \n",ordinat());
    //nRoom
    ADVKATA();
    RN = KataToInt(CKata);
    printf("RN : %d\n",RN);
    LoadHand();
}

void LoadHand(){
    ADVKATA();
    //Number of bahan
    int N = KataToInt(CKata);
    int i=0;
    //BAHAN b;
    while(i<N){
        ADVKATA();
        printf("Bahan ke-%d : ",(i+1));
        PrintKata(CKata);
        printf("\n");
        i++;
    }//i=N, reading bahan selesai
}

void LoadDataRestoran(){
    LoadTickTime();
    LoadTray();
    LoadCustomerQueue();
    LoadOrderArray();
    LoadTable();
    LoadResep();
}

void LoadTickTime(){
    ADVKATA();
    printf("Waktu Tick : %d\n",KataToInt(CKata));
}

void LoadTray(){
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    while(i<N){
        ADVKATA();
        printf("Nama Makanan ke-%d :",(i+1));
        PrintKata(CKata);
        ADVKATA();
        printf(" Harga : %d\n",KataToInt(CKata));
        i++;
    }

}

void LoadCustomerQueue(){
    ADVKATA();
    printf("MaxEL of Queue : %d\n",KataToInt(CKata));
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    while(i<N){
        printf("Data Customer ke-%d : ",(i+1));
        ADVKATA();
        printf("Kesabaran(%d) ",KataToInt(CKata));
        ADVKATA();
        printf("Jumlah(%d) ",KataToInt(CKata));
        ADVKATA();
        PrintKata(CKata);
        ADVKATA();
        if(KataToInt(CKata)==1){
            printf(" IsStar");
        }
        printf("\n");
        i++;
    }
}

void LoadOrderArray(){
    int indeks;
    Kata K_makanan;
    int nomor;
    ADVKATA();
    printf("MaxEl Order : %d\n",KataToInt(CKata));
    ADVKATA();
    printf("Number of Orders : %d\n",KataToInt(CKata));
    int N = KataToInt(CKata);
    int i=0;
    while(i<N){
        ADVKATA();
        indeks = KataToInt(CKata);
        ADVKATA();
        K_makanan = CKata;
        ADVKATA();
        nomor = KataToInt(CKata);
        printf("Data order ke-%d : indeks = %d makanan = ",(i+1),indeks);
        PrintKata(K_makanan);
        printf(" nomor = %d\n",nomor);
        i++;
    }
}

void LoadTable(){
    int N;
    ADVKATA();
    N = KataToInt(CKata);
    printf("Number of meja = %d\n",N);
    int i=0;
    while(i<N){
        ADVKATA();
        printf("Kapasitas : %d |",KataToInt(CKata));
        ADVKATA();
        printf("Kesabaran : %d |",KataToInt(CKata));
        ADVKATA();
        printf("Jumlah orang : %d |",KataToInt(CKata));
        ADVKATA();
        PrintKata(CKata);
        ADVKATA();
        if(KataToInt(CKata)==1){
            printf("|IsStar");
        }
        ADVKATA();
        if(KataToInt(CKata)==1){
            printf("|IsFull");
        }
        ADVKATA();
        printf("| X = %d",KataToInt(CKata));
        ADVKATA();
        printf("| Y = %d",KataToInt(CKata));
        ADVKATA();
        printf("| n_room = %d\n",KataToInt(CKata));
        i++;
    }
}

void LoadResep(){
    int N,i;
    ADVKATA();
    N = KataToInt(CKata);
    printf("Ada %d resep : \n",N);
    i=0;
    while(i<N){
        ADVKATA();
        PrintKata(CKata);
        printf("\n");
        i++;
    }
}
