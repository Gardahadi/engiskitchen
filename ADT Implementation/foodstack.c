/* NIM : 13517144
   Nama : Gardahadi
   Desktripsi : Implementasi ADT FSTACK
   */


#include <stdio.h>
#include "foodstack.h"
#include "bahanstack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyFS (FSTACK *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah FSTACK S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri FSTACK kosong : TOP bernilai Nil */
  Top(*S) = Nil;
}




/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyFS (FSTACK S) {
/* Mengirim true jika FSTACK kosong: lihat definisi di atas */
  return (Top(S)==Nil);
}
boolean IsFullFS (FSTACK S)
/* Mengirim true jika tabel penampung nilai elemen FSTACK penuh */
{
  return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke FSTACK ************ */
void PushFS (FSTACK * S, infotype X)
/* Menambahkan X sebagai elemen FSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen FSTACK TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen FSTACK ************ */
void PopFS (FSTACK * S, infotype* X)
/* Menghapus X dari FSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X = InfoTop(*S);
  Top(*S)--;
}
