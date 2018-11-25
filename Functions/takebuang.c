/*Implementasi dari procedure Take, Buang, dan Give*/
#include "../restoran.h"

/* Definisi akses dengan Selektor : Get */

void Take (){
	//KAMUS
	int Abs;
	int ord;
	int z;
	BAHAN bhn;
	//ALGORITMA


	if (RN != 4){
		printf(" Anda sedang tidak berada di dapur\n");
	}
	else{
		//player ada di kitchen

		//Mengecek apakah bahan bersebelahan dengan pemain

		Abs = -1;
		ord = -1;
		if(Room(RN, ordinat(), absis())=='M'){
			Abs = ordinat();
			ord = absis();
		}

		if(Room(RN, ordinat()+1, absis())=='M'){
			Abs = ordinat()+1;
			ord = absis();
		}

		if(Room(RN, ordinat()-1, absis())=='M'){
			Abs = ordinat()-1;
			ord = absis();
		}

		if(Room(RN, ordinat(), absis()+1)=='M'){
			Abs = ordinat();
			ord = absis()+1;
		}

		if(Room(RN, ordinat(), absis()-1)=='M'){
			Abs = ordinat();
			ord = absis()-1;
		}
		if ((Abs!=-1)&&(ord!=-1)){
			//bersebelahan dengan pemain

			//menaruh makanan
			z = 0;
			while ((PosKitchenArray(z).x != ord) || (PosKitchenArray(z).y != Abs)) {
				z++;
			}
			Message = "Anda baru saja TAKE, Luar biasa!";
			bhn.Name = InfoKitchenArray(z);
			PushBS(&hand(), bhn);
		}
		else{
			Message="Bahan tidak bersebelahan dengan pemain";
		}
	}

}

void BuangH(){
	Message2 = "Isi HAND kosong";
	Message3 = "Mubadzir loh :(";
	CreateEmptyBS (&hand());
}

void BuangT(){
	Message2 = "Isi TRAY kosong";
	Message3 = "Mubadzir loh :(";
	CreateEmptyFS (&tray());
}

void Give (){
	//KAMUS
	FOOD food;
	int i;
	int Abs; //posisi x customer
	int ord; //posisi y customer
	boolean found;
	//ALGORITMA

	//PopFS(&tray(), &food);

	//cek apakah ada pengunjung bertetanggaan

	Abs = -1;
	ord = -1;

	if(Room(RN, ordinat(), absis())=='C'){
		ord = ordinat();
		Abs = absis();
	}

	if(Room(RN, ordinat()+1, absis())=='C'){
		ord = ordinat()+1;
		Abs = absis();
	}

	if(Room(RN, ordinat()-1, absis())=='C'){
		ord = ordinat()-1;
		Abs = absis();
	}

	if(Room(RN, ordinat(), absis()+1)=='C'){
		ord = ordinat();
		Abs = absis()+1;
	}

	if(Room(RN, ordinat(), absis()-1)=='C'){
		ord = ordinat();
		Abs = absis()-1;
	}

	if ((Abs!=-1)&&(ord!=-1)){
		//bersebelahan dengan pemain
		if(!IsEmptyFS(tray())){
			//cek apakah pesanan sesuai
			PopFS(&tray(), &food);

			i = 0;
			found = false;

			while (!found) {

				if ((PosTableArray(RN, i).x + 1 == Abs) && (PosTableArray(RN, i).y == ord)){
					found = true;
				}

				if ((PosTableArray(RN, i).x - 1 == Abs) && (PosTableArray(RN, i).y == ord)){
					found = true;
				}

				if ((PosTableArray(RN, i).x == Abs) && (PosTableArray(RN, i).y + 1 == ord)){
					found = true;
				}

				if ((PosTableArray(RN, i).x == Abs) && (PosTableArray(RN, i).y - 1 == ord)){
					found = true;
				}

				if(!found){
					i++;
				}

			}
			printf("%d |",i);
			printf("\n");
			if (IsKataSama(food.Nama, InfoTableArray(RN, i))){
				// pesanan sesuai
				DelCust(i);
				DelOrderan(i);
				TableArray(RN, i).IsFull = false;
				player().Money += food.Harga;
			}else{
				Message="Pesanan tidak sesuai";
				PushFS(&tray(), food);
			}


		}


	}
	else{
		Message="Pelanggan tidak bersebelahan dengan pemain";
	}


}
