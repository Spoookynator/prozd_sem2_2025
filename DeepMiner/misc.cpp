#include "misc.h"
#include <algorithm>

void sortVector(std::vector<int>& vec, bool ascending)
{
	if (ascending)
	{
		std::sort(vec.begin(), vec.end());
	}
	else
	{
		std::sort(vec.begin(), vec.end(), std::greater<int>());
	}
}