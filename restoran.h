/* MODUL RESTORAN */

#ifndef RESTORAN_H
#define RESTORAN_H

#include "boolean.h"
#include "jam.h"
#include "point.h"
#include "array.h"
#include "matriks.h"
#include "mesinkata.h"
#include "queue.h"
#include "stackt.h"
#include "list.h"
#include "tree.h"
#include "graph.h"

#include <stdio.h>

/*  Kamus Umum */

#define BrsMin 0
#define BrsMax 100
#define KolMin 0
#define KolMax 100
#define KolMax 100

/* Definisi elemen dan koleksi objek */

typedef struct {
	//Tree of food
} Resep;

boolean Room [BrsMax][KolMax]; 
/* Indeks Room yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */

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

void Move (Restoran *R, char* Perintah);

void GetOrder (Restoran *R);

void Put (Restoran *R);

void Take (Restoran *R);

void Buang (Restoran *R, char* Perintah);

void Place (Restoran *R);

void Give (Restoran *R);

void Recipe (Restoran *R, Resep Rs);

void Save (Restoran *R);

void Load (Restoran *R);

#endif
