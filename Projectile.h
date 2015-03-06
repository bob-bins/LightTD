#pragma once

class Projectile
{
private:
	bool live;
	int monsterID; //monster that it's locked to. currently only works if all waves have 10 monsters
	float xCenter;
	float yCenter;
	float damage;
	float slow;
	float splash;
	float speed;

public:
	Projectile();
	float CollideMonster(int mx, int my);
	void DrawProjectile();
	void UpdatePosition(int mx, int my);

	bool GetLive() {return live;}
	int GetMonsterID() {return monsterID;}
	float GetXCenter() {return xCenter;}
	float GetYCenter() {return yCenter;}
	float GetDamage() {return damage;}
	float GetSlow() {return slow;}
	float GetSplash() {return splash;}
	float GetSpeed() {return speed;}
	void SetLive(bool live) {Projectile::live = live;}
	void SetMonsterID(int monstID) {monsterID = monstID;}
	void SetXCenter(float x) {xCenter = x;}
	void SetYCenter(float y) {yCenter = y;}
	void SetSlow(float slow) {Projectile::slow = slow;}
};
