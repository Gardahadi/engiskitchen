#include <stdio.h>
#include "../restoran.h"


void BuildResto() {

  R1 = AlokNodeG(1);
  R2 = AlokNodeG(2);
  R3 = AlokNodeG(3);
  R4 = AlokNodeG(4);
  CreateGraph(R1,&R.Building);
  //Menyambungkan antar Room
  NextGN(R1) = R2;
  NextGN(R2) = R3;
  NextGN(R3) = R4;

  //Membangun pintu-pintunya
  D1A = AlokDoorNode(10,5,3,R1);
  D1B = AlokDoorNode(5,10,2,R1);

  D2A = AlokDoorNode(2,1,4,R2);
  D2B = AlokDoorNode(10,5,3,R2);

  D3A = AlokDoorNode(1,5,1,R3);
  D3B = AlokDoorNode(2,1,4,R3);

  D4A = AlokDoorNode(1,5,1,R4);
  D4B = AlokDoorNode(5,10,2,R4);
  //Membuat Pintu di masing-masing Room
  Trail(R1) = D1A;
  NextGT(D1A) = D1B;

  Trail(R2) = D2A;
  NextGT(D2A) = D2B;

  Trail(R3) = D3A;
  NextGT(D3A) = D3B;

  Trail(R4) = D4A;
  NextGT(D4A) = D4B;

  //Menyambungkan Pintu-pintunya
  NextDoor(D1A) = D4A;
  NextDoor(D1B) = D2A;
  NextDoor(D2A) = D1B;
  NextDoor(D2B) = D3A;
  NextDoor(D3A) = D2B;
  NextDoor(D3B) = D4B;
  NextDoor(D4A) = D1A;
  NextDoor(D4B) = D3B;
  }
