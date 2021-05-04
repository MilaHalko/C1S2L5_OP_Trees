#include "R-tree.h"
/*
void readFile(string filename)
{
	ifstream fin;
	fin.open(fs::current_path().string() + "\\" + filename);

	if (!fin.is_open())
	{
		cout << "Unable to open the file!" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			string temp;
			getline(fin, temp);
			cout << temp << endl;
			system("pause");
			// action
		}
	}
	fin.close();
}
*/

void GetCoordinates(float& latitude, float& longitude, float& radius, string& type, Dot& location)
{
    cout << "Write coordinates:" << endl << "Latitude is "; cin >> latitude;
    cout << "." << endl;
    location.latitude = latitude;

    cout << "Longitude is "; cin >> longitude;
    cout << "." << endl;
    location.longitude = longitude;
    
    cout << "Radius is "; cin >> radius;
    cout << "." << endl;
    
    cout << "Type is "; cin >> type;
    cout << "." << endl;
}



