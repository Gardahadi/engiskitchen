#include <stdio.h>
#include "boolean.h"

typedef struct tRoomNode * adrNode;
typedef struct tDoorNode * adrDoorNode;
typedef struct tRoomNode {
  int Id;
  adrDoorNode Trail;
  adrNode Next;
} RoomNode;

typedef struct tDoorNode {
  adrDoorNode NextDoor;
  adrDoorNode Next;
  adrNode Parent;
  int Xpos;
  int Ypos;
  int Direction;
}DoorNode;

typedef struct Graph {
  adrNode First;
}GRAPH;

#define FirstG(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define NextGN(Pn) (Pn)->Next
#define NextDoor(Pt) (Pt)->NextDoor
#define NextGT(Pt) (Pt)->Next
#define Daddy(P) (P)->Parent

//Fungsi Prototype
void CreateGraph (adrNode X, GRAPH *G); //Membut GraphRoom Kosong

adrNode AlokNodeG(int X);

void DealokNode (adrNode P);

adrDoorNode AlokDoorNode (int X, int Y, int d, adrNode D);

void DealokDoorNode (adrDoorNode P);

adrNode SearchNode (GRAPH G, int X);

void ConnectDoor(GRAPH G, adrNode *R, adrDoorNode *D );

void BuildDoor(GRAPH *G, adrNode *R, adrDoorNode *D); //I.S Room sudah Connected!!

boolean IsWall();

void PosChanger(int dx, int dy, int direc);
