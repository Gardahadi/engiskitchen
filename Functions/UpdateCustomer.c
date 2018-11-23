#include "../restoran.h"
/*
File for procedure to Update Customer on Table
Cause they're impatient little brats
*/

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
            AddCustomerToQueue(&QCustomer, temp);
            *NewCustomer = true;
        }
    }
}
