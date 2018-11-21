#include <stdio.h>
#include "restoran.h"
#include "basetype.h"
#include "Order.h"

void AddOrder(TabOrder *To, ROOM *Ro, int j)
{
    if (IsEmptyOrder(*To)){
        Neff(*To) = 1;
    }
    else{
        Neff(*To) += 1;
    }
    *To.TOrd[NeffOrd(*To)].CustomerOrder = *Ro.TableArray[j].C;
    *To.TOrd[NeffOrd(*To)].NomorMeja = j;
}

void GetOrder(CQUEUE *Q, ROOM *Ro, PLAYER P, TabOrder *To)
{
    boolean nearP;
    int i;

    nearP = false;
        while ((!nearP) && (i<4)){
            if ((*R.TableArray[i].PosMeja.nRoom == P.Position.nRoom) && (*R.TableArray[i].IsFull == true)
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
                                AddOrder(TabOrder To, ROOM Ro,i);
                        }
                        else{
                            i++;
                        }
            }
}

void PrintOrder(TabOrder To)
{
    int i;

    i = 0;
    while (i < NeffOrder(To))
    {
        printf(To.TOrd[i].CustomerOrder.C.Makanan); //Gimana cara nulis nama makanan ke layar??? %c atau %s
    }
}
