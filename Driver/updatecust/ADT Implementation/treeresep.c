/*Author  : Lukas Kurnia Jonathan / 13517006*/
/* ADT Pohon resep makanan */
/* Implementasi dengan menggunakan pointer */

#include <stdio.h>
#include "../ADT Header/treeresep.h"



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
/* Membuat Binary tree seimbang dengan  N buah simpul*/
{
  BinTree T;
  T = BuildTreeResepRec(n,TabResep,idx); /*Isi Tree hanya N resep*/
  AddDaunResep(&T,TabResep[21],TabResep[*idx]); /*Pemrosesan khusus pada resep ke-N+1*/
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

  PrintTreeResepRec(P,0,h); //memanggil prosedur treeresepRec

}

/*Untuk mengetahui kedalaman dibutuhkan parameter tambahan*/
void PrintTreeResepRec(BinTree P, int kedalaman,int h)
/*Prosedur tambahan untuk melakukan rekursi terhadap PrintTree
I.S : P terdefinisi, kedalaman terdefinisi, h adalah jarak dari bagian kiri Layar
F.S : melakukan rekursi hingga tree kosong*/
{
  if(!IsTreeEmpty(P))
  {
      for(int i =0; i< kedalaman*h;i++)
      {
        printf("-");
      }
      PrintKata(Akar(P).Name);
      printf("\n");
      PrintTreeResepRec(Left(P),kedalaman+1,h); //rekurens
      PrintTreeResepRec(Right(P),kedalaman+1,h); //rekurens
  }
}
