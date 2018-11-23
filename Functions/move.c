/*Implementasi dari procedure Take, Buang, dan Give*/
#include "../restoran.h"
boolean Hit;


//DUplicate type jangan sampe ada

boolean IsWall(){
	if (absis()==0 || ordinat()==0 || absis()==11 || ordinat()==11){
		Hit = true;
		return true;
	}
	else {
		Hit = false;
		return false;
	}

}

/* Implementasi prosedur dan fungsi terkait Move */
void Move (int Dir) {
	switch (Dir) {
		case 1:
			ordinat()--;
			if(IsWall()){
				PosChanger(0,1,Dir);
			}
			break;
		case 2 :
			absis()--;
			if(IsWall()){
				PosChanger(1,0,Dir);
			}
			break;
		case 3 :
			ordinat() ++;
			break;
			if(IsWall()){
				PosChanger(0,-1,Dir);
			}
		case 4 :
			absis()++;
			if(IsWall()){
				PosChanger(-1,0,Dir);
			}
			break;
	}
}

void PosChanger(int dx, int dy, int direc){

	//KAMUS
	adrNode P;
	adrDoorNode Pt;
	boolean found;

	//Algoritma
	found = false;
	P = SearchNode(BuildingResto, RN);
	Pt = Trail(P);
	while(!found && Pt != NULL){
		if(absis()+dx == Pt->Xpos && ordinat()+dy == Pt->Ypos && direc == Pt->Direction){
			found = true;
		}
		else {
			Pt = NextGT(Pt);
		}
	}
	if(found){
		absis() = NextDoor(Pt)->Xpos;
		ordinat() = NextDoor(Pt)->Ypos;
		RN = Id(Daddy(Pt));
	}
	else{
		absis() = absis()+dx;
		ordinat() = ordinat()+dy;
	}


}

// void GetOrder (); //Badur
//
// void Put (); //Badur
//
//
// void Place (); //Lukas

//
// void Recipe (); //Lukas
//
// void Save (); //Alam
//
// void Load (); //Alam
//
// void UpdateCust(); //Alam
