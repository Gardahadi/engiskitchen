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
 while (((CC == BLANK)||(CC == '\n')) && (CC != MARK)) {
   ADV();
 }
}



void STARTKATA(int i)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START(i);
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

boolean IsKataSama(Kata K1, Kata K2) {
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
    int i;
	i=1;
	while(i<=K.Length){
		printf("%c",K.TabKata[i]);
		i++;
	}
}

Kata StringToKata(char s[]){
	//Kamus
	int i;
	Kata K;
	//Algoritma
	i = 1;
	while((s[i-1]!='\0')&&(i<=NMax)){
		K.TabKata[i]= s[i-1];
		K.Length++;
		i++;
	}
    
	return K;
}

int KataToInt(Kata K) {
    //I.S. K terdefinisi
    //Output berupa konversi kata ke integer
    //Bila kata mengandung huruf maka mengembalikan 0 (error flag)
    //Kamus
    int i,angka;
    boolean negative_flag, err_flag;
    //Algoritma
    i=1;
    angka=0;
    err_flag = false;
    if(K.TabKata[i]=='-'){
        negative_flag = true;
        i++;
    } else {
        negative_flag = false;
    }
    while((i<=K.Length)&&(!err_flag)){
        switch (K.TabKata[i]){
            case '0':
                angka = angka*10+0;
                break;
            case '1':
                angka = angka*10+1;
                break;
            case '2':
                angka = angka*10+2;
                break;
            case '3':
                angka = angka*10+3;
                break;
            case '4':
                angka = angka*10+4;
                break;
            case '5':
                angka = angka*10+5;
                break;
            case '6':
                angka = angka*10+6;
                break;
            case '7':
                angka = angka*10+7;
                break;
            case '8':
                angka = angka*10+8;
                break;
            case '9':
                angka = angka*10+9;
                break;
            default : 
                err_flag = true;
                break;
        }
        if(!err_flag){
            i++;
        }
    }//err_flag = true or i>Length
    if(err_flag){
        return 0;
    }
    if(negative_flag){
        angka = -angka;
    }
    return angka;
}