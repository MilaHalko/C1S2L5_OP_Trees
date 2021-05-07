#include "Rectangle.h"

// функции названы по принципу check_object1_object2
// проверяют пересикаются ли заднные обьекты
bool check_point_rectangle(PointOnMap point, Rectangle rect)
{
	/*  
		**************(x2,y2)
		********************
		(x1,y1)*************
	*/

	if (point.x < rect.leftDown.x || point.x > rect.rightUp.x ||
		point.y < rect.leftDown.y || point.y > rect.rightUp.y) 
		return false;
	return true;
}

bool check_rectangles(Rectangle rect1, Rectangle rect2) // rect1 >= rect2
{
	if ((rect1.leftDown.x <= rect2.rightUp.x || rect1.rightUp.x >= rect2.leftDown.x) &&
		(rect1.leftDown.y <= rect2.rightUp.y || rect1.rightUp.y >= rect2.leftDown.y))
		return true;
	return false;
}

bool check_circle_rectangle(PointOnMap point, float R, Rectangle rect)
{
	float centerX = (rect.leftDown.x + rect.rightUp.x) / 2, // половина диагонали по X
		   centerY = (rect.leftDown.y + rect.rightUp.y) / 2, // .. по Y
		   width = -rect.leftDown.x + rect.rightUp.x, // ширина прямоугльника
		   height = -rect.leftDown.y + rect.rightUp.y; // высота пр-а
	
	// расстояние между центрами 
	float dist_x = abs(point.x - centerX);
	float dist_y = abs(point.y - centerY);
	// если центры слишком далеко и пересечение невозможно 
	if (dist_x > width / 2 + R) return false;
	if (dist_y > height / 2 + R) return false;
	// если центр круга внутри пр-а
	if (dist_x <= width / 2) return true; 
	if (dist_y <= height / 2) return true; 
	// (расстояние до угла)^2
	float distance = pow(dist_x - width / 2, 2) + pow(dist_y - height / 2, 2);
	return distance <= pow(R, 2);
}

bool check_circle_point(PointOnMap center, float R, PointOnMap point)
{
	return pow(center.x - point.x, 2) + pow(center.y - point.y, 2) <= pow(R, 2); // расстояние от центра до точки <= радиус
}