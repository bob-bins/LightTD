#pragma once
#include "Grid.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

enum COLORS{RED = 1, GREEN, BLUE};

Grid::Grid()
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
		{
			grid[i][j].cell.SetXTop(i*COORD_BOX_SIZE);
			grid[i][j].cell.SetYTop(j*COORD_BOX_SIZE);
			grid[i][j].cell.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
			grid[i][j].cell.SetYBot(j*COORD_BOX_SIZE + COORD_BOX_SIZE);

			grid[i][j].redTower.SetXTop(i*COORD_BOX_SIZE);
			grid[i][j].redTower.SetYTop(j*COORD_BOX_SIZE);
			grid[i][j].redTower.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
			grid[i][j].redTower.SetYBot(j*COORD_BOX_SIZE + COORD_BOX_SIZE);

			grid[i][j].greenTower.SetXTop(i*COORD_BOX_SIZE);
			grid[i][j].greenTower.SetYTop(j*COORD_BOX_SIZE);
			grid[i][j].greenTower.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
			grid[i][j].greenTower.SetYBot(j*COORD_BOX_SIZE + COORD_BOX_SIZE);

			grid[i][j].blueTower.SetXTop(i*COORD_BOX_SIZE);
			grid[i][j].blueTower.SetYTop(j*COORD_BOX_SIZE);
			grid[i][j].blueTower.SetXBot(i*COORD_BOX_SIZE + COORD_BOX_SIZE);
			grid[i][j].blueTower.SetYBot(j*COORD_BOX_SIZE + COORD_BOX_SIZE);
		}
	Path(2, grid);
}
bool Grid::CheckEmpty(int xCoord, int yCoord)
{
	if(xCoord/COORD_BOX_SIZE < MAP_WIDTH/COORD_BOX_SIZE && yCoord/COORD_BOX_SIZE < MAP_HEIGHT/COORD_BOX_SIZE)
		return grid[xCoord/COORD_BOX_SIZE][yCoord/COORD_BOX_SIZE].cell.GetIsEmpty();
	return false;
}
void Grid::DrawGrid(int chosenTowerColor, int lastMouseXPos, int lastMouseYPos)
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
			{
				if(grid[i][j].pathElement.GetLive() == false)
				{
					al_draw_rectangle(grid[i][j].cell.GetXTop() + .5, grid[i][j].cell.GetYTop() + .5, 
						grid[i][j].cell.GetXBot(), grid[i][j].cell.GetYBot(), al_map_rgb(20, 20, 20), 1);
				}
				if(lastMouseXPos < MAP_WIDTH && lastMouseYPos < MAP_HEIGHT && grid[lastMouseXPos/COORD_BOX_SIZE][lastMouseYPos/COORD_BOX_SIZE].cell.GetIsEmpty())
				{
					if(chosenTowerColor == RED)
					{
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, 10, al_map_rgb(255, 0, 0), 1);
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, grid[0][0].redTower.GetRange(), al_map_rgb(255, 0, 0), 1);
					}
					else if(chosenTowerColor == GREEN)
					{
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, 10, al_map_rgb(0, 255, 0), 1);
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, grid[0][0].greenTower.GetRange(), al_map_rgb(0, 255, 0), 1);
					}
					else if(chosenTowerColor == BLUE)
					{
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, 10, al_map_rgb(0, 0, 255), 1);
						al_draw_circle(lastMouseXPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, lastMouseYPos/COORD_BOX_SIZE*COORD_BOX_SIZE + COORD_BOX_SIZE/2, grid[0][0].blueTower.GetRange(), al_map_rgb(0, 0, 255), 1);
					}
				}
			}
}
void Grid::DrawGridElements()
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
		{
			if(grid[i][j].redTower.GetLive() == true)
			{
				grid[i][j].redTower.DrawTower();
				grid[i][j].redTower.DrawProjectiles();
			}
			else if(grid[i][j].greenTower.GetLive() == true)
			{
				grid[i][j].greenTower.DrawTower();
				int waveNum = grid[i][j].greenTower.GetMonsterID()/10;
				int monstNum = grid[i][j].greenTower.GetMonsterID()%10;
				if(gridWaves.monsterWaves[waveNum][monstNum].GetLive() && grid[i][j].greenTower.WithinRange(gridWaves.monsterWaves[waveNum][monstNum].GetXPos(), 
					gridWaves.monsterWaves[waveNum][monstNum].GetYPos()))
					grid[i][j].greenTower.DrawLaser(gridWaves.monsterWaves[waveNum][monstNum].GetXPos(), gridWaves.monsterWaves[waveNum][monstNum].GetYPos());
			}
			else if(grid[i][j].blueTower.GetLive() == true)
			{
				grid[i][j].blueTower.DrawTower();
				grid[i][j].blueTower.DrawFireAnimation();
			}
		}
}
void Grid::PlaceTower(int xMouse, int yMouse, int color)
{
	if(xMouse/COORD_BOX_SIZE < MAP_WIDTH/COORD_BOX_SIZE && yMouse/COORD_BOX_SIZE < MAP_HEIGHT/COORD_BOX_SIZE)
	{
		if(color == RED)
			grid[xMouse/COORD_BOX_SIZE][yMouse/COORD_BOX_SIZE].redTower.SetLive(true);
		else if(color == GREEN)
			grid[xMouse/COORD_BOX_SIZE][yMouse/COORD_BOX_SIZE].greenTower.SetLive(true);
		else if(color == BLUE)
			grid[xMouse/COORD_BOX_SIZE][yMouse/COORD_BOX_SIZE].blueTower.SetLive(true);

		grid[xMouse/COORD_BOX_SIZE][yMouse/COORD_BOX_SIZE].cell.SetIsEmpty(false);
	}
}
void Grid::UpdateTowers()
{
	for(int k=0; k<MAP_HEIGHT/COORD_BOX_SIZE; k++)
		for(int l=0; l<MAP_WIDTH/COORD_BOX_SIZE; l++)
		{
			//red towers
			int withinRangeCount = 0;
			int *temp;
			temp = new int[20]; //need to make DYNAMIC!!!!!!!!!!!???????????
			if(grid[l][k].redTower.GetLive())
				if(grid[l][k].redTower.TimeToFire())
				{
					for(int j=0; j<10; j++)
						for(int i=0; i<10; i++)
							if(gridWaves.monsterWaves[j][i].GetLive() && 
								grid[l][k].redTower.WithinRange(gridWaves.monsterWaves[j][i].GetXPos(), gridWaves.monsterWaves[j][i].GetYPos()))
							{
								temp[withinRangeCount] = j*10+i;
								withinRangeCount++;
							}
					if(withinRangeCount > 0)
						grid[l][k].redTower.FireProjectile(temp[rand()%withinRangeCount]);
					withinRangeCount = 0;
				}
			delete[] temp;

			//green towers
			if(grid[l][k].greenTower.GetLive())
				if(grid[l][k].greenTower.TimeToFire())
					for(int j=0; j<10; j++)
						for(int i=0; i<10; i++)
							if(gridWaves.monsterWaves[j][i].GetLive() && 
								grid[l][k].greenTower.WithinRange(gridWaves.monsterWaves[j][i].GetXPos(), gridWaves.monsterWaves[j][i].GetYPos()))
							{
								gridWaves.monsterWaves[j][i].GotHit(grid[l][k].greenTower.FireLaser(j*10+i), grid[l][k].greenTower.GetSlow());
								i=10;
								j=10;
							}

			//blue towers
			if(grid[l][k].blueTower.GetLive())
			{
				if(grid[l][k].blueTower.TimeToFire())
					for(int j=0; j<10; j++)
						for(int i=0; i<10; i++)
							if(gridWaves.monsterWaves[j][i].GetLive() && 
								grid[l][k].blueTower.WithinRange(gridWaves.monsterWaves[j][i].GetXPos(), gridWaves.monsterWaves[j][i].GetYPos()))
							{
								gridWaves.monsterWaves[j][i].GotHit(grid[l][k].blueTower.FireAttack(), grid[l][k].blueTower.GetSlow());
							}
				grid[l][k].blueTower.ReduceFireAnimationLength();
			}
		}
}
void Grid::UpdateProjectiles()
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
			for(int k=0; k<20; k++)
				if(grid[i][j].redTower.projectiles[k].GetLive())
				{
					int waveNum = grid[i][j].redTower.projectiles[k].GetMonsterID()/10;
					int monstNum = grid[i][j].redTower.projectiles[k].GetMonsterID()%10;
					grid[i][j].redTower.projectiles[k].UpdatePosition(gridWaves.monsterWaves[waveNum][monstNum].GetXPos(), 
						gridWaves.monsterWaves[waveNum][monstNum].GetYPos());
					gridWaves.monsterWaves[waveNum][monstNum].GotHit(grid[i][j].redTower.projectiles[k].CollideMonster(gridWaves.monsterWaves[waveNum][monstNum].GetXPos(), 
						gridWaves.monsterWaves[waveNum][monstNum].GetYPos()), grid[i][j].redTower.projectiles[k].GetSlow());
				}
}
MapElement Grid::ReturnEndPath()
{
	for(int j=0; j<MAP_WIDTH/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
			if(grid[i][j].pathElement.GetLive() == true && grid[i][j].pathElement.GetEnd() == true)
				return grid[i][j];
	return grid[0][0];
}
MapElement Grid::ReturnStartPath()
{
	for(int j=0; j<MAP_WIDTH/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
			if(grid[i][j].pathElement.GetLive() == true && grid[i][j].pathElement.GetStart() == true)
				return grid[i][j];
	return grid[0][0];
}
