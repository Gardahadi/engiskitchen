#include "../restoran.h"
#include <stdio.h>
#include <stdlib.h>


//Global save variables
FILE* output_file;


void Save ();
/**FUNGSI DAN PROSEDUR PEMBANTU**/
/*PENCACAHAN FUNGSI UNTUK MODULARITAS PROGRAM*/
void SavePlayerName();
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
    SavePlayerName();
    SaveNomorSimulasi();
    SaveTime();
    SaveDataPlayer();
    SaveDataRestoran();
    fprintf(output_file,"\n."); //Mark
    fclose(output_file);
}

void SavePlayerName(){
    KataToFile(output_file,player().Name);
    PrintSpace(output_file);
}
void SaveNomorSimulasi(){
    fprintf(output_file,"%d\n",R.Simulasi);
}
void SaveTime(){
    // time_t seconds;
    // seconds = time(NULL);
    // seconds = seconds%86400;
    // fprintf(output_file,"%ld\n",seconds);

}

void SaveDataPlayer(){
    //Save money
    fprintf(output_file,"%ld\n",player().Money);
    //Save life
    fprintf(output_file,"%d\n",player().Life);
    //Save posisi
    fprintf(output_file,"%d %d %d\n",absis(),ordinat(),RN);
    //Save Hand
    SaveHand();
}

void SaveHand(){
    //Save number of bahan in stack
    //Save all bahan -> item in bottom of stack is written first
    int i=1;
    if(IsEmptyBS(hand())){
        fprintf(output_file,"%d\n",0);
    } else {
        fprintf(output_file,"%d\n",bTop(hand()));
        while(i<=bTop(hand())){
            KataToFile(output_file,hand().T[i].Name);
            PrintSpace(output_file);
            i++;
        }
        PrintNewline(output_file);
    }
}

void SaveDataRestoran(){
    //Save tick
    // SaveTickTime();
    //Save TRAY
    SaveTray();
    //Save customer Queue
    SaveCustomerQueue();
    //Save array of order
    SaveOrderArray();
    //Save table data
    SaveTable();
    //Save Resep
    SaveResep();
    //Save Kitchenset
    SaveKitchenSet();

}

void SaveTickTime(){
    fprintf(output_file,"%d\n",R.Tick);
}
void SaveTray(){
    if(IsEmptyFS(tray())){
        fprintf(output_file,"%d\n",0);
    } else {
        int i;
        fprintf(output_file,"%d\n",fTop(tray()));
        i=1;
        while(i<=fTop(tray())){
            KataToFile(output_file,tray().T[i].Nama);
            i++;
            PrintSpace(output_file);
        }
        PrintNewline(output_file);
    }
}

void SaveCustomerQueue(){
    //Kamus
    int i;
    //Algoritma
    if(IsEmptyCQ(QCustomer)){
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
    if(!IsEmptyCQ(QCustomer)){
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

void SaveOrderArray(){
    //Number of Neff
    fprintf(output_file,"%d\n",NbElmtOrder(R.TabOfOrder));
    int i=1;
    while(i<=NbElmtOrder(R.TabOfOrder)){
        fprintf(output_file,"%d ",i);
        KataToFile(output_file,OrderResto[i].CustomerOrder.Nama);
        PrintSpace(output_file);
        fprintf(output_file,"%d\n",OrderResto[i].NomorMeja);
        i++;
    }
}

void SaveTable(){
    //Num of room
    fprintf(output_file,"%d\n",3);
    //Per room
    int i=1;
    while(i<=3){
        //Number room
        fprintf(output_file,"%d %d\n",i,4);
        int j=0;
        //4 tables
        while(j<4){
            fprintf(output_file,"%d %d ",TableArray(i,j).Nomor,TableArray(i,j).Kapasitas);
            //Kesabaran dan Jumlah
            fprintf(output_file,"%d %d ",Kesabaran(TableArray(i,j).C),Jumlah(TableArray(i,j).C));
            KataToFile(output_file,Makanan(TableArray(i,j).C).Nama);
            PrintSpace(output_file);
            if(IsStar(TableArray(i,j).C)){
                fprintf(output_file,"%d ",1);
            } else {
                fprintf(output_file,"%d ",0);
            }

            if(TableArray(i,j).IsFull){
                fprintf(output_file,"%d ",1);
            } else {
                fprintf(output_file,"%d ",0);
            }

            fprintf(output_file,"%d %d\n",PosTableArray(i,j).x,PosTableArray(i,j).y);
            j++;
        }
        i++;
    }
}
void SaveResep(){
    int i;
    //Algoritma
    fprintf(output_file,"%d\n",24);
    i=0;
    while(i<=24){
        KataToFile(output_file,arrResep(i).Name);
        PrintNewline(output_file);
        i++;
    }
}
void SaveKitchenSet(){
    int i=0;
    //Print number of kitchen set
    fprintf(output_file,"%d\n",16);
    while(i<16){
        KataToFile(output_file,InfoKitchenArray(i));
        PrintSpace(output_file);
        fprintf(output_file,"%d %d\n",PosKitchenArray(i).x,PosKitchenArray(i).y);
        i++;
    }
}
