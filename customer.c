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
            i = Tail(*Q);
            while((!IsStar((*Q).T[i]))&&(i>Head(*Q))){
                (*Q).T[i+1]=(*Q).T[i];
                i--;
            }//i is other star customer(s) or i=Head(*Q)
            if(i>Head(*Q)){
                //i is not head
                (*Q).T[i+1]=C;
            } else {
                if(IsStar(InfoHead(*Q))){
                    (*Q).T[i+1]=C;
                } else {
                    (*Q).T[i+1]=InfoHead(*Q);
                    InfoHead(*Q)=C;
                }
            }
            Tail(*Q)++;

        } else {
            //normal customer addition
            Tail(*Q)++;
            Info(Tail(*Q)) = C;
        }
    } //full queue case -> queue stay as previous
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
            i = Head(*Q);
            while(i<Tail(*Q)){
                (*Q).T[i]=(*Q).T[i+1];
                i++;
            } //i=Tail(*Q)
            Tail(*Q)--;
        }
    }
}

Customer GenerateCustomer(){
    /* Return customer */
    /* Customer is generated with random generation */
    /* If undefined customer is returned, it means that no customer is generated */
    /* Dictionary */
    int frequency_ratio = 9; //program X times more likely to not generate any customers in one tick time
    int number_ratio = 2; //program X times more likely to produce guest with 2 seats
    int star_ratio = 15;//program is X times more likely to generate normal guest instead of star guest
    int X; //number for placeholder
    Customer C;
    /* Algorithm */
    X = rand();
    if((X mod(frequency_ratio+1))==0){
        //Random guests generated
        //Determining number of guest
        X = rand();
        if((X mod(number_ratio+1))==0){
            Jumlah(C)=4;
        } else {
            Jumlah(C)=2;
        }
        //Determining whether guests are star guests or not
        X=rand();
        if((X mod(star_ratio+1))==0){
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
        Jumlah(C) = UndefCustomer;
        IsStar(C) = false;
    }
    return C;
}