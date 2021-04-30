#include "R-tree.h"

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