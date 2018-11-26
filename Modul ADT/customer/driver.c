#include "customer.h"


int main(){
    CQueue Q;
    Customer C;
    CreateEmptyCQ(&Q,10);
    int i=0;
    int life=0;
    while(i<MaxEl(Q)){
        C = GenerateCustomer(i);
        while(Jumlah(C)==UndefCustomer){
            C = GenerateCustomer(i);
        } //C is defined
        AddCustomerToQueue(&Q,C);
        i++;
    }
    i=0;
    while(i<MaxEl(Q)){
        printf("Kesabaran : %d\n",Kesabaran(Q.T[i]));
        printf("Jumlah : %d\n", Jumlah(Q.T[i]));
        if(IsStar(Q.T[i])){
            printf("Tamu bintang\n");
        }
        printf("----------------\n");
        i++;
    }
    UpdateQueue(&Q,&life);
    i=0;
    while(i<MaxEl(Q)){
        printf("Kesabaran : %d\n",Kesabaran(Q.T[i]));
        i++;
    }
    return 0;
}