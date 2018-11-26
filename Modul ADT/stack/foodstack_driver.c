//Included Libraries
#include <stdio.h>
#include "foodstack.h"
#include "mesinkata.h"
#include "basetype.h"

/*
Cara Compile:
gcc foodstack.c foodstack_driver.c mesinkata.c mesinkar.c -o tes

Cara Run:
./tes

Hasil yang diekspektasi:
Tes3
3
Tes2
2
Tes1
1

Hasil yang didapat:
Tes3
3
Tes2
2
Tes1
1
*/

int main () {
	FSTACK S;
	CreateEmptyFS (&S);

	FOOD B;

	B.Nama = StringToKata("Tes1");
	B.Harga = 1;
	if(!IsFullFS(S)) {
		PushFS(&S, B);
	}

	B.Nama = StringToKata("Tes2");
	B.Harga = 2;
	if(!IsFullFS(S)) {
		PushFS(&S, B);
	}

	B.Nama = StringToKata("Tes3");
	B.Harga = 3;
	if(!IsFullFS(S)) {
		PushFS(&S, B);
	}

	while(!IsEmptyFS(S)){
		PopFS(&S, &B);
		PrintKata(B.Nama);
		printf("\n");
		printf("%ld",B.Harga);
		printf("\n");
	}


	return 0;
}
