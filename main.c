#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// #DEF?NE ?LE SAB?T TANIMLARI

#define bolum "Bilgisayar Muhendisligi"
#define yil 1
#define donem "1.yariyil"
#define kredi 36

// Dosyalar
FILE *OgrDosya, *DersDosya, *KayitDosya, *OgrenciYedek, *DersYedek;
int i=0;
int i2=0;
int sayac;

// STRUCTLAR
struct ogrenciKayit{
	int no;
	char ad[50], soyad[50];
}ogr;

struct dersler{
   	char dersAdi[30];
    int dersKodu;
    int akts;
}ders;

struct dersKayit{
	int basariNotu;
}kayit;

int secim;
//      FONKS?YONLAR

// Ogrenci fonksiyonlari 
void ogrenci_islemleri_menu(void);
void ogrenci_kayit(void);
void ogrenci_arama(void);
void ogrenci_listeleme(void);
void ogrenci_sil(void);

// Ders fonksiyonlari
void ders_islemleri_menu(void);
void ders_kayit(void);
void ders_arama(void);
void ders_listeleme(void);
void ders_sil(void);

// Ders Kayit fonksiyonlari

void ders_sec(void);
	


int main() {
	system("color b"); 
do{
	system("cls");
	printf("\t\tMENU \n1- Ogrenci Islemleri \n2- Ders Islemleri \n3- Ders Kayit Islemeri \n4- Cikis \n\nLutfen islemi seciniz...");
	secim = getch() ;
	if(secim == '1'){
		system("cls");
		ogrenci_islemleri_menu();
	   }
	
	
	else if(secim == '2'){
		system("cls");
		ders_islemleri_menu();
		
	}
	
	else if(secim == '3'){
		system("cls");
		printf("\t\t Ders Kayit Ekrani"); 
		ders_sec();
		
	}
	
	else if(secim == '4'){
		return 0;
	}
	
	else {
		system("cls");
		printf("Hatali Giris..."); 
	}
	
	}while(1);

 return 0;
}

// menu fonksiyonlari 
void ogrenci_islemleri_menu(){
	system("cls"); 
	printf("\t\tOgrenci Islem Menusu \n1- Ogrenci Kayit \n2- Ogrenci Arama \n3- Ogrenci Listele \n4- Ogrenci Kayit Sil \n\nLutfen islemi seciniz...\nAna Menuye Donmek Icin ESC tusuna Basiniz. \n ");
       secim = getch(); 
	   switch(secim){
	   	case '1':{
	   		system("cls"); 
	   		ogrenci_kayit();
	   		getch();
	   		return ogrenci_islemleri_menu();
	   		break;
		   }
		case '2':{
			system("cls"); 
			ogrenci_arama();
			getch();
			return ogrenci_islemleri_menu();
			break;
		   }
		case '3':{
			system("cls");
			ogrenci_listeleme();
			getch();
	   		return ogrenci_islemleri_menu();
			break;
		   }
		case '4':{
	   		system("cls");
	   		ogrenci_sil();
	   		getch();
	   		return ogrenci_islemleri_menu();
			break;
		   }
		case 27:{
			return main();
			break;
		}
		default:{
			 
			printf("\nHatali Giris...\n");
			system("pause"); 
			return ogrenci_islemleri_menu();
			break;
		}
		
		   }

}

void ders_islemleri_menu(){
	system("cls"); 
	printf("\t\tDers Islem Menusu \n1- Ders Kayit \n2- Ders Arama \n3- Ders Listele \n4- Ders Kayit Sil \n\nLutfen islemi seciniz...\nAna Menuye Donmek Icin ESC tusuna Basiniz. \n ");
	   switch(getch()){
	   	case '1':{
	   		system("cls"); 
	   		ders_kayit();
	   		getch();
	   		return ders_islemleri_menu();
	   		break;
		   }
		case '2':{
			system("cls"); 
			ders_arama();
			getch();
			return ders_islemleri_menu();
			break;
		   }
		case '3':{
			system("cls");
			ders_listeleme();
			getch();
	   		return ders_islemleri_menu();
			break;
		   }
		case '4':{
			system("cls");
			ders_sil();
	   		getch();
	   		return ders_islemleri_menu();
			break;
		   }
		case 27:{
			return main();
			break;
		}
		   
		default:{
			 
			printf("\nHatali Giris...\n");
			system("pause");
			return ders_islemleri_menu(); 
			break;
		}
		
		   }

}


 // Ogrenci menusu fonksiyonlari
void ogrenci_kayit(void){
OgrDosya = fopen("OgrenciDosyasi.txt","a+");
 	if(OgrDosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nOgrenci bilgilerini giriniz: ");
 do{
  i++;
  fflush(stdin);
  printf("%d. Ogrencinin Adi : ",i);
  gets(ogr.ad);
  printf("%d. Ogrencinin SoyAdi : ",i);
  gets(ogr.soyad);
  printf("%d. Ogrencinin Numarasi : ",i);
  scanf("%d",&ogr.no);

  printf("\n");

  fprintf(OgrDosya,"%s %s %d\n",ogr.ad,ogr.soyad,ogr.no);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(OgrDosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
 }
 
void ogrenci_arama(void){
 char ogr_ad[20];
 int durum=0;
 fflush(stdin);
 printf("\nOgrenci adini giriniz: ");
 gets(ogr_ad);
 OgrDosya=fopen("OgrenciDosyasi.txt","r");
 if(OgrDosya==NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(OgrDosya)){
   fscanf(OgrDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no);
   if(strcmp(ogr.ad,ogr_ad) == 0){ 
    printf("%s %s %d\n\n Devam etmek icin bir tusa basiniz...",ogr.ad,ogr.soyad,ogr.no);
    durum=1;
   }
  }
  fclose(OgrDosya);
  if(durum == 0){ 
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
   getch();
   return ogrenci_islemleri_menu();
  }
 getch();
	
	
}
void ogrenci_listeleme(void){
	OgrDosya = fopen("OgrenciDosyasi.txt","r"); 
 if(OgrDosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 i=1;

 while(!feof(OgrDosya)){ 
  fflush(stdout);
  fscanf(OgrDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no); 
   if(ogr.ad != NULL){ 
    printf("\n%d - %s %s %d",i,ogr.ad,ogr.soyad,ogr.no);
    i++;
   }
 }
 fclose(OgrDosya);
 puts("\n\nBilgiler listelendi devam etmek icin bir tusa basin ...");
  getch();
  
 

}
void ogrenci_sil(void){
	ogrenci_listeleme();
 int numara,durum=0;
 printf("\nSilinecek ogrencinin numarasini giriniz : ");
 scanf("%d",&numara);
 OgrDosya = fopen("OgrenciDosyasi.txt","r");
 OgrenciYedek = fopen("OgrenciYedek.txt","w");
 if(OgrDosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(OgrDosya)){
  fscanf(OgrDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no); 
    if(numara != ogr.no){
     fprintf(OgrenciYedek,"%s %s %d\n",ogr.ad,ogr.soyad,ogr.no);
     
    }
    else durum=1; 
 }
 fclose(OgrDosya);
 fclose(OgrenciYedek);
 if(durum == 1){
  remove("OgrenciDosyasi.txt"); 
  rename("OgrenciYedek.txt","OgrenciDosyasi.txt"); 
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
  getch();
 } 
 else{ 
  remove("OgrenciYedek.txt"); 
  printf(" %d numarasinda bir ogrenci bulunamadi devam etmek icin bir tusa basin ...",numara);
  getch();
 }
 fflush(stdin);
 getch();
}

// Ders menusu fonksiyonlari
void ders_kayit(void){
	i=0;
	DersDosya = fopen("DersDosyasi.txt","a+");
 	if(DersDosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nDers bilgilerini giriniz: ");
 do{ 
  
  i++;
  fflush(stdin);
  printf("%d. Dersin Adi : ",i);
  gets(ders.dersAdi);
  printf("%d. Ders Kodunu Giriniz : ",i);
  scanf("%d",&ders.dersKodu);
  printf("%d. Ders AKTS Giriniz : ",i);
  scanf("%d",&ders.akts);

  printf("\n");
  
  fprintf(DersDosya,"%s %d %d\n",ders.dersAdi,ders.dersKodu,ders.akts);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(DersDosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
	
}
void ders_arama(void){
 int DersKodu,durum = 0; 
 fflush(stdin);
 printf("\nDers kodunu giriniz: ");
 scanf("%d",&DersKodu);
 DersDosya=fopen("DersDosyasi.txt","r");
 if( DersDosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(DersDosya)){
   fscanf(DersDosya,"%s %d %d\n",&ders.dersAdi,&ders.dersKodu,&ders.akts); 
   if(ders.dersKodu == DersKodu){ 
    printf("%s %d %d\n\n Devam etmek icin bir tusa basiniz...",ders.dersAdi,ders.dersKodu,ders.akts);
    durum = 1;
    // 
   }
  }
  fclose(DersDosya);
  if(durum == 0){ 
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
   getch();
  
  }
 getch();
	
}
void ders_listeleme(void){
	DersDosya = fopen("DersDosyasi.txt","r"); 
 if(DersDosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 i2=1;
 while(!feof(DersDosya)){ 
  fflush(stdout);
  fscanf(DersDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no); 
   if(ders.dersAdi != NULL){ 
    printf("\n%d - %s %s %d",i2,ogr.ad,ogr.soyad,ogr.no);
    i2++;
   }
 }
 fclose(DersDosya);
 puts("\nBilgiler listelendi devam etmek icin bir tusa basin ...");
  getch();
 
}
void ders_sil(void){
	ders_listeleme();
	int numara,durum=0;
 printf("\nSilinecek dersin kodunu giriniz : ");
 scanf("%d",&numara);
 DersDosya = fopen("DersDosyasi.txt","r");
 DersYedek = fopen("DersYedek.txt","w");
 if(DersDosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(DersDosya)){
  fscanf(DersDosya,"%s %d %d\n",&ders.dersAdi,&ders.dersKodu,&ders.akts); 
    if(numara != ders.dersKodu){ 
     fprintf(DersYedek,"%s %d %d\n",ders.dersAdi,ders.dersKodu,ders.akts);
     
    }
    else durum=1; 
 }
 fclose(DersDosya);
 fclose(DersYedek);
 if(durum == 1){
  remove("DersDosyasi.txt");
  rename("DersYedek.txt","DersDosyasi.txt"); 
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
  getch();
 } 
 else{ 
  remove("DersYedek.txt"); 
  printf(" %d kodlu bir ders bulunamadi devam etmek icin bir tusa basin ...",numara);
  getch();
 }
 fflush(stdin);
 getch();
}

// ders secim fonksiyonu

void ders_sec(void){

	OgrDosya = fopen("OgrenciDosyasi.txt","r"); 
 if(OgrDosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 i=1;

 while(!feof(OgrDosya)){ 
  fflush(stdout);
  fscanf(OgrDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no); 
   if(ogr.ad != NULL){
    printf("\n%d - %s %s %d",i,ogr.ad,ogr.soyad,ogr.no);
    i++;
   }
 }
 fclose(OgrDosya);
 puts("\n\nDers Secimi Yapilacak Ogrenciyi Seciniz\n\nDevam etmek icin bir tusa basin ...");
  getch();
  
// ogrenci_arama fonksiyonu revize

char ogr_ad[20];
 int durum=0;
 fflush(stdin);
 fprintf(KayitDosya,"\n");
 printf("\nOgrenci adini giriniz: ");
 gets(ogr_ad);
 OgrDosya=fopen("OgrenciDosyasi.txt","r");
 if(OgrDosya==NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(OgrDosya)){//Dosya sonuna kadar okunur
   fscanf(OgrDosya,"%s %s %d\n",&ogr.ad,&ogr.soyad,&ogr.no); // Belle?e yaz?yoruz
   if(strcmp(ogr.ad,ogr_ad) == 0){ // okunan de?er girdi?imiz isme e?itse strcmp 0 d?nd?r?r
    KayitDosya = fopen("KayitDosyasi.txt","a+");
    fprintf(KayitDosya,"\n"); 
    fprintf(KayitDosya,"%s %s %d",ogr.ad,ogr.soyad,ogr.no);
    
    
	int DersKodu,durum = 0; 
    
	ders_listeleme();
for(sayac=0;sayac<i2-1;){
	fflush(stdin);
 printf("\n%d. Dersin Kodunu Giriniz: ",sayac+1);
 scanf("%d",&DersKodu);
 DersDosya=fopen("DersDosyasi.txt","r");
 if( DersDosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(DersDosya)){
   fscanf(DersDosya,"%s %d %d\n",&ders.dersAdi,&ders.dersKodu,&ders.akts); 
   if(ders.dersKodu == DersKodu){ 
   sayac++;
    fprintf(KayitDosya,"/ %s /",ders.dersAdi);
    durum = 1;
   }
    
  }
  

}
 
    durum=1;
  }
  
}
  fclose(OgrDosya);
  fclose(KayitDosya);
printf("\n\nKayit Yapildi devam etmek icin bir tusa basiniz...\n");
getch();  
	durum = 1;
	
	system("cls"); 
	
}

