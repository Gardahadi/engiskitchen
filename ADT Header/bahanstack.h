/* File : bahanstack.h */
/* deklarasi Stack of Bahan yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* bTop adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef bahanstack_H
#define bahanstack_H

#include "boolean.h"
#include "basetype.h"

#define Nil 0
#define MaxElBS 100
/* Nil adalah BSTACK dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */


typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype BSTACK dengan ciri bTop : */
/* Versi I : dengan menyimpan tabel dan alamat bTop secara eksplisit*/
typedef struct {

	BAHAN T[MaxElBS+1]; /* tabel penyimpan elemen */
	address bTOP;  /* alamat bTop: elemen puncak */
} BSTACK;
/* Definisi BSTACK S kosong : S.bTop = Nil */
/* Elemen yang dipakai menyimpan nilai BSTACK T[1]..T[MaxELBS] */
/* Jika S adalah BSTACK maka akses elemen : */
   /* S.T[(S.bTop)] untuk mengakses elemen bTop */
   /* S.bTop adalah alamat elemen bTop */

/* Definisi akses dengan Selektor : Set dan Get */
#define bTop(S) (S).bTOP
#define InfobTop(S) (S).T[(S).bTOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyBS (BSTACK *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah BSTACK S yang kosong berkapasitas MaxELBS */
/* jadi indeksnya antara 1.. MaxELBS+1 karena 0 tidak dipakai */
/* Ciri BSTACK kosong : bTop bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyBS (BSTACK S);
/* Mengirim true jika BSTACK kosong: lihat definisi di atas */
boolean IsFullBS (BSTACK S);
/* Mengirim true jika tabel penampung nilai elemen BSTACK penuh */

/* ************ Menambahkan sebuah elemen ke BSTACK ************ */

void PushBS (BSTACK * S, BAHAN X);
void PushBS (BSTACK * S, BAHAN X);

/* Menambahkan X sebagai elemen BSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen BSTACK TIDAK penuh */
/* F.S. X menjadi bTop yang baru,bTop bertambah 1 */

/* ************ Menghapus sebuah elemen BSTACK ************ */

void PopBS (BSTACK * S, BAHAN* X);

void PopBS (BSTACK * S, BAHAN* X);

/* Menghapus X dari BSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen bTop yang lama, bTop berkurang 1 */


#endif
