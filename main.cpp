#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "strOperations.h"
#include "reservationMenu.h"
#include <string>
#include "myMenu.h"
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include "screenOperations.h"
#include <stdio.h>
#include <time.h>
#include "personelMenu.h"

using namespace std;

void menu_AddParentedReservation(string rezNo);
void menu_AddReservation();
void menu_MainMenu();
void menu_PersonelMenu();
void menu_RandevuIslemleri();
void menu_RezervasyonListele();
void menu_RezervasyonAra();
void menu_RezervasyonSil();
void animatedWelcome();
void menu_RezervasyonGuncelle();
void menu_PersonelMenu();
void menu_AddPersonel();
void menu_DeletePersonel();
void menu_ListPersonel();
void menu_UserMenu();
void menu_addUser();
void menu_removeUser();
void menu_loginPanel();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	screenOperations sc; //Ekran boyutunu ayarlamak için screenOperations classý çaðýrýldý.
	sc.setScreen(800,600); //Ekran boyutu 800x600 þeklinde ayarlandý
	sc.setFontBold(); // Font Kalýnlýðý Ayarlandý 
	animatedWelcome();
	system("color f1");
	menu_MainMenu();	
}


void animatedWelcome() {
	screenOperations sc;
	strOperations so;
	sc.setFontColor(10);
		so.allCenterAnimatedString("GEZ TUR OTOMASYON SISTEMINE HOSGELDINIZ!");
		cout << endl;
		so.centerAnimatedString("Algoritma Proje Odevi Icin Onur Yuksel Tarafindan Kodlanmistir");
		cout << endl;
		so.centerAnimatedString("2019 ---- Onur Yuksel ------- 2019");
		Sleep(100);
	
	for(int i = 1; i < 13; i++)
	{
		so.allCenterString("GEZ TUR OTOMASYON SISTEMINE HOSGELDINIZ!");
		so.centerString("Algoritma Proje Odevi Icin Onur Yuksel Tarafindan Kodlanmistir");
		so.centerString("2019 ---- Onur Yuksel ------- 2019");
		sc.setFontColor(i);
		system("cls");
		Sleep(300);
}
	Sleep(300);

}
void menu_AddParentedRezervation(string rezNo)
{
	system("cls");
	
	string tc, name, surname, r_no, hotelName, phoneNo, o_Tc;
	bool isParent = true;
	string crez;
	rezervation rez;
	
	cout << "~~~~ gezTur Randevu Ekleme Sistemi ~~~~~" << endl;
	cout << "Isim: ";
	cin >> name;
	cout << "Soyisim: ";
	cin >> surname;
	cout << "TC No: ";
	cin >> tc;
	cout << "Tel No: ";
	cin >> phoneNo;
	cout << "Isletme Adi: ";
	cin >> hotelName;
	
	
	 
	if (name != "" or surname != "" or tc != "" or phoneNo != "" or hotelName != "") 
	{
		cout << "Rezervasyon Basariyla Eklendi!" << endl;
		rez.addReservation(tc,name,surname,rezNo,hotelName,phoneNo,isParent);
	}
	else {
		cout << "Bir Hata Meydana Geldi!" << endl;
	}
	
	cout << "Yeni Bagli Rezervasyon Eklemek Ister Misiniz ?" << endl;
	crez = getch();
	if (crez == "Y" or crez == "y") {
		menu_AddParentedRezervation(rezNo);
	}
	else {
		menu_MainMenu();
	}
}
void menu_AddReservation() {

	
	system("cls");
		
	string tc, name, surname, r_no, hotelName, phoneNo, o_Tc;
	bool isParent;
	string c_rez = "";
	
	
	cout << "~~~~ gezTur Randevu Ekleme Sistemi ~~~~~" << endl;
	cout << "Isim: ";
	cin >> name;
	cout << "Soyisim: ";
	cin >> surname;
	cout << "TC No: ";
	cin >> tc;
	cout << "Tel No: ";
	cin >> phoneNo;
	cout << "Isletme Adi: ";
	cin >> hotelName;
	
	srand(time(NULL));
	long long int i_rezNo = rand() % 900000000 + 100000000;
	strOperations so;
	string rezNo = so.toStr(i_rezNo);
	
	if (name != "" or surname != "" or tc != "" or phoneNo != "" or hotelName != "") 
	{
		cout << "Rezervasyon Basariyla Olusturuldu!" << endl;
		rezervation rez;
		rez.addReservation(tc,name,surname,rezNo,hotelName,phoneNo,isParent);
	}
	else {
		
		cout << "Bir Hata Meydana Geldi!" << endl;
		
	}
		
	cout << "Bagli Rezervasyon Yapilacak Mi? (Y/N)" << endl;
	c_rez = getch();
	if (c_rez == "Y" or c_rez == "y") {
		if (name != "" or surname != "" or tc != "" or phoneNo != "" or hotelName != "") 
	{
		isParent = false;
		menu_AddParentedRezervation(rezNo);		
	}
	
	
}	
	else {
		menu_RandevuIslemleri();
	}
		
}

void menu_MainMenu() {

system("cls");
	
index mainMenu;
mainMenu.noS = 2;  
mainMenu.addIndex("Randevu Islemleri",menu_RandevuIslemleri);
mainMenu.addIndex("Personel Islemleri",menu_PersonelMenu);
mainMenu.buildMenu("Secim Yapiniz","~~~ gezTur Otomasyon Sistemi ~~~");

}

void menu_PersonelMenu() {
	system("cls");
	index pMenu;
	pMenu.noS = 4;
	pMenu.addIndex("Personel Ekle",menu_AddPersonel);
	pMenu.addIndex("Personel Sil",menu_DeletePersonel);
	pMenu.addIndex("Personel Listele",menu_ListPersonel);
	pMenu.addIndex("Ana Menu",menu_MainMenu);
	pMenu.buildMenu("Secim Yapiniz", "~~~ gezTur Otomasyon Sistemi ~~~");
}

void menu_AddPersonel() {
	system("cls");
	string id,name,surname,age,startyear,position,salary;
	
	cout << "Personel ID: " ;
	cin >> id;
	cout << "Personel Adi: ";
	cin >> name;
	cout << "Personel Soyadi: ";
	cin >> surname;
	cout << "Personel Yasi: ";
	cin >> age;
	cout << "Personel Pozisyonu ";
	cin >> position;
	cout << "Personel Ucreti: ";
	cin >> salary;
	personel staff;
	staff.AddPersonel(id,name,surname,age,startyear,position,salary);
	cout << "Personel Ekleme Islemine Devam Etmek Ister Misiniz ?(Y/N)" << endl;
	char cnt;
	cnt = getch();
	if (cnt == 'Y' or cnt == 'y') 
	{
		menu_AddPersonel();
	}
	else {
		menu_PersonelMenu();
	}
	
}

void menu_DeletePersonel()
{
	system("cls");
	string id;
	cout << "Silinecek Personel ID: ";
	cin >> id;
	personel staff;
	staff.RemovePersonel(id);
	char cnt;
	cout << "Personel Silme Islemine Devam Etmek Istiyor Musunuz ?(Y/N)" << endl; 
	cnt = getch();
	if (cnt == 'Y' or cnt == 'y') 
	{
		menu_DeletePersonel();
	}
	else {
		menu_PersonelMenu();
	}
}

void menu_ListPersonel()
{
	system("cls");
	personel staff;
	staff.ListPersonel();
	cout << "Devam Etmek Icin Bir Tusa Basiniz";
	char cnt;
	cnt = getch();
	menu_PersonelMenu();
	
}

void menu_RezervasyonListele() {
system("cls");
rezervation rez;
rez.listReservations();
char cont;
cout << "Devam Etmek Icin Bir Tusa Basiniz" << endl;
cont = getch();
menu_RandevuIslemleri();
}

void menu_RezervasyonAra() {
	system("cls");
	string sT;
	string cnt;
	cout << "Aranacak Degeri Giriniz: " << endl;
	cin >> sT;
	rezervation rez;
	rez.searchReservation(sT);
	cout << "Arama Yapmaya Devam Etmek Istiyor Musunuz ?(Y/N)" << endl;
	cnt = getch();
	if (cnt == "Y" or cnt == "y") {
		menu_RezervasyonAra();
	}
	else {
		menu_MainMenu();
	}
}

void menu_RezervasyonSil() {
	system("cls");
	string r_no;
	cout << "Silinecek Rezervasyona Ait Rezervasyon Numarasini Giriniz: ";
	cin >> r_no;
	rezervation rez;
	rez.deleteReservation(r_no);
	menu_RandevuIslemleri();
}

void menu_RezervasyonGuncelle() {
	rezervation rez;
	string rNum;
	cout << "Guncellenecek Rezervasyona Ait Rezervasyon Numarasini Giriniz: ";
	cin >> rNum;
	rez.updateReservation(rNum);
	menu_RandevuIslemleri();
}

void menu_RandevuIslemleri() {

	


system("cls");

index randevuMenusu;
randevuMenusu.noS = 6;
randevuMenusu.addIndex("Rezervasyon Ekle",menu_AddReservation);
randevuMenusu.addIndex("Rezervasyon Sil",menu_RezervasyonSil);
randevuMenusu.addIndex("Rezervasyonlari Listele",menu_RezervasyonListele);
randevuMenusu.addIndex("Rezervasyon Ara",menu_RezervasyonAra);
randevuMenusu.addIndex("Rezervasyon Guncelle",menu_RezervasyonGuncelle);
randevuMenusu.addIndex("Ana Menu",menu_MainMenu);
randevuMenusu.buildMenu("Secim Yapiniz: ","~~~ Randevu Islemleri Menusu ~~~");

}

void menu_UserMenu() {
	system("cls");
	index userMenu;
	userMenu.noS = 3;
	userMenu.addIndex("Kullanici Ekle",menu_addUser);
	userMenu.addIndex("Kullanici Sil",menu_removeUser);
	userMenu.addIndex("Ana Menu",menu_MainMenu);
	userMenu.buildMenu("Secim Yapiniz","~~~ gezTur Otomasyon Sistemi ~~~");
	
}

void menu_addUser() {
	system("cls");
	string uname, pw;
	int lv;
	cout << "Kullanici Adi: ";
	cin >> uname;
	cout << "Parola: "; 
	cin >> pw;
	cout << "Kullanici Duzeyi: ";
	cin >> lv;
	user u;
	u.addUser(uname,pw,lv);
	cout << "Kullanici Basariyla Eklendi!" << endl;
	cout << "Yeni Kullanici Eklemek Ister Misiniz ?(Y/N)" <<endl;
	char ct;
	ct = getch();
	if (ct == 'Y' or ct == 'y')
	{
		menu_addUser();
	}
	else {
		menu_UserMenu();
	}
}

void menu_removeUser() {
	system("cls");
	string un;
	user u;
	u.deleteUser(un);
	cout << "Devam Etmek Icin Bir Tusa Basiniz" << endl;
	char ct;
	ct = getch();
	menu_UserMenu();
	
}

void menu_loginPanel()
{
	//system("cls");
	string un,pw;
	cout << "gezTur Otomasyon Sistemine Hosgeldiniz! Lutfen Giris Yapin" << endl;
	cout << "Kullanici Adi: ";
	cin >> un;
	cout << "Parola: ";
	cin >> pw;
	user u;
	bool lgn = u.loginUser(un,pw);
	if (lgn == true)
	{
		menu_MainMenu();
	}
	else {
		menu_loginPanel();
	}
}
