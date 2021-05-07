

#include <iostream>
#include <stdio.h>//standart k�t�phane �a��r�yoruz
#include <stdlib.h>//rand kullanmak i�in bu k�t�phaneyi �a��rd�k
#include <locale.h>//t�rk�e karakter i�in �a��rd�k
#include <string.h>//strlen komutu i�in �a�ard���m�z k�t�phane
#include <time.h>//random komutu kullanmak i�in �a��rd�k
#include <string> // kareliYaz fonksiyonu i�in �a��rd�k

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

	kareliYazi("ADAM ASMACA OYUNUNA HO�GELD�N�Z");
	kareliYazi("DEVAM ETMEK ���N ENTER BASINIZ");

	int randomsayi = rand() % 7;
	int kelimesayisi;
	kelimesayisi = strlen(kelimeler[randomsayi]); // strlen char de�i�kenin boyutunu bulur
	
	char bosluk[1][20];

	for (int i = 0; i <= kelimesayisi-1; i++) // dizinin 0. eleman�n� atamak i�in kelimesay�s�-1 yapt�k
	{
		bosluk[0][i] = '_';
	}
	
	//while d�ng�s�nde kullanaca��m�z de�i�kenler
	bool tahmin=false;
	int bosluksayac=kelimesayisi;
	char harftahmin;
	int hak = 5;
	char kelime;
	
	while (1) // while d�ng�s� ba�lang�c�
	{
		system ("pause");
		system ("CLS");
		cout << hak << " tane yanl�� hakk�n�z kald�.\n\n";
		
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
				tahmin=true; // Ekrana do�ru veya yanl�� yaz�lmas�n� belirler.
				bosluksayac--;
			}
				
		}
		
			if (tahmin==false)
			{
				kareliYazi("YANLI� TAHM�N :( Tekrar dene!");
				hak--;
			}
			else 
				kareliYazi("DO�RU TAHM�N :) G�zel gidiyorsun!");
			
			cout << "Devam etmek i�in herhangi bir tu�a bas�n�z.\n\n";
			tahmin=false; // Ekrana do�ru veya yanl�� yaz�lmas�n� belirler.
	
	
		if (bosluksayac==0)
			break;
		
		if (hak<=0) // oyun kaybedildi. 
			break;
			
	} // while d�ng�s� sonu
	
	finish:
		
	system ("CLS");
		
	if (bosluksayac==0)
	{
		kareliYazi("  Tebrikler! OYUNU KAZANDIN :)");
	}
	
	if (hak<=0) // oyun kaybedildi.
	{
	kareliYazi("\t  Oyunu Kaybettiniz :(");
	cout << "\t\t\t       Do�ru Kelime: " << kelimeler[randomsayi];
	}
	
	
	
	cout <<"\n\n\n";
	kareliYazi("Oyuna devam etmek i�in (1)");
	kareliYazi ("Oyundan ��kmak i�in (0)");
	
	int devam;
	cin >> devam;
	
	switch (devam)
	{
		case 1: goto bas;
		break;
		
		case 0: system("CLS"); kareliYazi ("\t    G�R��MEK �ZERE"); 
		break;
		
		default: cout << "Hatal� de�er girdiniz. L�tfen tekrar deneyiniz."; goto finish;
		break;
	
	}
	
	return 0;
}
