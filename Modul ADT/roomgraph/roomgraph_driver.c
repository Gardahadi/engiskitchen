//Included Libraries
#include <stdio.h>
#include "roomgraph.h"

/*
Cara Compile:
gcc roomgraph.c roomgraph_driver.c -o tes

Cara Run:
./tes

Hasil yang diekspektasi:
ya
no

Hasil yang didapat:
ya
no
*/

int main () {
	GRAPH G;
	adrNode Pn1;
	adrNode Pn2;
	adrDoorNode Pt1;
	adrDoorNode Pt2;

	Pn1 = AlokNodeG(1); //room 1
	Pn2 = AlokNodeG(2); //room 2

	CreateGraph (Pn1, &G);
	NextGN(Pn1) = Pn2;

	Pt1 = AlokDoorNode(1, 1, 2, Pn1); //door room 1
	Trail(Pn1) = Pt1;
	Pt2 = AlokDoorNode(2, 3, 2, Pn2); //door room 2
	Trail(Pn2) = Pt2;
	NextDoor(Pt1) = Pt2;

	if(SearchNode(G, 1) == Pn1){
		printf("ya\n");
	}else{
		printf("no\n");
	}

	if(SearchNode(G, 3) == Pn1){
		printf("ya\n");
	}else{
		printf("no\n");
	}

	DealokNode(Pn1);
	DealokNode(Pn2);

	DealokDoorNode(Pt1);
	DealokDoorNode(Pt2);

	return 0;
}
