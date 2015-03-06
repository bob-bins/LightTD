#pragma once
#include "Waves.h"

Waves::Waves()
{
	spawnCount = 0;
	waveCount = 0;
	timeBetweenSpawn = 60;
	EasyMonster e;
	for(int j=0; j<10; j++)
	{
		for(int i=0; i<10; i++)
			monsterWaves[j][i] = e;
		e.SetMaxHealth(100*(1+j/10));
	}
	endOfWave = false;
}
void Waves::SendWaves(MapElement startPath, int timeCount)
{
	if(timeCount % timeBetweenSpawn == 0 && waveCount < 10 && endOfWave == false)
	{
		monsterWaves[waveCount][spawnCount].PlaceMonster(startPath);
		spawnCount++;
		if(spawnCount == 10)
		{
			spawnCount = 0;
			waveCount++;
			endOfWave = true;
		}
	}
}
void Waves::StartWave()
{
	endOfWave = false;
}
void Waves::WalkMonsters(MapElement grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE], Player &player)
{
	for(int j=0; j<10; j++)
		for(int i=0; i<10; i++)
			monsterWaves[j][i].WalkMonster(grid, player);
}
void Waves::DrawMonsters()
{
	for(int j=0; j<10; j++)
		for(int i=0; i<10; i++)
			monsterWaves[j][i].DrawMonster();
}
