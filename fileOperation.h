#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <vector>
#include "strOperations.h"
#include <stdio.h>

using namespace std;

class fileOperation

{
	strOperations so;
	
	
	
	public:
		
		string outputText;
		
		void writeFile(std::string filePath, string text) {
			string txt =  filePath;
			char* pString = so.strToChar(txt);
			fstream file;
			file.open(pString,ios::app);
			if (file.good()) {
				file << text;
			}
			file.close();
				}
		
		void getHide(string filePath) {
			fstream file;
			char *pString = so.strToChar(filePath);
			file.open(pString,ios::out);
			file.close();
			
			
			
		}
		
		void readFile(string filePath)
		{
			string line;
			string txt =  filePath;
			char* pString = so.strToChar(txt);
			ifstream file;
			file.open(pString,ios::in);
			if (file.good())
			{
				while(!file.eof())
				{
					getline(file,line);
					outputText += line + "\n";
				}
			}
			file.close();
			
		}
		
		
			int getLineCount(string filePath) {
			int linecount = 0;
			string txt =  filePath;
			char *pString = so.strToChar(txt);
			ifstream file;
				file.open(pString,ios::in);
			if (file.good()) {
				while(!file.eof())
				{
					linecount++;
				}
			}
			
			file.close();
			return linecount;
		}
		
		void searchFile(string filePath,string searchText)
			{
				string line;
			string txt =  filePath;
			char* pString = so.strToChar(txt);
			ifstream file;
			file.open(pString,ios::in);
			if (file.good())
			{
				int foundCounter = 0;
				while(!file.eof())
				{
					getline(file,line);
					string st = line;
					size_t found = st.find(searchText);
					if (found != string::npos)
					{
						cout << line << endl;
						foundCounter++;
					}
				}
							cout << foundCounter << " Adet Sonuc Bulundu" << endl;
			}
			file.close();
			}
			
			void removeLine(string filePath,string tmpFilePath,string searchText) {
			
			string tmpText;
			string line;
			string txt = filePath;
			string tmpTxt = tmpFilePath;
			char acceptDel;
			char* pString = so.strToChar(txt);
			char* tmpString = so.strToChar(tmpTxt);
			vector<int> selectedLines;
				int activeLine = 0;
				int foundCounter = 0;
			fstream file;
			file.open(pString,ios::in);
			if (file.good())
			{
				
				while(!file.eof())
				{
					getline(file,line);
					string st = line;
					size_t found = st.find(searchText);
					
					if (found != string::npos)
					{
						cout << line << endl;
						selectedLines.push_back(activeLine);
						foundCounter++;
					}
					
					activeLine++;
				}
			}
			file.close();
			file.open(pString,ios::in);
				activeLine = 0;
				cout << foundCounter << " Adet Sonuc Bulundu Silmek Istediginize Emin Misiniz? (Y/N)\nBu Islem Veri Boyutuna Gore Biraz Vakit Alabilir!"<< endl;
				cin >> acceptDel;
				if (acceptDel == 'Y' or acceptDel == 'y')
				{
					if (file.good()) {
				
				cout << endl << endl << endl;
				
				cout << "Silme Islemi Gerceklestiriliyor Lutfen Bekleyiniz";	
				while(!file.eof())
				{
					cout << "." << flush;
					Sleep(8);
					getline(file,line);
					for(int i = 0; i < selectedLines.size(); i++)
					{
					if (!(activeLine == selectedLines[i]))
					{
						tmpText += line+"\n";
					}
				}
					activeLine++;
				}
			}
			
				file.close();
				remove(pString);
				file.open(tmpString,std::fstream::out);
				if (file.good())
				{
					file << tmpText;
				}
				file.close();
				rename(tmpString,pString);
		}	
			}
			


};

#endif
