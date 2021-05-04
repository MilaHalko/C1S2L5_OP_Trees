#include "libraries.h"

int main()
{   /*
	// utf-8
	SetConsoleCP(65001); 
	SetConsoleOutputCP(65001);
     */
	string filename;
	cout << "Enter the name of the file: ";
	getline(cin, filename);
	filename = "ukraine_poi.csv";
	readFile(filename);
    
    
    float latitude, longitude, radius;
    string type;
    Dot location;

    GetCoordinates(latitude, longitude, radius, type, location);

    vector <Dot*> locations;
    FindLocatios(location, radius, type, locations);
    

	system("pause");
}
