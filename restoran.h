
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ADT Header/boolean.h"
#include "ADT Header/basetype.h"
#include "ADT Header/foodstack.h"
#include "ADT Header/bahanstack.h"
#include "ADT Header/matriksroom.h"



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
  //CQUEUE CustQueue; //queue of customer
  //ORDERTAB OrderTab; //queue of order
  PLAYER P; //player P
  //GRAPH RoomGraph;
} RESTAURANT;

/*FUNGSI PROSEDUR*/

extern RESTAURANT R;
//extern Rs;
extern ROOM Room [5]; //indeks [1..4]

void Move (Kata Command); //Garda

void GetOrder (); //Badur

void Put (); //Badur

void Take (); //Done

void Buang (Kata Command); //Done

void Place (); //Lukas

void Give (); //Done

void Recipe (); //Lukas

void Save (); //Alam

void Load (); //Alam

void UpdateCust(); //Alam


#endif
