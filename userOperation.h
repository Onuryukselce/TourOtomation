#ifndef USEROPERATION_H
#define USEROPERATION_H


#include <string>
#include <vector>
#include "fileOperation.h"
#include <fstream>

using namespace std;



class userOperation
{
	public:
		fileOperation fo;	
		std::string a_un;
		std::string a_pw;
		int a_lv;
		
		vector<string> userNames;
		vector<string> passWords;
		vector<int> userLevels;
		
		//Function Section
		
		userOperation() {
			filePath = "data/accounts/";
			fileName = "accounts.txt";
			tmp_fileName = "tmp_accounts.txt";
			tmp_filePath = "data/accounts/";
			
			filePath += fileName;
			tmp_filePath += tmp_fileName;
			
			registerUser();
		}
		
		string &getFilePath()
		{
			
			return filePath;
			
		}
		
		string &getTmpFilePath()
		{
			return tmp_filePath;	
		}
		
		void setFilePath(string f_Name, string _filePath)
		{
			filePath = _filePath;
			fileName = f_Name;
			tmp_fileName = "tmp_" + f_Name;
			tmp_filePath = "tmp_" + _filePath;
		}
		
		void registerUser()
		{
			string fp = getFilePath();
			fo.readFile(fp);
			
			string str = fo.outputText;
			int deliCounter = 0;
			string delimiter = "|";
			string s = str;
			size_t pos = 0;
			string token;
			
			while((pos = s.find(delimiter)) != std::string::npos) {
				token = s.substr(0,pos);
				deliCounter++;
				if(deliCounter == 1)
				{
					userNames.push_back(token);
				}
				else if(deliCounter == 2)
				{
					passWords.push_back(token);
				}
				else if(deliCounter == 3)
				{
					strOperations so;
					int tkn = so.strToInt(token);
					userLevels.push_back(tkn);
					deliCounter = 0;
				}
				s.erase(0,pos+delimiter.length());
				
			}
			
		}
		
	private:
		string filePath;
		string tmp_filePath;
		string fileName;
		string tmp_fileName;
		
		
};

class uProc : public userOperation
{
	public:
		void addUser(string un, string pw, int lv) {
			
			string fp = getFilePath();
			strOperations so;
			string l = so.toStr(lv);
			string str = un + "|" + pw + "|" + l + "|" + "\n";
			fo.writeFile(fp,str);
			registerUser(); 
		}
		
		void deleteUser(string un)
		{
			string fp = getFilePath();
			string tmpfp = getFilePath();
			fo.removeLine(fp,tmpfp,un);
		}
		
		bool loginUser(string un, string pw) {
			
			int unCount;
			registerUser();
			
			for(int i = 0; i < userNames.size(); i++)
			{
				if (userNames[i] == un)
				{
					unCount = i;
				}
			}

			
			if(passWords[unCount] == pw ) {
				
				a_un = userNames[unCount];
				a_pw = passWords[unCount];
				a_lv = userLevels[unCount];
				
				return true;
				
			}
			else {
				false;
			}
			
		}
	private:
};

class user : public uProc
{
	
};

#endif
