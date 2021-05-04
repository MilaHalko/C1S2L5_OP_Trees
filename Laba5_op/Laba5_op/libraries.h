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
void FindLocatios(Dot, float, vector <Dot>&);
void CheckTheDistance(Node*, Earth, float, vector <Dot>&);



