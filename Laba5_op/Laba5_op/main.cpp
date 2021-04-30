#include "libraries.h"

int main()
{
	system("chcp 65001"); // utf-8

	string filename;
	cout << "Enter the name of the file: ";
	getline(cin, filename);
	filename = "ukraine_poi.csv";
	readFile(filename);


	system("pause");
	return 0;
}