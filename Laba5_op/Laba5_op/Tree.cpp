#include "Tree.h"
int MaxDots = 10;

Tree::Tree()
{
	root = new Node;
	switcher = 0;
}

void Tree::GetCoordinates(float& radius, string& type, Dot dot)
{
	cout << "Write coordinates:" << endl << "Latitude is "; cin >> dot.latitude;
	cout << "." << endl;

	cout << "Longitude is "; cin >> dot.longitude;
	cout << "." << endl;

	cout << "Radius is "; cin >> radius;
	cout << "." << endl;

	cout << "Type is "; cin >> type;
	cout << "." << endl;
}


void Tree::insert(string data) // на вход идет строка
{
	Dot dot;

	dot.latitude = stof(data.substr(0, data.find(";")));
	data.erase(0, data.find(";") + 1);

	dot.longitude = stof(data.substr(0, data.find(";")));
	data.erase(0, data.find(";") + 1);

	dot.data = data;

	ChooseLeaf(root, dot);
}

void Tree::print()
{
	for (int i = 0; i < MaxDots; i++)
	{
		cout << root->dots[i].data << endl;
	}
}


void Tree::ChooseLeaf(Node* root, Dot dot)
{
	if (root->child_1 == nullptr && root->child_2 == nullptr) // если нет детей
	{
		root->AdjustBounds(dot); // расширить прямоугольник
		if (root->dots.size() < MaxDots) // если не переполнен
		{
			root->dots.push_back(dot); // добавляем точку
		}
		else
		{
			Split(root); // разделяем 
			ChooseLeaf(root, dot); // проверяем снова
		}
	}
	else
	{
		root->AdjustBounds(dot); // расширить прямоугольник
		if (switcher == 0) ChooseLeaf(root->child_1, dot); // переход к ребенку
		else ChooseLeaf(root->child_2, dot);
	}
}

void Tree::Split(Node* root)
{
	switcher = (switcher + 1) % 2; // чтобы делилось по горизонтали и вертикали 
	root->child_1 = new Node;
	root->child_2 = new Node;

	if (switcher == 0)
	{
		float half = (root->top - root->bottom) / 2; // половина высоты

		for (size_t i = 0; i < MaxDots; i++)
		{
			if (root->dots[i].latitude >= half)
			{
				root->child_1->AdjustBounds(root->dots[i]);
				root->child_1->dots.push_back(root->dots[i]);
			}
		}
	}
	else
	{
		float half = (root->right - root->left) / 2; // половина ширины

		for (size_t i = 0; i < MaxDots; i++)
		{
			if (root->dots[i].longitude >= half)
			{
				root->child_1->AdjustBounds(root->dots[i]);
				root->child_1->dots.push_back(root->dots[i]);
			}
		}
	}
}


void Tree::output(vector<Dot> &dots, string type)
{
    cout << "We found next entities in the sector: " << endl;
    int counter = 1;
    
    for (int i = 0; i < dots.size(); i++) {
        if (dots[i].data.find(type)) {
            cout << counter << ". " << dots[i].latitude << ";" << dots[i].longitude << ";" << dots[i].data << endl;
            counter++;
        }
    }
}


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


