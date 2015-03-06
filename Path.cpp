#pragma once
#include "Path.h"

Path::Path(int pathNum, MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE])
{
	switch(pathNum)
	{
		case 1: CreatePath1(grid);
				break;
		case 2: CreatePath2(grid);
				break;
	}
}
void Path::CreatePath1(MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE])
{
	for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
	{
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].cell.SetIsEmpty(false);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetLive(true);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetXTop(i*COORD_BOX_SIZE);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetYTop(MAP_HEIGHT/2);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetYBot(MAP_HEIGHT/2 + COORD_BOX_SIZE);
		if(i == 0)
			grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetStart(true);
		if(i == MAP_WIDTH/COORD_BOX_SIZE - 1)
			grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetEnd(true);
	}
}
void Path::CreatePath2(MapElement (&grid)[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE])
{
	for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE/3; i++)
	{
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].cell.SetIsEmpty(false);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetLive(true);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetXTop(i*COORD_BOX_SIZE);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetYTop(MAP_HEIGHT/2);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
		grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetYBot(MAP_HEIGHT/2 + COORD_BOX_SIZE);
		if(i == 0)
			grid[i][MAP_HEIGHT/COORD_BOX_SIZE/2].pathElement.SetStart(true);
	}
	for(int j=MAP_HEIGHT/COORD_BOX_SIZE/2; j>0; j--)
	{
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].cell.SetIsEmpty(false);
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetLive(true);
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetXTop(MAP_WIDTH/3);
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetYTop(MAP_HEIGHT/2 - j*COORD_BOX_SIZE);
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetXBot(MAP_WIDTH/3 + COORD_BOX_SIZE);
		grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetYBot(MAP_HEIGHT/2 - j*COORD_BOX_SIZE + COORD_BOX_SIZE);
		if(j == 1)
			grid[MAP_WIDTH/COORD_BOX_SIZE/3][j].pathElement.SetEnd(true);
	}
}
