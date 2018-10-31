/* Author : Nur Alam Hasabie 13517096 */
#ifndef CQUEUE_H
#define CQUEUE_H

#include "boolean.h"
#include "basetype.h"

#define UndefCustomer -1
#define EmptyCQ -1
typedef int CAddress;

//Tipe queue dengan elemen customer
//Representasi array dinamik eksplisit rapat kiri

typedef struct {
    Customer * T;   /* tabel penyimpan elemen */
    CAddress HEAD;  /* alamat penghapusan */
    CAddress TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} CQUEUE;

//Selectors with macros
//Queue selector
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

//Customer selector
#define Makanan(C) (C).Makanan
#define Jumlah(C) (C).Jumlah
#define Kesabaran(C) (C).Kesabaran
#define IsStar(C) (C).IsStar

/*PREDICATE FUNCTION AND PROCEDURE*/
boolean IsEmptyCQ(CQueue Q);
/* I.S. Q is defined */
/* Return true if Q is empty, false otherwise */
boolean IsFullCQ(CQueue Q);
/* I.S. Q is defined */
/* Return true if Q is full, false otherwise */
void CreateEmptyCQ(CQueue * Q, int Max);
/* F.S. Q is defined with max element = Max if allocation success*/

void DeAlokasi(CQueue * Q);
/* F.S. Q is deallocated */
void AddCustomerToQueue(CQueue *Q,Customer C);
/* I.S. Q is defined-> Q may be full */
/* F.S. a new customer is added If new customer is star customer, then
addition is by priority.
    If full then Q stayed the same
*/
void DeleteCustomerFromQueue(CQueue *Q,Customer *C);
/* I.S. Q is defined , maybe empty */
/* F.S. Head customer is deleted : Queue maybe empty */
/* C adalah customer yang didelete*/

void UpdateQueue(CQueue *Q,int *Life);
/* I.S. Sembarang, Q boleh kosong */
/* F.S. Seluruh customer dengan kesabaran 1 dihapus , seluruh customer kesabarannya dikurangi 1*/
/* Life berkurang sejumlah dengan pelanggan yang yang dihapus*/

Customer GenerateCustomer(int seed);
/* Return customer */
/* Customer is generated with random generation */
/* If undefined customer is returned, it means that no customer is generated */

#endif
