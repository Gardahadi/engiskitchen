/*Implementasi dari procedure Take, Buang, dan Give*/
#include "../restoran.h"

char *Message,*Message2;
//DUplicate type jangan sampe ada

char* IntToChar(int X){
	if (X==1){
		return "1\0";
	}
	else if (X==2){
		return "2\0";
	}
	else if (X==3){
		return "3\0";
	}
	else if (X==4){
		return "4\0";
	}
	else if (X==5){
		return "5\0";
	}
	else if (X==6){
		return "6\0";
	}
	else if (X==7){
		return "7\0";
	}
	else if (X==8){
		return "8\0";
	}
	else if (X==9){
		return "9\0";
	}
	else if (X==10){
		return "10\0";
	}
	else if (X==11){
		return "11\0";
	}
}

boolean IsWall(){
	if (absis()==1 || ordinat()==1 || absis()==12 || ordinat()==12){
		return true;
	}
	else {
		return false;
	}

}

/* Implementasi prosedur dan fungsi terkait Move */
void Move (int Dir) {
	switch (Dir) {
		case 1:
			ordinat()--;
			Message=IntToChar(absis());
			Message2= IntToChar(ordinat());
			if(IsWall()){
				PosChanger(0,1,Dir);
			}
			break;
		case 2 :
			absis()--;
			Message=IntToChar(absis());
			Message2= IntToChar(ordinat());
			if(IsWall()){

				PosChanger(1,0,Dir);
			}
			break;
		case 3 :
			ordinat() ++;
			Message=IntToChar(absis());
			Message2= IntToChar(ordinat());
			break;
			if(IsWall()){

				PosChanger(0,-1,Dir);
			}
		case 4 :
			absis()++;
			Message=IntToChar(absis());
			Message2= IntToChar(ordinat());
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
	Message= IntToChar(Pt->Xpos);
	Message2= IntToChar(Pt->Direction);
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
		RN = Id(Daddy(NextDoor(Pt)));

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
