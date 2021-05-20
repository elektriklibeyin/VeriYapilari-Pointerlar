//172803036 - MÜCAHİT TOKTAŞ
#include <iostream>


using namespace std;


struct Ogrenci
{
string isim,harfnotu;
int ogrencino,*testnotlari;
double ortalama;
};

 //Struct ile Fonksiyonlarımızı Tanımlıyoruz
void verial(Ogrenci *Ogrnci, int i, int *notlar, int testsayisi);
double notHesapla(Ogrenci *Ogrnci, int i, int testsayisi);
void goster(Ogrenci *Ogrnci, int i);
void sil(Ogrenci *Ogrnci);


int main()
{
    int OgrenciSayisi;
    int testSayisi;

 // Programımız öncelikle kullanıcıdan Öğrenci sayısı ve Test sayısını alıyor,
    cout <<endl;
    cout << "Ogrenci sayisini giriniz: ";
     cin >> OgrenciSayisi;
    cout << "Test sayisini giriniz: ";
     cin >> testSayisi;

 //girilen bilgiler doğrultusunda Struct yapımızdan “Ogrnci” adında bir diziyi öğrenci sayısı uzunluğunda dinamik olarak yaratıyoruz.
    Ogrenci *Ogrnci = new Ogrenci[OgrenciSayisi];

 //“notlar” adında bir integer dizi daha test sayisi uzunluğunda dinamik olarak yaratılıyor.
    int *notlar = new int[testSayisi];

 //Öğrenci sayısı uzunluğunda bir döngü oluşturulur.
    for(int i=0; i<OgrenciSayisi; i++)
    {
        //Her öğrenci için önce veriler alınır;
       verial(Ogrnci,i,notlar,testSayisi);

        //Notlar dizisinin başlangıç Adresi   *testnotlarına tanıtılır ve testnotları pointeri artık notlar arrayinin yerini, dolayısı ile notları bilir.
       Ogrnci[i].testnotlari=&notlar[0];

        //bu fonksiyon double tipte veri döndürmektedir, bu veri arrayimizin ortalamasına atanır.
       Ogrnci[i].ortalama = notHesapla(Ogrnci,i,testSayisi);

        //ortalama ve harf notu console ekranına yazdırılır.
       goster(Ogrnci,i);
    }

    //diziyi sisteme geri veriyoruz.
    sil(Ogrnci);

    return EXIT_SUCCESS;
}

//Verial Fonksiyonumuzun ve diğer fonksiyonlarımızın Struct parametreleri birer işaretçi,
//gönderilen Dinamik arraylerin adreslerini alarak işlemleri gerçekleştiriyoruz.
void verial(Ogrenci *Ogrnci, int i, int *notlar, int testsayisi){

        //Öncelikle öğrenci adı ve numarası alınır
        cout <<endl;
        cout <<i+1<<". Ogrencinin adini giriniz: ";
          cin>>Ogrnci[i].isim;
        cout <<i+1<<". Ogrencinin numarasini giriniz: ";
          cin>>Ogrnci[i].ogrencino;

        //test sayisi uzunluğunda bir döngü oluşturularak test notları alınır.
        int sayac=0;
        while(sayac<testsayisi){
        cout<<i+1<<". Ogrencinin "<<sayac+1<<". test notunu giriniz: ";
        cin>>notlar[sayac];
        sayac++;
        }
}

//Not hesaplama fonksiyonunda “Ogrnci” structının elemanı “testnotları”nın içerisinden notları çekip ortalamasını alıyoruz.
double notHesapla(Ogrenci *Ogrnci, int i,int testsayisi){

    float toplam=0,ortalama=0;
    for(int n=0; n<testsayisi; n++){
        toplam += *(Ogrnci[i].testnotlari+n);
    }

    ortalama = toplam/testsayisi;

    return (ortalama);
}


//Goster fonksiyonunda, ortalama değerine göre harf notu seçimi yapılmakta, harf notu öncelikle Ogrnci->harfnotuna atanmakta ve adından sonuçlar console ekranına yazdırılmaktadır.
void goster(Ogrenci *Ogrnci, int i){

    if(Ogrnci[i].ortalama>=85){
        Ogrnci[i].harfnotu="A";
       }
       else if(Ogrnci[i].ortalama>=75 && Ogrnci[i].ortalama<=84){
        Ogrnci[i].harfnotu="B";
       }
       else if(Ogrnci[i].ortalama>=65 && Ogrnci[i].ortalama<=74){
        Ogrnci[i].harfnotu="C";
       }
       else if(Ogrnci[i].ortalama>=50 && Ogrnci[i].ortalama<=64){
        Ogrnci[i].harfnotu="D";
       }
       else{
        Ogrnci[i].harfnotu="F";
       }

   cout<<" Ortalama: "<< (Ogrnci[i].ortalama);
   cout<<"  Harf Notu: "<< (Ogrnci[i].harfnotu);
   cout<<endl;
}


//Tüm öğrencilerin bilgileri alınıp harfnotu ve ortalamaları yazdırıldıktan sonra diziyi “delete” komutu ile iade ediyoruz.
void sil(Ogrenci *Ogrnci){

   delete[]Ogrnci;
}






