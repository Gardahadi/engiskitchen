/*Author  : Lukas Kurnia Jonathan / 13517006*/
/* ADT Pohon resep makanan */
/* Implementasi dengan menggunakan pointer */

#include <stdio.h>
#include "../ADT Header/treeresep.h"

/*CATATAN BUAT YANG NGURUS FILE EKSTERNAL, Di bawah ini URUTAN PENULISAN file agar menjadi tree yang sesuai spek:
Misal disimpan dalam sebuah array of RESEP maka dimulai dari indeks ke-1 dengan rincian masing2 indeks sg berikut:
1 Piring
2 Sendok
3 Eskrim
4 Pisang
5 Banana Split
6 Stroberi
7 Sundae
8 Nasi
9 Telur
10 Nasi telur dadar
11 Ayam Goreng
12 Nasi Ayam Goreng
13 Garpu
14 Roti
15 Patty
16 Burger
17 Sosis
18 Hot Dog
19 Spaghetti
20 Bolognese
21 Keju
22 Carbonara
23 Spaghetti Carbonara
24 Spaghetti Bolognese
*/



/* ***Alokasi Memori untuk Tree Resep*** */
addrNode AlokNode(resinfotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen RESEP */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  addrNode P;

  P= (addrNode) malloc(sizeof(Node));
  if(P!=Nil)
  {
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
    return P;
  }
  else
  {return Nil;}
}

/* *** Konstruktor RESEP *** */
BinTree Tree(resinfotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree P = AlokNode(Akar);
  if(P!=Nil)
  {
    Right(P) = R;
    Left(P) = L;
    return P;
  }
  else
  {return Nil;}
}

void AddDaunResep(BinTree *P, resinfotype X, resinfotype Y)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X */
{
  if(IsTreeOneElmt(*P))
  {
      Left(*P) = Tree(Y,Nil,Nil);
  }
  else
  {
    if(SearchTree(Left(*P),X))
    {
      AddDaunResep(&Left(*P),X,Y);
    }
    else
    {
      AddDaunResep(&Right(*P),X,Y);
    }
  }
}

BinTree BuildTreeResepRec(int n,resinfotype *TabResep, int *idx)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/*Jika sebuah akar hanya mempunya satu buah daun, maka daun tersebut ada di sebelah kiri (IsUnerLeft)*/
/* Untuk tubes ini n= 23 untuk membuat resep dengan Balance (kecuali Spaghetti Bolognese).
 */
{
  addrNode P;
  resinfotype X;
  BinTree L,R;
  int nL,nR;
  // printf("rec\n");

  if(n==0)
  {
    return Nil;
  }
  else
  {
    /*Menggunakan sebuah tempat penyimpanan (tergantung load game simpan kemana),
     entah array atau stack atau sejenisnya, diasumsikan <TabResep> dulu..*/
    P = AlokNode(TabResep[*idx]);
    if(P!=Nil)
    {
      nL = n/2;
      nR = n-nL-1;
      (*idx)++;
      L = BuildTreeResepRec(nL,TabResep,idx);
      R = BuildTreeResepRec(nR,TabResep,idx);
      Left(P) = L;
      Right(P) = R;

      return P;
    }
  }
}

BinTree BuildTreeResep(int n,resinfotype *TabResep, int *idx)
/* Di Akhir fungsi menambahkan resep ke 24 (Spaghetti Bolognese) menggunakan AddDaunResep*/
{
  BinTree T;
  // printf("test");
  T = BuildTreeResepRec(n,TabResep,idx); /*Isi Tree hanya 23 resep, kurang 1*/
  AddDaunResep(&T,TabResep[21],TabResep[*idx]); /*Pemrosesan khusus pada resep ke-24*/
  return T;
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
  return P==Nil;
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
  if(!IsTreeEmpty(P))
  {
    return (Left(P)== Nil && Right(P)==Nil);
  }
  else
  {return false;}
}

/* ***** Fungsi Pendukung ***** */
boolean SearchTree(BinTree P, resinfotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
  if(IsTreeEmpty(P))
  {
    return false;
  }
  else
  {
    return (IsKataSama(Akar(P).Name,X.Name) || SearchTree(Left(P),X) || SearchTree(Right(P),X));
  }
}

/* ***** Menampilkan Tree resep ke Layar dalam bentuk 2 dimensi. ***** */
void PrintTreeResep(BinTree P, int h)
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
{

  PrintTreeResepRec(P,0,h);

}

/*Untuk mengetahui kedalaman dibutuhkan parameter tambahan*/
void PrintTreeResepRec(BinTree P, int kedalaman,int h)
{
  if(!IsTreeEmpty(P))
  {
      for(int i =0; i< kedalaman*h;i++)
      {
        printf("-");
      }
      PrintKata(Akar(P).Name);
      printf("\n");
      PrintTreeResepRec(Left(P),kedalaman+1,h);
      PrintTreeResepRec(Right(P),kedalaman+1,h);
  }
}
