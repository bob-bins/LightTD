#pragma once

class Player
{
private:
	int lives;
	int money;
	int waveNum;

public:
	Player();
	void LoseLife() {lives--;}
	void GainMoney(int value) {money = money + value;}
	void LoseMoney(int value) {money = money - value;}
	void UpdateWaveNum(int wave) {waveNum = wave;}
	int GetLives() {return lives;}
	int GetMoney() {return money;}
};
