//Included Libraries
#include <stdio.h>
#include "bahanstack.h"
#include "mesinkata.h"
#include "basetype.h"

/*
Cara Compile:
gcc bahanstack.c bahanstack_driver.c mesinkata.c mesinkar.c -o tes

Cara Run:
./tes

Hasil yang diekspektasi:
Tes3
Tes2
Tes1

Hasil yang didapat:
Tes3
Tes2
Tes1
*/

int main () {
	BSTACK S;
	CreateEmptyBS (&S);
	
	BAHAN B;

	B.Name = StringToKata("Tes1");
	if(!IsFullBS(S)) {
		PushBS(&S, B);
	}

	B.Name = StringToKata("Tes2");
	if(!IsFullBS(S)) {
		PushBS(&S, B);
	}

	B.Name = StringToKata("Tes3");
	if(!IsFullBS(S)) {
		PushBS(&S, B);
	}

	while(!IsEmptyBS(S)){
		PopBS(&S, &B);
		PrintKata(B.Name);
		printf("\n");
	}


	return 0;
}
