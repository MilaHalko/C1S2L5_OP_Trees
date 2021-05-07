#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <math.h>
using namespace std;
namespace fs = std::filesystem;

struct Dot
{
	float latitude;
	float longitude;
	string data;

    float x = 6371 * cos(latitude * MP_PI / 180) * (longitude * MP_PI / 180);
	float y = 6371 * (latitude * MP_PI / 180);
};
