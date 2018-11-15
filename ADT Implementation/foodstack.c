/* NIM : 13517144
   Nama : Gardahadi
   Desktripsi : Implementasi ADT FSTACK
   */


#include <stdio.h>
#include "../ADT Header/foodstack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyFS (FSTACK *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah FSTACK S yang kosong berkapasitas MaxElFS */
/* jadi indeksnya antara 1.. MaxElFS+1 karena 0 tidak dipakai */
/* Ciri FSTACK kosong : fTop bernilai Nil */
  fTop(*S) = Nil;
}




/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyFS (FSTACK S) {
/* Mengirim true jika FSTACK kosong: lihat definisi di atas */
  return (fTop(S)==Nil);
}
boolean IsFullFS (FSTACK S)
/* Mengirim true jika tabel penampung nilai elemen FSTACK penuh */
{
  return (fTop(S) == MaxElFS);
}

/* ************ Menambahkan sebuah elemen ke FSTACK ************ */
void PushFS (FSTACK * S, finfotype X)
/* Menambahkan X sebagai elemen FSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen FSTACK TIDAK penuh */
/* F.S. X menjadi fTop yang baru,fTop bertambah 1 */
{
    fTop(*S)++;
    InfofTop(*S) = X;
}
/* ************ Menghapus sebuah elemen FSTACK ************ */
void PopFS (FSTACK * S, finfotype* X)
/* Menghapus X dari FSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen fTop yang lama, fTop berkurang 1 */
{
  *X = InfofTop(*S);
  fTop(*S)--;
}
