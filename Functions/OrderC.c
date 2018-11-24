#include <stdio.h>
#include "../restoran.h"

void AddOrder(int j)
{
    if (IsEmptyOrder(R.TabOfOrder)){
        NeffOrd(R.TabOfOrder) = 1;
        OrderResto[NeffOrd(R.TabOfOrder)].CustomerOrder = TableArray(RN,j).C.Makanan;
        OrderResto[NeffOrd(R.TabOfOrder)].NomorMeja = TableArray(RN,j).Nomor;
    }
    else{
        int i = 1;
        boolean SudahAda = false;
        while ((i <= NeffOrd(R.TabOfOrder) && (!SudahAda))){
            if (OrderResto[i].NomorMeja == (TableArray(RN,j).Nomor)){
                SudahAda = true;
            }
            else{
                i++;
            }
        }
        if (!SudahAda){
            NeffOrd(R.TabOfOrder) += 1;
            OrderResto[NeffOrd(R.TabOfOrder)].CustomerOrder = TableArray(RN,j).C.Makanan;
            OrderResto[NeffOrd(R.TabOfOrder)].NomorMeja = TableArray(RN,j).Nomor;
            
        }
    }
}

void DelOrderan (int i){
	/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
	/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
	/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
	/*          Kurangi elemen efektif tabel */
	int j;
	for (j = i; j < NeffOrd(R.TabOfOrder); j++) {
		OrderResto[j] = OrderResto[j];
	}
	NeffOrd(R.TabOfOrder);
}
void GetOrder()
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
