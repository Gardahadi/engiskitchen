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
	int Abs;
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

		Abs = -1;
		ord = -1;

    if(Room(RN, ordinat(), absis())=='T'){
			Abs = ordinat();
			ord = absis();
		}

		if(Room(RN, ordinat()+1, absis())=='T'){
			Abs = ordinat()+1;
			ord = absis();
		}

		if(Room(RN, ordinat()-1, absis())=='T'){
			Abs = ordinat()-1;
			ord = absis();
		}

		if(Room(RN, ordinat(), absis()+1)=='T'){
			Abs = ordinat();
			ord = absis()+1;
		}

		if(Room(RN, ordinat(), absis()-1)=='T'){
			Abs = ordinat();
			ord = absis()-1;
		}
    if ((Abs!=-1)&&(ord!=-1))
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
  //printf("Test1\n");
  bisadimasak = false;
  price = 0;
  PopBS(&S,&X);
  if(IsKataSama(X.Name,Akar(T).Name))
    {
      price +=30;
      bisadimasak = true;
      //printf("Test2\n");
      while((Left(T) != Nil || Right(T)!=Nil) && bisadimasak && !IsEmptyBS(S))
      {
        //printf("Test3\n");
        PopBS(&S,&X);
        if(Left(T)==Nil && Right(T)!= Nil)
        {
          if(IsKataSama(X.Name,Akar(Right(T)).Name))
          {
            T = Right(T);
            //printf("Test4\n");
            price +=30;
            bisadimasak = true;
          }
          else
          //printf("Test5\n");
          {bisadimasak = false;}
        }
        else if(Right(T)==Nil && Left(T) != Nil)
        {
          //printf("Test6\n");
          if(!IsEmptyBS(S)){
            if(IsKataSama(X.Name,Akar(Left(T)).Name))
            {
              //printf("Test7\n");
              T = Left(T);
              price +=30;
              bisadimasak = true;
            }
            else
            //printf("Test8\n");
            {bisadimasak = false;}
          }
          else {
            bisadimasak = true;
          }
        }
        else
        {
          if(IsKataSama(X.Name,Akar(Left(T)).Name))
          {
            //printf("Test9\n");
            T = Left(T);
            price +=30;
            bisadimasak = true;
          }
          else if(IsKataSama(X.Name,Akar(Right(T)).Name))
          {
            //printf("Test10\n");
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

    if(Left(T) == Nil && Right(T)==Nil && bisadimasak && IsEmptyBS(S))
    {
      //printf("Test11\n");
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
