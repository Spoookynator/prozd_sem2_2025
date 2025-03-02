#pragma once
namespace Constants {
	constexpr int MAX_FIELDSIZE = 5;	
	constexpr int PLAYER_HP = 5;
	
	// looks best in multiples of 2
	constexpr int PRINT_FIELD_SPACING = 4;

	// chances
	constexpr int8_t EMPTY_FIELD_WEIGHT = 40;
	constexpr int8_t TRAP_FIELD_WEIGHT = 40;
	constexpr int8_t RELIC_FIELD_WEIGHT = 10;
	constexpr int8_t WELL_FIELD_WEIGHT = 10;
	
	constexpr double RELIC_HURT_CHANCE = 1.0f / 6.0f;

	// symbols
	constexpr char PLAYER_SYMBOL = '@';
	constexpr char EMPTY_SYMBOL = '_';
	constexpr char RELIC_SYMBOL = 'R';
	constexpr char TRAP_SYMBOL = '^';
	constexpr char WELL_SYMBOL = '+';
	constexpr char ENEMY_SYMBOL = '#';
}