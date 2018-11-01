//File definisi dasar berbagai tipe bentukan
//Tipe bentukan semuanya dibutuhkan untuk proses di restoran
//Library
#include "matriks.h" //MATRIKS untuk bentukan Room
#include "boolean.h" //Boolean
#include "stdio.h"
#include "stdlib.h"
#include "stackt.h"
#include "mesinkata.h" //Mesin kata untuk tipe kata dan mesin kata untuk pembacaan file

//Tipe bentukan food
typedef struct {
  Kata Nama; //nama food
  long Harga; //harga food
} FOOD;

//Tipe bentukan posisi
typedef struct {
  int x; //absis
  int y;  //ordinat
  int nRoom; //nomer ruangan
  //Definisi ruangan : room 1 = 1
  //room 2 = 3, room 3 = 3 , kitchen = 4
} POSISI;

//Tipe bentukan customer
typedef struct {
  Food Makanan; //nama makanan
  int Jumlah; //jumlah customer
  int Kesabaran; //tingkat kesabaran
  boolean IsStar; //true jika star customer
} CUSTOMER;

//Tipe bentukan meja
typedef struct{
  int Kapasitas;
  Customer C;
  boolean IsFull;
  Posisi PosMeja;
} TABLE;

//Tipe bentukan order
typedef struct {
  Kata Name; //nama food yang diorder
  int TableNumber; //nomer meja
} ORDER;

//Tipe bentukan room
typedef struct{
  MATRIKS RoomBoard; //UBAH ELTYPE MATRIKS JADI CHAR
  TABLE TableArray[4];
} ROOM;

//Tipe bentukan resep
typedef struct {
	//Tree of food
} RESEP;



typedef struct {
  Kata Name; //nama food yang diorder
}BAHAN;
