/*Implementasi dari procedure Take, Buang, dan Give*/
#include "../restoran.h"

/* Definisi akses dengan Selektor : Get */

void Take (){
	//KAMUS
	int abs;
	int ord;
	int i;
	BAHAN bhn;
	//ALGORITMA


	if (RN != 4){
		printf("Anda sedang tidak berada di dapur\n");
	}
	else{
		//player ada di kitchen

		//Mengecek apakah bahan bersebelahan dengan pemain

		abs = -1;
		ord = -1;

		if(Room(RN, absis(), ordinat())=='M'){
			abs = absis();
			ord = ordinat();
		}

		if(Room(RN, absis()+1, ordinat())=='M'){
			abs = absis()+1;
			ord = ordinat();
		}

		if(Room(RN, absis()-1, ordinat())=='M'){
			abs = absis()-1;
			ord = ordinat();
		}

		if(Room(RN, absis(), ordinat()+1)=='M'){
			abs = absis();
			ord = ordinat()+1;
		}

		if(Room(RN, absis(), ordinat()-1)=='M'){
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
			bhn.Name = InfoKitchenArray(i);
			PushBS(&hand(), bhn);

		}
		else{
			printf("Bahan tidak bersebelahan dengan pemain\n");
		}
	}

}

void Buang (Kata Perintah){
	//KAMUS
	//ALGORITMA

	if (Perintah.TabKata[1] == 'H'){
		//perintah CH
		CreateEmptyBS (&hand());
	}else{
		//perintah CT
		CreateEmptyFS (&tray());
	}
}

void Give (){
	//KAMUS
	FOOD food;
	int i;
	int abs; //posisi x customer
	int ord; //posisi y customer
	boolean found;
	//ALGORITMA
	PopFS(&tray(), &food);

	//cek apakah ada pengunjung bertetanggaan

	abs = -1;
	ord = -1;

	if(Room(RN, absis(), ordinat())=='C'){
		abs = absis();
		ord = ordinat();
	}

	if(Room(RN, absis()+1, ordinat())=='C'){
		abs = absis()+1;
		ord = ordinat();
	}

	if(Room(RN, absis()-1, ordinat())=='C'){
		abs = absis()-1;
		ord = ordinat();
	}

	if(Room(RN, absis(), ordinat()+1)=='C'){
		abs = absis();
		ord = ordinat()+1;
	}

	if(Room(RN, absis(), ordinat()-1)=='C'){
		abs = absis();
		ord = ordinat()-1;
	}

	if ((abs!=-1)&&(ord!=-1)){
		//bersebelahan dengan pemain

		//cek apakah pesanan sesuai
		PopFS(&tray(), &food);

		i = 0;
		found = false;

		while (!found) {

			if ((PosTableArray(RN, i).x + 1 == abs) && (PosTableArray(RN, i).y == ord)){
				found = true;
			}

			if ((PosTableArray(RN, i).x - 1 == abs) && (PosTableArray(RN, i).y == ord)){
				found = true;
			}

			if ((PosTableArray(RN, i).x == abs) && (PosTableArray(RN, i).y + 1 == ord)){
				found = true;
			}

			if ((PosTableArray(RN, i).x == abs) && (PosTableArray(RN, i).y - 1 == ord)){
				found = true;
			}

			if(!found){
				i++;
			}

		}

		if (IsKataSama(food.Nama, InfoTableArray(RN, i))){
			// pesanan sesuai
			TableArray(RN, i).IsFull = false;
			player().Money += food.Harga;
		}else{
			printf("Pesanan tidak sesuai\n");
			PushFS(&tray(), food);
		}


	}
	else{
		printf("Pelanggan tidak bersebelahan dengan pemain\n");
	}


}
