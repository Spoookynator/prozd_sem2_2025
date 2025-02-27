#pragma once
namespace Constants {
	constexpr int MAX_FIELDSIZE = 5;	
	
	// looks best in multiples of 2
	constexpr int PRINT_FIELD_SPACING = 4;

	// chances
	constexpr int8_t EMPTY_FIELD_WEIGHT = 40;
	constexpr int8_t TRAP_FIELD_WEIGHT = 40;
	constexpr int8_t RELIC_FIELD_WEIGHT = 10;
	constexpr int8_t WELL_FIELD_WEIGHT = 10;
	
	constexpr double BASE_HURT_CHANCE = 1/6;

	// symbols
	constexpr char PLAYER_SYMBOL = 'P';
	constexpr char EMPTY_SYMBOL = '*';
	constexpr char RELIC_SYMBOL = 'R';
	constexpr char TRAP_SYMBOL = 'T';
	constexpr char WELL_SYMBOL = 'W';
	
	enum Stat {
		None,
		Intelligence,
		Dexterity,
		Luck,
	};
}