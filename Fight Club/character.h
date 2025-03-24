#pragma once
#include <string>

struct Ability;

class Character
{
public:
	Character(std::string, int, int);
	~Character();

	void setAbility1(Ability*);
	void setAbility2(Ability*);

	std::string getAbility1Name();
	std::string getAbility2Name();

	int getHp();
	int getMana();

	int getMaxHp();
	int getMaxMana();

	void changeHp(int);
	void changeMana(int);

	std::string getName();

	bool useAbility1(Character*);
	bool useAbility2(Character*);

	bool getIsCpu();
	void setIsCpu(bool);

	bool isDead() const { return hp == 0; }

	virtual int getManaRegen() { return 8; };

	void addWin() { wins++; }
	void addLoss() { losses++; }

private:
	int hp, maxHp;

	int mana, maxMana;

	int wins, losses;

	std::string name = "";

	Ability* ability1 = nullptr;
	Ability* ability2 = nullptr;

	bool isCpu = false;
};

class Fighter : public Character
{
public:
	Fighter(std::string = "Fighter");

	int getManaRegen() override { return 6; }

private:
};

class Healer : public Character
{
public:
	Healer(std::string = "Healer");
	int getManaRegen() override { return 11; }

private:
};

class Gambler : public Character
{
public:
	Gambler(std::string = "Gambler");
	int getManaRegen() override { return 21; }

private:
};