#pragma once
#include "Button.h"
#include "DisplayScreen.h"

class Menu
{
public:
	Menu();
	void DrawMenuElements(Player player);

	StartPauseButton startPause;
	NextWaveButton nextWaveButton;
	TowerButton towerButton;
	RedTowerButton redButton;
	GreenTowerButton greenButton;
	BlueTowerButton blueButton;
	DisplayScreen displayScreen;
};
