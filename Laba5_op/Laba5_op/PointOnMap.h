#pragma once
#include <string>
#include <iostream>
using namespace std;

struct PointOnMap
{
	float x, y; // координаты
	float latitude, longitude; // широта, долгота
	string type = "", subtype = "", name = "", address = "";
	void converse(); // перевод в x, y
};

