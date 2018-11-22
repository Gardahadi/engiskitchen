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
/*PROSEDUR UNTUK MELAKUKAN PENGOSONGAN SEMUA DATA PADA GAME*/
void CreateEmptyAll();


/*IMPLEMENTATION*/

void Load(int N){
    //Load file -> 1 if load from save
    //Load file -> 2 if load from default
    CreateEmptyAll();
    STARTKATA(N);
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
    //nRoom
    ADVKATA();
    RN = KataToInt(CKata);
    printf("RN : %d\n",RN);
    LoadHand();
}

void LoadHand(){
    BAHAN btemp;
    ADVKATA();
    //Number of bahan
    int N = KataToInt(CKata);
    int i=0;
    //BAHAN b;
    while(i<N){
        ADVKATA();
        btemp.Name = CKata;
        PushBS(&hand(),btemp);
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
    R.Time = KataToInt(CKata);
}

void LoadTray(){
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    //HARGA MAKANAN BELUM DIKETAHUI CARA PENENTUANNYA!!!!!!!!!!!!
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
    CUSTOMER Ctemp;
    ADVKATA();
    //Make queue
    CreateEmptyCQ(&QCustomer,KataToInt(CKata));
    //Isi Queue
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    while(i<N){
        ADVKATA();
        Kesabaran(Ctemp) = KataToInt(CKata);
        ADVKATA();
        Jumlah(Ctemp) = KataToInt(CKata);
        ADVKATA();
        Makanan(Ctemp).Nama = CKata();
        //Harga belum ada!!!!!!!!!!!!!!!!
        ADVKATA();
        if(KataToInt(CKata)==1){
           IsStar(Ctemp) = true;
        } else {
            IsStar(Ctemp) = false;
        }
        //Add to Queue
        AddCustomerToQueue(&QCustomer,Ctemp);
        i++;
    }
}

void LoadOrderArray(){
    int indeks;
    Orderan Orderan_temp;
    int nomor;
    //number of orders
    ADVKATA();
    int N = KataToInt(CKata);
    int i=1;
    while(i<=N){
        //Get index
        ADVKATA();
        indeks = KataToInt(CKata);
        ADVKATA();
        //Food name
        Orderan_temp.FOOD.Nama = CKata;
        //!!!!HARGA BELUM DITENTUKAN
        ADVKATA();
        Orderan_temp.NomorMeja = KataToInt(CKata);
        OrderResto[indeks] = Orderan_temp;
        i++;
    }
}

void LoadTable(){
    int N;
    TABLE table_temp;
    ADVKATA();
    N = KataToInt(CKata);
    printf("Number of meja = %d\n",N);
    int i=0;
    while(i<N){
        ADVKATA();
        table_temp.Nomor = KataToInt(CKata);
        ADVKATA();
        table_temp.Kapasitas = KataToInt(CKata);
        ADVKATA();
        Kesabaran(table_temp.C) = KataToInt(CKata);
        ADVKATA();
        Jumlah(table_temp.C) = KataToInt(CKata);
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

void CreateEmptyAll(){
    //Empty hand
    CreateEmptyBS(&(hand()));
    //Empty stack
    CreateEmptyFS(&tray());
    MakeEmptyOrder()


}
