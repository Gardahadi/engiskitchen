#include "../restoran.h"
/*
File for procedure to Update Customer on Table
Cause they're impatient little brats
*/
void AddCustomerToQueue(CUSTOMER C){
    /* Dictionary */
    CAddress i;
    if(IsEmptyCQ(QCustomer)){
        //empty case
        Head(QCustomer)=0;
        Tail(QCustomer)=0;
        (QCustomer).T[Head(QCustomer)] = C;
    } else if (!IsFullCQ(QCustomer)){
        //not full case
        //star customer insertion
        if(IsStar(C)){
            i = Tail(QCustomer);
            while((!IsStar((QCustomer).T[i]))&&(i>Head(QCustomer))){
                (QCustomer).T[i+1]=(QCustomer).T[i];
                i--;
            }//i is other star customer(s) or i=Head(QCustomer)
            if(i>Head(QCustomer)){
                //i is not head
                (QCustomer).T[i+1]=C;
            } else {
                if(IsStar(InfoHead(QCustomer))){
                    (QCustomer).T[i+1]=C;
                } else {
                    (QCustomer).T[i+1]=InfoHead(QCustomer);
                    InfoHead(QCustomer)=C;
                }
            }
            Tail(QCustomer)++;
            Neff(QCustomer)++;

        } else {
            //normal customer addition
            Tail(QCustomer)++;
            InfoTail(QCustomer) = C;
        }
    } //full queue case -> queue stay as previous
}

void UpdateQueue(){
    /* Kamus */
    CAddress i,j;
    if(!IsEmptyCQ(QCustomer)){
        i = Head(QCustomer);
        while(i<Tail(QCustomer)){
            if(Kesabaran((QCustomer).T[i])==1){
                //Hapus elemen dari queue, majukan seluruh elemen
                j = i;
                while(j<Tail(QCustomer)){
                    (QCustomer).T[j]=(QCustomer).T[j+1];
                    j++;
                }//j = Tail(Q)
                Tail(QCustomer)--;
                if(player().Life>0){
                    //Mengurangi nyawa
                    Message = "Nyawa berkurang";
                    player().Life--;
                }
            } else {
                Kesabaran((QCustomer).T[i])--;
                i++;
            }
        }//i = Tail(Q)
        //Pengolahan elemen terakhir
        
        if(Kesabaran((QCustomer).T[i])==1){
            if(Head(QCustomer)==Tail(QCustomer)){
                //kasus satu elemen -> create empty queue
                int N=MaxEl(QCustomer);
                DeAlokasi(&QCustomer);
                CreateEmptyCQ(&QCustomer,N);
            } else {
                Tail(QCustomer)--;
            }
            if(player().Life>0){
                //Mengurangi nyawa
                Message = "Nyawa berkurang";
                player().Life--;
            }
        }
        else {
            Kesabaran((QCustomer).T[i])--;
        }
    }
}


void UpdateCust(boolean *NewCustomer){
    //Update dilakukan per meja
    //Traversal dari room 1->3, meja 0->3
    int n_room, n_table;
    //Algoritma
    n_room=1;
    while(n_room<=3){
        n_table=0;
        while(n_table<4){
            if(Kesabaran(TableArray(n_room,n_table).C)>=0){
                if(Kesabaran(TableArray(n_room,n_table).C)==1){
                    if(player().Life>0){
                        player().Life--;
                    }
                    Kesabaran(TableArray(n_room,n_table).C) = UndefCustomer;
                    Jumlah(TableArray(n_room,n_table).C) = 0;
                    IsStar(TableArray(n_room,n_table).C) = false;
                    Makanan(TableArray(n_room,n_table).C).Nama = StringToKata("NoMakanan\0");
                    Makanan(TableArray(n_room,n_table).C).Harga = 0;
                    TableArray(n_room,n_table).IsFull = false;
                } else {
                    Kesabaran(TableArray(n_room,n_table).C)--;
                }
            }
            n_table++;
        }
        n_room++;
    }


    if(player().Life>0){
        CUSTOMER temp;
        int X = rand();
        X = X%10;
        temp = GenerateCustomer(X);
        if(Kesabaran(temp)==UndefCustomer){
            *NewCustomer = false;
        } else {
            //New customer is coming
            AddCustomerToQueue(temp);
            *NewCustomer = true;
        }
    }


}
