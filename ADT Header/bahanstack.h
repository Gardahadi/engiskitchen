/* File : bahanstack.h */
/* deklarasi Stack of Bahan yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef bahanstack_H
#define bahanstack_H

#include "boolean.h"
#include "basetype.h"
#define Nil 0
#define MaxEl 10
/* Nil adalah BSTACK dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */


typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype BSTACK dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	BAHAN T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} BSTACK;
/* Definisi BSTACK S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai BSTACK T[1]..T[MaxEl] */
/* Jika S adalah BSTACK maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyBS (BSTACK *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah BSTACK S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri BSTACK kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyBS (BSTACK S);
/* Mengirim true jika BSTACK kosong: lihat definisi di atas */
boolean IsFullBS (BSTACK S);
/* Mengirim true jika tabel penampung nilai elemen BSTACK penuh */

/* ************ Menambahkan sebuah elemen ke BSTACK ************ */
void PushBS (BSTACK * S, BAHAN X);
/* Menambahkan X sebagai elemen BSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen BSTACK TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen BSTACK ************ */
void PopBS (BSTACK * S, BAHAN* X);
/* Menghapus X dari BSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
