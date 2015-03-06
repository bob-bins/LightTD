#pragma once
#include "Map.h"
#include <iostream>
using namespace std;

enum COLOR{NO_COLOR, RED, GREEN, BLUE};

Map::Map()
{
	chosenTowerColor = 0;
	chosenTowerXCoord = -1;
	chosenTowerYCoord = -1;
	leftClickUp = true;
}
void Map::ButtonPressCheck(int xMouse, int yMouse, Player &player) /////////////////////&player
{
	if(leftClickUp == true)
		leftClickUp = false;
	else if(leftClickUp == false)
		leftClickUp = true;

	//start and pause button
	if(gameMenu.startPause.WithinButton(xMouse, yMouse))
		gameMenu.startPause.PressButton(leftClickUp);

	//next wave button
	if(gameMenu.nextWaveButton.WithinButton(xMouse, yMouse))
		gameMenu.nextWaveButton.PressButton(leftClickUp, gameGrid.gridWaves);

	//red tower button
	if(gameMenu.redButton.WithinButton(xMouse, yMouse))
	{
		if(gameMenu.redButton.GetPressed() && leftClickUp)
		{
			chosenTowerColor = 1;
			gameMenu.displayScreen.SetGrid(0, gameGrid.grid[0][0]);  //lazyyyyyyyyyyy cheaterrrrr [0][0] could have a tower placed on it
		}
		if(gameMenu.redButton.GetActivated() == true)
		{
			chosenTowerColor = 0;
			gameMenu.displayScreen.ClearDisplay();
		}
		gameMenu.redButton.PressButton(leftClickUp);
	}
	else if(gameMenu.redButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) && !leftClickUp)
	{
		gameGrid.PlaceTower(xMouse, yMouse, 1);
		gameMenu.redButton.ResetButton();
		chosenTowerColor = 0;
	}
	else if(gameMenu.redButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) == false)
	{
		gameMenu.redButton.ResetButton();
		gameMenu.displayScreen.ClearDisplay();
		chosenTowerColor = 0;
	}
		
	//green tower button
	if(gameMenu.greenButton.WithinButton(xMouse, yMouse))
	{
		if(gameMenu.greenButton.GetPressed() && leftClickUp)
		{
			chosenTowerColor = 2;
			gameMenu.displayScreen.SetGrid(1, gameGrid.grid[0][0]);
		}
		if(gameMenu.greenButton.GetActivated() == true)
		{
			chosenTowerColor = 0;
			gameMenu.displayScreen.ClearDisplay();
		}
		gameMenu.greenButton.PressButton(leftClickUp);
	}
	else if(gameMenu.greenButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) && !leftClickUp)
	{
		gameGrid.PlaceTower(xMouse, yMouse, 2);
		gameMenu.greenButton.ResetButton();
		chosenTowerColor = 0;
	}
	else if(gameMenu.greenButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) == false)
	{
		gameMenu.greenButton.ResetButton();
		gameMenu.displayScreen.ClearDisplay();
		chosenTowerColor = 0;
	}

	//blue tower button
	if(gameMenu.blueButton.WithinButton(xMouse, yMouse))
	{
		if(gameMenu.blueButton.GetPressed() && leftClickUp)
		{
			chosenTowerColor = 3;
			gameMenu.displayScreen.SetGrid(2, gameGrid.grid[0][0]);
		}
		if(gameMenu.blueButton.GetActivated() == true)
		{
			chosenTowerColor = 0;
			gameMenu.displayScreen.ClearDisplay();
		}
		gameMenu.blueButton.PressButton(leftClickUp);
	}
	else if(gameMenu.blueButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) && !leftClickUp)
	{
		gameGrid.PlaceTower(xMouse, yMouse, 3);
		gameMenu.blueButton.ResetButton();
		chosenTowerColor = 0;
	}
	else if(gameMenu.blueButton.GetActivated() == true && gameGrid.CheckEmpty(xMouse,yMouse) == false)
	{
		gameMenu.blueButton.ResetButton();
		gameMenu.displayScreen.ClearDisplay();
		chosenTowerColor = 0;
	}

	//if player clicks on the grid
	if(xMouse/COORD_BOX_SIZE < MAP_WIDTH/COORD_BOX_SIZE && yMouse/COORD_BOX_SIZE < MAP_HEIGHT/COORD_BOX_SIZE)
	{
		if(gameGrid.GetGridCoord(xMouse/COORD_BOX_SIZE, yMouse/COORD_BOX_SIZE).redTower.GetLive() == true ||
			gameGrid.GetGridCoord(xMouse/COORD_BOX_SIZE, yMouse/COORD_BOX_SIZE).greenTower.GetLive() == true ||
			gameGrid.GetGridCoord(xMouse/COORD_BOX_SIZE, yMouse/COORD_BOX_SIZE).blueTower.GetLive() == true)
		{
			chosenTowerXCoord = xMouse/COORD_BOX_SIZE;
			chosenTowerYCoord = yMouse/COORD_BOX_SIZE;
			gameMenu.displayScreen.SetGrid(&gameGrid.GetGridCoord(xMouse/COORD_BOX_SIZE, yMouse/COORD_BOX_SIZE));
		}
		else
			gameMenu.displayScreen.ClearDisplay();

		gameMenu.startPause.ResetButton();
		gameMenu.redButton.ResetButton();
		gameMenu.greenButton.ResetButton();
		gameMenu.blueButton.ResetButton();
	}

	//upgrade buttons
		//red
	if(gameMenu.displayScreen.upgradeRed.WithinButton(xMouse, yMouse))
	{
		if(gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].redTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].greenTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].blueTower.GetLive() )
		{
			gameMenu.displayScreen.CheckUpgradeValid(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord]);
			gameMenu.displayScreen.upgradeRed.PressButton(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord], leftClickUp);
			gameMenu.displayScreen.SetGrid(&gameGrid.GetGridCoord(chosenTowerXCoord, chosenTowerYCoord));
		}
	}
		//green
	if(gameMenu.displayScreen.upgradeGreen.WithinButton(xMouse, yMouse))
	{
		if(gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].redTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].greenTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].blueTower.GetLive() )
		{
			gameMenu.displayScreen.CheckUpgradeValid(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord]);
			gameMenu.displayScreen.upgradeGreen.PressButton(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord], leftClickUp);
			gameMenu.displayScreen.SetGrid(&gameGrid.GetGridCoord(chosenTowerXCoord, chosenTowerYCoord));
		}
	}
		//blue
	if(gameMenu.displayScreen.upgradeBlue.WithinButton(xMouse, yMouse))
	{
		if(gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].redTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].greenTower.GetLive() ||
			gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord].blueTower.GetLive() )
		{
			gameMenu.displayScreen.CheckUpgradeValid(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord]);
			gameMenu.displayScreen.upgradeBlue.PressButton(&gameGrid.grid[chosenTowerXCoord][chosenTowerYCoord], leftClickUp);
			gameMenu.displayScreen.SetGrid(&gameGrid.GetGridCoord(chosenTowerXCoord, chosenTowerYCoord));
		}
	}

	//resetting those values
	if(leftClickUp)
	{
		gameMenu.displayScreen.upgradeRed.ResetButton();
		gameMenu.displayScreen.upgradeGreen.ResetButton();
		gameMenu.displayScreen.upgradeBlue.ResetButton();
	}
}
void Map::DrawMapElements(Player player)
{
	gameGrid.DrawGrid(chosenTowerColor, lastMouseXPos, lastMouseYPos);
	gameGrid.gridWaves.DrawMonsters();
	gameGrid.DrawGridElements();
	gameMenu.DrawMenuElements(player);
}
void Map::UpdateMapElements(int timeCount, Player &player)
{
	gameGrid.gridWaves.SendWaves(gameGrid.ReturnStartPath(), timeCount); //need to make so it changes gridwaves. pass by ref
	gameGrid.gridWaves.WalkMonsters(gameGrid.grid, player); //this one too i guess
	gameGrid.UpdateTowers();
	gameGrid.UpdateProjectiles();
}

