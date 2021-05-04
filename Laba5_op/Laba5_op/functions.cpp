#include "R-tree.h"

void readFile(string filename, Tree Rtree)
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
			Rtree.insert(temp);
		}
	}
	fin.close();
}
