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

MATRIKS Room; //UBAH ELTYPE MATRIKS JADI CHAR

typedef struct {
  Food Makanan; //nama makanan
  int Jumlah; //jumlah customer
  int Kesabaran; //tingkat kesabaran
  boolean IsStar; //true jika star customer
} Customer;

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

void AddCust();
// I.S. Arbitrary
// F.S. Random customer generated :
// Customer can be either star customer or non-star customer
// If no customer generated, return a not-valid customer

void DelQCust();

void DelCust();
// I.S. Arbitrary
// F.S. Customer in restaurant with zero patience is 

#endif
