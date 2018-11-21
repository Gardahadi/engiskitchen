/*Nama : Gardahadi
  NIM : 13517144
  Nama file : array.c
  deskripsi : Definisi dan implementasi fungsi primitif untuk tipe data abstrak "array"
*/

#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
	/* I.S. T sembarang */
	/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
{
	return Neff(T);
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}
IdxType GetLastIdx (TabInt T)
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T terakhir */
{
	return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
	/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
	/* yaitu antara indeks yang terdefinisi utk container*/
{
	return (i>=IdxMin && i<=IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i)
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
	/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
	/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (NbElmt(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
	/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
	/* I.S. T sembarang */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
	/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
	/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
	IdxMin satu per satu diakhiri enter */
	/*    Jika N = 0; hanya terbentuk T kosong */
{
	int N,i;
	scanf("%d",&N);
	while (!(N>=0 && N<=MaxNbEl(*T))) {
		scanf("%d",&N);
	}
	MakeEmpty(T);
	for (i=GetFirstIdx(*T); i<=N; i++){
		scanf("%d", &Elmt(*T,i));
		Neff(*T)++;
	}
}
void BacaIsiTab (TabInt * T){
	/* I.S. T sembarang */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
	/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
	/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
	/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
	ElType x;
	IdxType i;
	scanf("%d",&x);
	MakeEmpty(T); i = GetFirstIdx(*T);
	while (x != -9999 && i <= MaxNbEl(*T)) {
		Elmt(*T,i) = x;
		Neff(*T)++; i++;
		scanf("%d",&x);
	}
}
void TulisIsi (TabInt T)
	/* Proses : Menuliskan isi tabel dengan traversal */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
	/*      Jika T kosong : Hanya menulis "Tabel kosong" */
	/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
	Maka tercetak di layar:
	[1]1
	[2]20
	[3]30
	[4]50
	*/
	{
		if (IsEmpty(T)) {
			printf("Tabel kosong\n");
		} else {
			int i;
			for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
				printf("[%d]%d\n",i,Elmt(T,i));
			}
		}
	}
void TulisIsiTab (TabInt T)
	/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
	antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
	di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika tabel kosong : menulis [] */
{

	if (IsEmpty(T)) {
		printf("[]");
	} else {
		int i;
		printf("[");
		for (i = GetFirstIdx(T); i < GetLastIdx(T); i++) {
			printf("%d,",Elmt(T,i));
		}
		printf("%d]",Elmt(T,GetLastIdx(T)));
	}
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
	{
		TabInt X;
		int i;
		Neff(X) = NbElmt(T1);
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
			Elmt(X,i) = Elmt(T1,i) + Elmt(T2,i);
		}
		return X;
	}

TabInt MinusTab (TabInt T1, TabInt T2)
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
	{
		TabInt X;
		int i;
		Neff(X) = NbElmt(T1);
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
			Elmt(X,i) = Elmt(T1,i) - Elmt(T2,i);
		}
		return X;
	}
TabInt KaliTab (TabInt T1, TabInt T2)
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
  TabInt X;
  int i;
  i=1;
  while((i<=Neff(T1)) && (i<=Neff(T2))) {
    Elmt(X,i)=Elmt(T1,i)*Elmt(T2,i);
    Neff(X) = i;
    i++;
  }

  return X;
}


TabInt KaliKons (TabInt Tin, ElType c)
	/* Prekondisi : Tin tidak kosong */
	/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
	{
	  int i;
	  TabInt X;
	  for (i=GetFirstIdx(Tin);i<=Neff(Tin);i++)
	  {
	    Elmt(X,i) = Elmt(Tin,i)*c;
	    Neff(X) = i;
	  }
	  return X;
	}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
	/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
	{
	 /*kamus lokal*/
	   int i,ls;
	 /*algoritma*/
	   i = 1;
	   if(NbElmt(T1) == NbElmt(T2))
	    {
	      while((Elmt(T1,i) == Elmt(T2,i)) && (i < NbElmt(T1)))
	       {
	       	i++;
	       }
	      ls = GetLastIdx(T1);
	      if((i==ls)&&(Elmt(T1,ls) == Elmt(T2,ls)))
	        {
	          return true;
	        }
	      else
	      {
	      	return false;
	      }
	    }
	   else
	   {
	   	return false;
	   }
	}
boolean IsLess (TabInt T1, TabInt T2){
	/* Mengirimkan true jika T1 < T2, */
	/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
	if (NbElmt(T1) < NbElmt(T2)){
		return true; //T1<T2
	}else if (NbElmt(T1) > NbElmt(T2)){
		return false; //T1>T2
	}else if (IsEQ(T1,T2)){
		return false; //T1==T2
	}else{
		int i;
		i = GetFirstIdx(T1);
		while (i<GetLastIdx(T1) && Elmt(T1,i) == Elmt(T2,i)) {
			i++;
		}
		if (Elmt(T1,i) < Elmt(T2,i)) {
			return true; //T1[i] < T2[i]
		}else{
			return false; //T1[i] > T2[i]
		}
	}
}

/* ********** SEARCHING ********** */
/***  Perhatian : Tabel boleh kosong!! ***/
IdxType Search1 (TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
	/* Jika tidak ada, mengirimkan IdxUndef */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
	/* Memakai skema search TANPA boolean */
	if (IsEmpty(T)) {
		return IdxUndef;
	} else {
		int i;
		i = GetFirstIdx(T);
		while (i<GetLastIdx(T) && Elmt(T,i)!=X) {
			i++;
		}
		if (Elmt(T,i) == X) {
			return i;
		}else{
			return IdxUndef;
		}
	}
}
IdxType Search2 (TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
	/* Jika tidak ada, mengirimkan IdxUndef */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
	/* Memakai skema search DENGAN boolean Found */
	if (IsEmpty(T)){
		return IdxUndef;
	}else{
		boolean found; int i,Idx;
		found = false; i = GetFirstIdx(T);
		while (!found && i<=GetLastIdx(T)) {
			if (Elmt(T,i) == X){
				found = true;
				Idx = i;
			}
			i++;
		}
		if (found) {
			return Idx;
		} else {
			return IdxUndef;
		}
	}
}
boolean SearchB (TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
	/* Memakai Skema search DENGAN boolean */
	if (IsEmpty(T)){
		return false;
	}else{
		boolean found; int i;
		found = false; i = GetFirstIdx(T);
		while (!found && i<=GetLastIdx(T)) {
			if (Elmt(T,i) == X){
				found = true;
			}
			i++;
		}
		return found;
	}
}
boolean SearchSentinel (TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
	/* dengan metoda sequential search dengan sentinel */
	/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
	yang tidak dipakai dalam definisi tabel */
	if (IsEmpty(T)){
		return false;
	}else{
		if(!IsEmpty(T)){
			Elmt(T,0) = X;
			int i;
			i = GetLastIdx(T);
			while (Elmt(T,i) != X) {
				i--;
			}
			if (i == 0) {
				return false;
			}else{
				return true;
			}
		}
	}
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan nilai maksimum tabel */
	int i; ElType Max;
	Max = Elmt(T,GetFirstIdx(T));
	//Start Searching dari Elemen Ke-2
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (Elmt(T,i)>Max) {
			Max = Elmt(T,i);
		}
	}
	return Max;
}
ElType ValMin (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan nilai minimum tabel */
	/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
	int i; ElType Min;
	Min = Elmt(T,GetFirstIdx(T));
	//Start Searching dari Elemen Ke-2
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (Elmt(T,i)<Min) {
			Min = Elmt(T,i);
		}
	}
	return Min;
}
IdxType IdxMaxTab (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
	int i,Max,MaxIdx;
	Max = Elmt(T,GetFirstIdx(T));
	MaxIdx = GetFirstIdx(T);
	//Start Searching dari Elemen Ke-2
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (Elmt(T,i)>Max) {
			Max = Elmt(T,i);
			MaxIdx = i;
		}
	}
	return MaxIdx;
}
IdxType IdxMinTab (TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
	int i,Min,MinIdx;
	Min = Elmt(T,GetFirstIdx(T));
	MinIdx = GetFirstIdx(T);
	//Start Searching dari Elemen Ke-2
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (Elmt(T,i)<Min) {
			Min = Elmt(T,i);
			MinIdx = i;
		}
	}
	return MinIdx;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
	/* I.S. Tin terdefinisi, Tout sembarang */
	/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
	/* Proses : Menyalin isi Tin ke Tout */
	MakeEmpty(Tout);
	Neff(*Tout) = NbElmt(Tin);
	int i;
	for (i = GetFirstIdx(Tin); i <= NbElmt(Tin); i++) {
		Elmt(*Tout, i) = Elmt(Tin, i);
	}
}
TabInt InverseTab (TabInt T){
	/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
	/* elemen pertama menjadi terakhir, */
	/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
	/* Tabel kosong menghasilkan tabel kosong */
	TabInt retInvTab;
	Neff(retInvTab) = NbElmt(T);
	int i;
	for (i = GetFirstIdx(T); i <= NbElmt(T); i++) {
		Elmt(retInvTab, Neff(retInvTab)-i+1) = Elmt(T, i);
	}
	return retInvTab;
}
boolean IsSimetris (TabInt T){
	/* Menghasilkan true jika tabel simetrik */
	/* Tabel disebut simetrik jika: */
	/*      elemen pertama = elemen terakhir, */
	/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
	/* Tabel kosong adalah tabel simetris */

	if(IsEmpty(T)) {
		return true;
	}
	else {
		return (IsEQ(InverseTab(T),T));
	}
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T){
	/* I.S. T boleh kosong */
	/* F.S. T elemennya terurut menurun dengan Maximum Sort */
	/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
	/*          tanpa menggunakan tabel kerja */
	if (!IsEmpty(*T)) {
		int i,j,last;
		ElType temp;
		last = GetLastIdx(*T);
		for (i = 1; i < last; i++) {
			ElType Max,MaxIdx;
			Max = Elmt(*T,i);
			MaxIdx = i;
			for (j = i; j <= last; j++) {
				if (Elmt(*T,j)>Max) {
					Max = Elmt(*T,j);
					MaxIdx = j;
				}
			}
			temp = Elmt(*T,MaxIdx);
			Elmt(*T,MaxIdx) = Elmt(*T,i);
			Elmt(*T,i) = temp;
		}
	}
}
void InsSortAsc (TabInt * T){
	/* I.S. T boleh kosong */
	/* F.S. T elemennya terurut menaik dengan Insertion Sort */
	/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
	/*          tanpa menggunakan tabel kerja */
	if (!IsEmpty(*T)) {
		int i,j,key;
		for (i = GetFirstIdx(*T)+1; i <= GetLastIdx(*T); i++) {
			key = Elmt(*T, i);
			j = i-1;
			while (j>=GetFirstIdx(*T) && Elmt(*T,j)>=key) {
				Elmt(*T,j+1) = Elmt(*T,j);
				j--;
			}
			Elmt(*T,j+1) = key;
		}
	}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
	/* Proses: Menambahkan X sebagai elemen terakhir tabel */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/* F.S. X adalah elemen terakhir T yang baru */
	Neff(*T)++;
	Elmt(*T,GetLastIdx(*T)) = X;
}
void AddEli (TabInt * T, ElType X, IdxType i){
	/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
	terhadap elemen yang sudah ada */
	/* I.S. Tabel tidak kosong dan tidak penuh */
	/*      i adalah indeks yang valid. */
	/* F.S. X adalah elemen ke-i T yang baru */
	/* Proses : Geser elemen ke-i+1 s.d. terakhir */
	/*          Isi elemen ke-i dengan X */
	ElType geserEl,tmp;
	geserEl = Elmt(*T,i);
	Elmt(*T,i) = X;
	Neff(*T)++; i++;
	for (i; i <= NbElmt(*T); i++) {
		tmp = Elmt(*T,i);
		Elmt(*T,i) = geserEl;
		geserEl = tmp;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
	/* Proses : Menghapus elemen terakhir tabel */
	/* I.S. Tabel tidak kosong */
	/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	*X = Elmt(*T,GetLastIdx(*T));
	Neff(*T)--;
}
void DelEli (TabInt * T, IdxType i, ElType * X){
	/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
	/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
	/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
	/*          Kurangi elemen efektif tabel */
	int j;
	*X = Elmt(*T,i);
	for (j = i; j < GetLastIdx(*T); j++) {
		Elmt(*T,j) = Elmt(*T,j+1);
	}
	Neff(*T)--;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X){
	/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/*      dan semua elemennya bernilai unik, tidak terurut */
	/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
	jika belum ada elemen yang bernilai X.
	Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
	dan dituliskan pesan "nilai sudah ada" */
	/* Proses : Cek keunikan dengan sequential search dengan sentinel */
	/*          Kemudian tambahkan elemen jika belum ada */
	if (!SearchB(*T,X)) {
		AddAsLastEl(T,X);
	} else {
		printf("nilai sudah ada\n");
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X){
	/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
	/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
	/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
	return Search1(T,X);
}
ElType MaxUrut (TabInt T){
	/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
	/* Mengirimkan nilai maksimum pada tabel */
	return Elmt(T,GetLastIdx(T));
}
ElType MinUrut (TabInt T){
	/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
	/* Mengirimkan nilai minimum pada tabel*/
	return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
	/* I.S. Tabel T tidak kosong, elemen terurut membesar */
	/* F.S. Max berisi nilai maksimum T;
	Min berisi nilai minimum T */
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X){
	/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
	/* Nilai dalam tabel tidak harus unik. */
	/* I.S. Tabel T boleh kosong, boleh penuh. */
	/*      Jika tabel isi, elemennya terurut membesar. */
	/* F.S. Jika tabel belum penuh, menambahkan X. */
	/*      Jika tabel penuh, maka tabel tetap. */
	/* Proses : Search tempat yang tepat sambil geser */
	/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
	if (!IsFull(*T)) {
		int i;
		i = GetLastIdx(*T);
		while (i>=GetFirstIdx(*T) && Elmt(*T,i)>X) {
			Elmt(*T,i+1) = Elmt(*T,i);
			i--;
		}
		i++;
		Elmt(*T,i) = X;
		Neff(*T)++;
	}
}
void Del1Urut (TabInt * T, ElType X){
	/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
	/* I.S. Tabel tidak kosong */
	/* F.S. Jika ada elemen tabel bernilai X , */
	/*      maka banyaknya elemen tabel berkurang satu. */
	/*      Jika tidak ada yang bernilai X, tabel tetap. */
	/*      Setelah penghapusan, elemen tabel tetap kontigu! */
	/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
	/*          Delete jika ada. */
	if (!IsEmpty(*T) && SearchB(*T,X)) {
		DelEli(T,SearchUrut(*T,X),&X);
	}
}
