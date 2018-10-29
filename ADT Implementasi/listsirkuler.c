
#include <stdlib.h>
#include <stdio.h>
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
  //KAMUS

  //ALGORITMA
  return ( First(L) == Nil );
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang       */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
  //KAMUS

  //ALGORITMA
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  //KAMUS
  address P;

  //ALGORITMA
  P = (address)malloc(1*sizeof(ElmtList));
  if ( P != Nil )
  {
    Info(P) = X;
    Next(P) = Nil;
    return P;
  }
  else
  {
    return P;
  }
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  //KAMUS

  //ALGORITMA
  free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  //KAMUS
  address P;

  //ALGORITMA
  P = First(L);
  if (Info(P)==X)
 {
   return P;
 }
      else
  {
    P = Next(P);
    while(P!=First(L))
    {
      if (Info(P)==X)
      {
        return P;
      }
   P = Next(P);
     }
  }
      return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  //KAMUS
  address P,P1;

  //ALGORITMA
  P = Alokasi(X);

  if ( P != Nil )
  {
    if ( IsEmpty(*L) )
    {
      First(*L) = P;
      Next(P) = First(*L);
    }
    else
    {
      P1 = First(*L);
      Next(P) = First(*L);
      while ( Next(P1) != First(*L) )
      {
        P1 = Next(P1);
      }
      First(*L) = P;
      Next(P1) = First(*L);
    }
  }

}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  //KAMUS
  address P , P1;

  //ALGORITMA
  P = Alokasi(X);
  P1 = First(*L);

  if ( P != Nil )
  {
    if ( P1 != Nil )
    {
      while ( Next(P1) != First(*L) )
      {
        P1 = Next(P1);
      }
      Next(P) = First(*L);
      Next(P1)= P;
    }
    else
    {
      InsVFirst(L,X);
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  //KAMUS
  address P,Piter;

  //ALGORITMA
  P = First(*L);
  Piter = First(*L);

  *X = Info(P);

  if ( Next(Piter) == First(*L) )
  {
    First(*L) = Nil;
  }
  else
  {
    while ( Next(Piter) != First(*L) )
    {
      Piter = Next(Piter);
    }

    First(*L) = Next(P);
    Next(Piter) = First(*L);
  }

  Dealokasi(P);

}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  //KAMUS
  address Piter,P1;

  //ALGORITMA
  Piter = First(*L);
  P1 = Nil;

  while ( Next(Piter) != First(*L) )
  {
    P1 = Piter;
    Piter = Next(Piter);
  }
  *X = Info(Piter);
  if ( P1 == Nil )
  {
    First(*L) = Nil;
  }
  else
  {
    Next(P1) = First(*L);
  }

  Dealokasi(Piter);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  //KAMUS
  address P1;

  //ALGORITMA
  if ( IsEmpty(*L) )
  {
    First(*L) = P;
    Next(P) = First(*L);
  }
  else
  {
    P1 = First(*L);
    while ( Next(P1) != First(*L) )
    {
      P1 = Next(P1);
    }
    Next(P) = First(*L);
    First(*L) = P;
    Next(P1) = P;
  }
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  //KAMUS
  address P1;

  //ALGORITMA
  P1 = First(*L);
  if ( IsEmpty(*L) )
  {
    InsertFirst(L,P);
  }
  else
  {
    while ( Next(P1) != First(*L) )
      {
        P1 = Next(P1);
      }
    Next(P1) = P;
    Next(P) = First(*L);
  }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  //KAMUS

  //ALGORITMA
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  //KAMUS
  address P1;

  //ALGORITMA
  P1 = First(*L);
  *P = First(*L);
  if ( Next(P1) == First(*L) )
  {
    First(*L) = Nil;
  }
  else
  {
    while ( Next(P1) != First(*L) )
    {
      P1 = Next(P1);
    }
    First(*L) = Next(First(*L));
    Next(P1) = First(*L);
  }

}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  //KAMUS
  address P1,P2;

  //ALGORITMA
  P1 = First(*L);
  P2 = Nil;
  if ( Next(P1) == First(*L) )
  {
    *P = P1;
    P1 = Nil;
    First(*L) = Nil;
  }
  else
  {
    while ( Next(P1) != First(*L))
    {
      P2 = P1;
      P1 = Next(P1);
    }
    *P = P1;
    if ( P2 != Nil )
    {
      Next(P2) = First(*L);
    }
  }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  //KAMUS
  address P1;

  //ALGORITMA
  P1 = First(*L);
  while ( P1 != Prec)
  {
    P1 = Next(P1);
  }
  *Pdel = Next(Prec);

  Next(Prec) = Next(Next(Prec));

}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  //KAMUS
  address P,Prec;

  //ALGORITMA
  P = First(*L);
  Prec = Nil;

  if ( Info(P) == X)
  {
   if ( Next(P) == First(*L) )
    {
      First(*L) = Nil;
    }
   else
    {
      while ( Next(P) != First(*L) )
      {
        P = Next(P);
      }
      Dealokasi(First(*L));
      First(*L) = Next(First(*L));
      Next(P) = First(*L);
    }
  }
  else
  {
    Prec = P;
    P = Next(P);

    while ( (P!=First(*L)) && ( Info(P) != X) )
    {
      Prec = P;
      P = Next(P);
    }

    if ( P != First(*L) )
    {
      Next(Prec) = Next(Next(Prec));
      Dealokasi(P);
    }
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  //KAMUS
  address P;

  //ALGORITMA
  P = First(L);

  printf("[");

      if (!IsEmpty(L))
      {
        printf("%d",Info(P));

        if ( Next(P) != First(L) )
        {
    printf(",");
        }
        P = Next(P);

        while (P != First(L))
    {
      printf("%d",Info(P));

      if (Next(P)!=First(L))
      {
        printf(",");
      }
      P = Next(P);
    }
      }

  printf("]");
}
