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
int KataToInt(Kata K) {
    //I.S. K terdefinisi
    //Output berupa konversi kata ke integer
    //Bila kata mengandung huruf maka mengembalikan 0 (error flag)
    //Kamus
    int i,angka;
    boolean negative, err_flag;
    //Algoritma
    i=1;
    angka=0;
    err_flag = false;
    if(K.TabKata[i]=='-'){
        negative_flag = true
        i++;
    } else {
        negative_flag = false;
    }
    while((i<=K.Length)&&(!err_flag)){
        case(K.TabKata[i]){
            '0':
                angka = angka*10+0;
                break;
            '1':
                angka = angka*10+1;
                break;
            '2':
                angka = angka*10+2;
                break;
           '3':
                angka = angka*10+3;
                break;
            '4':
                angka = angka*10+4;
                break;
            '5':
                angka = angka*10+5;
                break;
            '6':
                angka = angka*10+6;
                break;
            '7':
                angka = angka*10+7;
                break;
            '8':
                angka = angka*10+8;
                break;
            '9':
                angka = angka*10+9;
                break;
            default : 
                err_flag = true;
                break;
        }
        if(!err_flag){
            i++;
        }
    }//err_flag = true or i>Length
    if(err_flag){
        return 0;
    }
    if(negative_flag){
        angka = -angka;
    }
    return angka;
}

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
    LoadTime();
    LoadDataPlayer();
    LoadDataRestoran();
}