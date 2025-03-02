#include "Enemy.h"
#include "random"

Enemy::Enemy(Pattern pattern, Position pos, int8_t hp, int8_t damage) : Entity(pos, hp)
{
	this->pattern = pattern;
	this->damage = damage;
}

void Enemy::movePattern(Position playerPos)
{
    if (this->getPosition().isEqualPosition(playerPos))
    {
        return;
    }

    if (this->pattern == Chase)
    {
        std::pair<int8_t, int8_t> distance = this->getPosition().distance_to(playerPos);

        bool xSmaller = (std::abs(distance.first) >= std::abs(distance.second));

        if (xSmaller)
        {
            this->move(distance.first / std::abs(distance.first), 0);
        }
        else
        {
            this->move(0, distance.second / std::abs(distance.second));
        }
    }
    else if (this->pattern == Random)
        {

        bool sucess = false;
        do
        {
            int rng1 = rand() % 2, rng2 = rand() % 2;

            int x = 0, y = 0;

            if (rng1 == 1)
            {
                x = 1;
            }
            else
            {
                y = 1;
            }

            if (rng2 == 1)
            {
                x *= -1;
                y *= -1;
            }

            sucess = this->move(x, y);
        } while (sucess == false);

    }
}

int8_t Enemy::getDamage() const
{
    return this->damage;
}

Enemy::Pattern Enemy::getPattern() const
{
    return this->pattern;
}
