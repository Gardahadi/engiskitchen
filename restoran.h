/* MODUL RESTORAN */

#ifndef RESTORAN_H
#define RESTORAN_H

#include "ADT header/boolean.h"
#include "ADT header/jam.h"
#include "ADT header/point.h"
#include "ADT header/array.h"
#include "ADT header/mesinkata.h"
#include "ADT header/queue.h"
#include "ADT header/list.h"
#include "ADT header/tree.h"
#include "ADT header/graph.h"
#include "basetype.h"

/* Definisi elemen dan koleksi objek */
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
