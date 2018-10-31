/* MODUL RESTORAN */

#ifndef RESTORAN_H
#define RESTORAN_H

#include "ADT header/boolean.h"
#include "ADT header/array.h"
#include "ADT header/mesinkata.h"
#include "ADT header/customer.h"
#include "ADT header/tree.h"
#include "ADT header/graph.h"
#include "ADT header/basetype.h"
#include "ADT header/fstack.h"



//Tipe bentukan player
typedef struct {
  long Money; //uang player
  int Life; //nyawa player
  Posisi Pos; //posisi player
  BStack Hand; //stack of bahan
} Player;


/* Definisi elemen dan koleksi objek */
typedef struct {
  int Time; //waktu permainan
  FStack Tray; //stack of food
  CQueue CustQueue; //queue of customer
  OQueue OrderQueue; //queue of order
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
