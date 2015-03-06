#pragma once
#include "Monster.h"
#include "MapElement.h"
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

enum DIRECTION{RIGHT, UP, LEFT, DOWN};

//Monster
Monster::Monster()
{
	live = false;
	xPos = 0;
	yPos = 0;
	slowed = 0;
	direction = 4;
	distanceTravelled = COORD_BOX_SIZE;
}
void Monster::PlaceMonster(MapElement startPath)
{
	live = true;
	xPos = (startPath.cell.GetXTop() + startPath.cell.GetXBot())/2;
	yPos = (startPath.cell.GetYTop() + startPath.cell.GetYBot())/2;
}
void Monster::WalkMonster(MapElement grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE], Player &player)
{
	if(live)
	{
		int i = xPos/COORD_BOX_SIZE;
		int j = yPos/COORD_BOX_SIZE;
		distanceTravelled += speed - slowed;

		if(distanceTravelled >= COORD_BOX_SIZE)
		{
			if(grid[i + 1][j].pathElement.GetLive() && direction != LEFT)
			{
				direction = RIGHT;
			}
			else if(grid[i][j - 1].pathElement.GetLive() && direction != DOWN)
			{
				direction = UP;
			}
			else if(grid[i - 1][j].pathElement.GetLive() && direction != RIGHT)
			{
				direction = LEFT;
			}
			else if(grid[i][j + 1].pathElement.GetLive() && direction != UP)
			{
				direction = DOWN;
			}
			distanceTravelled = 0;
		}

		if(direction == RIGHT)
			xPos += speed - slowed;
		else if(direction == UP)
			yPos -= speed - slowed;
		else if(direction == LEFT)
			xPos -= speed + slowed;
		else if(direction == DOWN)
			yPos += speed + slowed;

		if(grid[i][j].pathElement.GetEnd() == true)
		{
			if(distanceTravelled >= COORD_BOX_SIZE*9/10)
			{
				live = false;
				player.LoseLife();
			}
		}
	}
}
void Monster::GotHit(float dmg, float slow)
{
	if(live)
	{
		health -= dmg;
		if(health <= 0)
			live = false;
		if(slowed < slow)
			slowed = slow;
	}
}
void Monster::DrawMonster()
{
	if(live)
		al_draw_filled_rectangle(xPos - 10, yPos - 10, xPos + 10, yPos + 10, al_map_rgb(health/maxHealth*200, health/maxHealth*200, health/maxHealth*200));
}

//EasyMonster
EasyMonster::EasyMonster()
{
	live = false;
	maxHealth = 50;
	health = maxHealth;
	speed = .7;
}
