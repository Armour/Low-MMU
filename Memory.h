#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

class Memory
{
public:
	Memory (int size = 256, bool e = 1);
	virtual ~Memory ();
	int getMemSize() { return this->MemSize; }
	bool getEndian() { return this->Endian; }
	void setEndian(bool Endian) { this->Endian = Endian; }
	unsigned int readWord(int addr);
	unsigned int readByte(int addr, bool sign);
	unsigned int readHalfWord(int addr, bool sign);
	void writeWord(int addr, unsigned int word);
	void writeByte(int addr, unsigned int byte);
	void writeHalfWord(int addr, unsigned int halfword);

private:
	unsigned int *Mem;
	int MemSize;
	bool Endian;
};

#endif
