/*  ENGI'S KITCHEN EXTENDED
    Program untuk tugas besar Algoritma dan Struktur Data yang berupa simulaasi restoran.
    Kelompok "Back to Nature"
    1. Nur Alam Hasabie - 13517006
    2.
    3.
    4.
    5.
    6.
*/

//Included Libraries
#include <stdio.h>
#include "restoran.h"

int main () {
  //Inisialisasi
  simulation_running = false;
  no_simulasi = 0;
  load_success = true;

  //Looping Inti Program yang akan berjalan sampai pengguna melakukan perintah "Exit"
  do {
    do {
      printf(">");
      scanf("%s",&command);
      switch(command) {
        case "new game" : break;
        case "start game" : break;
        case "load game" : break;
        case "exit" : break;
        default : printf("Perintah Salah silahkan mengetik 'help' untuk melihat daftar perintah\n");
      }
      while (simulation_running = false);
    }


    do {
      printf(">>");
      scanf("%s",&command);
      switch(command){
        case "GU" :
        case "GD" :
        case "GL" :
        case "GL" :
        case "GR" :
        case "GL" :
        case "ORDER" :
        case "PUT"  :
        case "TAKE" :
        case "CH"   :
        case "CT"   :
        case "PLACE":
        case "GIVE" :
        case "RECIPE" :
        case "SAVE" :
        case "LOAD" :
        case "EXIT" :
        default : printf("Perintah Salah silahkan mengetik 'help' untuk melihat daftar perintah\n");
      }
      updateTime();
      while(simulation_running);
    }

  }
}
