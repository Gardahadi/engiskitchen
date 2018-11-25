/*
NIM/Nama  : 13517147/Rika Dewi
Nama file : point.c
Topik     : Review konsep dasar
Tanggal   : 9 September 2018
Deskripsi : ADT Point
*/

#include "../ADT Header/point.h"
#include <stdio.h>
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
    /* Membentuk sebuah POINT dari komponen-komponennya */
    //KAMUS
    POINT p;
    //ALGORITMA
    Absis(p)=X;
    Ordinat(p)=Y;
    return p;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
       POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
    /* Contoh: 1 2
       akan membentuk POINT <1,2> */
    /* I.S. Sembarang */
    /* F.S. P terdefinisi */
    //KAMUS
    float x; //absis
    float y; //ordinat
    //ALGORITMA
    scanf ("%f %f", &x, &y);
    *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
       tanpa spasi, enter, atau karakter lain di depan, belakang,
       atau di antaranya
       Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */
    //KAMUS
    //ALGORITMA
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean Equivalen (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    //KAMUS
    //ALGORITMA
    return ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

boolean NEquivalen (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 tidak sama dengan P2 */
    //KAMUS
    //ALGORITMA
    return (!Equivalen(P1,P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    /* Menghasilkan true jika P adalah titik origin */
    //KAMUS
    //ALGORITMA
    return (IsOnSbX(P)&&IsOnSbY(P));
}
boolean IsOnSbX (POINT P){
    /* Menghasilkan true jika P terletak Pada sumbu X */
    //KAMUS
    //ALGORITMA
    return (Ordinat(P)==0);
}

boolean IsOnSbY (POINT P){
    /* Menghasilkan true jika P terletak pada sumbu Y */
    //KAMUS
    //ALGORITMA
    return (Absis(P)==0);
}
int Kuadran (POINT P){
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    /* Prekondisi : P bukan titik origin, dan P tidak terletak di salah satu sumbu */
    //KAMUS
    //ALGORITMA
    if (Absis(P)>0){
        if (Ordinat(P)>0){
            return 1;
        }
        else{
            return 4;
        }
    }else{
        if (Ordinat(P)>0){
            return 2;
        }
        else{
            return 3;
        }
    }
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    /* Mengirim salinan P dengan absis ditambah satu */
    //KAMUS
    //ALGORITMA
    return MakePOINT(Absis(P)+1,Ordinat(P));
}

POINT NextY (POINT P){
    /* Mengirim salinan P dengan ordinat ditambah satu */
    //KAMUS
    //ALGORITMA
    return MakePOINT(Absis(P),Ordinat(P)+1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    //KAMUS
    //ALGORITMA
    return MakePOINT(Absis(P)+ deltaX,Ordinat(P)+ deltaY);
}
POINT MirrorOf (POINT P, boolean SbX){
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
    /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    //KAMUS
    //ALGORITMA
    if (SbX){
        return MakePOINT(Absis(P),Ordinat(P)*-1);
    }else{
        return MakePOINT(Absis(P)*-1,Ordinat(P));
    }
}

float Jarak0 (POINT P){
    /* Menghitung jarak P ke (0,0) */
    //KAMUS
    //ALGORITMA
    return sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
    /* Menghitung jarak antara titik P1 dan P2 */
    /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
    /* Tuliskan spec fungsi yang lebih tepat. */
    //KAMUS
    POINT P;
    //ALGORITMA
    Absis(P) = Absis(P1) - Absis(P2);
    Ordinat(P) = Ordinat(P1)-Ordinat(P2);
    return Jarak0(P);
}

void Geser (POINT *P, float deltaX, float deltaY){
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    //KAMUS
    //ALGORITMA
    *P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P){
    /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
    /* Proses : P digeser ke sumbu X. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    //KAMUS
    //ALGORITMA
    Ordinat(*P)=0;
}

void GeserKeSbY (POINT *P){
    /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    /* Proses : P digeser ke sumbu Y. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    //KAMUS
    //ALGORITMA
    Absis(*P)=0;
}

void Mirror (POINT *P, boolean SbX){
    /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    /* Jika SbX true maka dicerminkan terhadap sumbu X */
    /* Jika SbX false maka dicerminkan terhadap sumbu Y */
    //KAMUS
    //ALGORITMA
    *P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut){
    /* I.S. P terdefinisi */
    /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    //asumsi diputar berlawanan arah jarum jam
    //KAMUS
    float x;//absis setelah rotasi
    float y;//ordinat setelah ditransformasi
    //ALGORITMA
    Sudut = M_PI/180 * Sudut; //ubah ke radian
    x = Absis (*P) * cos(Sudut) - Ordinat(*P) * sin (Sudut);
    y = Ordinat(*P) * cos(Sudut) + Absis(*P) * sin (Sudut);
    Absis (*P)=x;
    Ordinat(*P)=y;
}
