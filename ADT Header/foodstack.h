/* File : bahanstack.h */
/* deklarasi Stack of Bahan yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* fTop adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef FSTACK_H
#define FSTACK_H

#include "boolean.h"
#include "basetype.h"
#define Nil 0
#define MaxElFS 10
/* Nil adalah FSTACK dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef FOOD finfotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype FSTACK dengan ciri fTop : */
/* Versi I : dengan menyimpan tabel dan alamat fTop secara eksplisit*/
typedef struct {
	finfotype T[MaxElFS+1]; /* tabel penyimpan elemen */
	address fTOP;  /* alamat fTop: elemen puncak */
} FSTACK;
/* Definisi FSTACK S kosong : S.fTop = Nil */
/* Elemen yang dipakai menyimpan nilai FSTACK T[1]..T[MaxElFS] */
/* Jika S adalah FSTACK maka akses elemen : */
   /* S.T[(S.fTop)] untuk mengakses elemen fTop */
   /* S.fTop adalah alamat elemen fTop */

#define fTop(S) (S).fTOP
#define InfofTop(S) (S).T[(S).fTOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyFS (FSTACK *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah FSTACK S yang kosong berkapasitas MaxElFS */
/* jadi indeksnya antara 1.. MaxElFS+1 karena 0 tidak dipakai */
/* Ciri FSTACK kosong : fTop bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyFS (FSTACK S);
/* Mengirim true jika FSTACK kosong: lihat definisi di atas */
boolean IsFullFS (FSTACK S);
/* Mengirim true jika tabel penampung nilai elemen FSTACK penuh */

/* ************ Menambahkan sebuah elemen ke FSTACK ************ */
void PushFS (FSTACK * S, finfotype X);
/* Menambahkan X sebagai elemen FSTACK S. */
/* I.S. S mungkin kosong, tabel penampung elemen FSTACK TIDAK penuh */
/* F.S. X menjadi fTop yang baru,fTop bertambah 1 */

/* ************ Menghapus sebuah elemen FSTACK ************ */
void PopFS (FSTACK * S, finfotype* X);
/* Menghapus X dari FSTACK S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen fTop yang lama, fTop berkurang 1 */

#endif
