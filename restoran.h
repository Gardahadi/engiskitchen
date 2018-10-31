
/* MODUL RESTORAN */
#ifndef RESTORAN_H
#define RESTORAN_H

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
  POSISI Posisi; //posisi player
  BSTACK Hand; //stack of bahan
} PLAYER;


/* Definisi elemen dan koleksi objek */
typedef struct {
  int Time; //waktu permainan
  FSTACK Tray; //stack of food
  CQUEUE CustQueue; //queue of customer
  OQUEUE OrderQueue; //queue of order
  PLAYER P; //player P
} RESTORAN;

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
