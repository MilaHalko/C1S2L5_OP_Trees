#pragma once
#include "PointOnMap.h"
#include <cmath>

struct Rectangle
{
	// MBR
	PointOnMap leftDown, rightUp;
};

bool check_point_rectangle(PointOnMap, Rectangle);
bool check_rectangles(Rectangle, Rectangle);
bool check_circle_rectangle(PointOnMap, float R, Rectangle);
bool check_circle_point(PointOnMap center, float R, PointOnMap point);
