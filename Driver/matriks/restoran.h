
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ADT Header/boolean.h"
#include "ADT Header/basetype.h"
#include "ADT Header/matriksroom.h"



extern ROOM ArrRoom[5]; //indeks [1..4]



/* Definisi akses dengan Selektor : Get */
#define hand() R.P.Hand
#define tray() R.P.Tray
#define absis() R.P.Pos.x
#define ordinat() R.P.Pos.y
#define player() R.P
#define Room(n, x, y) Room[(n)].RoomBoard.Mem[(x)][(y)]
#define GetKitchenArray(X) Room[4].KitchenArray[(X)]
#define InfoKitchenArray(X) Room[4].KitchenArray[(X)].Name
#define PosKitchenArray(X) Room[4].KitchenArray[(X)].Pos
#define InfoTableArray(n, X) Room[n].TableArray[(X)].C.Makanan.Nama
#define PosTableArray(n, X) Room[(n)].TableArray[(X)].PosMeja


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
