#pragma once
#include "Globals.h"
#include "MapElement.h"
#include "Button.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class MapElement;

class DisplayScreen
{
private:
	int xPos;
	int yPos;
	float damage;
	float cooldown;
	float range;
	float slow;

	bool allowUpgrade;
	bool drawRange;
	bool redLive;
	bool greenLive;
	bool blueLive;
	bool goodToGo;
	bool loadedFont;

	MapElement grid;

	ALLEGRO_FONT *font15;
	ALLEGRO_FONT *font11;

public:
	DisplayScreen();
	void SetGrid(MapElement *grid); //rename to fit better
	void SetGrid(int tower, MapElement grid); //rename this to fit better
	void DrawBackground();
	void DrawDisplay(Player &player);
	void ClearDisplay();
	void Destroy();
	void LoadFont(ALLEGRO_FONT **font15, ALLEGRO_FONT **font11);
	void CheckUpgradeValid(MapElement *grid);

	UpgradeRedButton upgradeRed;
	UpgradeGreenButton upgradeGreen;
	UpgradeBlueButton upgradeBlue;
};
