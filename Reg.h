#ifndef REG_H
#define REG_H

#include <iostream>
using namespace std;

class Reg
{
public:
	Reg ();
	virtual ~Reg ();
	unsigned int readReg(int addr);
	void writeWord(int addr, unsigned int);

private:
	unsigned int reg[32];
};

#endif
