/* MODUL RESTORAN */

#ifndef RESTORAN_H
#define RESTORAN_H

#include "ADT header/boolean.h"
#include "ADT header/jam.h"
#include "ADT header/point.h"
#include "ADT header/array.h"
#include "ADT header/matriks.h"
#include "ADT header/mesinkata.h"
#include "ADT header/queue.h"
#include "ADT header/stackt.h"
#include "ADT header/list.h"
#include "ADT header/tree.h"
#include "ADT header/graph.h"

#include <stdio.h>

/* Definisi elemen dan koleksi objek */

typedef struct {
	//Tree of food
} Resep;

typedef struct{
  MATRIKS RoomBoard; //UBAH ELTYPE MATRIKS JADI CHAR
  Meja arrayMeja[4];
} Room

typedef struct{
  int Kapasitas;
  Customer C;
  boolean isFull;
  Posisi posMeja;
} Meja

typedef struct {
  char *Nama; //nama food
  long Harga; //harga food
} Food;

typedef struct {
  char *Nama; //nama food yang diorder
  int Meja; //nomer meja
} Order;

typedef struct {
  int x; //absis
  int y;  //ordinat
  int nRoom; //nomer ruangan
  //room 1 = 1
  //room 2 = 3
  //room 3 = 3
  //kitchen = 4
} Posisi;

typedef struct {
  long Money; //uang player
  int Life; //nyawa player
  Posisi Pos; //posisi player
  STACK Hand; //stack of bahan
} Player;

typedef struct {
  int Time; //waktu permainan
  STACK Tray; //stack of food
  QUEUE CustQueue; //queue of customer
  QUEUE OrderQueue; //queue of order
  Player P; //player P
} Restoran;

/*FUNGSI PROSEDUR*/

extern Restoran R;
extern Rs;
extern Room Room1;
extern Room Room2;
extern Room Room3;
extern Room Kitchen;

void Move (char* Perintah);

void GetOrder ();

void Put ();

void Take ();

void Buang (char* Perintah);

void Place ();

void Give ();

void Recipe ();

void Save ();

void Load ();

void UpdateCust();


#endif
