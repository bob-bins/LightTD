#pragma once
#include "MapElement.h"
#include "Player.h"

class MapElement;

class Monster
{
protected:
	bool live;
	int direction; //0 right, 1 up, 2 left, 3 down
	float distanceTravelled;
	float health;
	float maxHealth;
	float speed;
	float slowed;
	float xPos;
	float yPos;

public:
	Monster();
	void PlaceMonster(MapElement startPath);
	void WalkMonster(MapElement grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE], Player &player);
	void GotHit(float dmg, float slow);
	void DrawMonster();

	bool GetLive() {return live;}
	float GetMaxHealth() {return maxHealth;};
	float GetXPos() {return xPos;}
	float GetYPos() {return yPos;}

	void SetMaxHealth(float health) {maxHealth = health;}
};

class EasyMonster: public Monster
{
public:
	EasyMonster();
};
