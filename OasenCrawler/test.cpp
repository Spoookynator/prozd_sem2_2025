#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Position.h"
#include "stat.h"
#include "Entity.h"
#include "player.h"
#include "Enemy.h"

TEST_CASE("Position distance_to", "[Position]")
{
	Position p1(0, 0);
	Position p2(3, 4);

	auto distance = p1.distance_to(p2);
	REQUIRE(distance.first == 3);
	REQUIRE(distance.second == 4);

	auto distance2 = p2.distance_to(p1);
	REQUIRE(distance2.first == -3);
	REQUIRE(distance2.second == -4);
}

TEST_CASE("Position isEqualPosition", "[Position]")
{
	Position p1(0, 0);
	Position p2(0, 0);
	Position p3(1, 1);

	REQUIRE(p1.isEqualPosition(p2) == true);
	REQUIRE(p1.isEqualPosition(p3) == false);
	REQUIRE(p2.isEqualPosition(p3) == false);
}

TEST_CASE("Stat toString", "[Stat]")
{
	Stat stat1(Stat::Intelligence, 5);
	Stat stat2(Stat::Strength, 10);
	Stat stat3(Stat::Luck, 15);
	Stat stat4(Stat::None, 0);

	REQUIRE(stat1.toString() == "Intelligence");
	REQUIRE(stat1.value == 5);
	REQUIRE(stat2.toString() == "Strength");
	REQUIRE(stat2.value == 10);
	REQUIRE(stat3.toString() == "Luck");
	REQUIRE(stat3.value == 15);
	REQUIRE(stat4.toString() == "None");
	REQUIRE(stat4.value == 0);
}

TEST_CASE("Entity get and set", "[Entity]")
{
	Position pos(5, 5);
	Entity entity(pos, 10);

	REQUIRE(entity.getCurrentHp() == 10);
	REQUIRE(entity.getMaxHp() == 10);
	REQUIRE(entity.getPosition().x == 5);
	REQUIRE(entity.getPosition().y == 5);
	entity.takeDamage(3);
	REQUIRE(entity.getCurrentHp() == 7);
	entity.heal(2);
	REQUIRE(entity.getCurrentHp() == 9);
	entity.setPosition(Position(2, 3));
	REQUIRE(entity.getPosition().x == 2);
	REQUIRE(entity.getPosition().y == 3);
}

TEST_CASE("Player Movement", "[Player]")
{
	Player player(10);

	REQUIRE(player.getPosition().x == 0);
	REQUIRE(player.getPosition().y == 0);

	REQUIRE(player.moveNorth() == false);
	REQUIRE(player.moveSouth() == true);
	REQUIRE(player.getPosition().x == 1);
	REQUIRE(player.getPosition().y == 0);
	REQUIRE(player.moveEast() == true);
	REQUIRE(player.getPosition().x == 1);
	REQUIRE(player.getPosition().y == 1);
	REQUIRE(player.moveWest() == true);
	REQUIRE(player.getPosition().x == 1);
	REQUIRE(player.getPosition().y == 0);
	REQUIRE(player.moveNorth() == true);
	REQUIRE(player.getPosition().x == 0);
	REQUIRE(player.getPosition().y == 0);

	REQUIRE(player.moveWest() == false);
}

TEST_CASE("Player Level Up", "[Player]")
{
	Player player(10);

	REQUIRE(player.useScroll() == false);
	REQUIRE(player.usePotion() == false);
	REQUIRE(player.useSword() == false);

	player.gainItem(Stat::Intelligence);

	REQUIRE(player.useScroll() == true);
	REQUIRE(player.usePotion() == false);
	REQUIRE(player.useSword() == false);

	REQUIRE(player.useScroll() == false);

	player.gainItem(Stat::Intelligence);
	player.gainItem(Stat::Intelligence);

	player.gainItem(Stat::Strength);
	player.gainItem(Stat::Luck);

	REQUIRE(player.usePotion() == true);
	REQUIRE(player.useSword() == true);

	REQUIRE(player.useScroll() == true);
	REQUIRE(player.useScroll() == true);
}

TEST_CASE("Enemy Chase Movement", "[Enemy]")
{
	Position playerPos(4, 4);
	Position enemyPos(0, 0);
	Enemy enemy(Enemy::Chase, enemyPos, 10, 2);

	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			enemy.movePattern(playerPos);
			if (k % 2 == 0)
			{
				REQUIRE(enemy.getPosition().x == i + 1);
			}
			else {
				REQUIRE(enemy.getPosition().y == i + 1);

			}
		}

	}

	auto dist = enemy.getPosition().distance_to(playerPos);
	REQUIRE(dist.first == 0);
	REQUIRE(dist.second == 0);
}

TEST_CASE("Enemy Stationary Movement", "[Enemy]")
{
	Position playerPos(4, 4);
	Position enemyPos(0, 0);
	Enemy enemy(Enemy::Stationary, enemyPos, 10, 2);
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			enemy.movePattern(playerPos);
			REQUIRE(enemy.getPosition().x == 0);
			REQUIRE(enemy.getPosition().y == 0);
		}
	}
}