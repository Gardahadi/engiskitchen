#include <stdio.h>
#include "restoran.h"

void AddOrder(int j)
{
    if (IsEmptyOrder(R.TabOfOrder)){
        NeffOrd(R.TabOfOrder) = 1;
    }
    else{
        NeffOrd(R.TabOfOrder) += 1;
    }
    OrderResto[NeffOrd(R.TabOfOrder)].CustomerOrder = TableArray(RN,j).C.Makanan;
    OrderResto[NeffOrd(R.TabOfOrder)].NomorMeja = j;
}

void GetOrder(CQUEUE *Q, TabOrder *To)
{
    boolean nearP;
    int i;

    nearP = false;
        while ((!nearP) && (i<4)){
            if ((TableArray(RN,i).IsFull == true)
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
                                AddOrder(i);
                        }
                        else{
                            i++;
                        }
            }
}

// void PrintOrder(TabOrder To)
// {
//     int i;
//
//     i = 0;
//     while (i < NeffOrder(To))
//     {
//         printf(To.TOrd[i].CustomerOrder.C.Makanan); //Gimana cara nulis nama makanan ke layar??? %c atau %s
//     }
// }
