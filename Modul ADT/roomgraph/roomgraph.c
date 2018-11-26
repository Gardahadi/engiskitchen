#include <stdio.h>
#include <stdlib.h>
#include "roomgraph.h"

void CreateGraph (adrNode X, GRAPH *G){

  FirstG(*G) = X;
}

adrNode AlokNodeG(int X) {
  adrNode P = (adrNode) malloc(sizeof(RoomNode));
  if (P != NULL) {
    Id(P) = X;
    Trail(P) = NULL;
    NextGN(P) = NULL;
    return P;
  }
  else {
    return NULL;
  }

}

void DealokNode (adrNode P){
  free(P);
}

adrDoorNode AlokDoorNode (int X, int Y, int d, adrNode D){
  adrDoorNode P = (adrDoorNode) malloc(sizeof(DoorNode));
  if (P != NULL) {
    Daddy(P) = D;
    NextDoor(P) = NULL;
    NextGT(P) = NULL;
    P->Xpos = X;
    P->Ypos = Y;
    P->Direction = d;
    return P;
  }
  else {
    return NULL;
  }

}

void DealokDoorNode (adrDoorNode P){
  free(P);
}


adrNode SearchNode (GRAPH G, int X){
  //KAMUS
  adrNode Pn;
  boolean found;
  //Inisialisasi
  Pn = FirstG(G);
  found = false;
  while(!found && NextGN(Pn) != NULL){
    if (Id(Pn) == X) {
      found=true;
    }
    else {
      Pn = NextGN(Pn);
    }
  }
  return Pn;
}
