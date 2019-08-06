//Name: Ethan Thomas
//Class: CS 131 Section A
//Description : This program reads into 2 different employee data
//files and outputs them to the user in descending order based
//on total hours worked in one week. It does this action one
//file at a time.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Employee
{
	string name;
	vector <int> hours;
	int totalHrs;
};

//This funtion reads into the file and stores the data
vector<Employee*> read(ifstream & fin, vector<Employee*>workers, int &size);

//This function will sort the vector in descending order
//of total hours in a week(most hours to least hours)
void sort(vector<Employee*>workers, int size);

//This function will output the vector to the user
void output(vector<Employee*>workers, int size);

int main()
{
	
	vector<Employee*>workers;
	ifstream fin;
	string user_input = "";
	int size;

	fin.open("empdata3.txt");

	while (fin.fail())
	{
		cout << "Unable to find the input file." << endl;
		cout << "Would you like to try to access employee files again?"
			<< "If Yes enter Y otherwise enter N to exit program:";
		cin >> user_input;
		if (user_input == "N")
		{
			exit(0);
		}
		else
		{
			fin.close();
			fin.clear();
			fin.open("empdata3.txt");
		}
	}

	workers = read(fin,workers, size);
	sort(workers, size);
	output(workers, size);
	system("pause");

	system("CLS");
	for (int i = 0; i < size; i++)
	{
		delete workers[i];
	}
	fin.close();
	fin.clear();
	fin.open("empdata4.txt");

	while (fin.fail())
	{
		cout << "Unable to find the input file." << endl;
		cout << "Would you like to try to access employee files again?"
			<< "If Yes enter Y otherwise enter N to exit program:";
		cin >> user_input;
		if (user_input == "N")
		{
			exit(0);
		}
		else
		{
			fin.close();
			fin.clear();
			fin.open("empdata4.txt");
		}
	}

	workers = read(fin,workers, size);
	sort(workers, size);
	output(workers, size);
	fin.close();

	system("pause");
	for (int i = 0; i < size; i++)
	{
		delete workers[i];
	}
	return 0;
}

vector<Employee*> read(ifstream & fin, vector<Employee*>workers, int &size)
{
	int total;
	

	fin >> size;
	
	

	for (int i = 0; i < size; ++i)
	{
		
		
		workers.resize(size);
		workers[i] = new Employee;
	    workers[i]->hours.resize(7);
		fin >> workers[i]->name;
		workers[i]->totalHrs = 0;

		for (int j = 0; j < 7; ++j)
		{
			fin >> workers[i]->hours[j];
			workers[i]->totalHrs += workers[i]->hours[j];
		}
		
	}
	return workers;
}

void sort(vector<Employee*>workers, int size)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (workers[i+1]->totalHrs > workers[i]->totalHrs)
			{
				flag = true;
				swap(*workers[i], *workers[i+1]);
								
			}
		}
	}
}

void output(vector<Employee*>workers, int size)
{
	cout << "Employee Weekly Hours:" << endl;
	cout <<"Name:" << "\t"<< "\t" << "\t"<< "\t"<< setw(4)
		 << "S" << setw(4)  << "M" << setw(4)
		 << "T" << setw(4)  << "W" << setw(4)
		 << "TH" << setw(4) << "F" << setw(4)
		 << "S" << setw(4)  << "TTL" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << setw(24) << left << workers[i]->name << "\t";
		for (int j = 0; j < 7; ++j)
		{
			cout << setw(4) << right << workers[i]->hours[j];
		}
		cout << setw(4) << right << workers[i]->totalHrs;
		cout << endl;
	}
}

//Output:
//Employee Weekly Hours :
//Name:                      S   M   T   W  TH   F   S TTL
//Kirk, James               10  10   0  10  12   0   0  42
//Bosco, Sam                 7   3   8   7   2   5   7  39
//Rugg, James                7   3   8   7   2   5   7  39
//VanPelt, Grace             5   6   5   6   5   6   5  38
//Peters, Greg               5   6   5   6   5   6   5  38
//Jane, Patrick              9   3   7   5   8   0   0  32
//Lisbon, Teresa             2   3   8   3   6   3   5  30
//Rigsby, Wayne              9  10   4   7   0   0   0  30
//Lilly, Jack                2   3   8   3   6   3   5  30
//Theiss, Bill               9  10   4   7   0   0   0  30
//Cho, Kimball               8   8   3   0   8   2   0  29
//Daniels, Carl              8   8   3   0   8   2   0  29
//Minelli, Virgil            2   5   3   0   4   9   4  27
//McCoy, Lenard              0   4   0   8   4   0   2  18
//Scott, Annis               1   6   2   0   0   1   0  10
//
//Employee Weekly Hours :
//Name:                      S   M   T   W  TH   F   S TTL
//Kirk, James               10  10   0  10  12   0   0  42
//Ryan, Kevin                5   6   7   6   5   6   5  40
//Leslie, Eddie              5   6   5   6   7   6   5  40
//Uhura, Nyota              10  10   0   8  12   0   0  40
//Bosco, Sam                 7   3   8   7   2   5   7  39
//Rugg, James                7   3   8   7   2   5   7  39
//Chekov, Pavel              7   3   8   7   2   5   7  39
//VanPelt, Grace             5   6   5   6   5   6   5  38
//Peters, Greg               5   6   5   6   5   6   5  38
//Parish, Lanie              7   3   8   6   2   5   7  38
//Esposito, Javier           2   5   3   9   4   9   4  36
//Beckett, Kate              2   8   8   3   6   3   5  35
//Galloway, David            9  10   4   8   0   0   2  33
//Jane, Patrick              9   3   7   5   8   0   0  32
//Castle, Richard            4   3   7   5   8   0   5  32
//Sulu, Hikaru               2   3   8   5   6   3   5  32
//Lisbon, Teresa             2   3   8   3   6   3   5  30
//Rigsby, Wayne              9  10   4   7   0   0   0  30
//Lilly, Jack                2   3   8   3   6   3   5  30
//Theiss, Bill               9  10   4   7   0   0   0  30
//Montgo, Roy                9   2   4   7   0   0   8  30
//Cho, Kimball               8   8   3   0   8   2   0  29
//Daniels, Carl              8   8   3   0   8   2   0  29
//Rodgers, Martha            8   7   3   0   8   2   0  28
//Minelli, Virgil            2   5   3   0   4   9   4  27
//Chapel, Christine          1   6   2   8   9   1   0  27
//Kyle, John                 8   8   3   0   2   2   0  23
//McCoy, Lenard              0   4   0   8   4   0   2  18
//Rand, Janice               0   4   0   8   3   0   2  17
//Scott, Annis               1   6   2   0   0   1   0  10
