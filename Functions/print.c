#include <stdio.h>
#include "../restoran.h"

void PrintHelp()
{
  printf("Help Engi's Kitchen Expansion:\n");
  printf("===============================================================\n");
  printf("\n");
  printf("MOVEMENT PLAYER:\n");
  printf("-------------------------------\n");
  printf("-- GU = Bergerak ke atas\n");
  printf("-- GD = Bergerak ke bawah\n");
  printf("-- GL = Bergerak ke kiri\n");
  printf("-- GR = Bergerak ke kanan\n");
  printf("\n");
  printf("CUSTOMER COMMAND\n");
  printf("-------------------------------\n");
  printf("-- PLACE = Menempatkan customer dari Queue Customer ke kursi yang kosong\n");
  printf("-- ORDER = Mengambil Order atau pesanan dari Customer\n");
  printf("-- GIVE = Memberikan makanan yang sudah dimasak ke Customer\n");
  printf("\n");
  printf("KITCHEN COMMAND\n");
  printf("-------------------------------\n");
  printf("-- TAKE = Mengambil bahan makanan dari meja di dapur \n");
  printf("-- PUT = Menaruh bahan makanan yang diambil ke tray untuk dimasak\n");
  printf("\n");
  printf("EMPTY HAND\n");
  printf("-------------------------------\n");
  printf("-- CT = Membuang seluruh makanan yang ada di nampan \n");
  printf("-- CH = Membuang seluruh bahan makanan yang ada di tangan\n");
  printf("\n");
  printf("LAIN-LAIN\n");
  printf("-------------------------------\n");
  printf("-- RECIPE = Menampilkan resep untuk memasak makanan \n");
  printf("-- HELP = Menampilkan 'help' menu\n");
  printf("-- SAVE = Save game state ke file eksternal \n");
  printf("-- LOAD = Load game dari file eksternal \n");
  printf("-- EXIT = Keluar dari Game \n");
  printf("===============================================================\n");

}
void PrintCredit()
{
  printf("         )          (    (          )  (                     )          )"); printf("\n");
  printf("      ( /(  (       )\\ ) )\\ )    ( /(  )\\ )  *   )   (    ( /(       ( /(");printf("\n");
  printf(" (    )\\()) )\\ )   (()/((()/(    )\\())(()/(` )  /(   )\\   )\\()) (    )\\())");printf("\n");
  printf(" )\\  ((_)\\ (()/(    /(_))/(_)) |((_)\\  /(_))( )(_))(((_) ((_)\\  )\\  ((_)\\");printf("\n");
  printf("((_)  _((_) /(_))_ (_)) (_))   |_ ((_)(_)) (_(_()) )\\___  _((_)((_)  _((_)");printf("\n");
  printf("| __|| \\| |(_)) __||_ _|/ __|  | |/ / |_ _||_   _|((/ __|| || || __|| \\| |");printf("\n");
  printf("| _| | .` |  | (_ | | | \\__ \\    ' <   | |   | |   | (__ | __ || _| | .` |");printf("\n");
  printf("|___||_|\\_|   \\___||___||___/  __|\\_\\ |___|  |_|    \\___||_||_||___||_|\\_|");printf("\n");

  printf("\n");
  printf("\n");
  printf("===============================================================\n");
  printf("\n");
  printf("Thank's for playing this game!\n");
  printf("Credit:\n");
  printf("-- Lukas Kurnia Jonathan / 13517006\n");
  printf("-- Nur Alam Hasabie / 13517096\n");
  printf("-- Abdurrahman Adni / 13517117\n");
  printf("-- Gardahadi / 13517144\n");
  printf("-- Rika Dewi / 13517147\n");
  printf("\n");
  printf("IF2110 - Algoritma dan Struktur Data, 2018\n");
  printf("Bandung Institute of Technology\n");
}
