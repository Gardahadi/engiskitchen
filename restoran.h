
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ADT Header/boolean.h"
#include "ADT Header/basetype.h"
#include "ADT Header/Order.h"
#include "ADT Header/foodstack.h"
#include "ADT Header/bahanstack.h"
#include "ADT Header/matriksroom.h"
#include "ADT Header/customer.h"
#include "ADT Header/treeresep.h"



//Tipe bentukan player
typedef struct {
  long Money; //uang player
  int Life; //nyawa player
  POSITION Pos; //posisi player
  BSTACK Hand; //stack of bahan
  FSTACK Tray; //stack of food
} PLAYER;


/* Definisi elemen dan koleksi objek */
typedef struct {
  int Time; //waktu permainan
  CQUEUE CustQueue; //queue of customer
  TabOrder TabOfOrder; // Sebuah Array of Order
  PLAYER P; //player P
  //GRAPH RoomGraph;
} RESTAURANT;

/* Definisi elemen dan koleksi objek */
typedef struct {
  RESEP TabResep[25]; //array of resep
  BinTree TResep; // tree of resep
} TREEPACKAGE;


/*FUNGSI PROSEDUR*/

extern RESTAURANT R;
extern TREEPACKAGE Rs;
extern ROOM ArrRoom[5]; //indeks [1..4]

/* Definisi akses dengan Selektor : Get */
#define hand() R.P.Hand
#define tray() R.P.Tray
#define arrResep(i) Rs.TabResep[(i)]
#define pohonresep() Rs.TResep
#define absis() R.P.Pos.x
#define ordinat() R.P.Pos.y
#define player() R.P
#define RN R.P.Pos.nRoom
#define Room(n, x, y) ArrRoom[(n)].RoomBoard.Mem[(x)][(y)]
#define GetKitchenArray(X) ArrRoom[4].KitchenArray[(X)]
#define InfoKitchenArray(X) ArrRoom[4].KitchenArray[(X)].Name
#define PosKitchenArray(X) ArrRoom[4].KitchenArray[(X)].Pos
#define InfoTableArray(n, X) ArrRoom[n].TableArray[(X)].C.Makanan.Nama
#define PosTableArray(n, X) ArrRoom[(n)].TableArray[(X)].PosMeja
#define TableArray(n, X) ArrRoom[(n)].TableArray[(X)]
#define OrderResto R.TabOfOrder.TOrd
#define QCustomer R.CustQueue


void Move (int Dir); //Garda

void loadMap();

void GetOrder (); //Badur

void Put (); //Done

void Take (); //Done

void Buang (Kata Command); //Done

void Place (); //Done

void Give (); //Done

void Recipe (); //Lukas

void Save (); //Alam

void Load (); //Alam

void UpdateCust(); //Alam


#endif
