/* Auithor : Nur Alam Hasabie 13517096*/

#include "customer.h"
#include "stdio.h"
#include "stdlib.h"

/*PREDICATE FUNCTION AND PROCEDURE*/
boolean IsEmptyCQ(CQueue Q){
    return (Head(Q)==EmptyCQ)&&(Tail(Q)==EmptyCQ);
}
boolean IsFullCQ(CQueue Q){
    return Tail(Q)==(MaxEl(Q)-1);
}
void CreateEmpty (CQueue * Q, int Max){
    (*Q).T = (Customer *)malloc(Max*sizeof(Customer));
    if((*Q).T!=NULL){
        //Head and Tail assignment->definition of empty queue
        Head(Q)=EmptyCQ;
        Tail(Q)=EmptyCQ;
        MaxEl(Q)=Max;
    }
}

void DeAlokasi(CQueue * Q){
    MaxEl(*Q)=0;
    free(*Q).T;
}
void AddCustomerToQueue(CQueue *Q,Customer C){
    /* Dictionary */
    CAddress i;
    if(IsEmptyCQ(*Q)){
        //empty case
        Head(*Q)=0;
        Tail(*Q)=0;
        (*Q).T = C;
    } else if (!IsFullCQ(*Q)){
        //not full case
        //star customer insertion
        if(IsStar(C)){

        } else {
            //normal customer addition
            Tail(*Q)++;
            Info(Tail(*Q)) = C;
        }
    } //full case -> queue stay as previous
}
void DeleteCustomerFromQueue(CQueue *Q,Customer *C){
    /* I.S. Q is defined , maybe empty */
    /* F.S. Head customer is deleted : Queue maybe empty */
    if(!IsEmptyCQ(*Q)){
        *C = InfoHead(*Q);
        //geser
        if(Head(*Q)==Tail(*Q)){
            //one element case
            CreateEmpty(Q,MaxEl(*Q));
        } else {
            //not one element case
            //all elements must be moved
            //which is very very inefficient AF
        }
    }
}

Customer GenerateCustomer();
/* Return customer */
/* Customer is generated with random generation */
/* If undefined customer is returned, it means that no customer is generated */