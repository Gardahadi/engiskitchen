#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#include "listdp.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
  return (First(L) == Nil);

}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
  First(*L) = Nil;
  Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
  address P = (address) malloc(sizeof(ElmtList));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
    Prev(P) = Nil;
    return P;
  }
  else {
    return Nil;
  }
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  address Pt;
  Pt = First(L);
  while (Next(Pt) != Nil && Info(Pt) != X) {
    Pt = Next(Pt);
  }
  if (Info(Pt) == X) {
    return Pt;
  }
  else {
    return Nil;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  //Kamus Lokal
  address P;
  //Algoritma
  P = Alokasi(X);
  if(P!=Nil){
    if(!IsEmpty(*L)){
      Next(P) = First(*L);
      Prev(First(*L))=P;
    }
    if(IsEmpty(*L)){
      Last(*L)=P;
    }
    First(*L) = P;
  }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  //Kamus
  address Pin;

  //ALgoritma
  Pin = Alokasi(X);
  if (Pin != Nil){
    //Kasus Kosong
    if(IsEmpty(*L)){
      InsVFirst(L,X);
    }
    else{
      Next(Last(*L))=Pin;
      Prev(Pin)=Last(*L);
      Last(*L)=Pin;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  //Kamus
  address P;
  //Algoritma
  *X = Info(First(*L));
  P = First(*L);
  //Jika elemen hanya 1
  if(P == Last(*L)) {
    First(*L)=Nil;
    Last(*L)=Nil;
  }
  else{
    Prev(Next(P))=Nil;
    First(*L) = Next(P);
  }
  Dealokasi(P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  //Kamus
  address P,Pdel;
  //ALgoritma
  //Kasus List cuma 1
  Pdel=Last(*L);
  *X=Info(Last(*L));
  if(Prev(Last(*L))==Nil){
    Last(*L)=Nil;
    First(*L)=Nil;
  }
  else{
    Last(*L)=Prev(Last(*L));
    Next(Last(*L))=P;
  }


}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
//Jika tidak KOSONG
{
  if (!(IsEmpty(*L))){
    Prev(First(*L))= P;
    Next(P) = First(*L);
    First(*L) = P;
  }
//Jika KOSONG
  else{
    First(*L) = P;
    Last(*L) = P;
  }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  if (IsEmpty(*L)) {
		InsertFirst(L,P);
	}
  else {
  		address PLast;
  		PLast = First(*L);
  		while (Next(PLast) != Nil) {
  			PLast = Next(PLast);
		}
  Prev(P) = PLast;
	Next(P) = Nil;
	Next(PLast) = P;
  Last(*L)=P;
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  //Kasus Jika Prec bukan elemen terakhir
  if(Last(*L) != Prec){
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Prev(Next(Prec))=P;
    Next(Prec) = P;
  }
  else{
    Next(P) = Nil;
    Prev(P)= Prec;
    Next(Prec)=P;
    Last(*L)=P;
  }
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
  //Kasus Jika Succ ada First
  if(First(*L)==Succ){
    InsertFirst(L,P);
  }
  else{

    Next(P) = Succ;
    Prev(P) = Prev(Succ);
    Next(Prev(Succ))=P;
    Prev(Succ) = P;
  }

}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  //Algoritma
  *P = First(*L);
  First(*L) = Next(First(*L));
  if(First(*L) != Nil){
    Prev(First(*L))=Nil;
  }
  else {
    Last(*L) = Nil;
  }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
  *P = Last(*L);
  Last(*L) = Prev(Last(*L));
  if(Last(*L) != Nil){
    Next(Last(*L))=Nil;
  }
  else {
    First(*L) = Nil;
  }
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
      // Kamus Lokal
          address P,P1;

      // Algoritma
          P = First(*L);
          P1 = Nil;
          if ( Info(P) == X)
              {
                  if ( First(*L) == Last(*L) )
                      {
                          First(*L) = Nil;
                          Last(*L) = Nil;
                      }
                  else
                      {
                          First(*L) = Next(P);
                          Prev(Next(P)) = Nil;
                      };
              }
          else
              {
                  while ( ( P != Nil ) && (Info(P) != X ) )
                      {
                          P1 = P;
                          P = Next(P);
                      };

                  if ( P != Nil )
                      {
                          if ( P == Last(*L) )
                              {
                                  Last(*L) = P1;
                                  Next(P1) = Nil;
                              }
                          else
                              {
                                  Prev(Next(P)) = P1;
                                  Next(P1) = Next(P);
                              }

                      }
              }
          Dealokasi(P);
  }

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel= Next(Prec);
  if(Next(Prec) != Nil){
    Next(Prec) = Next(Next(Prec));
    if(Next(Prec)!=Nil){
      Prev(Next(Prec)) = Prec;
    }
    else{
      Last(*L)=Prec;
    }
  }

}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel = Prev(Succ);
  if(Prev(Succ)!=Nil){
    Prev(Succ)=Prev(Prev(Succ));
    if(Prev(Succ)!=Nil){
      Next(Prev(Succ)) = Succ;
    }
    else{
      First(*L)=Succ;
    }
  }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  //Kamus
  address P;
  //If IsEmpty
  if (IsEmpty(L)){
    printf("[]");
  }
  else {
    P=First(L);
    printf("[");
    while(Next(P)!=Nil){
      printf("%d,",Info(P));
      P = Next(P);
    }
    printf("%d]",Info(P));
  }
}


void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  //Kamus
  address P;
  //If IsEmpty
  if (IsEmpty(L)){
    printf("[]");
  }
  else {
    P=First(L);
    printf("[");
    while(Next(P)!=Nil){
      P = Next(P);
    }
    while(Prev(P) != Nil){
      printf("%d,",Info(P));
      P=Prev(P);
    }
    printf("%d]",Info(P));
  }
}
