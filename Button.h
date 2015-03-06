#pragma once
#include <math.h>
#include "Waves.h"
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

class Waves;

class Button
{
public:
	Button();
	void LoadFont(ALLEGRO_FONT **font18);
	void virtual ResetButton() {pressed = false; activated = false;}
	//void virtual DrawButton();
	//void virtual PressButton();
	//bool virtual WithinButton(float xMouse, float yMouse);

	ALLEGRO_FONT *font18;
	bool loadedFont;
	bool pressed;
	bool activated;
	int redValue;
	int greenValue;
	int blueValue;
};

class TowerButton: public Button
{
protected:
	int xCenter;
	int yCenter;
	int radius;

public:
	TowerButton();
	int GetXCenter() {return xCenter;}
	int GetYCenter() {return yCenter;}
	int GetRadius() {return radius;}
	void DrawButton();
	void DrawButtonBorder();
	void ResetButton();
	void PressButton(bool leftClickUp);
	bool WithinButton(float xMouse, float yMouse);
	bool GetActivated() {return activated;}
	bool GetPressed() {return pressed;}
};


class RedTowerButton: public TowerButton
{
public:
	RedTowerButton();
};


class GreenTowerButton: public TowerButton
{
public:
	GreenTowerButton();
};


class BlueTowerButton: public TowerButton
{
public:
	BlueTowerButton();
};

class StartPauseButton: public Button
{
private:
	int xTop, yTop;
	int xBot, yBot;

public:
	StartPauseButton();
	void Destroy();
	void DrawButton();
	void PressButton(bool leftClickUp);
	void ResetButton() {;}
	bool WithinButton(float xMouse, float yMouse);
	bool GetPaused();
};

class NextWaveButton: public Button
{
private:
	int xTop, yTop;
	int xBot, yBot;

public:
	NextWaveButton();
	void PressButton(bool leftClickUp, Waves &waves);
	void DrawButton();
	bool WithinButton(float xMouse, float yMouse);
};

class UpgradeButton: public Button
{
protected:
	int xCenter;
	int yCenter;
	int radius;
	bool live;

public:
	UpgradeButton();
	void DrawButton();
	bool WithinButton(float xMouse, float yMouse);
	bool GetLive() {return live;}
	void ResetButton() {pressed = false;}
	void SetLive(bool live) {UpgradeButton::live = live;}
	void SetActive(bool activated) {UpgradeButton::activated = activated;}
	void SetXCenter(int x) {xCenter = x;}
	void SetYCenter(int y) {yCenter = y;}
	int GetRadius() {return radius;}
};
class UpgradeRedButton: public UpgradeButton
{
public:
	UpgradeRedButton();
	void PressButton(MapElement *grid, bool leftClickUp);
};
class UpgradeGreenButton: public UpgradeButton
{
public:
	UpgradeGreenButton();
	void PressButton(MapElement *grid, bool leftClickUp);
};
class UpgradeBlueButton: public UpgradeButton
{
public:
	UpgradeBlueButton();
	void PressButton(MapElement *grid, bool leftClickUp);
};
