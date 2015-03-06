#pragma once
#include "Button.h"
#include <iostream>
using namespace std;


//Button
Button::Button()
{
	redValue = 255;
	greenValue = 215;
	blueValue = 0;
	loadedFont = false;
	font18 = NULL;
	pressed = false;
	activated = false;
}
void Button::LoadFont(ALLEGRO_FONT **font18)
{
	if(loadedFont == false)
	{
		*font18 = al_load_font("arial.ttf", 18, 0);
		loadedFont = true;
	}
}
//TowerButton
TowerButton::TowerButton()
{
	radius = 18;
}
void TowerButton::PressButton(bool leftClickUp)
{
	if(pressed == true && leftClickUp)
	{
		activated = true;
		pressed = false;
	}
	else if(pressed == false)
		pressed = !leftClickUp;
}
void TowerButton::DrawButton()
{
	al_draw_circle(xCenter, yCenter, radius, al_map_rgb(redValue, greenValue, blueValue), 1); 
}
void TowerButton::DrawButtonBorder()
{
	LoadFont(&font18);
	al_draw_text(font18, al_map_rgb(redValue, greenValue, blueValue), MAP_WIDTH + 20 + (DISP_WIDTH - MAP_WIDTH - 40)/2-60, 373, 0, "TOWER BASE");
	al_draw_rectangle(MAP_WIDTH + 20, 365, DISP_WIDTH - 20, 465, al_map_rgb(redValue, greenValue, blueValue), 1);
	al_draw_rectangle(MAP_WIDTH + 25, 370, DISP_WIDTH - 25, 395, al_map_rgb(redValue, greenValue, blueValue), 1);
}
void TowerButton::ResetButton()
{
	pressed = false;
	activated = false;
}
bool TowerButton::WithinButton(float xMouse, float yMouse)
{
	if(sqrt(pow(xMouse - xCenter, 2) + pow(yMouse - yCenter, 2)) <= radius)
		return true;
	return false;
}

//RedTowerButton
RedTowerButton::RedTowerButton()
{
	xCenter = MAP_WIDTH + 20 + radius + (DISP_WIDTH - 40 - MAP_WIDTH - radius*6)/4;
	yCenter = 430;
	redValue = 255;
	greenValue = 0;
	blueValue = 0;
}

//GreenTowerButton
GreenTowerButton::GreenTowerButton()
{
	xCenter = MAP_WIDTH + 20 + ((DISP_WIDTH - 20) - (MAP_WIDTH + 20))/2;
	yCenter = 430;
	redValue = 0;
	greenValue = 255;
	blueValue = 0;
}

//BlueTowerButton
BlueTowerButton::BlueTowerButton()
{
	xCenter = DISP_WIDTH - 20 - radius - (DISP_WIDTH - 40 - MAP_WIDTH - radius*6)/4;
	yCenter = 430;
	redValue = 0;
	greenValue = 0;
	blueValue = 255;
}

//StartPauseButton
StartPauseButton::StartPauseButton()
{
	xTop = MAP_WIDTH + 20;
	xBot = MAP_WIDTH + 10 + (DISP_WIDTH - MAP_WIDTH - 40)/2;
	yTop = 490;
	yBot = 530;
	activated = true;
}
bool StartPauseButton::GetPaused()
{
	return activated;
}
void StartPauseButton::Destroy()
{
	al_destroy_font(font18);
	loadedFont = false;
}
void StartPauseButton::DrawButton()
{
	LoadFont(&font18);
	if(pressed == false)
		al_draw_rectangle(xTop, yTop, xBot, yBot, al_map_rgb(redValue, greenValue, blueValue), 3);
	else
		al_draw_rectangle(xTop, yTop, xBot, yBot, al_map_rgb(redValue, greenValue, blueValue), 4);
	if(!activated)
		al_draw_text(font18, al_map_rgb(redValue, greenValue, blueValue), (xTop+xBot)/2-29, yTop+10, 0, "PAUSE");
	else
		al_draw_text(font18, al_map_rgb(redValue, greenValue, blueValue), (xTop+xBot)/2-29, yTop+10, 0, "START");
}
void StartPauseButton::PressButton(bool leftClickUp)
{
	if(pressed == true && leftClickUp)
	{
		if(activated)
			activated = false;
		else
			activated = true;
		pressed = false;
	}
	else if(pressed == false)
		pressed = !leftClickUp;
}
bool StartPauseButton::WithinButton(float xMouse, float yMouse)
{
	if(xMouse >= xTop && xMouse <= xBot && yMouse >= yTop && yMouse <= yBot)
		return true;
	return false;
}

//NextWaveButton
NextWaveButton::NextWaveButton()
{
	xTop = MAP_WIDTH + 30 + (DISP_WIDTH - MAP_WIDTH - 40)/2;
	xBot = DISP_WIDTH - 20;
	yTop = 490;
	yBot = 530;
}
void NextWaveButton::PressButton(bool leftClickUp, Waves &waves)
{
	if(pressed == true && leftClickUp)
	{
		waves.StartWave();
		pressed = false;
	}
	else if(pressed == false)
		pressed = !leftClickUp;
}
void NextWaveButton::DrawButton()
{
	//LoadFont(&font18);
	//al_draw_text(font18, al_map_rgb(redValue, greenValue, blueValue), (xTop+xBot)/2-40, yTop+10, 0, "NEXT WAVE");
	if(pressed == false)
	{
		al_draw_rectangle(xTop, yTop, xBot, yBot, al_map_rgb(redValue, greenValue, blueValue), 3);
		al_draw_triangle((xTop+xBot)/2-9, yTop+12, (xTop+xBot)/2-9, yTop+28, (xTop+xBot)/2+7, yTop+20, al_map_rgb(redValue, greenValue, blueValue), 2);
		al_draw_rectangle((xTop+xBot)/2+7, yTop+12, (xTop+xBot)/2+10, yTop+28, al_map_rgb(redValue, greenValue, blueValue), 2);
	}
	else
	{
		al_draw_rectangle(xTop, yTop, xBot, yBot, al_map_rgb(redValue, greenValue, blueValue), 4);
		al_draw_triangle((xTop+xBot)/2-9, yTop+12, (xTop+xBot)/2-9, yTop+28, (xTop+xBot)/2+7, yTop+20, al_map_rgb(redValue, greenValue, blueValue), 3);
		al_draw_rectangle((xTop+xBot)/2+7, yTop+12, (xTop+xBot)/2+10, yTop+28, al_map_rgb(redValue, greenValue, blueValue), 3);
	}

}
bool NextWaveButton::WithinButton(float xMouse, float yMouse)
{
	if(xMouse >= xTop && xMouse <= xBot && yMouse >= yTop && yMouse <= yBot)
		return true;
	return false;
}

//UpgradeButton
UpgradeButton::UpgradeButton()
{
	live = false;
	pressed = false;
	radius = 10;
	activated = true;
}
void UpgradeButton::DrawButton()
{
	if(live && activated)
	{
		if(pressed == false)
			al_draw_circle(xCenter, yCenter, radius, al_map_rgb(redValue, greenValue, blueValue), 1);
		else
			al_draw_circle(xCenter, yCenter, radius, al_map_rgb(redValue, greenValue, blueValue), 2);
	}
	else if(live && !activated)
	{
		al_draw_circle(xCenter, yCenter, radius, al_map_rgb(redValue/2, greenValue/2, blueValue/2), 1);
	}
}
bool UpgradeButton::WithinButton(float xMouse, float yMouse)
{
	if(live)
	{
		if(sqrt(pow(xMouse - xCenter, 2) + pow(yMouse - yCenter, 2)) <= radius)
			return true;
	}
	return false;
}
UpgradeRedButton::UpgradeRedButton()
{
	redValue = 255;
	greenValue = 0;
	blueValue = 0;
	xCenter = MAP_WIDTH + 20 + radius + (DISP_WIDTH - 40 - MAP_WIDTH - radius*6)/4;
	yCenter = 320;
}
void UpgradeRedButton::PressButton(MapElement *grid, bool leftClickUp)
{
	if(live && pressed == true && leftClickUp && grid->redTower.GetRedUpgrade()+grid->redTower.GetGreenUpgrade()+grid->redTower.GetBlueUpgrade() < 10
		&& grid->greenTower.GetRedUpgrade()+grid->greenTower.GetGreenUpgrade()+grid->greenTower.GetBlueUpgrade() < 10
		&& grid->blueTower.GetRedUpgrade()+grid->blueTower.GetGreenUpgrade()+grid->blueTower.GetBlueUpgrade() < 10)
	{
		grid->redTower.IncreaseUpgrade(1);
		grid->greenTower.IncreaseUpgrade(1);
		grid->blueTower.IncreaseUpgrade(1);
		pressed = false;
	}
	else if(live && pressed == false)
		pressed = !leftClickUp;
}

UpgradeGreenButton::UpgradeGreenButton()
{
	redValue = 0;
	greenValue = 255;
	blueValue = 0;
	xCenter = MAP_WIDTH + 20 + ((DISP_WIDTH - 20) - (MAP_WIDTH + 20))/2;
	yCenter = 320;
}
void UpgradeGreenButton::PressButton(MapElement *grid, bool leftClickUp)
{
	if(live && pressed == true && leftClickUp && grid->redTower.GetRedUpgrade()+grid->redTower.GetGreenUpgrade()+grid->redTower.GetBlueUpgrade() < 10
		&& grid->greenTower.GetRedUpgrade()+grid->greenTower.GetGreenUpgrade()+grid->greenTower.GetBlueUpgrade() < 10
		&& grid->blueTower.GetRedUpgrade()+grid->blueTower.GetGreenUpgrade()+grid->blueTower.GetBlueUpgrade() < 10)
	{
		grid->redTower.IncreaseUpgrade(2);
		grid->greenTower.IncreaseUpgrade(2);
		grid->blueTower.IncreaseUpgrade(2);
		pressed = false;
	}
	else if(live && pressed == false)
		pressed = !leftClickUp;
}

UpgradeBlueButton::UpgradeBlueButton()
{
	redValue = 0;
	greenValue = 0;
	blueValue = 255;
	xCenter = DISP_WIDTH - 20 - radius - (DISP_WIDTH - 40 - MAP_WIDTH - radius*6)/4;
	yCenter = 320;
}
void UpgradeBlueButton::PressButton(MapElement *grid, bool leftClickUp)
{
	if(live && pressed == true && leftClickUp && grid->redTower.GetRedUpgrade()+grid->redTower.GetGreenUpgrade()+grid->redTower.GetBlueUpgrade() < 10
		&& grid->greenTower.GetRedUpgrade()+grid->greenTower.GetGreenUpgrade()+grid->greenTower.GetBlueUpgrade() < 10
		&& grid->blueTower.GetRedUpgrade()+grid->blueTower.GetGreenUpgrade()+grid->blueTower.GetBlueUpgrade() < 10)
	{
		grid->redTower.IncreaseUpgrade(3);
		grid->greenTower.IncreaseUpgrade(3);
		grid->blueTower.IncreaseUpgrade(3);
		pressed = false;
	}
	else if(live && pressed == false)
		pressed = !leftClickUp;
}
