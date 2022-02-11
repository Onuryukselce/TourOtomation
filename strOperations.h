#ifndef STROPERATIONS_H
#define STROPERATIONS_H
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "screenOperations.h"

        
using namespace std;

class strOperations
{
	public:
		string toString;
		
		char* strToChar(std::string str) 
		{
			std::ostringstream iss;
			iss << str;
			std::string s = iss.str();
			char* pString = new char[s.length() + 1];
			std::copy(s.c_str(), s.c_str() + s.length() + 1, pString);
			char* toCh = pString;
			return toCh;
		}
		
		void centerString(string str) 
		{
			
			int l = str.size();
			int pos = (int)((90-l)/2);
			for (int i = 0; i <pos; i++)
			{
				cout<<" ";
				
			}
			cout<<str<<endl;
		}
		
			void allCenterString(string str)
		{
			int l = str.size();
			int pos1 = (int)((90-l)/2);
			int pos2 = 15;
			for(int i = 0; i < pos2; i++ )
			{
				cout << endl;
			}
			for(int i = 0; i <pos1; i++)
			{
				cout <<" ";
			}
			cout << str << endl;
		}
		void allCenterAnimatedString(string str)
		{
			int l = str.size();
			int pos1 = (int)((90-l)/2);
			int pos2 = 15;
			for(int i = 0; i < pos2; i++ )
			{
				cout << endl;
			}
			for(int i = 0; i <pos1; i++)
			{
				cout <<" ";
			}
			for(int a = 0; a < str.size(); a++)
			{
				cout<<str[a]<<flush;
				Sleep(8); 
			}
		}
		
		void centerAnimatedString(string str)
		{
			int l = str.size();
			int pos = (int)((90-l)/2);
			for (int i = 0; i <pos; i++)
			{
				cout<<" ";
				
			}
			
			for(int a = 0; a < str.size(); a++)
			{
				cout<<str[a]<<flush;
				Sleep(8); 
			}
			
			
		}
		
		int strToInt(std::string str)
		{
			std::istringstream iss(str);
			int toInt;
			iss >> toInt; 
		}
		
		long long int strToLong(std::string str)
		{
			std::istringstream iss(str);
			long long int toLong;
			iss >> toLong;
			
			return toLong;
		}
		
		string &toStr (long long int x) {
			
			std::stringstream iss;
			string toStr;
			iss << x;
			
			toString = iss.str();
			
			return toString;
		}
		
		string &toStr(int x) {
			std::stringstream iss;
			string toStr;
			iss << x;
			
			toString = iss.str();
			
			return toString;
		}
		
		string &toStr (double x) {
			std::stringstream iss;
			string toStr;
			iss << x;
			
			toString = iss.str();
			
			return toString;
		}
		
		string &toStr (float x) {
			std::stringstream iss;
			string toStr;
			iss << x;
			
			toString = iss.str();
			
			return toString;
		}
		
		string &toStr (char* x) {
			std::stringstream iss;
			string toStr;
			iss << x;
			
			toString = iss.str();
			
			return toString;
		}
		
		
	protected:
};

#endif
