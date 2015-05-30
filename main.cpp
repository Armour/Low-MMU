#include "MemoryManagerUnit.h"
#include <iostream>

#define MEMSIZE 1024
#define BigEndian true
#define SmallEndian false

int main() {
	MemoryManagerUnit *MMU = new MemoryManagerUnit(MEMSIZE, BigEndian);
	MMU->init();
	MMU->sw(3, 0x12345678);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " " << MMU->lw(i) <<std::endl;
	}
	MMU->display(0, 16);

	MMU->init();
	MMU->sh(3, 0x1234);
	for (int i = 0; i < 6; i++) {
		std::cout << i << " " << MMU->lh(i) <<std::endl;
	}
	MMU->display(0, 16);
	return 0;
}
