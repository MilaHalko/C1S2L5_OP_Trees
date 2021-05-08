#include "RTree.h"
#include <windows.h>
#include <fstream>

void parse(string path, vector<PointOnMap>& items);

int main()
{
	SetConsoleOutputCP(65001);
    PointOnMap point;
    float radius;
    string type, subtype;
    vector<PointOnMap> items;
    
    cout << "Latitude = "; cin >> point.latitude;
    cout << "Longtitude = "; cin >> point.longitude;
    cout << "Radius = "; cin >> radius;
    cout << "Type = "; cin >> type;
    cout << "Subtype = "; cin >> subtype;
    cout << "Parsing..." << endl;

    point.converse();

    parse("ukraine_poi.csv", items);

    cout << "Making a tree..." << endl;
    RTree tree(0., 0., 7000., 7000.);
    for (auto i : items)
    {
        tree.addPoint(tree.getRoot(), i);
    }
    cout << "Build successfuly!" << endl;

    vector<PointOnMap> res;
    tree.findPointsInCircle(tree.getRoot(), point, radius, type, subtype, res);

    cout << "Number of results found: " << res.size() << endl << endl;
    for (int i = 0; i < res.size(); i++) 
    {
        printf("%i) ", i);
        cout << res[i].latitude << "; " << res[i].longitude << "; " << res[i].type << "; " << res[i].subtype << "; " << res[i].name << "; " << res[i].address << "; " << endl;
    }

	system("pause");
	return 0;
}

void parse(string path, vector<PointOnMap>& items)
{
    ifstream fin;
    fin.open(path);

    if (!fin) cout << "Unable to open!" << endl;
    else
    {
        string str;

        while (!fin.eof())
        {
            str = "";
            getline(fin, str);

            int count = 0;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == ',') str[i] = '.';
                if (str[i] == ';') count++;
            }

            if (count == 6)
            {
                PointOnMap point;

                point.latitude = stof(str.substr(0, str.find(";")));
                str.erase(0, str.find(";") + 1);

                point.longitude = stof(str.substr(0, str.find(";")));
                str.erase(0, str.find(";") + 1);

                point.type = str.substr(0, str.find(";"));
                str.erase(0, str.find(";") + 1);

                point.subtype = str.substr(0, str.find(";"));
                str.erase(0, str.find(";") + 1);

                point.name = str.substr(0, str.find(";"));
                str.erase(0, str.find(";") + 1);

                point.address = str.substr(0, str.find(";"));
                str.erase(0, str.find(";") + 1);

                point.converse();
                items.push_back(point);
            }
        }
    }
    fin.close();
}