#pragma once
#include <vector>
#include "baseRobot.h"


class MathBot : public BaseRobot
{
public:

	int mine(std::vector<std::vector<std::vector<int>>>& world) override;
private:

};

class DoubleBot : public BaseRobot
{
public:

	int mine(std::vector<std::vector<std::vector<int>>>& world) override;
private:

};

class GamblerBot : public BaseRobot
{
public:
	int mine(std::vector<std::vector<std::vector<int>>>& world) override;
private:

};