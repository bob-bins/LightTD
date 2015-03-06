#pragma once
#include "MapElement.h"

class Path
{
public:
	Path() {;}
	Path(int pathNum, MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE]);
	void CreatePath1(MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE]); //straight line
	void CreatePath2(MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE]); //backward L
};
