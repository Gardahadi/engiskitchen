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

char cmd[10];

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
  mvwprintw(BoxTop2,1,1,"Money : %d",player().Money);
  wrefresh(BoxTop2);
  mvwprintw(BoxTop3,1,1,"Lives : %d",player().Life);
  wrefresh(BoxTop3);
  mvwprintw(BoxTop4,1,1,"Time : %s", cmd);
  wrefresh(BoxTop4);


  //Make middle-left/right zone
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


  //Make Grid Zone
  MapBox = newwin(LINES-LINES/4-LINES/32,COLS/2,LINES/2-LINES/4-LINES/8-LINES/16-LINES/32,COLS/2-COLS/4);
  box(MapBox,0,0);
  wrefresh(MapBox);

  //Make Bottom Zone
  BoxBot = newwin(LINES/6,COLS,LINES-LINES/6,0);
  box(BoxBot,0,0);
  wrefresh(BoxBot);
  mvwprintw(BoxBot,1,1,"COMMAND : ");
  wrefresh(BoxBot);

}

char GetChar(int y, int x){

  if(Room(RN,y,x) == '#') {
    return 'X';
  }

  else if (y == ordinat() && x == absis()){
    return 'G';
  }

  else {
    return '_';
  }
}

void printBoard(MATRIKS X) {

  //Kamus Lokal
  int px,py,i,j;

  //Inisialisasi
  px=1;
  py=1;

  //Algoritma

  for (i=1;i<=NBrsEff(X);i++) {
    for (j=1;j<=NKolEff(X);j++) {

      if ((j==NKolEff(X)))  {
        mvwprintw(MapBox,py,px," %c ",GetChar(i,j));
        wrefresh(MapBox);
        px=1;
        py=py+2;

      }

      else if ((j==1))  {
        mvwprintw(MapBox,py,px," %c ",GetChar(i,j));
        wrefresh(MapBox);
        px=px+5;

      }

      else {
        mvwprintw(MapBox,py,px," %c ",GetChar(i,j));
          wrefresh(MapBox);
          px=px+5;
      }
    }
  }
}


int main () {

  //kamus lokal
  int i,j;



  //Inisialisasi Peta
  BuildResto();
  printf("%d\n",NextDoor(D1A)->Xpos);
  printf("%d\n",NextDoor(D1A)->Ypos);
  // Load();
  // loadMap(); //Loading Map dari mapfile.txt
  // CreateUI(); //Membuat Window2 beserta isinya
  // printBoard(ArrRoom[1].RoomBoard); // Print Petak Ruangan
  // wrefresh(BoxBot);
  //
  // //Looping Utama Program
  // wgetstr(BoxBot,cmd);
  // while(!(IsKataSama(StringToKata("Exit\0"),StringToKata(cmd)))){
  //
  //   if(IsKataSama(StringToKata(cmd),StringToKata("GU\0"))){
  //     Move(1);
  //     printBoard(ArrRoom[RN].RoomBoard);
  //   }
  //   else if(IsKataSama(StringToKata(cmd),StringToKata("GD\0"))){
  //     Move(3);
  //     printBoard(ArrRoom[RN].RoomBoard);
  //   }
  //   else if(IsKataSama(StringToKata(cmd),StringToKata("GL\0"))){
  //     Move(2);
  //     printBoard(ArrRoom[RN].RoomBoard);
  //   }
  //   else if(IsKataSama(StringToKata(cmd),StringToKata("GR\0"))){
  //     Move(4);
  //     printBoard(ArrRoom[RN].RoomBoard);
  //   }
  //
  //   CreateUI();
  //   printBoard(ArrRoom[RN].RoomBoard);
  //   wgetstr(BoxBot,cmd);
  //
  // }
  // endwin();

}
