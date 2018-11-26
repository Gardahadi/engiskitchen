#include <stdio.h>
#include "treeresep.h"

/*Driver untuk adt treeresep

Cara compile :
  gcc *.c -o driver

Cara menjalankan:
  ./driver
*/

int main(){
  resinfotype TabResep[25];
  resinfotype X;
  BinTree T;



  X.Name = StringToKata("Makanan");
  /*Mengecek fungsi alokasi*/
  T = AlokNode(X);
  printf("Akar dari T  = ");
  PrintKata(Akar(T).Name);
  printf("\n");
  if(Left(T) == Nil && Right(T) == Nil)
  {
    printf("Alokasi sukses\n");
  }

  /*Membuat Tree*/
  X.Name = StringToKata("Tree");
  T = Tree(X,Nil,Nil);
  printf("Akar dari T  = ");
  PrintKata(Akar(T).Name);
  printf("\n");
  if(Left(T) == Nil && Right(T) == Nil)
  {
    printf("Fungsi Tree sukses\n");
  }


  /*Satu elemen atau kosong*/
  if(IsTreeEmpty(T))
  {
    printf("Tree Kosong\n");
  }
  else{printf("Tree tidak kosong\n");}

  if(IsTreeOneElmt(T))
  {
    printf("Tree satu elemen\n");
  }
  else{printf("Tree tidak satu elemen\n");}

  /*Search*/
  if(SearchTree(T,X))
  {
    printf("Simpul bernama Tree ditemukan\n");
  }
  else{printf("tidak ditemukan\n");}

  /*Add Daun dan print tree*/
  X.Name = StringToKata("Apel");
  printf("Tree sebelum ditambah daun: \n");
  PrintTreeResep(T,2);
  AddDaunResep(&T,Akar(T),X);
  printf("Tree setelah ditambah daun: \n");
  PrintTreeResep(T,2);

  /*BuildTreeResep dari Array*/
  TabResep[1].Name = StringToKata("a");
  TabResep[2].Name = StringToKata("b");
  TabResep[3].Name = StringToKata("c");
  TabResep[4].Name = StringToKata("d");
  TabResep[5].Name = StringToKata("e");
  TabResep[6].Name = StringToKata("f");
  TabResep[7].Name = StringToKata("g");
  TabResep[8].Name = StringToKata("h");
  TabResep[9].Name = StringToKata("i");
  TabResep[10].Name = StringToKata("j");
  TabResep[11].Name = StringToKata("k");
  TabResep[12].Name = StringToKata("l");
  TabResep[13].Name = StringToKata("m");
  TabResep[14].Name = StringToKata("n");
  TabResep[15].Name = StringToKata("x");
  TabResep[16].Name = StringToKata("o");
  TabResep[17].Name = StringToKata("p");
  TabResep[18].Name = StringToKata("q");
  TabResep[19].Name = StringToKata("r");
  TabResep[20].Name = StringToKata("s");
  TabResep[21].Name = StringToKata("t");
  TabResep[22].Name = StringToKata("u");
  TabResep[23].Name = StringToKata("v");
  TabResep[24].Name = StringToKata("w");

  int i=1;
  T = BuildTreeResep(23,TabResep,&i); //Membuat simpul dengan banyak 23+1 dari array dimulai indeks ke-1
  PrintTreeResep(T,2);






  return 0;
}
