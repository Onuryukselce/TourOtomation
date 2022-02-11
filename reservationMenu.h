#ifndef RESERVATIONMENU_H
#define RESERVATIONMENU_H

#include "fileOperation.h"
#include "strOperations.h"
#include <vector>
#include "myMenu.h"
#include <iomanip>


using namespace std;

class reservationMenu
{
	
	private:
		std::string filePath;
		std::string tmp_filePath;
		std::string fileName;
		std::string tmpfileName;
		bool isHidden;
		
	
		
		
	public:
			reservationMenu() {
			fileName = "reservation.txt";
			tmpfileName = "tmp_reservation.txt";
			filePath = "data/reservations/" + fileName;
			tmp_filePath = "data/reservations/" + tmpfileName;
		}
		
		void setFilePath(string f_Name, string _filePath)		
		{
			fileName = f_Name;
			filePath = _filePath + f_Name;
			tmp_filePath = "data/reservations/" + filePath;
		}
		
		string &getFilePath()
		{
			return filePath;
		}
		
		string &getTmpFilePath() 
		{
			return tmp_filePath;
		}
		
};



class add_reservationOps : public reservationMenu
{
	
	private:
		
		
	public:
		void addReservation(long long int tc, char* name, char* surname, long long int r_no, int htl, long long int p_no, bool isParent)
		{
			strOperations so;
			string tc_str = so.toStr(tc);
			string name_str = so.toStr(name);
			string surname_str = so.toStr(surname);
			string r_no_str = so.toStr(r_no); 
			string p_no_str = so.toStr(p_no);
			string addStr = tc_str + "|" + name_str + "|" + surname_str + "|" + r_no_str + "|" + p_no_str + "|" + "\n";
			
			string fp = getFilePath();
			fileOperation fo;
			fo.writeFile(fp,addStr);
			
		}
		
		void addReservation(char* tc, char* name, char* surname, char* r_no, int htl, char* p_no, bool isParent,char* o_tc = NULL)
		{
				strOperations so;
			string tc_str = so.toStr(tc);
			string name_str = so.toStr(name);
			string surname_str = so.toStr(surname);
			string r_no_str = so.toStr(r_no); 
			string p_no_str = so.toStr(p_no);
			string o_tc_str = so.toStr(o_tc);
			string addStr;
			if (isParent == true) {
			addStr = tc_str + "|" + name_str + "|" + surname_str + "|" + r_no_str + "|" + p_no_str +  "|" "\n"; }
			else {
				addStr = tc_str + "|" + name_str + "|" + surname_str + "|" + r_no_str + "|" + p_no_str + "|" "\n"; }
				
			string fp = getFilePath();
			fileOperation fo;
			fo.writeFile(fp,addStr);
			
		}
		
		void addReservation(string tc, string name, string surname, string r_no, string htl, string p_no, bool isParent )
		{
				string addStr = tc + "|" + name + "|" + surname + "|" + r_no + "|" + htl + "|" + p_no + "|" + "\n";
			
			string fp = getFilePath();
			fileOperation fo;
			fo.writeFile(fp,addStr);
		}
		
		void listReservations()
		{
			string fp = getFilePath();
			fileOperation fo;
			fo.readFile(fp);
			cout << fo.outputText << endl;
			
			
		}
		
		void searchReservation(string searchText)
		{
			string fp = getFilePath();
			fileOperation fo;
			fo.searchFile(fp,searchText);
		
		}
		

		
		
};

class update_reservationOps : public  reservationMenu
{
	public:
		void deleteReservation(string reservationID)
		{
			string fp = getFilePath();
			string tmpfp = getTmpFilePath();
			fileOperation fo;
			fo.removeLine(fp,tmpfp,reservationID);
		}
		
		void updateReservation(string reservationID)
		{
			string fp = getFilePath();
			string tmpfp = getTmpFilePath();
			string tmpText;
			
			strOperations so;
			char* pString = so.strToChar(fp);
			char* tmpString = so.strToChar(tmpfp);
			fstream file;
			fstream tmpfile;
			string selectedLine,activeLine;
			int sLine,aLine=0;
			string line;
			file.open(pString,ios::in);
			tmpfile.open(tmpString,ios::out);

				if (file.good())
				{
					while(!file.eof())
					{
						getline(file,line);
						activeLine = line;
						if (activeLine.find(reservationID) != std::string::npos)
						{
							sLine = aLine;
							selectedLine = activeLine;
							
						}
						else {
							if (tmpfile.good())
							{
								tmpfile << activeLine << endl;
							}
						}
						aLine++;
					}
				}
			file.close();
			tmpfile.close();
			remove(pString);
			rename(tmpString,pString);
			
			string o_tc, o_name, o_surname, o_r_no, o_htl, o_p_no, o_o_tc;
			string n_tc, n_name, n_surname, n_r_no, n_htl, n_p_no, n_o_tc;
			
			int delimeterCounter = 0;
			vector<string> Tabs;
			string delimiter = "|";
			string s = selectedLine;
			size_t pos = 0;
			string token;
			while((pos = s.find(delimiter)) != std::string::npos) {
				token = s.substr(0,pos);
				Tabs.push_back(token);
				s.erase(0,pos+delimiter.length());
			}
			
			for(int i = 0; i < Tabs.size(); i++)
			{
				cout << i << "Dongu Okey "<< endl;
				if (i == 0)
					o_tc = Tabs[i];
				else if (i == 1)
					o_name = Tabs[i];
				else if(i == 2)
					o_surname = Tabs[i];
				else if(i == 3)
					o_r_no = Tabs[i];
				else if(i == 4)
					o_htl = Tabs[i];
				else if(i == 5)
					o_p_no = Tabs[i];
				else if(i ==6)
					o_o_tc = Tabs[i];
			}
			
			bool again = false;
			do {
			cout << "|" << setw(11)<<"TC NO" << "|"<<setw(11)<<"AD"<<"|"<<setw(11)<<"SOYAD"<<"|"<<setw(16)<<"Rezervasyon No"<<"|"<<setw(16)<<"Otel Adi"<<"|"<<setw(11)<<"Telefon No"<<"|"<<endl;
			cout << "|"<<setw(11)<<o_tc<<"|"<<setw(11)<<o_name<<"|"<<setw(11)<<o_surname<<"|"<<setw(16)<<o_r_no<<"|"<<setw(16)<<o_htl<<"|"<<setw(11)<<o_p_no<<"|"<<endl;
			cout << endl;
			
				cout << "TC: " << o_tc << endl;
				cout << "Yeni TC: ";
				cin >> n_tc;
				
				cout<<"AD: " << o_name << endl;
				cout<<"Yeni AD: ";
				cin >> n_name;
				
				cout<<"SOYAD: " << o_surname << endl;
				cout<<"Yeni SOYAD: ";
				cin>>n_surname;
				
				cout<<"Rezervasyon No: " << o_r_no << endl;
				cout<<"Yeni Rezervasyon No: ";
				cin>>n_r_no;
				
				cout<<"Otel Adi:" << o_htl << endl;
				cout<<"Yeni Otel Adi: ";
				cin>>n_htl;
				
				cout<<"Telefon NO: " << o_p_no << endl;
				cout<<"Yeni Telefon No: ";
				cin>>n_p_no;
			
			system("cls");
			
			cout << "TC: " << o_tc << " ------> " << n_tc << endl;
			cout << "AD: " << o_name << " ------> " << n_name << endl;
			cout << "SOYAD: " << o_surname << " ------> " << n_surname << endl;
			cout << "Rezervasyon No: " << o_r_no << " ------> " << n_r_no << endl;
			cout << "Otel Adi: " << o_htl << " ------> " << n_htl << endl;
			cout << "Telefon No: " << o_p_no << " ------> " << n_p_no << endl;
			
			cout << "Degisiklikleri Kaydetmek Istiyor Musunuz ?(Y/N)" << endl;
			char yn;
			yn = getch();
			if(yn == 'Y' or yn == 'y') {
				string newStr = n_tc + "|" + n_name + "|" + n_surname + "|" + n_r_no + "|" + n_htl + "|" + n_p_no + "|\n";
				fileOperation fo;
				fo.writeFile(pString,newStr);
				again = false;
			}
			else{
				again = true;
			}
			
		}while(again==true);
		
		
			}
	protected:
};

class rezervation : public add_reservationOps, public update_reservationOps
 {
	public:
		
	private:
		
};



#endif
