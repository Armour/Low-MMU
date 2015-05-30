#include "MemoryManagerUnit.h"
#include <iostream>

MemoryManagerUnit::MemoryManagerUnit(int size, bool e) {
	this->MemSize = size;
	this->MemArrLen = size/sizeof(int);
	this->Endian = e;
}

MemoryManagerUnit::~MemoryManagerUnit() {

}

void MemoryManagerUnit::init() {
	for (int i = 0; i < MemSize; i++) {
		this->sb(i, i);
	}
}

void MemoryManagerUnit::display(int adr, int n) {
	for (int i = adr; i < n; ++i) {
		std::cout << this->lb(i) << std::endl;
	}
}

int MemoryManagerUnit::lw(int adr) {

}

void MemoryManagerUnit::sw(int adr, int dat) {

}

short MemoryManagerUnit::lh(int adr) {

}

short MemoryManagerUnit::lhu(int adr) {

}

void MemoryManagerUnit::sh(int adr, short dat) {

}

short MemoryManagerUnit::lb(int adr) {

}

short MemoryManagerUnit::lbu(int adr) {

}

void MemoryManagerUnit::sb(int adr, char dat) {

}
