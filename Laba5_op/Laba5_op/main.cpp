#include "Tree.h"

int main()
{
	// utf-8
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	Tree Rtree;
	string filename;
	cout << "Enter the name of the file: ";
	getline(cin, filename);
	filename = "test.csv";
	readFile(filename, Rtree);

	float radius;
	string type;
	Dot dot;
	Rtree.GetCoordinates(radius, type, dot);

	Rtree.print();
    vector<Dot> dots;
    Rtree.output(dots, type);
    

	system("pause");
	return 0;
}
