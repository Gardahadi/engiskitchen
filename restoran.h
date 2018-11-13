
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ADT header/boolean.h"
#include "ADT header/customer.h"
#include "ADT header/basetype.h"
#include "ADT header/foodstack.h"
#include "ADT header/bahanstack.h"
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
  ORDERTAB OrderTab; //queue of order
  PLAYER P; //player P
  GRAPH RoomGraph;
} RESTAURANT;

/*FUNGSI PROSEDUR*/

extern Restaurant R;
extern Rs;
extern Room [5]; //indeks [1..4]
/* EXTERN PLAYER ADA TIDAK ? */

void Move (char* Command); //Garda

void GetOrder (); //Badur

void Put (); //Badur

void Take (); //Done

void Buang (char* Command); //Done

void Place (); //Lukas

void Give (); //Done

void Recipe (); //Lukas

void Save (); //Alam

void Load (); //Alam

void UpdateCust(); //Alam


#endif
