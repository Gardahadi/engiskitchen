//Author : Nur Alam Hasabie 1317096
//File saveload.c
//Function to save and load data dari file eksternal

#include "restoran.h"

/**FUNGSI DAN PROSEDUR IMPLEMENTASI****/

void Save (); 
//Procedure untuk menyimpan data ke file eksternal
//Format file eksternal ada di readme

void Load ();
//Procedure untuk mengambil data dari file eksternal
//Format file eksternal ada di readme

/**FUNGSI DAN PROSEDUR PEMBANTU**/


/*PENCACAHAN FUNGSI UNTUK MODULARITAS PROGRAM*/
void LoadTray();

void LoadCustomerQueue();

void LoadOrderArray();

/*IMPLEMENTATION*/

void Load(){
    STARTKATA(1);
    LoadNomorSimulasi();
    LoadTime();
    LoadDataPlayer();
    LoadDataRestoran();
}

void LoadNomorSimulasi(){
    int Nomor_simulasi = KataToInt(CKata);
}

void LoadTime(){
    ADVKATA();
    R.Time = KataToInt(CKata);
}

void LoadDataPlayer(){
    //Money
    ADVKATA();
    R.P.Money = KataToInt(CKata);
    //Life
    ADVKATA();
    R.P.Life = KataToInt(CKata);
    //Posisi
    //X
    ADVKATA();
    R.P.Position.x = KataToInt(CKata);
    //Y
    ADVKATA();
    R.P.Position.y = KataToInt(CKata);
    //nRoom
    ADVKATA();
    R.P.Position.nRoom = KataToInt(CKata);   
    LoadHand();
}

void LoadHand(){
    //EKstern player blm ada
    //Asumsi nama ekstern p
    PLAYER p;
    //Empty stack
    CreateEmptyBS(&(P.Hand));
    ADVKATA();
    //Number of bahan
    int N = KataToInt(CKata);
    int i=0;
    BAHAN b;
    while(i<N){
        ADVKATA();
        b.Name = CKata;
        PushBS(&(P.Hand),b);
        i++;
    } //i=N, reading bahan selesai
}

void LoadDataRestoran(){
    LoadTickTime();
    LoadTray();
    LoadCustomerQueue();
    LoadOrderArray();
    LoadTable();
}

void LoadTickTime(){
    ADVKATA();
    
}

void LoadTray(){



}

void LoadCustomerQueue(){

}

void LoadOrderArray(){


}

void LoadTable(){

}

int main(){
    Load()
    return 0;
}