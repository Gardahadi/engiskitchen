/*  ENGI'S KITCHEN EXTENDED
    Program untuk tugas besar Algoritma dan Struktur Data yang berupa simulaasi restoran.
    Kelompok "Back to Nature"
    1. Lukas Kurnia Jonathan - 13517006
    2. Nur Alam Hasabie - 13517096
    3. Abdurrahman Adni - 13517117
    5. Gardahadi - 13517144
    6. Rika Dewi - 13517147
*/

//Included Libraries
#include <stdio.h>
#include <ncurses.h>
#include "restoran.h"


//KAMUS GLOBAL
WINDOW* BoxTop1, *BoxTop2, *BoxTop3, *BoxTop4;
WINDOW* Box1, *Box2, *Box3, *Box4;
WINDOW* BoxBot, *MapBox;
ROOM ArrRoom[5];
RESTAURANT R;
TREEPACKAGE Rs;
adrNode R1,R2,R3,R4;
adrDoorNode D1A,D1B,D2A,D2B,D3A,D3B,D4A,D4B;
char *Message,*Message2, *Message3;
char cmd[10];


//Fungsi untuk merubah Karakter ke Integer

int main () {

  //kamus lokal
  int i,j;
  int Choice; //Menyimpan input awal dari player
  boolean new;
  Load(2);
  int X;
  scanf("%d",&X);
  while(X==1){
      UpdateCust(&new);
      i=1;
      while(i<=3){
        j=0;
        while(j<4){
          printf("%d %d\n",
          Kesabaran(TableArray(i,j).C),
          Jumlah(TableArray(i,j).C)
          );
          j++;
        }
        i++;
      }
      scanf("%d",&X);
  }
 
}
