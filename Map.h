#pragma once
#include "Grid.h"
#include "Menu.h"
#include "Player.h"

class Map
{
public:
	Map();
	Menu ReturnGameMenu() {return gameMenu;}
	void ButtonPressCheck(int xMouse, int yMouse, Player &player); //for mouse clicks
	void DrawMapElements(Player player); //draws everything
	void UpdateMapElements(int timeCount, Player &player); //updates everything
	void SetMousePos(int x, int y) {lastMouseXPos = x; lastMouseYPos = y;}

private:
	bool leftClickUp;
	Grid gameGrid;
	int chosenTowerColor;
	int chosenTowerXCoord;
	int chosenTowerYCoord;
	int lastMouseXPos;
	int lastMouseYPos;
	Menu gameMenu;
};
