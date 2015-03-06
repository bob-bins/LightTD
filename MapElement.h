#pragma once
#include "Projectile.h"
#include "globals.h"

class Cell
{
protected:
	float xBot;
	float xTop;
	float yBot;
	float yTop;
	bool isEmpty;
	bool live;

public:
	Cell();
	bool GetIsEmpty() {return isEmpty;}
	bool GetLive() {return live;}
	float GetXBot() {return xBot;}
	float GetXTop() {return xTop;}
	float GetYBot() {return yBot;}
	float GetYTop() {return yTop;}
	void SetIsEmpty(bool empty) {isEmpty = empty;}
	void SetLive(bool live) {Cell::live = live;}
	void SetXBot(float xBot) {Cell::xBot = xBot;}
	void SetXTop(float xTop) {Cell::xTop = xTop;}
	void SetYBot(float yBot) {Cell::yBot = yBot;}
	void SetYTop(float yTop) {Cell::yTop = yTop;}

};

class PathElement: public Cell
{
private:
	bool end;
	bool start;
	
public:
	PathElement();
	bool GetEnd() {return end;}
	bool GetStart() {return start;}
	void SetEnd(bool end) {PathElement::end = end;}
	void SetStart(bool start) {PathElement::start = start;}
};

class Tower: public Cell
{
protected:
	float CDCount;
	float cooldown;
	float damage;
	float range;
	float slow;
	float slowLength;
	int redUpgrade;
	int greenUpgrade;
	int blueUpgrade;

public:
	Tower();
	bool TimeToFire();
	bool WithinRange(int xMonst, int yMonst);
	float GetCDCount() {return CDCount;}
	float GetCooldown() {return cooldown;}
	float GetDamage() {return damage;}
	float GetRange() {return range;}
	float GetSlow() {return slow;}
	float GetSlowLength() {return slowLength;}
	int GetRedUpgrade() {return redUpgrade;} //put upgrade cap too
	int GetGreenUpgrade() {return greenUpgrade;}
	int GetBlueUpgrade() {return blueUpgrade;}
	void IncreaseUpgrade(int color);
	void SetCDCount(float CDCount) {Tower::CDCount = CDCount;}
	void SetCooldown(float cooldown) {Tower::cooldown = cooldown;}
	void SetDamage(float damage) {Tower::damage = damage;}
	void SetRange(float range) {Tower::range = range;}
	void SetSlow(float slow) {Tower::slow = slow;}
	void SetSlowLength(float slowLength) {Tower::slowLength = slowLength;}
};

class RedTower: public Tower
{
private:
	int projCount;	

public:
	RedTower();
	int GetProjCount() {return projCount;}
	void DrawProjectiles();
	void DrawTower(); //draws all red towers
	void DrawTower(int x, int y); //draws non-upgraded tower for DisplayScreen
	void FireProjectile(int monstID);
	void SetProjCount(int projCount) {RedTower::projCount = projCount;}

	Projectile projectiles[20]; //make this private later!!!!!!!!!!!!!????????????
};

class GreenTower: public Tower
{
private:
	int monsterID;

public:
	GreenTower();
	float FireLaser(int monstID);
	int GetMonsterID() {return monsterID;}
	void DrawLaser(int xMonst, int yMonst);
	void DrawTower();
	void DrawTower(int x, int y);
	void SetMonsterID(int monstID) {monsterID = monstID;}
};

class BlueTower: public Tower
{
private:
	float fireAnimationLength;

public:
	BlueTower();
	float FireAttack();
	void DrawTower();
	void DrawTower(int x, int y);
	void DrawFireAnimation();
	void IncreaseRedUpgrade();
	void IncreaseGreenUpgrade();
	void IncreaseBlueUpgrade();
	void ReduceFireAnimationLength() {fireAnimationLength--;}
};

class MapElement
{
public:
	MapElement() {}

	Cell cell;
	PathElement pathElement;
	RedTower redTower;
	GreenTower greenTower;
	BlueTower blueTower;
};
