/*  ENGI'S KITCHEN EXTENDED
    Program untuk tugas besar Algoritma dan Struktur Data yang berupa simulaasi restoran.
    Kelompok "Back to Nature"
    1. Nur Alam Hasabie - 13517006
    2.
    4.
    5. Gardahadi - 13517144
    6. Rika Dewi - 13517147
*/

//Included Libraries
#include <stdio.h>
// #include "restoran.h"
// #include <ncurses.h>

#include "../restoran.h"




ROOM ArrRoom[5];
RESTAURANT R;
TREEPACKAGE Rs;

int main () {

  //Inisialisasi Peta
  BuildResto();
  Load(2);
  Recipe();


}
