//Author : Nur Alam Hasabie 1317096
//File saveload.c
//Function to save and load data dari file eksternal

#include "../restoran.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNGSI DAN PROSEDUR IMPLEMENTASI****/
//Procedure untuk menyimpan data ke file eksternal
//Format file eksternal ada di readme
void Load (int N);
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
void LoadKitchenSet();
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
    ////ERRRORRRO
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
    BAHAN btemp;
    ADVKATA();
    //Number of bahan
    int N = KataToInt(CKata);
    int i=0;
    printf("Jumlah di hand : %d\n",N);
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
    LoadKitchenSet();
}

void LoadTickTime(){
    ADVKATA();
    R.Tick = KataToInt(CKata);
    printf("Jumlah tick : %d\n", R.Tick);
}

void LoadTray(){
    FOOD food_temp;
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    printf("Jumlah di tray ada  %d \n",N);
    //HARGA MAKANAN BELUM DIKETAHUI CARA PENENTUANNYA!!!!!!!!!!!!
    //Aku isi 0 aja ya wkwkwk
    while(i<N){
        ADVKATA();
        food_temp.Nama = CKata;
        food_temp.Harga = 0;
        PushFS(&tray(),food_temp);
        i++;
    }

}

void LoadCustomerQueue(){
    CUSTOMER Ctemp;
    ADVKATA();
    //Make queue
    CreateEmptyCQ(&QCustomer,KataToInt(CKata));
    //Isi Queue
    printf("Maxel customer QUeue : %d\n",KataToInt(CKata) );
    ADVKATA();
    int N = KataToInt(CKata);
    int i=0;
    printf("Jumlah orang di queue : %d\n",N);
    while(i<N){
        ADVKATA();
        Kesabaran(Ctemp) = KataToInt(CKata);
        ADVKATA();
        Jumlah(Ctemp) = KataToInt(CKata);
        ADVKATA();
        Makanan(Ctemp).Nama = CKata;
        Makanan(Ctemp).Harga = 0;
        //Harga belum ada!!!!!!!!!!!!!!!!
        //Aku isi 0 lagi ya wkwkwk
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
    printf("Jumlah order di order array : %d\n",N );
    while(i<=N){
        //Get index
        ADVKATA();
        indeks = KataToInt(CKata);
        ADVKATA();
        //Food name
        Orderan_temp.CustomerOrder.Nama = CKata;
        //!!!!HARGA BELUM DITENTUKAN
        Orderan_temp.CustomerOrder.Harga = 0;
        //Aku isi 0 lagi ya wkwkwwk
        ADVKATA();
        Orderan_temp.NomorMeja = KataToInt(CKata);
        OrderResto[indeks] = Orderan_temp;
        i++;
    }
}

void LoadTable(){
    int N,n_room,nomor_room;
    TABLE table_temp;
    ADVKATA();
    //Banyaknya ruangan
    n_room = KataToInt(CKata);
    int i=0;
    int j=0;
    printf("Jumlah room ada : %d\n",N );
    while(i<n_room){
        ADVKATA();
        //Room berapa yang dibaca
        nomor_room = KataToInt(CKata);
        ADVKATA();
        //Berapa meja dalam room
        N = KataToInt(CKata);
        j=0;
        while(j<N){
            ADVKATA();
            table_temp.Nomor = KataToInt(CKata);
            ADVKATA();
            table_temp.Kapasitas = KataToInt(CKata);
            ADVKATA();
            Kesabaran(table_temp.C) = KataToInt(CKata);
            ADVKATA();
            Jumlah(table_temp.C) = KataToInt(CKata);
            ADVKATA();
            Makanan(table_temp.C).Nama = CKata;
            //HARGA 0 lagi ya wkwkwkk
            Makanan(table_temp.C).Harga = 0;
            ADVKATA();
            if(KataToInt(CKata)==1){
                IsStar(table_temp.C) = true;
            } else {
                IsStar(table_temp.C) = false;
            }
            ADVKATA();
            if(KataToInt(CKata)==1){
                table_temp.IsFull = true;
            } else {
                table_temp.IsFull = false;
            }
            ADVKATA();
            table_temp.PosMeja.x = KataToInt(CKata);
            ADVKATA();
            table_temp.PosMeja.y = KataToInt(CKata);
            table_temp.PosMeja.nRoom = nomor_room;
            ArrRoom[nomor_room].TableArray[j] = table_temp;
            j++;
        }
        i++;
    }
}

void LoadResep(){
    int N,i;
    RESEP temp;
    ADVKATA();
    N = KataToInt(CKata);
    printf("jumlah resep ada : %d\n",N);
    i=1;
    while(i<=N){
        ADVKATA();
        temp.Name = CKata;
        arrResep(i) = temp;
        i++;
    }
    i=1;
    pohonresep()= BuildTreeResep(23,Rs.TabResep,&i);


}


void LoadKitchenSet(){
    int N,i;
    KITCHENSET temp;
    ADVKATA();
    N = KataToInt(CKata);
    i=0;
    while(i<N){
        ADVKATA();
        temp.Name = CKata;
        ADVKATA();
        temp.Pos.x = KataToInt(CKata);
        ADVKATA();
        temp.Pos.y = KataToInt(CKata);
        temp.Pos.nRoom = 4;
        ArrRoom[4].KitchenArray[i] = temp;
        i++;
    }
}
void CreateEmptyAll(){
    //Empty hand
    CreateEmptyBS(&(hand()));
    //Empty stack
    CreateEmptyFS(&tray());
    MakeEmptyOrder(&R.TabOfOrder);
}
