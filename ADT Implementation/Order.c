/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include <stdio.h>
#include "../ADT Header/Order.h"



/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabOrder, cara deklarasi dan akses: */
/* Deklarasi : T : TabOrder */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffOrd = 0
  Definisi elemen pertama : T.TOrd[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TOrd[i] dengan i=T.NeffOrd */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyOrder (TabOrder * T)
{
    NeffOrd(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtOrder (TabOrder T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return NeffOrd(T);
}
/* *** Selektor INDEKS *** */
IdxTypeOrder GetFirstIdxOrder (TabOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return 1;
}
IdxTypeOrder GetLastIdxOrder (TabOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return NeffOrd(T);
}
/* *** Test tabel kosong *** */
boolean IsEmptyOrder (TabOrder T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NeffOrd(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFullOrder (TabOrder T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return ((NeffOrd(T)) == 100);
}
