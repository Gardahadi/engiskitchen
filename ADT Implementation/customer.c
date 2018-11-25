/* Auithor : Nur Alam Hasabie 13517096*/

#include "../ADT Header/customer.h"
#include "../restoran.h"
#include "stdio.h"
#include "stdlib.h"
char *Message;
/*PREDICATE FUNCTION AND PROCEDURE*/
boolean IsEmptyCQ(CQUEUE Q){
    return (Head(Q)==EmptyCQ)&&(Tail(Q)==EmptyCQ);
}
boolean IsFullCQ(CQUEUE Q){
    return Tail(Q)==(MaxEl(Q)-1);
}
void CreateEmptyCQ(CQUEUE * Q, int Max){
    (*Q).T = (CUSTOMER *)malloc(Max*sizeof(CUSTOMER));
    if((*Q).T!=NULL){
        //Head and Tail assignment->definition of empty queue
        Head(*Q)=EmptyCQ;
        Tail(*Q)=EmptyCQ;
        MaxEl(*Q)=Max;

    }
}
void DeAlokasi(CQUEUE * Q){
    MaxEl(*Q)=0;
    free((*Q).T);
}
// void AddCustomerToQueue(CUSTOMER C){
//     /* Dictionary */
//     CAddress i;
//     if(IsEmptyCQ(*Q)){
//         //empty case
//         Head(*Q)=0;
//         Tail(*Q)=0;
//         (*Q).T[Head(*Q)] = C;
//     } else if (!IsFullCQ(*Q)){
//         //not full case
//         //star customer insertion
//         if(IsStar(C)){
//             i = Tail(*Q);
//             while((!IsStar((*Q).T[i]))&&(i>Head(*Q))){
//                 (*Q).T[i+1]=(*Q).T[i];
//                 i--;
//             }//i is other star customer(s) or i=Head(*Q)
//             if(i>Head(*Q)){
//                 //i is not head
//                 (*Q).T[i+1]=C;
//             } else {
//                 if(IsStar(InfoHead(*Q))){
//                     (*Q).T[i+1]=C;
//                 } else {
//                     (*Q).T[i+1]=InfoHead(*Q);
//                     InfoHead(*Q)=C;
//                 }
//             }
//             Tail(*Q)++;
//             Neff(*Q)++;
//
//         } else {
//             //normal customer addition
//             Tail(*Q)++;
//             InfoTail(*Q) = C;
//         }
//     } //full queue case -> queue stay as previous
// }
void DeleteCustomerFromQueue(CQUEUE *Q,CUSTOMER *C){
    /* I.S. Q is defined , maybe empty */
    /* F.S. Head customer is deleted : Queue maybe empty */
    CAddress i;
    if(!IsEmptyCQ(*Q)){
        *C = InfoHead(*Q);
        //geser
        if(Head(*Q)==Tail(*Q)){
            //one element case
            CreateEmptyCQ(Q,MaxEl(*Q));
        } else {
            //not one element case
            //all elements must be moved
            //which is very very inefficient AF
            i = Head(*Q);
            while(i<Tail(*Q)){
                (*Q).T[i]=(*Q).T[i+1];
                i++;
            } //i=Tail(*Q)
            Tail(*Q)--;
        }
    }
}


CUSTOMER GenerateCustomer(int seed){
    /* Return customer */
    /* Customer is generated with random generation */
    /* If undefined customer is returned, it means that no customer is generated */
    /* Dictionary */
    int frequency_ratio = 7; //program X times more likely to not generate any customers in one tick time
    int number_ratio = 10; //program X times more likely to produce guest with 2 seats
    int star_ratio = 9;//program is X times more likely to generate normal guest instead of star guest
    int X; //number for placeholder
    int i;
    CUSTOMER C;
    /* Algorithm */
    i=0;
    X = rand();
    while(i<seed){
        X = rand();
        i++;
    }
    if((X%(frequency_ratio+1))==0){
        //Random guests generated
        //Determining number of guest
        if((X%(number_ratio+1))==0){
            Jumlah(C)=4;
        } else {
            Jumlah(C)=2;
        }
        //Determining whether guests are star guests or not
        X = rand();
        if(X%(star_ratio+1)==0){
            //Star guest
            IsStar(C)=true;
            Kesabaran(C)=20;
        } else {
            //normal guest
            IsStar(C)=false;
            Kesabaran(C)=30;
        }
    } else {
        //Undefined guest
        Kesabaran(C) = UndefCustomer;
        Jumlah(C) = 0;
        IsStar(C) = false;
    }
    return C;

}
