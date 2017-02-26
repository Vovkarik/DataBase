// DataBase1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

typedef map<string, vector<string>> DataBase;

void ReadDataBase(DataBase & dataBase)
{
	ifstream in("dbex.csv");
	string record;
	vector<string> fields;
	unsigned i = 0, j = 0;
	fields.resize(100);
	if (in.is_open())
	{
		getline(in, record);
		while (getline(in, record))
		{
			while (i != record.length())
			{
				if (record[i] != ',' && record[i] != '"')
				{
					fields[j] += record[i];
				}
				else if (record[i] = ',')
				{
					j++;
				}
				i++;
			}
			i = 0;
			j = 0;
			dataBase.insert(pair < string, vector<string>>(fields[0], fields));
			fields.clear();
			fields.resize(100);
		}
	}
	else
	{
		cout << "Failed to open database file" << endl;
	}
}

int main()
{
	DataBase db;
	string name;
	ReadDataBase(db);
	cout << "Enter Name :";
	getline(cin, name);
	cout << endl << "ID is: ";
	for (auto it = db.begin(); it != db.end(); ++it)
	{
		if (find(it->second.begin(), it->second.end(), name) != it->second.end())
		{
			cout << it->first << ",";
		}
	}
    return 0;
}

