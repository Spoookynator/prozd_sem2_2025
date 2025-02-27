#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	using Entity::Entity;

private:
	int damage;
};