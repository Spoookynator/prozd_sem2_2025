#include <iostream>
#include "heapArray.h"

int main() {

	HeapArray test(2);

	HeapArray test2(test);

	test2.addLast(1);

	std::cout << test.getSize() << "\n" << test2.getSize();
}