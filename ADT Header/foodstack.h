/* File : bahanstack.h */
/* deklarasi Stack of Bahan yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef FSTACK_H
#define FSTACK_H

#include "boolean.h"
#include "basetype.h"
#define Nil 0
#define MaxEl 10
/* Nil adalah FSTACK dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */


typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype FSTACK dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	Bahan T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} FSTACK;
/* Definisi FSTACK S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai FSTACK T[1]..T[MaxEl] */
/* Jika S adalah FSTACK maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */



/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyFS (FSTACK *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah FSTACK S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri FSTACK kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyFS (FSTACK S);
/* Mengirim true jika FSTACK kosong: lihat definisi di atas */
boolean IsFullFS (FSTACK S);
/* Mengirim true jika tabel penampung nilai elemen FSTACK penuh */

/* ************ Menambahkan sebuah elemen ke FSTACK ************ */
void PushFS (FSTACK * S, infotype X);
/* Menambahkan X sebagai elemen FSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen FSTACK TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen FSTACK ************ */
void PopFS (FSTACK * S, infotype* X);
/* Menghapus X dari FSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
