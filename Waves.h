#pragma once
#include "Monster.h"
#include "Button.h"
#include "Player.h"

const int numPerWave = 10;
const int numWaves = 10;

class Waves
{
private:
	int spawnCount;
	int waveCount;
	int timeBetweenSpawn;
	bool endOfWave;

public:
	Waves();
	void SendWaves(MapElement startPath, int timeCount);
	void WalkMonsters(MapElement grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE], Player &player);
	void DrawMonsters();
	void StartWave();

	Monster monsterWaves[numWaves][numPerWave]; //10 waves of 10 monsters MAKE PRIVATE?
};
