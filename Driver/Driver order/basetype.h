//File definisi dasar berbagai tipe bentukan
//Tipe bentukan semuanya dibutuhkan untuk proses di restoran
//Library
#include "boolean.h" //Boolean
#include "stdio.h"
#include "stdlib.h"
#include "foodstack.h"
#include "mesinkata.h" //Mesin kata untuk tipe kata dan mesin kata untuk pembacaan file

#ifndef BASETYPE_H
#define BASETYPE_H


//Tipe bentukan food
typedef struct {
  Kata Nama; //nama food
  long Harga; //harga food
} FOOD;

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

#endif
