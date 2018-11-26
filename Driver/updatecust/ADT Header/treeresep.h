/*Author  : Lukas Kurnia Jonathan / 13517006*/
/* ADT Pohon resep makanan */
/* Implementasi dengan menggunakan pointer */

#ifndef TREE_RESEP
#define TREE_RESEP


/* Modul lain yang digunakan : */
#include "basetype.h"
#include "boolean.h"

#define Nil 0

/* *** Definisi Type Pohon Biner *** */
typedef RESEP resinfotype;
typedef struct tNode *addrNode;
typedef struct tNode
{
  resinfotype info;
  addrNode left;
  addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

/* ***Alokasi Memori untuk Tree Resep*** */
addrNode AlokNode(resinfotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen RESEP */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

/* *** Konstruktor RESEP *** */
BinTree Tree(resinfotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void AddDaunResep(BinTree *P, resinfotype X, resinfotype Y);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X */

BinTree BuildTreeResepRec(int n,resinfotype *TabResep, int *idx);
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/*Jika sebuah akar hanya mempunya satu buah daun, maka daun tersebut ada di sebelah kiri (IsUnerLeft)*/
/* Untuk tubes ini n= 23 untuk membuat resep dengan Balance (kecuali Spaghetti Bolognese).*/

BinTree BuildTreeResep(int n,resinfotype *TabResep, int *idx);
/* Di Akhir fungsi menambahkan resep ke 24 (Spaghetti Bolognese) menggunakan AddDaunResep*/

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

/* ***** Fungsi Pendukung ***** */
boolean SearchTree(BinTree P, resinfotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* ***** Menampilkan Tree resep ke Layar dalam bentuk 2 dimensi. ***** */
void PrintTreeResep(BinTree P, int h);
/* Pada dasarnya hanya memanggil prosedur PrintTreeResepRec */

void PrintTreeResepRec(BinTree P, int kedalaman,int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan bentuk Indentasi */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
#endif
