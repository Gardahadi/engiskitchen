/*Implementasi dari procedure Take, Buang, dan Give*/
#include "restoran.h"



//DUplicate type jangan sampe ada

/* Implementasi prosedur dan fungsi terkait Move */
void Move (int Dir) {
	switch (Dir) {
		case 1:
			ordinat()++;
			break;
		case 2 :
			ordinat()--;
		case 3 :
			absis() --;
			break;
		case 4 :
			absis()++;
			break;
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
