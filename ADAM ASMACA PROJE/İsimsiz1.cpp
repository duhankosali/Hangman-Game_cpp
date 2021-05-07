

#include <iostream>
#include <stdio.h>//standart kütüphane çaðýrýyoruz
#include <stdlib.h>//rand kullanmak için bu kütüphaneyi çaðýrdýk
#include <locale.h>//türkçe karakter için çaðýrdýk
#include <string.h>//strlen komutu için çaðardýðýmýz kütüphane
#include <time.h>//random komutu kullanmak için çaðýrdýk
#include <string> // kareliYaz fonksiyonu için çaðýrdýk

using namespace std;

void kareliYazi(string yazi) {
	cout << "\t\t\t***************************************\n";
	cout << "\t\t\t*                                     *\n";
	cout << "\t\t\t" << "    " << yazi << "\n";
	cout << "\t\t\t*                                     *\n";
	cout << "\t\t\t***************************************\n\n";
}

int main()
{
	bas:
		system ("CLS");
		
	char kelimeler[][16] = { "windows", "microsoft", "ram", "android", "mouse", "klavye", "kodlama" };
	
	
	setlocale(LC_ALL, "Turkish");

	kareliYazi("ADAM ASMACA OYUNUNA HOÞGELDÝNÝZ");
	kareliYazi("DEVAM ETMEK ÝÇÝN ENTER BASINIZ");

	int randomsayi = rand() % 7;
	int kelimesayisi;
	kelimesayisi = strlen(kelimeler[randomsayi]); // strlen char deðiþkenin boyutunu bulur
	
	char bosluk[1][20];

	for (int i = 0; i <= kelimesayisi-1; i++) // dizinin 0. elemanýný atamak için kelimesayýsý-1 yaptýk
	{
		bosluk[0][i] = '_';
	}
	
	//while döngüsünde kullanacaðýmýz deðiþkenler
	bool tahmin=false;
	int bosluksayac=kelimesayisi;
	char harftahmin;
	int hak = 5;
	char kelime;
	
	while (1) // while döngüsü baþlangýcý
	{
		system ("pause");
		system ("CLS");
		cout << hak << " tane yanlýþ hakkýnýz kaldý.\n\n";
		
		for (int i=0; i<=kelimesayisi-1; i++)
		{cout << bosluk[0][i];}
		
		cout << "\n\nHarf Tahmininizi Giriniz: ";
	cin >> harftahmin;

		for (int i = 0; i <= kelimesayisi; i++)
		{
			if (harftahmin == kelimeler[randomsayi][i])
			{
				cout << i+1 << ". harf " << harftahmin << '\n';
				bosluk[0][i] = harftahmin;
				tahmin=true; // Ekrana doðru veya yanlýþ yazýlmasýný belirler.
				bosluksayac--;
			}
				
		}
		
			if (tahmin==false)
			{
				kareliYazi("YANLIÞ TAHMÝN :( Tekrar dene!");
				hak--;
			}
			else 
				kareliYazi("DOÐRU TAHMÝN :) Güzel gidiyorsun!");
			
			cout << "Devam etmek için herhangi bir tuþa basýnýz.\n\n";
			tahmin=false; // Ekrana doðru veya yanlýþ yazýlmasýný belirler.
	
	
		if (bosluksayac==0)
			break;
		
		if (hak<=0) // oyun kaybedildi. 
			break;
			
	} // while döngüsü sonu
	
	finish:
		
	system ("CLS");
		
	if (bosluksayac==0)
	{
		kareliYazi("  Tebrikler! OYUNU KAZANDIN :)");
	}
	
	if (hak<=0) // oyun kaybedildi.
	{
	kareliYazi("\t  Oyunu Kaybettiniz :(");
	cout << "\t\t\t       Doðru Kelime: " << kelimeler[randomsayi];
	}
	
	
	
	cout <<"\n\n\n";
	kareliYazi("Oyuna devam etmek için (1)");
	kareliYazi ("Oyundan Çýkmak için (0)");
	
	int devam;
	cin >> devam;
	
	switch (devam)
	{
		case 1: goto bas;
		break;
		
		case 0: system("CLS"); kareliYazi ("\t    GÖRÜÞMEK ÜZERE"); 
		break;
		
		default: cout << "Hatalý deðer girdiniz. Lütfen tekrar deneyiniz."; goto finish;
		break;
	
	}
	
	return 0;
}
