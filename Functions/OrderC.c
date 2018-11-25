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

void DelOrderan (int i) {
	/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
	/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
	/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
	/*          Kurangi elemen efektif tabel */
	int j,k; //j merupakan iterator, k merupakan indeks ditemukan nomor meja i
  boolean found;
  k=1;
  found = false;



  while(!found){
    if(R.TabOfOrder.TOrd[k].NomorMeja == i){
      found = true;
    }
    else {
      k++;
    }
  }


	for (j = k; j < NeffOrd(R.TabOfOrder); j++) {
		OrderResto[j] = OrderResto[j+1];
	}
	NeffOrd(R.TabOfOrder)--;
}


void GetOrder()
{
    boolean nearP;
    int i;
    i=0;
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
                         Message="Anda baru saja meminta ORDER, Keren!";
                                AddOrder(i);
                        }
                        else{
                            i++;
                        }
            }
            if(!nearP){
              Message="Anda mau ngambil ORDER siapa? Tidak ada pelanggan disekitar";
            }
}
