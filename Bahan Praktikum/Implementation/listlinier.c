/* NIM / Nama : 13517144 / Gardahadi
/* IMPLEMENTASI PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
  return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  address P = (address) malloc(sizeof(ElmtList));
	if (P != NULL) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
  else {
		return Nil;
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
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
  //Kamus Lokal
  address Pin;
  address Pt;
  //Algoritma
  Pin = Alokasi(X);
  //Mengecek keberhasilan ALokasi
  if(Pin != Nil ){
      if(IsEmpty(*L)){
        InsVFirst(L,X);
      }
      else{
        Pt = First(*L);
        while(Next(Pt)!= Nil) {
          Pt = Next(Pt);
        }
        Next(Pt)=Pin;

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
  First(*L) = Next(First(*L));
  Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  //Kamus
  address PDel,PPrev;

  //ALgoritma
  PPrev = Nil;
	PDel = First(*L);
	while (Next(PDel) != Nil) {
		PPrev = PDel;
		PDel = Next(PDel);
	}
	*X = Info(PDel);
	if (PPrev == Nil) {
		First(*L) = Nil;
	} else {
		Next(PPrev) = Nil;
	}
	Dealokasi(&PDel);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  //Jika tidak KOSONG
  if (!(IsEmpty(*L))){
    Next(P) = First(*L);
  }
  First(*L) = P;

}


void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}



void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  if (IsEmpty(*L)) {
		InsertFirst(L,P);
	}
  else{
  		address PLast;
  		PLast = First(*L);
  		while (Next(PLast) != Nil) {
  			PLast = Next(PLast);
		}
	Next(P) = Nil;
	Next(PLast) = P;
	}
}

void DelFirst (List *L, address *P)
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  //Kamus Lokal
  //address Pt;

  //Algoritma
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = Nil;

}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{

  //Kamus
  address Pt,PPrev;

  //Algoritma
  if (!IsEmpty(*L)) {
		PPrev = Nil;
		Pt = First(*L);
		while (Next(Pt) != Nil && Info(Pt) != X) {
			PPrev = Pt;
			Pt = Next(Pt);
		}
		if (Info(Pt) == X) {
			if (PPrev == Nil) {
				First(*L) = Next(First(*L));
			} else {
				Next(PPrev) = Next(Pt);
			}
			Dealokasi(&Pt);
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  address PDel,PPrev;
	PPrev = Nil;
	PDel = First(*L);
	while (Next(PDel) != Nil) {
		PPrev = PDel;
		PDel = Next(PDel);
	}
	*P = PDel;
	if (PPrev == Nil) {
		First(*L) = Nil;
	} else {
		Next(PPrev) = Nil;
	}
	Next(*P) = Nil;
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  //Algoritma
  *Pdel= Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = Nil;

}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  //Kamus
  address Pt;

  //Algoritma
  Pt = First(L);

  //Kasus jika List KOSONG
  if (IsEmpty(L)){
    printf("[]");
  }
  else{
    printf("[");
    while(Next(Pt) != Nil) {
      printf("%d,",Info(Pt));
      Pt = Next(Pt);
    }
    printf("%d]",Info(Pt));
  }
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  //Kamus
  int counter;
  address Pt;

  //Algoritma
  if (IsEmpty(L)){
      return 0;
  } else{
      Pt = First(L);
      counter = 0;
      while(Pt!=Nil){
          counter += 1;
          Pt = Next(Pt);
      }
      return counter;
  }

}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
  // Kamus Lokal
      infotype maks;
      address P;
  // Algoritma
      P = First(L);
      maks = Info(P);
      while (P!=Nil){
          if (Info(P)>maks){
              maks = Info(P);
          }
          P = Next(P);
      }
      return maks;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  // Kamus
      address Last1;
  // Algoritma
      if (IsEmpty(*L1)){
          First(*L3) = First(*L2);
      } else{
          First(*L3) = First(*L1);
          Last1 = First(*L1);
          while (Next(Last1)!=Nil){
              Last1 = Next(Last1);
          }
          Next(Last1) = First(*L2);
      }
      CreateEmpty(L1);
      CreateEmpty(L2);
}
