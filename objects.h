/*
1. make monster pathfinding automatic
2. make a variety of monsters in each wave, make multiple waves per level
3. have a start, pause, and restart button

#include <math.h>


class MenuButton
{
public:
	void Activate();

	bool active;
	int xCenter;
	int yCenter;
};
class Start: public MenuButton
{
public:
	Start();
	void DrawButton();
};
Start::Start()
{
	active = false;
	xCenter = DISP_WIDTH - 75;
	yCenter = MAP_HEIGHT - 50;
}
void Start::DrawButton()
{
	al_draw_filled_rounded_rectangle(xCenter-50, yCenter-25, xCenter+50, yCenter+25, 10, 10,  al_map_rgb(0, 255, 0));
}
class Pause: public MenuButton
{
public:

};


class Path
{
public:
	Path();
	void CreatePath1(); //straight line
	void DrawPath();

	int xTopStart, yTopStart;
	int xTopEnd, yTopEnd;
	Coordinates path[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE];
};
Path::Path()
{
	xTopStart = yTopStart = xTopEnd = yTopEnd = NULL;
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
			path[i][j].xTop = path[i][j].yTop = path[i][j].xBot = path[i][j].yBot = NULL;
}
void Path::CreatePath1()
{
	/*xStart = COORD_BOX_SIZE/2 +1;
	yStart = MAP_HEIGHT/2 - COORD_BOX_SIZE/2 + 1;
	for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
	{
		path[MAP_HEIGHT/COORD_BOX_SIZE/2][i].xCenter = i*COORD_BOX_SIZE + xStart;
		path[MAP_HEIGHT/COORD_BOX_SIZE/2][i].yCenter = yStart;
		if(i == MAP_WIDTH/COORD_BOX_SIZE - 1)
		{
			xEnd = i*COORD_BOX_SIZE + xStart;
			yEnd = MAP_HEIGHT/2 - COORD_BOX_SIZE/2 + 1;
		}
	}
}
void Path::DrawPath()
{
	/*for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
		{
			if(path[i][j].xCenter != NULL && path[i][j].yCenter != NULL)
				al_draw_filled_rectangle(path[i][j].xCenter - COORD_BOX_SIZE/2, path[i][j].yCenter - COORD_BOX_SIZE/2, 
					path[i][j].xCenter + COORD_BOX_SIZE/2, path[i][j].yCenter + COORD_BOX_SIZE/2 - 1, al_map_rgb(100, 100, 100)); //width of path must be 1 smaller than coord box size
		
		}
}
class Grid
{
public:
	Grid(); //initializes grid elements with even spacing
	void DrawGrid();

	Coordinates grid[MAP_WIDTH/COORD_BOX_SIZE][MAP_HEIGHT/COORD_BOX_SIZE];
};
Grid::Grid()
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
		{
			grid[i][j].xTop = i*COORD_BOX_SIZE + 1;
			grid[i][j].yTop = j*COORD_BOX_SIZE + 1;
			grid[i][j].xBot = i*COORD_BOX_SIZE + COORD_BOX_SIZE;
			grid[i][j].yBot = j*COORD_BOX_SIZE + COORD_BOX_SIZE;
		}
}
void Grid::DrawGrid()
{
	for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)	
			al_draw_rectangle(grid[i][j].xTop, grid[i][j].yTop, grid[i][j].xBot, grid[i][j].yBot, al_map_rgb(0, 255, 255), 1);
}
///////////////////////////////////////////////////
/*class Projectile
{
public:
	

	bool live;
	int monsterID;
	int xCenter;
	int yCenter;
	int redValue;
	int greenValue;
	int blueValue;
	float damage;
	float slow;
	float splash;
};
class RedProjectile: public Projectile
{
public:
	RedProjectile();
	void UpdatePosition(int mx, int my, int monstID);

	int speed;
};
void RedProjectile::UpdatePosition(int mx, int my, int monstID)
{
		if(live == true && monsterID == monstID)
		{
			float xinc = mx-xCenter;
			float yinc = my-yCenter;
			float hypot = sqrt(pow(xinc, 2)+pow(yinc, 2));
			xCenter = xCenter + xinc/hypot*speed;
			yCenter = yCenter + yinc/hypot*speed;
		}
}
class GreenProjectile: public Projectile
{

};
class BlueProjectile: public Projectile
{

};
class Tower
{
public:
	Tower();

	bool live;
	int xCenter;
	int yCenter;
	int redValue;
	int greenValue;
	int blueValue;
	float cooldown;
	float range;
	Projectile projectile[20];
};
class RedTower: public Tower
{

};
class GreenTower: public Tower
{

};
class BlueTower: public Tower
{

};

///////////////////////////////////////////////////
class Monster
{
public:
	void PlaceMonster(int xStart, int yStart); //parameters are starting coords of path
	void WalkMonster(int xEnd, int yEnd);
	void GotHit(float dmg);
	void DrawMonster();

	bool live;
	float health;
	float speed;
	int xPos;
	int yPos;
};
void Monster::PlaceMonster(int xStart, int yStart)
{
	live = true;
	xPos = xStart;
	yPos = yStart;
}
void Monster::WalkMonster(int xEnd, int yEnd)
{
	if(live)
		xPos += speed;
	if(abs(xPos-xEnd) == 0 && abs(yPos-yEnd) == 0)
		live = false;
	/*for(int j=0; j<MAP_HEIGHT/COORD_BOX_SIZE ; j++)
		for(int i=0; i<MAP_WIDTH/COORD_BOX_SIZE; i++)
		{
			if(xPos+COORD_BOX_SIZE == p.path[i][j].xCenter && yPos == p.path[i][j].yCenter)
			{
				//walk right
			}
			if(xPos == p.path[i][j].xCenter && yPos+COORD_BOX_SIZE == p.path[i][j].yCenter)
			{
				//walk up
			}
		}
}
void Monster::GotHit(float dmg)
{
	health -= dmg;
	if(health <= 0)
		live = false;
}
void Monster::DrawMonster()
{
	if(live)
		al_draw_filled_rectangle(xPos - 15, yPos - 15, xPos + 15, yPos + 15, al_map_rgb(health*2, health*2, health*2));
}
class EasyMonster: public Monster
{
public:
	EasyMonster();
};
EasyMonster::EasyMonster()
{
	live = false;
	health = 100;
	speed = 1;
}
class Wave
{
public:
	Wave();
	void SpawnMonster(int frameCount, int xStart, int yStart);
	void WalkMonsters(int xEnd, int yEnd);
	void DrawMonsters();

	int monsterCount;
	int cooldown;
	EasyMonster easyMonst[10];
};
Wave::Wave()
{
	monsterCount = 0;
	cooldown = 120;
};
void Wave::SpawnMonster(int frameCount, int xStart, int yStart)
{
	if(frameCount % cooldown == 0 && monsterCount < 10)
	{
		easyMonst[monsterCount].PlaceMonster(xStart, yStart);
		monsterCount++;
	}
}
void Wave::DrawMonsters()
{
	for(int i=0; i<10; i++)
		easyMonst[i].DrawMonster();
}
void Wave::WalkMonsters(int xEnd, int yEnd)
{
	for(int i=0; i<10; i++)
		if(easyMonst[i].live == true)
			easyMonst[i].WalkMonster(xEnd, yEnd);
}
///////////////////////////////////////////////////
class Map
{
public:
	Map();
	void GetPath(int pathNum);
	void DrawMapElements();
	void SpawnWave();

	Grid mapGrid;
	Path mapPath;
	Wave testWave;
};
Map::Map(){}
void Map::GetPath(int pathNum)
{
	if(pathNum == 1)
		mapPath.CreatePath1();
}
void Map::DrawMapElements()
{
	mapGrid.DrawGrid();
	mapPath.DrawPath();
	testWave.DrawMonsters();
}*/
