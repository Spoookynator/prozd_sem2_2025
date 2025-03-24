#pragma once
#include <string>

class Character;

struct Ability
{
	Ability() = default;

	virtual bool useOn(Character*, Character*) = 0;
	virtual std::string getName() = 0;
};

struct Heal : Ability
{
public:
	Heal() = default;

	bool useOn(Character*, Character*) override;
	std::string getName() override { return "Heal"; }
};

struct GenderSwap : Ability
{
	GenderSwap() = default;

	bool useOn(Character*, Character*) override;
	
	std::string getName() override { return "GenderSwap"; }
};

struct Bite : Ability
{
	Bite() = default;
	bool useOn(Character*, Character*) override;
	std::string getName() override { return "Bite"; }
};

struct Slap : Ability
{
	Slap() = default;
	bool useOn(Character*, Character*) override;
	std::string getName() override { return "Slap"; }
};