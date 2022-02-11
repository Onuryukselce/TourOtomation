#ifndef MYMENU_H
#define MYMENU_H
#include <iostream>
#include <string>
#include <vector>
#include "strOperations.h"
#include "userOperation.h"


using namespace std;
class myMenu : public userOperation //class named myMenu defined as main class and menu proccesses are defined into || myMenu classi ana klas olarak tanimlanmis menu islemleri icerisine fonksiyon olarak tanimlanmistir.
{
	public:				
			vector<void (*)()>sEvent; //  a function array defined like a variable using pointer called 'sEvent' || i�eri�inde fonksiyonlar� tutan sEvent ad�nda bir vector tan�mlanm��t�r 
			vector<int> sAuthority; 
			void handleEvent(int index) // handle fonksiyonunu �a��racak handleEvent fonksiyonu �a�r�lm��t�r, handle fonksiyonunu ayr� fonksiyonda �a��rmam�z�n sebebi kod okunurlu�unu kolayla�t�rmakt�r.
			{
				handle(index-1); // Men�de g�sterilen 1.Eleman asl�nda listenin 0. eleman� oldu�undan dolay�; indexi kullan�c�n�n girdi�i say�dan bir eksik olan fonksiyon cagrilmistir.
										}
										
						
	private:	void handle(int part) {sEvent[part](); } //  defined handle functions for handle the function exported from vector || Listeden okunan fonksiyonun �a�r�lmas� i�in gerekli handle fonksiyonu ya�zlm��t�r		
};

class index : public myMenu // index class�na myMenu class� aktar�larak kal�t�m sa�lanm��t�r burada index s�n�f� asl�nda myMenu s�n�f�n�n bir alt k�me s�n�f�d�r.
{
	public:	
		int noS; // number of selection : ka� se�enekli bir men� olu�turulaca�� bilgisi al�nmaktad�r.
		vector<std::string>sText; // Men�n�n her bir eleman�n�n yaz� i�eri�i 'sText' adl� bir listeye aktar�lmaktad�r.
		
		void addIndex(string text, void (*func)(), int authority = 0)
			{
				sText.push_back(text);
				sEvent.push_back(func);
				sAuthority.push_back(authority);
			}
			
		void buildMenu(string inputText,const std::string& introText = std::string()) { //olu�turulan taslak Men�y� ekrana yazd�rmaya yarayan fonksiyon, ikinci parametre opsiyonel kar��lama mesaj�n� tan�mlamaktad�r
			strOperations so;
			userOperation user;
			so.centerString(introText); // Kar��lama mesasj�n� yazd�r
			int counter = 1; // counter isimli saya� se�eneklerin s�ralar�n� saymaktad�r.
			int selectIndex[noS]; // Say�lan saya� say�lar� selectIndex isimli bir tam say� dizisine aktar�lmaktad�r, noS ile dizinin boyutu dinamik olarak ayarlanmaktad�r
			for(int i = 0; i < noS; i++) // For d�ng�s�yle yazd�rma ve s�ralama i�lemleri basit bir �ekilde yap�lmaktad�r.
			{
				
				string ctr = so.toStr(counter); //counter int to str d�n���m� yap�ld�.
				string queue = ctr + "." + sText[i]; // queue isimli string n.SecnenekAdi olacak �ekilde ayarlandi
				so.centerAnimatedString(queue);  // Animasyonlu merkezlenmi� string
				cout << endl; 
				selectIndex[i] = counter; // yukarida bahsedildi�i gibi aktarim gerceklestirilmistir
				counter++; }
			string txt = "~~~"+inputText+"~~~"; // Kullan�c�dan veri al�nmas� i�in gereken bilgi ekrana yazd�r�lmaktad�r.
			so.centerString(txt);
			int input; // input de�i�keni kullan�c�dan al�nan veriyi denetlemektedir.
			input = getch(); // kullan�c�dan veri al�n�r.
			int i = (int)((char)input - '0');
			handleEvent(i); // kullan�c�dan al�nan veri myMenu class�ndaki handleEvent fonksiyonuna g�nderilerek listeden ilgili fonksiyonun �a�r�lmas� sa�lan�r.
			
			
			

		}				
	private:
};




#endif
