#ifndef MMU_H
#define MMU_H

#include <iostream>
#include "Memory.h"
#include "Reg.h"
using namespace std;

class MemoryManagerUnit {
public:
	MemoryManagerUnit();
	virtual ~MemoryManagerUnit();
	int showEndian() { return mem->getEndian(); }
	void switchEndian() { mem->setEndian(1 ^ mem->getEndian()); }

	void li(int addrT, unsigned int imm);
	void lw(int addrT, int addrS, int offset);
	void sw(int addrT, int addrS, int offset);
	void lh(int addrT, int addrS, int offset);
	void lhu(int addrT, int addrS, int offset);
	void lb(int addrT, int addrS, int offset);
	void lbu(int addrT, int addrS, int offset);
	void sb(int addrT, int addrS, int offset);

	void listReg();
	void listMem(int start, int stop);

private:
	Memory *mem;
	Reg *reg;
};

#endif
