#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
	 F.S. : CC ≠ BLANK atau CC = MARK */
{
 // ALgoritma
 while ((CC == BLANK) && (CC != MARK) && (CC!='\n')) {
   ADV();
 }
}



void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START();
  IgnoreBlank();
  if(CC == MARK) {
    EndKata = true;
  }
  else {
    EndKata = false;
    SalinKata();
  }

}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
 {
    /* Algoritma*/
    if (CC == MARK) {
      EndKata = true;
    } else /* CC != MARK */ {
      SalinKata();
    }
  }
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

{ /* Kamus Lokal */
  int i; // iterator
  i = 1;
  CKata.TabKata[i] = CC;
  ADV();
  while((CC!=BLANK) && (CC != MARK) && (i<NMax) && (CC!='\n')) {
    i++;
    CKata.TabKata[i] = CC;
    ADV();
  }
  CKata.Length=i;
  IgnoreBlank();
}

boolean IsKataSama(Kata K1,K2) {
  //Function untuk mengecek apakah ada dua kata yang sama
  //Bila iya maka return true, kalau tidak sama return false
	if(K1.Length!=K2.Length){
    	return false;
  	} else {
    	int i=1;
    	while((i<K1.Length)&&(K1.TabKata[i]==K2.TabKata[i])){
    		i++;
    	} //i= Length or ada huruf yang tidak sama
		if(K1.TabKata[i]==K2.TabKata[i]){
			return true;
		} else {
			return false;
		}
  	}
}

void PrintKata(Kata K){
	//Print kata, TIDAK DIAKHIRI OLEH NEWLINE
	i=1;
	while(i<=K.Length){
		printf("%c\n",K.TabKata[i]);
		i++;
	}
}

Kata StringToKata(char *s){
	//Kamus
	int i;
	Kata K;
	//Algoritma
	i = 1;
	while((s[i-1]!='\0')&&(i<=NMax)){
		K.TabKata[i]=s[i-1];
		K.Length++;
		i++;
	}
	return K;
}