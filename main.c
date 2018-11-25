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
char *Message,*Message2, *Message3;
char cmd[10];


char IntToChar(int N){
  if(N==1){
    return '1';
  }
  else if(N==2){
    return '2';
  }
  else if(N==3){
    return '3';
  }
  else if(N==4){
    return '4';
  }
  else if(N==5){
    return '5';
  }
  else if(N==6){
    return '6';
  }
  else if(N==7){
    return '7';
  }
  else if(N==8){
    return '8';
  }
  else if(N==9){
    return '9';
  }
}



void PrintBS (BSTACK S)
/*Mencetak ke layar semua isi S*/
/*I.S. S terdefinisi*/
/*F.S. S tetap*/
{
  int l,c;
  BAHAN bhn;
  //inisialisasi
  l = 2;
  c = 1;
  while(!IsEmptyBS(S)){
    PopBS(&S, &bhn);
    mvwprintw(Box4,l,c,KataToString(bhn.Name));
    wrefresh(Box4);
    l++;
  }
}

void PrintFS (FSTACK S)
/*Mencetak ke layar semua isi S*/
/*I.S. S terdefinisi*/
/*F.S. S tetap*/
{
  int l,c;
  FOOD bhn;
  //inisialisasi
  l = 2;
  c = 1;
  while(!IsEmptyFS(S)){
    PopFS(&S, &bhn);
    mvwprintw(Box4,l,c,KataToString(bhn.Nama));
    wrefresh(Box4);
    l++;
  }
}

void PrintQC (CQUEUE Q)
/*Mencetak ke layar semua isi S*/
/*I.S. S terdefinisi*/
/*F.S. S tetap*/
{
  int l,c1,c2,i;
  //inisialisasi
  l = 2;
  c1 = 1;
  c2 = 3;
  i=Head(Q);
  if(!IsEmptyCQ(Q)){

    while(i<=Tail(Q)){
      mvwprintw(Box1,l,c1,"%d",QCustomer.T[i].Jumlah);
      mvwprintw(Box1,l,c2,"%d",QCustomer.T[i].Kesabaran);
      if(QCustomer.T[i].IsStar){
        mvwprintw(Box1,l,6,"Star");
      }
      else{
        mvwprintw(Box1,l,6,"Normal");
      }
      wrefresh(Box1);
      l++;
      i++;
    }

  }
  else {
      mvwprintw(Box1,l,c1,"Antrian Sepi");
  }
}

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
  mvwprintw(BoxTop1,1,1,"Nama : %s",player().Name);
  wrefresh(BoxTop1);
  mvwprintw(BoxTop2,1,1,"Money : %d",player().Money);
  wrefresh(BoxTop2);
  mvwprintw(BoxTop3,1,1,"Lives : %d",player().Life);
  wrefresh(BoxTop3);
  mvwprintw(BoxTop4,1,1,"Time : %d", R.Tick);
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

  mvwprintw(Box1,1,1,"Waiting Cust ");
  wrefresh(Box1);
  PrintQC(QCustomer);

  mvwprintw(Box2,1,1,"Order");
  wrefresh(Box2);

  mvwprintw(Box3,1,1,"Food Stack");
  wrefresh(Box3);
  PrintFS(tray());

  mvwprintw(Box4,1,1,"Hand");
  PrintBS(player().Hand);

  wrefresh(Box4);



  //Make Grid Zone
  MapBox = newwin(LINES-LINES/4-LINES/32,COLS/2,LINES/2-LINES/4-LINES/8-LINES/16-LINES/32,COLS/2-COLS/4);
  box(MapBox,0,0);
  wrefresh(MapBox);

  //Make Bottom Zone
  BoxBot = newwin(LINES/6,COLS,LINES-LINES/6,0);
  box(BoxBot,0,0);
  wrefresh(BoxBot);
  mvwprintw(BoxBot,1,1,"%s",Message);
  mvwprintw(BoxBot,2,1,"%s","Player berada di room ");
  mvwprintw(BoxBot,2,23,"%c",IntToChar(RN));
  mvwprintw(BoxBot,3,1,"%s",Message2);
  mvwprintw(BoxBot,4,1,"%s",Message3);


  mvwprintw(BoxBot,6,1,"COMMAND : ");
  wrefresh(BoxBot);


}


char GetChar(int y, int x){

  if(Room(RN,y,x) == '#') {
    if (x==5 && y==12 && (RN==1||RN==4)){
      return '_';
    }
    else if (x==2 && y==1 && (RN==2||RN==3)){
      return '_';
    }
    else if (x==1 && y==5 && (RN==4||RN==3)){
      return '_';
    }
    else if (x==12 && y==5 && (RN==1||RN==2)){
      return '_';
    }
    else{
      wattron(MapBox,A_BOLD);
      return 'X';

    }
  }

  else if (Room(RN,y,x)=='K'){
    wattron(MapBox,A_BOLD);
    return 'K';
  }

  else if (Room(RN,y,x)=='T'){
    wattron(MapBox,A_BOLD);
    return 'T';
  }



  else if (Room(RN,y,x)=='C'){
    wattron(MapBox,A_BOLD);
    return 'C';
  }


  else if (Room(RN,y,x)=='M'){
    wattron(MapBox,A_BOLD);
    wattron(MapBox,A_STANDOUT);
    for(int i=0;i<4;i++){
      if(ArrRoom[RN].TableArray[i].PosMeja.x==x && ArrRoom[RN].TableArray[i].PosMeja.y==y ) {
        if (ArrRoom[RN].TableArray[i].Nomor>9){
            return 'M';
        }
        else{
          return IntToChar(ArrRoom[RN].TableArray[i].Nomor);
        }
      }
      else {
        return 'M';
      }
    }
  }

  else if (y == ordinat() && x == absis()){
    wattron(MapBox,A_BOLD);
    wattron(MapBox,A_STANDOUT);
    wattron(MapBox,COLOR_PAIR(1));
    return 'P';
  }

  //PRINT Pintu

  else {
    return '_';
  }
}

void printBoard(MATRIKS X) {

  //Kamus Lokal
  int px,py,i,j;
  char C;
  //Inisialisasi

  px=COLS/8;
  py=(LINES-LINES/4-LINES/32)/4;

  //Algoritma

  for (i=1;i<=NBrsEff(X);i++) {
    for (j=1;j<=NKolEff(X);j++) {
      C=GetChar(i,j);
      if ((j==NKolEff(X)))  {
        mvwprintw(MapBox,py,px," %c ",C);
        wrefresh(MapBox);
        px=COLS/8;
        py=py+2;
      }

      else if ((j==1))  {
        mvwprintw(MapBox,py,px," %c ",C);
        wrefresh(MapBox);
        px=px+5;

      }

      else {
        mvwprintw(MapBox,py,px," %c ",C);
          wrefresh(MapBox);
          px=px+5;
      }
      wattroff(MapBox,A_BOLD);
      wattroff(MapBox,A_STANDOUT);
      wattroff(MapBox,COLOR_PAIR(1));
    }
  }
}


int main () {

  //kamus lokal
  int i,j;
  int Choice; //Menyimpan input awal dari player
  boolean adaCustomer,isRunning;
  char  InputName[10];
  //Inisialisasi Message
  Message = "Selamat datang kembali di Engi's Kitchen!\n";
  isRunning = true;
  adaCustomer = false;


  BuildResto(); //Membangun peta

  //
  system("clear");
  printf("         )          (    (          )  (                     )          )"); printf("\n");
  printf("      ( /(  (       )\\ ) )\\ )    ( /(  )\\ )  *   )   (    ( /(       ( /(");printf("\n");
  printf(" (    )\\()) )\\ )   (()/((()/(    )\\())(()/(` )  /(   )\\   )\\()) (    )\\())");printf("\n");
  printf(" )\\  ((_)\\ (()/(    /(_))/(_)) |((_)\\  /(_))( )(_))(((_) ((_)\\  )\\  ((_)\\");printf("\n");
  printf("((_)  _((_) /(_))_ (_)) (_))   |_ ((_)(_)) (_(_()) )\\___  _((_)((_)  _((_)");printf("\n");
  printf("| __|| \\| |(_)) __||_ _|/ __|  | |/ / |_ _||_   _|((/ __|| || || __|| \\| |");printf("\n");
  printf("| _| | .` |  | (_ | | | \\__ \\    ' <   | |   | |   | (__ | __ || _| | .` |");printf("\n");
  printf("|___||_|\\_|   \\___||___||___/  __|\\_\\ |___|  |_|    \\___||_||_||___||_|\\_|");printf("\n");

  if (has_colors() == FALSE) {
    printf("WARNING : Your terminal does not support color\n");
  }

  printf("Selamat datang di Engi's Kitchen, Silahkan Input pilihan : \n");
  printf("[1] New Game\n");
  printf("[2] Load Game\n");
  printf("[3] Exit]\n");
  printf("Pilihan : " );

  scanf("%d",&Choice);
  while (Choice != 1 && Choice !=2 && Choice != 3) {
    printf("Invalid Choice, Please input either 1,2 or 3 : ");
    scanf("%d\n",&Choice);
  }

  //Jika Player memilih New Game
  if (Choice == 1){
    /*Inisialisasi Restoran*/
    printf("Silahkan Input Nama (WARNING : MAX 10 Karakter ): ");
    scanf("%s",player().Name);
    Load(2); //Melakukan loading data-data dari default save
    loadMap(); //Loading Map dari mapfile.txt
  }

  else if (Choice == 2){
    Load(1);
    loadMap();
  }

  else {
    printf("Bye-bye :)\n");
    isRunning =false;
  }

  //testing zone
  Recipe();
  scanf("%s",InputName);
  //Test Inpur
  //
  while(!adaCustomer){
    UpdateCust(&adaCustomer);
  }
  //
  // start_color();
  // init_pair(1,COLOR_RED,COLOR_YELLOW);
  /*Looping Utama Program*/
  while (isRunning)
  {

    CreateUI(); //Membuat Window2 beserta isinya
    printBoard(ArrRoom[RN].RoomBoard); // Print Petak Ruangan
    wrefresh(BoxBot);

    //Meminta Input dari User
    wgetstr(BoxBot,cmd);

    if(IsKataSama(StringToKata(cmd),StringToKata("GU\0"))){
      Move(1);
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("GD\0"))){
      Move(3);
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("GL\0"))){
      Move(2);
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("L\0"))){
      Move(2);
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("GR\0"))){
      Move(4);
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("TAKE\0"))){
      Take();
      Message="Anda abis take, wow!";
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("PLACE\0"))){
      Place();
      Message="Anda abis PLACE, wow!";
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("SAVE\0"))){
      Save();
      Message="Anda abis SAVE, wow!";
      printBoard(ArrRoom[RN].RoomBoard);
    }
    else if(IsKataSama(StringToKata(cmd),StringToKata("PUT\0"))){
      Put();
      Message="Anda abis PUT, Wow";
    }

    else if(IsKataSama(StringToKata(cmd),StringToKata("Exit\0"))){
      isRunning = false;
    }

    if(player().Life == 0){
      isRunning = false;
    }
    UpdateQueue(&QCustomer);
    UpdateCust(&adaCustomer);
    R.Tick++;
    CreateUI();
    printBoard(ArrRoom[RN].RoomBoard);

  }
  //Program Selesai
  endwin();
}
