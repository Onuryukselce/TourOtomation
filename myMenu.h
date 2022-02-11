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
			vector<void (*)()>sEvent; //  a function array defined like a variable using pointer called 'sEvent' || içeriðinde fonksiyonlarý tutan sEvent adýnda bir vector tanýmlanmýþtýr 
			vector<int> sAuthority; 
			void handleEvent(int index) // handle fonksiyonunu çaðýracak handleEvent fonksiyonu çaðrýlmýþtýr, handle fonksiyonunu ayrý fonksiyonda çaðýrmamýzýn sebebi kod okunurluðunu kolaylaþtýrmaktýr.
			{
				handle(index-1); // Menüde gösterilen 1.Eleman aslýnda listenin 0. elemaný olduðundan dolayý; indexi kullanýcýnýn girdiði sayýdan bir eksik olan fonksiyon cagrilmistir.
										}
										
						
	private:	void handle(int part) {sEvent[part](); } //  defined handle functions for handle the function exported from vector || Listeden okunan fonksiyonun çaðrýlmasý için gerekli handle fonksiyonu yaýzlmýþtýr		
};

class index : public myMenu // index classýna myMenu classý aktarýlarak kalýtým saðlanmýþtýr burada index sýnýfý aslýnda myMenu sýnýfýnýn bir alt küme sýnýfýdýr.
{
	public:	
		int noS; // number of selection : kaç seçenekli bir menü oluþturulacaðý bilgisi alýnmaktadýr.
		vector<std::string>sText; // Menünün her bir elemanýnýn yazý içeriði 'sText' adlý bir listeye aktarýlmaktadýr.
		
		void addIndex(string text, void (*func)(), int authority = 0)
			{
				sText.push_back(text);
				sEvent.push_back(func);
				sAuthority.push_back(authority);
			}
			
		void buildMenu(string inputText,const std::string& introText = std::string()) { //oluþturulan taslak Menüyü ekrana yazdýrmaya yarayan fonksiyon, ikinci parametre opsiyonel karþýlama mesajýný tanýmlamaktadýr
			strOperations so;
			userOperation user;
			so.centerString(introText); // Karþýlama mesasjýný yazdýr
			int counter = 1; // counter isimli sayaç seçeneklerin sýralarýný saymaktadýr.
			int selectIndex[noS]; // Sayýlan sayaç sayýlarý selectIndex isimli bir tam sayý dizisine aktarýlmaktadýr, noS ile dizinin boyutu dinamik olarak ayarlanmaktadýr
			for(int i = 0; i < noS; i++) // For döngüsüyle yazdýrma ve sýralama iþlemleri basit bir þekilde yapýlmaktadýr.
			{
				
				string ctr = so.toStr(counter); //counter int to str dönüþümü yapýldý.
				string queue = ctr + "." + sText[i]; // queue isimli string n.SecnenekAdi olacak þekilde ayarlandi
				so.centerAnimatedString(queue);  // Animasyonlu merkezlenmiþ string
				cout << endl; 
				selectIndex[i] = counter; // yukarida bahsedildiði gibi aktarim gerceklestirilmistir
				counter++; }
			string txt = "~~~"+inputText+"~~~"; // Kullanýcýdan veri alýnmasý için gereken bilgi ekrana yazdýrýlmaktadýr.
			so.centerString(txt);
			int input; // input deðiþkeni kullanýcýdan alýnan veriyi denetlemektedir.
			input = getch(); // kullanýcýdan veri alýnýr.
			int i = (int)((char)input - '0');
			handleEvent(i); // kullanýcýdan alýnan veri myMenu classýndaki handleEvent fonksiyonuna gönderilerek listeden ilgili fonksiyonun çaðrýlmasý saðlanýr.
			
			
			

		}				
	private:
};




#endif
