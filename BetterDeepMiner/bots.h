#pragma once
#include "bot.h"

class Doublebot : public Bot
{
public:

	using Bot::Bot;
	int mine(Map3D& map) override;
private:

};

class SortBot : public Bot
{
public:
	using Bot::Bot;

	int mine(Map3D& map) override;
private:

};

class TripleBot : public Bot
{
public:
	using Bot::Bot;


	int mine(Map3D& map) override;
private:

};