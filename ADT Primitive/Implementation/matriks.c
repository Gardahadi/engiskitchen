/* NIM : 13517144
   Nama : Gardahadi
   Nama file : matriks.c
   */

#include <stdio.h>
#include "ADT Header/matriks.h"
#include "boolean.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
}

boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  if ((i<=BrsMax) && (i>=BrsMin) && (j>=KolMin) && (j<=KolMax)) {
    return true;
  }
  else {
    return false;
  }
}


indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}



indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}


indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  return NBrsEff(M);
}


indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  if ((i<= NBrsEff(M)) && (j<=NKolEff(M)) && IsIdxValid(i,j)) {
    return true;
  }
  else {
    return false;
  }
}


ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
  return Elmt(M,i,i);
}



/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  int i,j;
  NBrsEff(*MHsl) = NBrsEff(MIn);
  NKolEff(*MHsl) = NKolEff(MIn);
  for (i=1;i<=NBrsEff(MIn);i++){
    for (j=1;j<=NKolEff(MIn);j++){
      Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
    }
  }
}



/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  int i,j,X;
  MakeMATRIKS(NB,NK,M);
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
  for (i=GetFirstIdxBrs(*M);i<=NB;i++){
    for(j=GetFirstIdxKol(*M);j<=NK;j++){
      scanf("%s",&X);
      Elmt(*M,i,j)=X;
    }
  }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  int i,j;
  //Membuat border a


  for (i=1;i<=NBrsEff(M);i++) {


    for (j=1;j<=NKolEff(M);j++) {

      if ((j==NKolEff(M)) && (i!=NBrsEff(M))) {
        printf(" %c |\n",Elmt(M,i,j));
      }
      else if ((j==NKolEff(M)) && (i==NBrsEff(M))) {
        printf(" %c |",Elmt(M,i,j));
      }
      else {
        printf("%s ",Elmt(M,i,j));
      }
    }
  }
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
  int i,j;
  MATRIKS X;
  NBrsEff(X) = NBrsEff(M1);
  NKolEff(X) = NKolEff(M1);
  for (i=1;i<=NBrsEff(M1);i++) {
    for (j=1;j<=NKolEff(M1);j++) {
      Elmt(X,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
    }
  }
  return X;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
  int i,j;
  MATRIKS X;
  NBrsEff(X) = NBrsEff(M1);
  NKolEff(X) = NKolEff(M1);
  for (i=1;i<=NBrsEff(M1);i++) {
    for (j=1;j<=NKolEff(M1);j++) {
      Elmt(X,i,j) = Elmt(M1,i,j)-Elmt(M2,i,j);
    }
  }
  return X;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
  int i,j,k;
  MATRIKS X;
  MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&X);
  for (i=1;i<=NBrsEff(X);i++) {
    for (j=1;j<=NKolEff(X);j++) {
      Elmt(X,i,j) = 0;
      for (k=1;k<=NKolEff(M1);k++){
        Elmt(X,i,j) = Elmt(X,i,j) + (Elmt(M1,i,k) * Elmt(M2,k,j));
      }
    }
  }
  return X;
}


MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  MATRIKS A;
  int i,j;
  NBrsEff(A) = NBrsEff(M);
  NKolEff(A) = NKolEff(M);
  for (i=1;i<=NBrsEff(M);i++) {
    for (j=1;j<=NKolEff(M);j++) {
      Elmt(A,i,j) = X * Elmt(M,i,j);
    }
  }
  return A;
}


void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
  int i,j;
    for (i=1;i<=NBrsEff(*M);i++) {
      for (j=1;j<=NKolEff(*M);j++) {
        Elmt(*M,i,j) = K * Elmt(*M,i,j);
      }
    }
}




/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxBrs(M1) != GetLastIdxBrs(M2)) || (NBElmt(M1) != NBElmt(M1))) {
  return false;
}else{
  indeks i,j;
  boolean eqEl=true;
  i = GetFirstIdxBrs(M1);
  while (eqEl && i <= GetLastIdxBrs(M1)) {
    j = GetFirstIdxKol(M1);
    while (eqEl && j <= GetLastIdxKol(M1) ) {
      if (Elmt(M1,i,j)!=Elmt(M2,i,j)) {
        eqEl = false;
      }else{
        j++;
      }
    }
    if (eqEl) {
      i++;
    }
  }
  return eqEl;
  }
}



boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
  boolean found;
  int i,j;
  i = 1;
  j=1;
  found = false;
  if (NBElmt(M1)!=NBElmt(M2)) {
    return true;
  }
  else {
    while ((i<=NBrsEff(M1)) && (!found) ) {
      while ((j<=NKolEff(M1)) && (!found)) {
        if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
          found = true;
        }
        j++;
      }
    i++;
    }
  }
  if(found) {
    return true;
  }
  else {
    return false;
  }
}


boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
  if ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NBrsEff(M2))) {
    return true;
  }
  else {
    return false;
  }
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  return NKolEff(M) * NBrsEff(M);
}



/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
  if ((NBrsEff(M) == NKolEff(M)) && (NBElmt(M)>0)) {
    return true;
  }
  else {
    return false;
  }
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
  boolean found;
  int i,j;
  i=1;
  j=1;
  found = false;
  while ((!found) && (i<=NBrsEff(M))) {
    while ((!found) && (j<=NKolEff(M))) {
      if (Elmt(M,i,j) != Elmt(M,j,i)) {
        found = true;
      }
      j++;
    }
    i++;
  }
  if (found) {
    return false;
  }
  else {
    return true;
  }
}



boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  boolean found;
  int i,j;
  i=1;
  j=1;
  found = false;
  while ((!found) && (i<=NBrsEff(M))) {
    while ((!found) && (j<=NKolEff(M))) {
      if (Elmt(M,i,i) != 1) {
        found = true;
      }
      if((Elmt(M,i,j) != 0) && (j != i))  {
        found = true;
      }
      j++;
    }
  i++;
  }
  if (found) {
    return false;
  }
  else {
    return true;
  }

}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  int thresh, count, i, j;
  count = 0;
  thresh = NBElmt(M) / 20;
  for (i=1;i<=NBrsEff(M);i++) {
    for (j=1;j<=NKolEff(M);j++) {
      if(Elmt(M,i,j)==0) {
        count++;
      }
    }
  }
  if (count>thresh) {
    return true;
  }
  else {
    return false;
  }

}


MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
  int i,j;
  MATRIKS X;
  NBrsEff(X) = NBrsEff(M);
  NKolEff(X) = NKolEff(M);
  for (i=1;i<=NBrsEff(M);i++) {
    for (j=1;j<=NKolEff(M);j++) {
      Elmt(X,i,j) = Elmt(M,i,j) * -1;
    }
  }
  return X;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
  float ratio;
  float det;
  float X[BrsMax+1][KolMax+1];
  int i,j;
  if(NBrsEff(M) == 2){
    det = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)) -
    Elmt(M, GetFirstIdxBrs(M), GetLastIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetFirstIdxKol(M));
    return det;
    }
  else {
    //inisialisasi X
    for (i = GetFirstIdxBrs(M); i<= GetLastIdxBrs(M);i++) {
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        X[i][j] = (float)Elmt(M, i, j);
      }
    }
    //Melakukan operasi baris Elementer untuk mendapatkan bentuk segitiga bawah
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
        if (j > i){
          ratio = X[j][i] / X[i][i];
          for (indeks k = GetFirstIdxBrs(M); k <= GetLastIdxBrs(M); k++){
            X[j][k] -= ratio * X[i][k];
          }
        }
      }
    }
    det = 1;
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      det *= X[i][i];
    }
    if (det == 0){
    return 0;
    }
    else {
      return det;
    }
  }
}



void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
  int i,j;
  for (i=1;i<=NBrsEff(*M);i++) {
    for (j=1;j<=NKolEff(*M);j++) {
      Elmt(*M,i,j) = Elmt(*M,i,j) * -1;
    }
  }
}


void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
  int i,j;
  MATRIKS X;
  NBrsEff(X) = NBrsEff(*M);
  NKolEff(X) = NKolEff(*M);
  for (i=1;i<=NBrsEff(*M);i++) {
    for (j=1;j<=NKolEff(*M);j++) {
      Elmt(X,i,j) = Elmt(*M,j,i);
    }
  }
  *M = X;
}
