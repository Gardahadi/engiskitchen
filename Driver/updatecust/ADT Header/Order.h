/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "basetype.h"
// /*  Kamus Umum */
// #define IdxMinOrder 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define int IdxTypeOrder

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

/* ********** SELEKTOR ********** */
#define NeffOrd(T)(T).NeffOrder
#define TOrd(T)   (T).TOrd
#define ElmtO(T,i) (T).TOrd[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyOrder (TabOrder * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtOrder (TabOrder T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Selektor INDEKS *** */
IdxTypeOrder GetFirstIdxOrder (TabOrder T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxTypeOrder GetLastIdxOrder (TabOrder T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyOrder (TabOrder T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullOrder (TabOrder T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
#endif
