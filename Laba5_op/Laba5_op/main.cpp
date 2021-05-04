#include "libraries.h"

int main()
{
	// utf-8
	SetConsoleCP(65001); 
	SetConsoleOutputCP(65001);

	/*
	string filename;
	cout << "Enter the name of the file: ";
	getline(cin, filename);
	filename = "ukraine_poi.csv";
	readFile(filename);
	*/

	float latitude, longtitude, radius;
	string type;

	GetCoordinates(latitude, longtitude, radius, type);
	Earth location(latitude, longtitude, type, "", "", "");

	vector <Earth*> locations;
	FindLocatios(location, radius, type, locations);

	system("pause");
	return 0;
}