#pragma once
#include "Path.h"
#include "Waves.h"

class Grid
{
public:
	Grid();
	bool CheckEmpty(int xCoord, int yCoord); //checks if grid cell is empty
	void DrawGrid(int chosenTowerColor, int lastMouseXPos, int lastMouseYPos);
	void DrawGridElements(); //draws towers and attacks
	void PlaceTower(int xMouse, int yMouse, int color);
	void UpdateTowers();
	void UpdateProjectiles();
	MapElement GetGridCoord(int col, int row) {return grid[col][row];}
	MapElement ReturnEndPath();
	MapElement ReturnStartPath();

	MapElement grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE]; //make private?
	Waves gridWaves; //make private?
};
