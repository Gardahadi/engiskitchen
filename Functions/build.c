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
  D1A = AlokDoorNode(11,5,4,R1);
  D1B = AlokDoorNode(5,11,3,R1);

  D4A = AlokDoorNode(2,2,1,R4);
  D4B = AlokDoorNode(11,5,4,R4);

  D3A = AlokDoorNode(2,5,2,R3);
  D3B = AlokDoorNode(2,2,1,R3);

  D2A = AlokDoorNode(2,5,2,R2);
  D2B = AlokDoorNode(5,11,3,R2);
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
  NextDoor(D1A) = D2A;
  NextDoor(D1B) = D4A;
  NextDoor(D2A) = D1A;
  NextDoor(D2B) = D3B;
  NextDoor(D3A) = D4B;
  NextDoor(D3B) = D2B;
  NextDoor(D4A) = D1B;
  NextDoor(D4B) = D3A;
  }
