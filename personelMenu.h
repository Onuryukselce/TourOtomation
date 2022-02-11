#ifndef PERSONELMENU_H
#define PERSONELMENU_H
#include <iostream>
#include <string>
#include "fileOperation.h"
#include "strOperations.h"


class personelMenu
{
	public:
		personelMenu() {
			fileName = "personel.txt";
			tmp_fileName = "tmp_personel.txt";
			filePath = "data/staff/" + fileName;
			tmp_filePath = "data/staff/" + tmp_fileName;
		}
		
		void setFilePath(string f_Name, string _filePath)		
		{
			fileName = f_Name;
			filePath = _filePath + f_Name;
			tmp_filePath = "data/staff/" + filePath;
		}
		
		string &getFilePath()
		{
			return filePath;
		}
		
		string &getTmpFilePath() 
		{
			return tmp_filePath;
		}
	private:
		string filePath;
		string fileName;
		string tmp_filePath;
		string tmp_fileName;
};

class personelIslem : public personelMenu
{
	public:
		void AddPersonel(string id,string name, string surname, string age, string startYear, string position, string salary)
		{
			string str = id + "|" + name + "|" + surname + "|" + age + "|" + startYear + "|" + position + "|" + salary + "|" + "\n";
			fileOperation fo;
			string fp = getFilePath();
			fo.writeFile(fp,str);
		}
		
		void RemovePersonel(string id)
		{
			fileOperation fo;
			string fp = getFilePath();
			string tmpfp = getTmpFilePath();
			fo.removeLine(fp,tmpfp,id);
		}
		
		void ListPersonel()
		{
			fileOperation fo;
			string fp = getFilePath();
			fo.readFile(fp);
			cout << fo.outputText << endl;
		}
};
class personel : public personelIslem
{
	public:
		
	private:
};

#endif
