
/* MODUL RESTORAN */
#ifndef RESTAURANT_H
#define RESTAURANT_H

//File-file header yang digunakan
// #include "ADT Header/boolean.h"
// #include "ADT Header/basetype.h"
// #include "ADT Header/Order.h"
// #include "ADT Header/foodstack.h"
// #include "ADT Header/bahanstack.h"
// #include "ADT Header/matriksroom.h"
// #include "ADT Header/customer.h"
// #include "ADT Header/treeresep.h"
// #include "ADT Header/roomgraph.h"
// #include "ADT Header/jam.h"





//Tipe bentukan player
typedef struct {
  long Money; //uang player
  int Life; //nyawa player
  POSITION Pos; //posisi player
  BSTACK Hand; //stack of bahan
  FSTACK Tray; //stack of food
  Kata Name;
} PLAYER;


/* Definisi elemen dan koleksi objek */
typedef struct {
  int Tick; //waktu permainan asli
  CQUEUE CustQueue; //queue of customer
  TabOrder TabOfOrder; // Sebuah Array of Order
  PLAYER P; //player P
  GRAPH Building; //Gedung resto yang diimplementasi menggunakan GRAPH
  int Simulasi;
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
extern adrNode R1,R2,R3,R4;
extern adrDoorNode D1A,D1B,D2A,D2B,D3A,D3B,D4A,D4B;
extern char *Message,*Message2, *Message3;

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
#define BuildingResto R.Building

void Move (int Dir); //Garda
//I.S sembarang
//F.S Player bergerak sesuai dir dengan ketentun 1=atas, 2=kiri, 3=bawh, 4-kanan

void loadMap();
//I.S Sembarang, map.txt ada dalam satu directory
//F.S memindahkan isi dari map.txt ke dalam struktur data internal restoran.h

void GetOrder (); //Badur
//I.S sembarang
//F.S Meminta order dari customer  dan memasukannya ke array order

void Put (); //Done
//I.S sembarang
//F.S Memasak makanan dan memasukannya ke tray apabila kondisi sudah terpenuhi (bahan lolos validasi dan player disamping tray)


void Take (); //Done
//I.S sembarang
//F.S Hand diisi oleh bahan sesuai dengan posisi dimana take dilakukan


void BuangT (); //Done
//I,S sembarang
//F.S Tray dikosongkan

void BuangH (); //Done
//I.S sembarang
//F.S Hand dikosongkan

void Place (); //Done
//I.S. sembarang
//F,S Menghilangkan customer di head of queue dan meletakannya di meja yang berdekatan dengan player, mengembalikan pesan error jika kondisi tersebut tidak terpenuhi


void Give (); //Done
//I.S sembarang
//F.S Menghilangkan customer dari table apabil order dengan top of tray sama dan menambah Money player sesuai harg makanan

void Recipe (); //Lukas
//I.S sembarang
//F.S Menampilkan recipe dengan format listing tree

void Save (); //Alam
//I.S sembarang
//F.S Menghasilkan file save.txt yang formatnya mengikuti file savefile.txt

void Load (); //Alam
//I.S File save.txt dan defaultsave.txt sudah adalah
//F.S Membaca file save dan memasukan datanya ke dalam struktur data internal restoran


void UpdateCust(boolean *NewCustomer); //Alam
//I.S sembarang
//F.S Melakukan update kesabaran customer baik di dalam queueu maupun yang berada di meja dan menambahkan customer ke queueu secara random

void BuildResto();
//I.S sembarang
//F.S Melakukan definisi dan pemasangan node-node Graph restoran


char IntToChar(int X);
//I.S sembarang
//F.S X menjadi sebuah karakter

void DelCust(int i);
//I.S sembarang
//F.S Customer di meja ke i akan di delete dari meja

void PrintHelp();
//I.S sembarang
//F.S Akan menampilkan pesan bantuan yang berisi daftar dan keterangan semua perintah


void PrintCredit();
//I.S sembarang
//F.S Akan menampilkan pesan credits ke layar

void DelOrderan(int i);
//I.S Sembarang
//F.S Orderan oleh Customer di meja ke i akan di delete dari Tab of order

#endif
