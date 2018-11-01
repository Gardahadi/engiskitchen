
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ADT header/boolean.h"
#include "ADT header/customer.h"
#include "ADT header/basetype.h"
#include "ADT header/foodstack.h"
#include "ADT header/supplystack.h"
#include "ADT header/matrikskar.h"



//Tipe bentukan player
typedef struct {
  long Money; //uang player
  int Life; //nyawa player
  POSITION Position; //posisi player
  BSTACK Hand; //stack of bahan
  FSTACK Tray; //stack of food
} PLAYER;


/* Definisi elemen dan koleksi objek */
typedef struct {
  int Time; //waktu permainan
  CQUEUE CustQueue; //queue of customer
  OQUEUE OrderQueue; //queue of order
  PLAYER P; //player P
} RESTAURANT;

/*FUNGSI PROSEDUR*/

extern Restaurant R;
extern Rs;
extern Room [5]; //indeks [1..4]

void Move (char* Command);

void GetOrder ();

void Put ();

void Take ();

void Buang (char* Command);

void Place ();

void Give ();

void Recipe ();

void Save ();

void Load ();

void UpdateCust();


#endif
