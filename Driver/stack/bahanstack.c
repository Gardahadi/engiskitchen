/* NIM : 13517144
   Nama : Gardahadi
   Desktripsi : Implementasi ADT BSTACK
   */


#include <stdio.h>
#include "bahanstack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyBS (BSTACK *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah BSTACK S yang kosong berkapasitas MaxElBS */
/* jadi indeksnya antara 1.. MaxElBS+1 karena 0 tidak dipakai */
/* Ciri BSTACK kosong : bTop bernilai Nil */

  bTop(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyBS (BSTACK S) {
/* Mengirim true jika BSTACK kosong: lihat definisi di atas */
  return (bTop(S)==Nil);
}
boolean IsFullBS (BSTACK S)
/* Mengirim true jika tabel penampung nilai elemen BSTACK penuh */
{
  return (bTop(S) == MaxElBS);
}

/* ************ Menambahkan sebuah elemen ke BSTACK ************ */
void PushBS (BSTACK * S, BAHAN X)
/* Menambahkan X sebagai elemen BSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen BSTACK TIDAK penuh */
/* F.S. X menjadi bTop yang baru,bTop bertambah 1 */
{
    bTop(*S)++;
    InfobTop(*S) = X;
}
/* ************ Menghapus sebuah elemen BSTACK ************ */
void PopBS (BSTACK * S, BAHAN* X)
/* Menghapus X dari BSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen bTop yang lama, bTop berkurang 1 */
{
  *X = InfobTop(*S);
  bTop(*S)--;
}
