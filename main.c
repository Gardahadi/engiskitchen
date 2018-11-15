/*  ENGI'S KITCHEN EXTENDED
    Program untuk tugas besar Algoritma dan Struktur Data yang berupa simulaasi restoran.
    Kelompok "Back to Nature"
    1. Nur Alam Hasabie - 13517006
    2.
    4.
    5. Gardahadi - 13517144
    6.
*/

//Included Libraries
#include <stdio.h>
#include "restoran.h"
#include <ncurses.h>

//KAMUS GLOBAL
WINDOW* BoxTop1, *BoxTop2, *BoxTop3, *BoxTop4;
WINDOW* Box1, *Box2, *Box3, *Box4;
WINDOW* BoxBot, MapBox;


void PrintText(WINDOW *Box);


void CreateUI(){
  initscr();
  cbreak();
  keypad(stdscr,TRUE);

  //Make Top Bar
  BoxTop1 = newwin(LINES/12,COLS/4,0,0);
  BoxTop2 = newwin(LINES/12,COLS/4,0,COLS/4);
  BoxTop3 = newwin(LINES/12,COLS/4,0,COLS/2);
  BoxTop4 = newwin(LINES/12,COLS/4,0,COLS-COLS/4);
  box(BoxTop1,0,0);
  box(BoxTop2,0,0);
  box(BoxTop3,0,0);
  box(BoxTop4,0,0);
  refresh();
  wrefresh(BoxTop1);
  wrefresh(BoxTop2);
  wrefresh(BoxTop3);
  wrefresh(BoxTop4);
  mvwprintw(BoxTop1,1,1,"Garda");
  wrefresh(BoxTop1);
  mvwprintw(BoxTop2,1,1,"Money :");
  wrefresh(BoxTop2);
  mvwprintw(BoxTop3,1,1,"Lives :");
  wrefresh(BoxTop3);
  mvwprintw(BoxTop4,1,1,"Time : ");
  wrefresh(BoxTop4);


  //Make middle zone
  Box1 = newwin(LINES/2-LINES/12,COLS/4,LINES/12,0);
  Box2 = newwin((LINES/2-LINES/6),COLS/4,LINES/2,0);
  Box3 = newwin(LINES/2-LINES/12,COLS/4,LINES/12,COLS-COLS/4);
  Box4 = newwin((LINES/2-LINES/6),COLS/4,LINES/2,COLS-COLS/4);
  box(Box1,0,0);
  box(Box2,0,0);
  box(Box3,0,0);
  box(Box4,0,0);
  refresh();
  wrefresh(Box1);
  wrefresh(Box2);
  wrefresh(Box3);
  wrefresh(Box4);

  mvwprintw(Box1,1,1,"Waiting Cust");
  wrefresh(Box1);
  mvwprintw(Box2,1,1,"Order");
  wrefresh(Box2);
  mvwprintw(Box3,1,1,"Food Stack");
  wrefresh(Box3);
  mvwprintw(Box4,1,1,"Hand");
  wrefresh(Box4);






  //Make Bottom Zone
  BoxBot = newwin(LINES/6,COLS,LINES-LINES/6,0);
  box(BoxBot,0,0);
  wrefresh(BoxBot);
  mvwprintw(BoxBot,1,1,"COMMAND : ");
  wrefresh(BoxBot);

}



int main () {

  //kamus

  CreateUI();
  char cmd[10];

  while()
  wgetstr(BoxBot,cmd);
  CreateUI();
  wgetstr(BoxBot,cmd);

  wgetch(BoxBot);
  endwin();

  // int no_simulasi;
  // boolean simulation_running, load_success;
  // char *command;

  //Inisialisasi
  // simulation_running = false;
  // no_simulasi = 0;
  // load_success = true;

  //Looping Inti Program yang akan berjalan sampai pengguna melakukan perintah "Exit"
  // do {
  //   do {
  //     printf(">"); refresh();
  //     scanf("%s",command);
  //     switch(command) {
  //       case "new game" : break;
  //       case "start game" : break;
  //       case "load game" : break;
  //       case "exit" : break;
  //       default : printf("Perintah Salah silahkan mengetik 'help' untuk melihat daftar perintah\n"); refresh();
  //     }
  //     while (simulation_running = false);
  //   }
  //
  //
  //   do {
  //     printf(">>");
  //     scanf("%s",&command);
  //     switch(command){
  //       case "GU" :
  //       case "GD" :
  //       case "GL" :
  //       case "GL" :
  //       case "GR" :
  //       case "GL" :
  //       case "ORDER" :
  //       case "PUT"  :gc
  //       case "TAKE" :
  //       case "CH"   :
  //       case "CT"   :
  //       case "PLACE":
  //       case "GIVE" :
  //       case "RECIPE" :
  //       case "SAVE" :
  //       case "LOAD" :
  //       case "EXIT" :
  //       default : printf("Perintah Salah silahkan mengetik 'help' untuk melihat daftar perintah\n");
  //     }
  //     updateTime();
  //     while(simulation_running);
  //   }
  //
  // }
}
