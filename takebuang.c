#include "restoran.h"


void Take (){
	//KAMUS
	int abs;
	int ord;
	int i;
	//ALGORITMA


	if (player().nRoom != 4){
		printf("Anda sedang tidak berada di dapur\n");
	}
	else{
		//player ada di kitchen

		//Mengecek apakah bahan bersebelahan dengan pemain

		abs = -1;
		ord = -1;

		if(Room(player().nRoom, absis(), ordinat())=='M'){
			abs = absis();
			ord = ordinat();
		}

		if(Room(player().nRoom, absis()+1, ordinat())=='M'){
			abs = absis()+1;
			ord = ordinat();
		}

		if(Room(player().nRoom, absis()-1, ordinat())=='M'){
			abs = absis()-1;
			ord = ordinat();
		}

		if(Room(player().nRoom, absis(), ordinat()+1)=='M'){
			abs = absis();
			ord = ordinat()+1;
		}

		if(Room(player().nRoom, absis(), ordinat()-1)=='M'){
			abs = absis();
			ord = ordinat()-1;
		}

		if ((abs!=-1)&&(ord!=-1)){
			//bersebelahan dengan pemain

			//menaruh makanan
			i = 0;

			while ((PosKitchenArray(i).x != abs) && (PosKitchenArray(i).y != ord)) {
				i++;
			}

			PushBS(&hand, InfoKitchenArray(i));

		}
		else{
			printf("Bahan tidak bersebelahan dengan pemain\n");
		}
	}

}

void Buang (char* Perintah){
	//KAMUS
	//ALGORITMA

	if (Perintah[1] == 'H'){
		//perintah CH
		CreateEmptyBS (&hand());
	}else{
		//perintah CT
		CreateEmpty (&tray());
	}
}

void Give (){
	//KAMUS
	FOOD food;
	int i;
	boolean found;
	//ALGORITMA
	Pop(&tray, &food);

	//cek apakah ada pengunjung bertetanggaan

	abs = -1;
	ord = -1;

	if(Room(player().nRoom, absis(), ordinat())=='C'){
		abs = absis();
		ord = ordinat();
	}

	if(Room(player().nRoom, absis()+1, ordinat())=='C'){
		abs = absis()+1;
		ord = ordinat();
	}

	if(Room(player().nRoom, absis()-1, ordinat())=='C'){
		abs = absis()-1;
		ord = ordinat();
	}

	if(Room(player().nRoom, absis(), ordinat()+1)=='C'){
		abs = absis();
		ord = ordinat()+1;
	}

	if(Room(player().nRoom, absis(), ordinat()-1)=='C'){
		abs = absis();
		ord = ordinat()-1;
	}

	if ((abs!=-1)&&(ord!=-1)){
		//bersebelahan dengan pemain

		//cek apakah pesanan sesuai
		Pop(&tray, &food)

		i = 0;
		found = false;

		while (!found) {

			if ((PosTableArray(player().nRoom, i).x + 1 == abs) && (PosTableArray(player().nRoom, i).y == ord)){
				found = true;
			}

			if ((PosTableArray(player().nRoom, i).x - 1 == abs) && (PosTableArray(player().nRoom, i).y == ord)){
				found = true;
			}

			if ((PosTableArray(player().nRoom, i).x == abs) && (PosTableArray(player().nRoom, i).y + 1 == ord)){
				found = true;
			}

			if ((PosTableArray(player().nRoom, i).x == abs) && (PosTableArray(player().nRoom, i).y - 1 == ord)){
				found = true;
			}

			if(!found){
				i++;
			}

		}

		if (food.Name == InfoTableArray(player().nRoom, i)){
			// pesanan sesuai

			Room(player().nRoom, x+1, y) = 'X';
			Room(player().nRoom, x-1, y) = 'X';
			Room(player().nRoom, x, y+1) = 'X';
			Room(player().nRoom, x, y-1) = 'X';

			player().Money += food.Harga;
		}else{
			printf("Pesanan tidak sesuai\n");
			Push(&tray, food)
		}


	}
	else{
		printf("Pelanggan tidak bersebelahan dengan pemain\n");
	}


}
