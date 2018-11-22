#include "restoran.h"
#include <stdio.h>

//Global save variables
FILE* output_file;


void Save ();
/**FUNGSI DAN PROSEDUR PEMBANTU**/
/*PENCACAHAN FUNGSI UNTUK MODULARITAS PROGRAM*/
void SaveNomorSimulasi();
void SaveTime();
void SaveDataPlayer();
void SaveHand();
void SaveDataRestoran();
void SaveTickTime();
void SaveTray();
void SaveCustomerQueue();
void SaveOrderArray();
void SaveTable();
void SaveResep();
void SaveKitchenSet();


void Save(){
    //Start file output interaction
    //Save nomor simulasi
    output_file = fopen("save.txt","w");
    SaveNomorSimulasi();
    SaveTime();
    SaveDataPlayer();
    SaveRestoran();
    fclose(output_file);
}
void SaveNomorSimulasi(){
    //Nomor simulasi belum ADAAAAAA !
    fprintf(output_file,"%d\n",Nomor_simulasi);
}
void SaveTime(){
    fprintf(output_file,"%d\n",Waktu);
}

void SaveDataPlayer(){
    //Save money
    fprintf(output_file,"%d\n",player().Money);
    //Save life
    fprintf(output_file,"%d\n",player().Life);
    //Save posisi
    fprintf(output_file,"%d %d %d\n",absis(),ordinat(),Rn);
    //Save Hand
    SaveHand();
}

void SaveHand(){
    //Save number of bahan in stack
    //Save all bahan -> item in bottom of stack is written first
    int i=1;
    while(i<=bTop(hand())){
        j=1;
        while(j<=hand().T[i].Nama.Length){
            fprintf(output_file,"%c",hand().T[i].Nama.TabKata[j]);
            j++;
        }
        fprintf(output_file," ");
        i++;
    }
}

void SaveRestoran(){
    //Save tick
    //Save TRAY
    SaveTray();
    //Save customer Queue
    SaveCustomerQueue();
    //Save array of order
    SaveOrder();
    //Save table data
    SaveTable();

}

void SaveResep(){

}

void SaveTray(){

}

void SaveCustomerQueue(){

}

void SaveOrder(){

}

void SaveTable(){

}

