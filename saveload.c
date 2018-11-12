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

void LoadTime();
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
void LoadHand();

void LoadDataRestoran(){
    //Time tick load
    ADVKATA();
    R.Time = KataToInt(CKata);
    LoadTray();
    LoadCustomerQueue();
    LoadOrderArray();


}

void LoadTray();

void LoadCustomerQueue();

void LoadOrderArray();



/*IMPLEMENTATION*/

void Load(){
    STARTKATA();
    LoadMap();
    LoadTime();
    LoadDataPlayer();
    LoadDataRestoran();
}