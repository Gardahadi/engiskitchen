#include "restoran.h"
#include "boolean.h"

#define UndefCustomer -1
#define EmptyCQ 0
typedef int CAddress

//Customer type definition

typedef struct {
  Food Makanan; //nama makanan
  int Jumlah; //jumlah customer
  int Kesabaran; //tingkat kesabaran
  boolean IsStar; //true jika star customer
} Customer;

//Customer queue type definition
//Implementation using dynamic array of customer

typedef struct { 
    Customer * T;   /* tabel penyimpan elemen */
    CAddress HEAD;  /* alamat penghapusan */
    CAddress TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} CQueue;

//Selectors with macros
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/*PREDICATE FUNCTION AND PROCEDURE*/
boolean IsEmptyCQ(CQueue Q);
/* I.S. Q is defined */
/* Return true if Q is empty, false otherwise */
boolean IsFullCQ(CQueue Q);
/* I.S. Q is defined */
/* Return true if Q is full, false otherwise */
void CreateEmpty (CQueue * Q, int Max);
/* F.S. Q is defined with max element = Max if allocation success*/

void DeAlokasi(CQueue * Q);
/* F.S. Q is deallocated */
void AddCustomerToQueue(CQueue *Q);
/* I.S. Q is defined-> Q may be full */
/* F.S. a new customer is added If new customer is star customer, then 
addition is by priority.
    If full then Q stayed the same
*/
void DeleteCustomerFromQueue(CQueue *Q);
/* I.S. Q is defined , maybe empty */
/* */