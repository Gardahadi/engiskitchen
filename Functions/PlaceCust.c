#include <stdio.h>
#include "../restoran.h"
/*#include "basetype.h"
#include "customer.h"
#include "customer.c"
#include "basetype.h"*/

void DelQCustAfter(CQUEUE *Qc, CUSTOMER *C2, int i)
/* Menghapus costumer pada antrian. Costumer yang dihapus adalah costumer bernomor antrian i */
{
    int j;

    *C2 = (*Qc).T[i];
    j = 0;
    while (j<i)
    {
        j++;
    }
    while(j<Tail(*Qc)){
                (*Qc).T[j]=(*Qc).T[j+1];
                j++;
    } //j=Tail(*Q)
      Tail(*Qc)--;
}

void Place(){
    int i; //variabel penunjuk nomor meja
    boolean nearP; // bernilai True jika Meja berada didekat P
    int j,k; //variabel yang digunakan untuk mencari Costumer berjumlah 2 di QueueCostumer
    boolean foundCust2;
    CUSTOMER C2,CMasuk;       //C2 sebagai variabel customer dengan jumlah 2

    if (!IsEmptyCQ(QCustomer)){
        i=0;
        nearP = false;
        while ((!nearP) && (i<4)){
            if ((TableArray(RN,i).IsFull == false)
                && ((((PosTableArray(RN,i).x)-2 == absis()) && (PosTableArray(RN,i).y == ordinat()))
                    || (((PosTableArray(RN,i).x)+2 == absis()) && (PosTableArray(RN,i).y == ordinat()))
                     || (((PosTableArray(RN,i).x)+1 == absis()) && ((PosTableArray(RN,i).y)+1 == ordinat()))
                      || (((PosTableArray(RN,i).x)-1 == absis()) && ((PosTableArray(RN,i).y)+1 == ordinat()))
                       || (((PosTableArray(RN,i).x)-1 == absis()) && ((PosTableArray(RN,i).y)-1 == ordinat()))
                        || (((PosTableArray(RN,i).x)+1 == absis()) && ((PosTableArray(RN,i).y)-1 == ordinat()))
                         || ((PosTableArray(RN,i).x == absis()) && ((PosTableArray(RN,i).y)+1 == ordinat()))
                          || ((PosTableArray(RN,i).x == absis()) && ((PosTableArray(RN,i).y)-1 == ordinat()))
                           || ((PosTableArray(RN,i).x == absis()) && ((PosTableArray(RN,i).y)+2 == ordinat()))
                            || ((PosTableArray(RN,i).x == absis()) && ((PosTableArray(RN,i).y)-2 == ordinat()))  )  ){
                         nearP = true;
                         if (TableArray(RN,i).Kapasitas == 2){
                                // Akan dilakukan pengecekan apakah ada costumer yang berjumlah 2. jika ada, maka akan menjadi
                                // prioritas dan antrian akan digeser.
                                j = 0; //inisialisasi
                                foundCust2 = false; //inisialisasi
                                while (j != Tail(QCustomer) && (!foundCust2)) {
                                    if (QCustomer.T[j].Jumlah == 2){
                                        foundCust2=true;
                                    }else{
                                        j++;
                                    }
                                }
                                if (foundCust2){

                                    DelQCustAfter(&QCustomer, &C2, j);
                                    Room(RN, PosTableArray(RN,i).y, PosTableArray(RN,i).x-1) = 'C';

                                    Room(RN, (PosTableArray(RN,i).y), PosTableArray(RN,i).x+1) = 'C';

                                    // printf(" %d | ",i+1);
                                    // printf(" %d |",j+1);
                                    // printf(" %d |",PosTableArray(RN,i).x);
                                    // printf(" %d |",PosTableArray(RN,i).y);
                                    // printf(" %c |",Room(RN, PosTableArray(RN,i).x+1, PosTableArray(RN,i).y));
                                    printf("\n");
                                    TableArray(RN,i).IsFull = true;


                                    if (IsStar(C2)){
                                         Kesabaran(C2) = 40;
                                     } else{
                                         Kesabaran(C2) = 50;
                                     }
                                    TableArray(RN,i).C = C2;
                                }

                            }
                         else if(TableArray(RN,i).Kapasitas == 4)
                            {
                                DeleteCustomerFromQueue(&QCustomer,&CMasuk); //apakah C sudah mewakili Costumer walau tidak diinisialisasikan di proram saya?
                                if (Jumlah(CMasuk) == 2)
                                {
                                    Room(RN, (PosTableArray(RN,i).y), PosTableArray(RN,i).x+1) = 'C';

                                    Room(RN, (PosTableArray(RN,i).y), PosTableArray(RN,i).x-1) = 'C';

                                    (TableArray(RN,i).IsFull = true);


                                     if (IsStar(CMasuk)){
                                         Kesabaran(CMasuk) = 40;
                                     } else{
                                         Kesabaran(CMasuk) = 50;
                                     }

                                    TableArray(RN,i).C = CMasuk;

                                }
                                else if (Jumlah(CMasuk) == 4)
                                {
                                    Room(RN, (PosTableArray(RN,i).y)+1, PosTableArray(RN,i).x) = 'C';

                                    Room(RN, (PosTableArray(RN,i).y)-1, PosTableArray(RN,i).x) = 'C';

                                    Room(RN, (PosTableArray(RN,i).y), (PosTableArray(RN,i).x) +1) = 'C';

                                    Room(RN, (PosTableArray(RN,i).y), (PosTableArray(RN,i).x) -1) = 'C';

                                    TableArray(RN,i).IsFull = true;

                                     if (IsStar(CMasuk)){
                                         Kesabaran(CMasuk) = 40;
                                     } else{
                                         Kesabaran(CMasuk) = 50;
                                     }
                                    TableArray(RN,i).C = CMasuk;
                                }
                            }
                }
                else{
                    i++;
                }

        }
    }
}

void DelCust(int i)
{
    if ((TableArray(RN, i).Kapasitas) == 4){
        Room(RN, (PosTableArray(RN,i).y)+1, PosTableArray(RN,i).x) = 'X';

        Room(RN, (PosTableArray(RN,i).y)-1, PosTableArray(RN,i).x) = 'X';

        Room(RN, (PosTableArray(RN,i).y), (PosTableArray(RN,i).x) +1) = 'X';

        Room(RN, (PosTableArray(RN,i).y), (PosTableArray(RN,i).x) -1) = 'X';
    }
    else{
              Room(RN, (PosTableArray(RN,i).y), PosTableArray(RN,i).x+1) = 'X';

              Room(RN, (PosTableArray(RN,i).y), PosTableArray(RN,i).x-1) = 'X';

    }
}
