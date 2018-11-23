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
    fprintf(output_file"\n."); //Mark
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
        KataToFile(output_file,hand().T[i].Nama);
        PrintSpace(output_file);
        i++;
    }
    PrintNewline(output_file);
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
    //Save Resep
    SaveResep();
    //Save Kitchenset
    SaveKitchenSet();

}
void SaveTray(){

}

void SaveCustomerQueue(){
    //Kamus
    int i;
    //Algoritma
    if(IsEmpty(CQ)){
        i=0;
    } else {
        i=Head(QCustomer);
        while(i<=Tail(QCustomer)){
            i++;
        }//i>Tail(QCustomer)
    }
        //MaxEl
    fprintf(output_file,"%d\n",MaxEl(QCustomer));
    fprintf(output_file,"%d\n",i);
    if(!IsEmpty(CQ)){
        i=Head(QCustomer);
        while(i<=Tail(QCustomer)){
            fprintf(output_file,"%d %d ",Kesabaran(QCustomer.T[i]),Jumlah(QCustomer.T[i]));
            KataToFile(output_file, Makanan(QCustomer.T[i]).Nama);
            PrintSpace(output_file);
            if(IsStar(QCustomer.T[i])){
                fprintf(output_file,"%d\n",1);
            } else {
                //not star
                fprintf(output_file,"%d\n",0);
            }
            i++;
        }
    }
}

void SaveOrder(){

}

void SaveTable(){

}
void SaveResep(){
    int i;
    //Algoritma
    fprintf(output_file,"%d\n",24);
    i=0;
    while(i<=24){
        KataToFile(output_file,arrResep(i).Nama);
        PrintNewline(output_file);
        i++;
    }
}
void SaveKitchenSet(){
    i=0;
    //Print number of kitchen set
    fprintf(output_file,"%d\n",16);
    while(i<16){
        KataToFile(output_file,InfoKitchenArray(i));
        PrintNewline(output_file);
        i++;
    }
}


