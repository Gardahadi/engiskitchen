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
/* F.S. Membuat sebuah BSTACK S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri BSTACK kosong : TOP bernilai Nil */

  Top(*S) = Nil;
}




/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyBS (BSTACK S) {
/* Mengirim true jika BSTACK kosong: lihat definisi di atas */
  return (Top(S)==Nil);
}
boolean IsFullBS (BSTACK S)
/* Mengirim true jika tabel penampung nilai elemen BSTACK penuh */
{
  return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke BSTACK ************ */
void PushBS (BSTACK * S, infotype X)
/* Menambahkan X sebagai elemen BSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen BSTACK TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen BSTACK ************ */
void PopBS (BSTACK * S, infotype* X)
/* Menghapus X dari BSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X = InfoTop(*S);
  Top(*S)--;
}
