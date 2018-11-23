#include "../restoran.h"

void Masak(BSTACK S, FOOD *F,boolean *valid);
/*Mengecek isi Stack di hand sesuai dengan resep tree. Jika valid maka akan menghasilkan FOOD*/

void Recipe ()
/*Menampilkan Resep*/
{
  PrintTreeResep(pohonresep(),2);
}

void Put()
/*Menaruh isi stack dari Hand ke Tray lalu diproses untuk menghasilkan Food Stack jika bahan sesuai resep*/
{
  //KAMUS
	int abs;
	int ord;
	int i;
  BSTACK TempStack,TempStackRev;
  BAHAN X;
  boolean valid;
  FOOD F;

  /*Algoritma*/
  if (RN != 4){
    printf("Anda sedang tidak berada di dapur\n");
  }
  else /*Player berada di dapur*/
  {
    //Mengecek apakah tray/kompor bersebelahan dengan pemain

		abs = -1;
		ord = -1;

		if(Room(RN, absis(), ordinat())=='T'){
			abs = absis();
			ord = ordinat();
		}

		if(Room(RN, absis()+1, ordinat())=='T'){
			abs = absis()+1;
			ord = ordinat();
		}

		if(Room(RN, absis()-1, ordinat())=='T'){
			abs = absis()-1;
			ord = ordinat();
		}

		if(Room(RN, absis(), ordinat()+1)=='T'){
			abs = absis();
			ord = ordinat()+1;
		}

		if(Room(RN, absis(), ordinat()-1)=='T'){
			abs = absis();
			ord = ordinat()-1;
		}
    if ((abs!=-1)&&(ord!=-1))
    {
      //tray dapat diakses oleh pemain
      CreateEmptyBS(&TempStack);
      CreateEmptyBS(&TempStackRev);
      TempStack = hand();
      while(!IsEmptyBS(TempStack))
      {
        PopBS(&TempStack,&X);
        PushBS(&TempStackRev,X); //Membalikkan isi BahanStack agar bisa diproses dari akar tree resep
      }
      Masak(TempStackRev,&F,&valid);
      if(valid)
        {
          PushFS(&tray(),F);
          CreateEmptyBS(&hand());
        }
    }
    else
    {
        printf("Anda terlalu jauh dari tray\n");
    }
  }
}

void Masak(BSTACK S, FOOD *F,boolean *valid)
/*Mengecek isi Stack di hand sesuai dengan resep tree. Jika valid maka akan menghasilkan FOOD*/
{
  BinTree T;
  BAHAN X;
  int price;
  boolean bisadimasak;

  T= pohonresep();
  bisadimasak = false;
  price = 0;
  PopBS(&S,&X);
  if(IsKataSama(X.Name,Akar(T).Name))
    {
      price +=30;
      bisadimasak = true;
      while((Left(T) != Nil || Right(T)!=Nil) && bisadimasak)
      {
        PopBS(&S,&X);
        if(Left(T)==Nil)
        {
          if(IsKataSama(X.Name,Akar(Right(T)).Name))
          {
            T = Right(T);
            price +=30;
            bisadimasak = true;
          }
          else
          {bisadimasak = false;}
        }
        else if(Right(T)==Nil)
        {
            if(IsKataSama(X.Name,Akar(Left(T)).Name))
            {
              T = Left(T);
              price +=30;
              bisadimasak = true;
            }
            else
            {bisadimasak = false;}
        }
        else
        {
          if(IsKataSama(X.Name,Akar(Left(T)).Name))
          {
            T = Left(T);
            price +=30;
            bisadimasak = true;
          }
          else if(IsKataSama(X.Name,Akar(Right(T)).Name))
          {
            T = Right(T);
            price +=30;
            bisadimasak = true;
          }
          else
          {
            bisadimasak = false;
          }
        }
      }
    }

    if(Left(T) == Nil && Right(T)==Nil && bisadimasak)
    {
      (*F).Harga = price;
      (*F).Nama = Akar(T).Name;
      *valid = true;
    }
    else
    {
      *valid = false;
      printf("Tidak dapat membuat makanan\n");
    }

}
