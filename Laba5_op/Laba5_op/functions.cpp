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


void FindLocatios(Earth location, float radius, vector <Earth> locations)
{
    int size = locations.size();
    CheckingLocation(tree.getRoot(), location, radius, locations);
}


void CheckingLocation(Node *node, Earth location, float radius, vector <Earth> locations)
{
    if (( location.type == node->left.type)  &&  (pow(location.getX() - node->left.getX(), 2)  +  (pow(location.getY() - node->left.getY(), 2)  <=  pow(radius, 2))){
        CheckingLocation(node->left, location, radius, locations);
    }

    if ((location.type == node->right.type) && (pow(location.getX() - node->rigth.getX(), 2) + (pow(location.getY() - node->right.getY(), 2) <= pow(radius, 2))){
        CheckingLocation(node->right, location, radius, locations);
    }
}
