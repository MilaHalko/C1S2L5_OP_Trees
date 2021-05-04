#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include "R-tree.h"
//#include <windows.h>
using namespace std;
//namespace fs = std::filesystem;

void readFile(string);
void GetCoordinates(float&, float&, float&, string&, Dot&);
void FindLocatios(Earth, float, vector <Earth>);
void CheckTheDistance(Node*, Earth, float, vector <Earth>);



