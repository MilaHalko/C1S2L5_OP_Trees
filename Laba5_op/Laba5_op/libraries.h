#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>
using namespace std;
namespace fs = std::filesystem;

struct Dot
{
	float latitude;
	float longitude;
	string data;

	float x;
	float y;
};