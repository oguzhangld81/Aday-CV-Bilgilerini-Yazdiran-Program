#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adayBilgi{ //adaylara ait bilgilerin degiskenlerini ve onlarin turlerini belirledim.
    char * isimSoyisim;
    char * universite;
    int yas;
    int YDS;
    float GANO;
    int telefonNo;
    float kilo;
    int boy;
    int dogumTarihi;//(YIL)
    char * dogumYeri;
};

struct mulakatKayit{
    char * mulakatiYapan;
    int * mulakatTarih;
    struct adayBilgi adaylar; //"NESTED" (icice) yapisi olusturdum.
};

//prototipleri bir arada yazdim;
void adayBilgileriniGir(struct adayBilgi *);
void adayBilgileriniYazdir(struct adayBilgi *);
float kiloBoyOraniBul(struct adayBilgi *, int);
int ydsEnYuksekveDusukNot(struct adayBilgi *, int);
float ganoEnYuksekveDusukNot(struct adayBilgi *adaylar, int);
int stringUzunluguBul(struct adayBilgi *);
int stringUzunluguBul01(struct adayBilgi *adaylar, int);
void menu();
// ------

void adayBilgileriniGir(struct adayBilgi *adaylar){ //gosterici tanimlama operatoru (*) ile fonksiyonlarimi tanimladim.

    //sirayla adaylara ait bilgileri girdim:
    adaylar[0].isimSoyisim = "Oguzhan Geldi";
    adaylar[0].universite = "Necmettin Erbakan Universitesi";
    adaylar[0].yas = 25;
    adaylar[0].YDS = 420;
    adaylar[0].GANO =3.50;
    adaylar[0].telefonNo = 123456;
    adaylar[0].kilo = 70;
    adaylar[0].boy = 175;
    adaylar[0].dogumTarihi = 2000;
    adaylar[0].dogumYeri = "Duzce";


    adaylar[1].isimSoyisim = "Elif Mertoglu";
    adaylar[1].universite = "Gazi Universitesi";
    adaylar[1].yas = 24;
    adaylar[1].YDS = 410;
    adaylar[1].GANO =3.10;
    adaylar[1].telefonNo = 123456;
    adaylar[1].kilo = 58;
    adaylar[1].boy = 165;
    adaylar[1].dogumTarihi = 2001;
    adaylar[1].dogumYeri = "Duzce";

    adaylar[2].isimSoyisim = "Bugra Ugurlu";
    adaylar[2].universite = "Duzce Universitesi";
    adaylar[2].yas = 24;
    adaylar[2].YDS = 350;
    adaylar[2].GANO =2.75;
    adaylar[2].telefonNo = 123456;
    adaylar[2].kilo = 75;
    adaylar[2].boy = 185;
    adaylar[2].dogumTarihi = 2000;
    adaylar[2].dogumYeri = "Duzce";

    adaylar[3].isimSoyisim = "Ahmet Kilic";
    adaylar[3].universite = "Orta Dogu Teknik Universitesi";
    adaylar[3].yas = 25;
    adaylar[3].YDS = 460;
    adaylar[3].GANO =3.50;
    adaylar[3].telefonNo = 123456;
    adaylar[3].kilo = 78;
    adaylar[3].boy = 178;
    adaylar[3].dogumTarihi = 1999;
    adaylar[3].dogumYeri = "Ankara";

    adaylar[4].isimSoyisim = "Melike Bal";
    adaylar[4].universite = "Istanbul Teknik Universitesi";
    adaylar[4].yas = 26;
    adaylar[4].YDS = 385;
    adaylar[4].GANO =3.25;
    adaylar[4].telefonNo = 0123456;
    adaylar[4].kilo = 62;
    adaylar[4].boy = 168;
    adaylar[4].dogumTarihi = 1998;
    adaylar[4].dogumYeri = "Istanbul";
}

void mulakatiYapaninBilgileri(struct mulakatKayit *mulakatSahibi){
    mulakatSahibi[0].mulakatiYapan="U.OZIC";
    mulakatSahibi[0].mulakatTarih= 2020;
}

void mulakatiYapaninBilgileriYazdir(struct mulakatKayit *mulakatSahibi){

    int i=0;

    for(i=0;i<1;i++){
        printf("Mulakati Yapanin Ismi: %s\n", mulakatSahibi[i].mulakatiYapan);
        printf("Mulakat Tarihi: %i\n", mulakatSahibi[i].mulakatTarih);
        printf("\n\n");
    }
}//geriye birsey donmeyeceginden return ifadesi yok!

void adayBilgileriniYazdir(struct adayBilgi *adaylar){ //aday bilgilerini yazdiracak programim:
    int i=0;//dongu sayacim.

    for(i=0;i<5;i++){ //sayac kosulum.
        printf("Isim Soyisim: %s\n",adaylar[i].isimSoyisim);
        printf("Universite: %s\n",adaylar[i].universite);
        printf("Yas: %d\n",adaylar[i].yas);
        printf("YDS: %d\n",adaylar[i].YDS);
        printf("GANO: %f\n",adaylar[i].GANO);
        printf("Telefon no: %d\n",adaylar[i].telefonNo);
        printf("Kilo: %f\n",adaylar[i].kilo);
        printf("Boy: %d\n",adaylar[i].boy);
        printf("Dogum tarihi: %d\n",adaylar[i].dogumTarihi);
        printf("Dogum yeri: %s\n",adaylar[i].dogumYeri);
        printf("\n\n");
    }
}

float kiloBoyOraniBul(struct adayBilgi *adaylar, int maxOrMin){
    int i=0;
    float oranAktif=0,oranDondur;

    if(maxOrMin==1) oranDondur=0; //girilen deger 1 ise max deger, 0 ise minimum degeri ceviren kod
    else oranDondur = 999;

    for(i=0;i<5;i++){ //for dongusu ile sartlari belirledim.
        oranAktif=(adaylar[i].kilo)/(adaylar[i].boy); //orani matematiksel olarak hesapladim.

        switch(maxOrMin){
        case 1:
            if(oranAktif>oranDondur) oranDondur=oranAktif;//kilo/boy orani en buyuk:
            break;
        default:  //"default" ifadesi "else" ifadesine benzer.
            if(oranAktif<oranDondur) oranDondur=oranAktif;//kilo/boy orani en kucuk:
        }
    }
    return oranDondur; //geriye istenilen orani dondurur.
}

int ydsEnYuksekveDusukNot(struct adayBilgi *adaylar, int maxOrMin){
    int i=0;
    int max=0;
    int notAktif=0, notDondur;

    if(maxOrMin==1) notDondur=0;
    else notDondur=999;

    for(i=0;i<5;i++){
        notAktif=(adaylar[i].YDS);

        switch(maxOrMin){
        case 1:
            if(notAktif>notDondur) notDondur=notAktif;
            break;
        default:
            if(notAktif<notDondur) notDondur=notAktif;
        }
    }
    return notDondur;
}


float ganoEnYuksekveDusukNot(struct adayBilgi *adaylar, int maxOrMin){
    int i=0;
    float notAktif=0, notDondur;

    if(maxOrMin==1) notDondur=0;
    else notDondur=999;

    for(i=0;i<5;i++){
        notAktif=adaylar[i].GANO;

        switch(maxOrMin){
        case 1:
            if(notAktif>notDondur) notDondur=notAktif;
            break;
        default:
            if(notAktif<notDondur) notDondur=notAktif;
        }
    }
    return notDondur;
}

int stringUzunluguBul(struct adayBilgi *adaylar){
    int i=0;
    int uzunluk=0;
    for(i=0;i<5;i++){
        uzunluk=strlen(adaylar[i].isimSoyisim); //strlen ifadesi uzunluk olcmeye yarayan bir fonksiyondur ve kutuphanesi string.h dir.
        printf("%s kisisinin isminin uzunlugu: %d\n",adaylar[i].isimSoyisim,uzunluk-1);
        //uzunluk - 1 yaptim cunku sadece "uzunluk" yapinca string uzunlugu +1 fazla cikiyordu sebebini arastirdim ama bulamadim.
    }
    return uzunluk;
}

int stringUzunluguBul01(struct adayBilgi *adaylar, int maxOrMin){
    int i=0;
    int uzunlukAktif=0, uzunlukDondur=0;

    if(maxOrMin==1) uzunlukDondur=0;
    else uzunlukDondur=999;

    for(i=0;i<5;i++){
        uzunlukAktif=strlen(adaylar[i].isimSoyisim);

        switch(maxOrMin){
    case 1:
        if(uzunlukAktif>uzunlukDondur) uzunlukDondur=uzunlukAktif;
        break;
    default:
        if(uzunlukAktif<uzunlukDondur) uzunlukDondur=uzunlukAktif;
        }
    }
    return uzunlukDondur-1;
}


int main(){
    int i=0, secim; //dongu sayacim ve degiskenlerimi tanimladim.
    struct adayBilgi mulakatAdaylar[5]; //5 aday var.
    struct mulakatKayit mulakatYapan[1]; //mulakati yapan 1 kisi.

    mulakatiYapaninBilgileri(mulakatYapan);
    adayBilgileriniGir(mulakatAdaylar);
    menu();

    printf("\nMenuden seciminizi yapiniz (1-7): ");
    scanf("%d",&secim);
    printf("\n");

    switch(secim){ //switch-case yapisi ile hazirladigim menuye deger gonderiyorum.
    case 1: // 1 numarali secim.
        mulakatiYapaninBilgileriYazdir(mulakatYapan);
        adayBilgileriniYazdir(mulakatAdaylar);
        printf("\n\n");
        break;

    case 2: // 2 numarali secim.
        printf("En yuksek kilo/boy orani: %f\n",kiloBoyOraniBul(mulakatAdaylar,1));
        printf("En dusuk kilo/boy orani: %f\n",kiloBoyOraniBul(mulakatAdaylar,0));
        printf("\n\n");
        break;

    case 3: // 3 numarali secim.
        printf("En yuksek YDS puani: %d\n",ydsEnYuksekveDusukNot(mulakatAdaylar,1));
        printf("En dusuk YDS puani: %d\n",ydsEnYuksekveDusukNot(mulakatAdaylar,0));
        printf("\n\n");
        break;

    case 4: // 4 numarali secim.
        printf("En yuksek GANO notu: %f\n",ganoEnYuksekveDusukNot(mulakatAdaylar,1));
        printf("En dusuk GANO notu: %f\n",ganoEnYuksekveDusukNot(mulakatAdaylar,0));
        printf("\n\n");
        break;

    case 6: // 6 numarali secim.
        stringUzunluguBul(mulakatAdaylar);
        printf("En yuksek karakter: %d\n",stringUzunluguBul01(mulakatAdaylar,1));
        printf("En dusuk karakter: %d\n\n",stringUzunluguBul01(mulakatAdaylar,0));
        break;
    }
    return main(); //menuden bir secim yaptiktan sonra menu tekrar kullanici onune gelir.

}

void menu(){ //menunun tasarimini olusturan programim.
    printf("*******************************************************************\n");
    printf("*********       LUTFEN MENUDEN SECIM YAPINIZ!           ***********\n");
    printf("*******************************************************************\n");
    printf("** 1.Tum adaylarin bilgisini ekrana yazdir.                      **\n");
    printf("** 2.Kilo/Boy orani en yuksek ve en dusuk.                       **\n");
    printf("** 3.YDS notu en yuksek ve en dusuk.                             **\n");
    printf("** 4.GANO'su en yuksek ve en dusuk.                              **\n");
    printf("** 5.Isminin bas harfi alfabede en onde/sonda olan(YOK).         **\n");
    printf("** 6.Isminin karakter sayisi en fazla/az olan aday.              **\n");
    printf("** 7.Isminin karakter sayisi en az olan adayin tersten ismi(YOK).**\n");
    printf("*******************************************************************\n");
}
