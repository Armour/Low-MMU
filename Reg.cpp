#include "Reg.h"

Reg::Reg() {
	this->reg[0] = 0;
}

Reg::~Reg() {
}

unsigned int Reg::readReg(int addr) {
	if ((addr < 0) || addr > 31) {
		cout << "register read out of range";
	}
	return reg[addr];
}

void Reg::writeWord(int addr, unsigned int in) {
	if ((addr < 0) || (addr > 31)) {
		cout << "register write out of range";
	} else if (addr == 0) {
		cout << "zero register cannot be written";
	}
	this->reg[addr] = in;
}
