/* File: jam.c */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#include "boolean.h"
#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S) {
    /* Mengirim true  jika H,M,S dapat membentuk J yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return ((H>=0)&&(H<=23)&&(M>=0)&&(M<=59)&&(S>=0)&&(S<=59));
}


/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS) {
    /* Membentuk sebuah JAM dari komponen-komponennya yang valid */
    /* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
    /*Kamus*/
    JAM J;
    /*Algoritma*/
    Hour(J)=HH;
    Minute(J)=MM;
    Second(J)=SS;
    return J;

}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J) {
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
    /*Kamus*/
    int HH;
    int MM;
    int SS;
    /*Algoritma*/
    do{
        scanf("%d",&HH);
        scanf("%d",&MM);
        scanf("%d",&SS);
        if(!IsJAMValid(HH,MM,SS)){
            printf("Jam tidak valid\n");
        }
    }while (!IsJAMValid(HH,MM,SS));
    *J = MakeJAM(HH,MM,SS);
}
   
void TulisJAM (JAM J) {
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
    printf("%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JAMToDetik (JAM J) {
    /* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*HH + 60*MM + SS */
    /* Nilai maksimum = 3600*23+59*60+59 */
    return (Hour(J)*3600 + Minute(J)*60 + Second(J));
}

JAM DetikToJAM (int N) {
    /* Mengirim  konversi detik ke JAM */
    /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
    mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
    N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
    /*Kamus*/
    int N_temp;
    /* Algoritma */
    if(N>=86400){
        N_temp = N % 86400;
        return MakeJAM((N_temp/3600),((N_temp%3600)/60),((N_temp%60)));
    }
    return MakeJAM((N/3600),((N%3600)/60),(N%60));
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2) {
    /* Mengirimkan true jika J1=J2, false jika tidak */
    return (JAMToDetik(J1)==JAMToDetik(J2));
}
boolean JNEQ (JAM J1, JAM J2){
    /* Mengirimkan true jika J1 tidak sama dengan J2 */
    return !JEQ(J1,J2);
}
boolean JLT (JAM J1, JAM J2) {
    return (JAMToDetik(J1)<JAMToDetik(J2));
}
boolean JGT (JAM J1, JAM J2) {
    /* Mengirimkan true jika J1>J2, false jika tidak */
     return (JAMToDetik(J1)>JAMToDetik(J2));
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J) {
    /* Mengirim 1 detik setelah J dalam bentuk JAM */
    /*Algoritma*/
    return NextNDetik(J,1);
}
JAM NextNDetik (JAM J, int N) {
    /* Mengirim N detik setelah J dalam bentuk JAM */
    /*Kamus*/
    int N_temp;
    /*Algoritma*/
    N_temp = JAMToDetik(J);
    N_temp = N_temp + N;
    return DetikToJAM(N_temp);
}
JAM PrevDetik (JAM J) {
    /* Mengirim 1 detik sebelum J dalam bentuk JAM */
    return PrevNDetik(J,1);
}
JAM PrevNDetik (JAM J, int N) {
    /* Mengirim N detik sebelum J dalam bentuk JAM */

    /*Algoritma*/
    if((JAMToDetik(J)-N)<0){
        return DetikToJAM((JAMToDetik(J)+86400-N));
    }
    return DetikToJAM((JAMToDetik(J)-N));
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh) {
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
    if (JGT(JAw,JAkh)){
        return (JAMToDetik(JAkh)+86400-JAMToDetik(JAw));
    }
    return (JAMToDetik(JAkh)-JAMToDetik(JAw));
}