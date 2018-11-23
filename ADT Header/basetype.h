//File definisi dasar berbagai tipe bentukan
//Tipe bentukan semuanya dibutuhkan untuk proses di restoran
//Library
#include "matriksroom.h" //MATRIKS untuk bentukan Room
#include "boolean.h" //Boolean
#include "stdio.h"
#include "stdlib.h"
#include "mesinkata.h" //Mesin kata untuk tipe kata dan mesin kata untuk pembacaan file

#ifndef BASETYPE_H
#define BASETYPE_H


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
  //room 2 = 2, room 3 = 3 , kitchen = 4
} POSITION;

//Tipe bentukan customer
typedef struct {
  FOOD Makanan; //nama makanan
  int Jumlah; //jumlah customer
  int Kesabaran; //tingkat kesabaran
  boolean IsStar; //true jika star customer
} CUSTOMER;

//Tipe bentukan meja
typedef struct{
  int Kapasitas;
  CUSTOMER C;
  boolean IsFull;
  POSITION PosMeja;
  int Nomor;
} TABLE;

//Tipe bentukan menyimpan object dapur

typedef struct{
  Kata Name;
  POSITION Pos;
} KITCHENSET;


//Tipe bentukan room
typedef struct{
  MATRIKS RoomBoard;
  TABLE TableArray[4];
  KITCHENSET KitchenArray[16];
} ROOM;

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeOrder;  /* type indeks */

typedef struct {
	FOOD CustomerOrder; /* Menyimpan  */
	int NomorMeja; /*Menyimpan Nomor meja yang memesan */
} Orderan;

typedef struct {
	Orderan TOrd[100+1]; /* memori tempat penyimpan elemen (container) */
	int NeffOrder; /* >=0, banyaknya elemen efektif */
} TabOrder;

//Tipe bentukan resep
typedef struct {
	Kata Name;
} RESEP;

typedef struct {
  Kata Name; //nama food yang diorder
}BAHAN;

#endif
