#include "PointOnMap.h"

void PointOnMap::converse()
{      
    // радиус Земли = 6371
    // PI ~ 3.14159
    x = 6371 * cos(latitude * 3.14159 / 180) * (longitude * 3.14159 / 180);
    y = (latitude * 3.14159 / 180) * 6371;
}
