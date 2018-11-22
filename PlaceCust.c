#include <stdio.h>
#include "restoran.h"
/*#include "basetype.h"
#include "customer.h"
#include "customer.c"
#include "basetype.h"*/

void DelQCustAfter(CQUEUE *Qc, CUSTOMER *C2, int i)
/* Menghapus costumer pada antrian. Costumer yang dihapus adalah costumer bernomor antrian i */
{
    int j;

    *C2 = (*Qc).T[i];
    j = Head(*Qc);
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

void Place(CQUEUE *Q, ROOM *R, PLAYER P){
    int i; //variabel penunjuk nomor meja
    boolean nearP; // bernilai True jika Meja berada didekat P
    int j,k; //variabel yang digunakan untuk mencari Costumer berjumlah 2 di QueueCostumer
    boolean foundCust2;
    CUSTOMER C2,CMasuk;       //C2 sebagai variabel customer dengan jumlah 2

    if (!IsEmptyCQ(*Q)){
        i=0;
        nearP = false;
        while ((!nearP) && (i<4)){
            if ((*R.TableArray[i].PosMeja.nRoom == P.Position.nRoom) && (*R.TableArray[i].IsFull == false)
                && ((((*R.TableArray[i].PosMeja.X)-2 == P.Position.X) && (*R.TableArray[i].PosMeja.Y == P.Position.Y))
                    || (((*R.TableArray[i].PosMeja.X)+2 == P.Position.X) && (*R.TableArray[i].PosMeja.Y == P.Position.Y))
                     || (((*R.TableArray[i].PosMeja.X)+1 == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)+1 == P.Position.Y))
                      || (((*R.TableArray[i].PosMeja.X)-1 == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)+1 == P.Position.Y))
                       || (((*R.TableArray[i].PosMeja.X)-1 == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)-1 == P.Position.Y))
                        || (((*R.TableArray[i].PosMeja.X)+1 == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)-1 == P.Position.Y))
                         || ((*R.TableArray[i].PosMeja.X == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)+1 == P.Position.Y))
                          || ((*R.TableArray[i].PosMeja.X == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)-1 == P.Position.Y))
                           || ((*R.TableArray[i].PosMeja.X == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)+2 == P.Position.Y))
                            || ((*R.TableArray[i].PosMeja.X == P.Position.X) && ((*R.TableArray[i].PosMeja.Y)-2 == P.Position.Y))  )  ){
                         nearP = true;
                         if (*R.TableArray[i].Kapasitas == 2){
                                // Akan dilakukan pengecekan apakah ada costumer yang berjumlah 2. jika ada, maka akan menjadi
                                // prioritas dan antrian akan digeser.
                                j = Head(*Q); //inisialisasi
                                foundCust2 = false; //inisialisasi
                                while ((j != Tail(*Q)) && (!foundCust2)) {
                                    if (((Q).T[j].Jumlah(C)) == 2){
                                        foundCust2=true;
                                    }else{
                                        j++;
                                    }
                                }
                                if (foundCust2){
                                    DelQCustAfter(Q, &C2, j);
                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)+1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)-1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    *R.TableArray[i].IsFull = true;


                                    if (IsStar(C2)){
                                        Kesabaran(C2) = //terdefinisi ulang untuk customer star
                                    } else{
                                        Kesabaran(C2) = //terdefinisi ulang unuk customer biasa
                                    }
                                    *R.TableArray[i].C = C2;
                                }

                            }
                         else if(*R.TableArray[i].Kapasitas == 4)
                            {
                                DeleteCustomerFromQueue(Q,&CMasuk); //apakah C sudah mewakili Costumer walau tidak diinisialisasikan di proram saya?
                                if (Jumlah(CMasuk) == 2)
                                {
                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)+1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)-1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    (*R.TableArray[i].IsFull = true);


                                    if (IsStar(CMasuk)){
                                        *R.TableArray[i].C.Kesabaran = //terdefinisi ulang
                                    } else{
                                        *R.TableArray[i].C.Kesabaran = //terdefinisi ulang
                                    }

                                    *R.TableArray[i].C = CMasuk;

                                }
                                else if (Jumlah(CMasuk) == 4)
                                {
                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)+1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X)-1, *R.TableArray[i].PosMeja.Y) = 'C');

                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X), (*R.TableArray[i].PosMeja.Y) +1) = 'C');

                                    (Elmt(R.RoomBoard, (*R.TableArray[i].PosMeja.X), (*R.TableArray[i].PosMeja.Y) -1) = 'C');

                                    (*R.TableArray[i].IsFull = true);

                                    if (IsStar(CMasuk)){
                                        Kesabaran(CMasuk) = //terdefinisi ulang. nah, nanti yg dilihat adalah kesabaran costume atau kesabaran meja?
                                    } else{
                                        Kesabaran(CMasuk) = //terdefinisi ulang. nah, nanti yg dilihat adalah kesabaran costume atau kesabaran meja?
                                    }
                                    *R.TableArray[i].C = CMasuk;
                                }
                            }
                }
                else{
                    i++;
                }

        }
    }
}
