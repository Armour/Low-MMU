#include "MemoryManagerUnit.h"
#include <iostream>

MemoryManagerUnit::MemoryManagerUnit() {
	mem = new Memory;
	reg = new Reg;
	for (int i = 1; i < 32; i++)
		reg->writeWord(i, 0);
	for (int i = 0; i <= mem->getMemSize(); i++) {
		mem->writeWord(i << 2, 0);
	}
}

MemoryManagerUnit::~MemoryManagerUnit() {
	delete mem;
	delete reg;
}

void MemoryManagerUnit::li(int addrT, unsigned int imm) {
	reg->writeWord(addrT, imm);
}

void MemoryManagerUnit::lw(int addrT, int addrS, int offset) {
	reg->writeWord(addrT, mem->readWord(reg->readReg(addrS) + offset));
}

void MemoryManagerUnit::sw(int addrT, int addrS, int offset) {
	mem->writeWord(reg->readReg(addrS) + offset, reg->readReg(addrT));
}

void MemoryManagerUnit::lh(int addrT, int addrS, int offset) {
	reg->writeWord(addrT, mem->readHalfWord(reg->readReg(addrS) + offset, 1));
}

void MemoryManagerUnit::lhu(int addrT, int addrS, int offset) {
	reg->writeWord(addrT, mem->readHalfWord(reg->readReg(addrS) + offset, 0));
}

void MemoryManagerUnit::lb(int addrT, int addrS, int offset) {
	reg->writeWord(addrT, mem->readByte(reg->readReg(addrS) + offset, 1));
}

void MemoryManagerUnit::lbu(int addrT, int addrS, int offset) {
	reg->writeWord(addrT, mem->readByte(reg->readReg(addrS) + offset, 0));
}

void MemoryManagerUnit::sb(int addrT, int addrS, int offset) {
	mem->writeByte(reg->readReg(addrS) + offset, reg->readReg(addrT));
}

void MemoryManagerUnit::listReg() {
	cout << "register list:" << endl;
	for (int i = 0; i < 32; i++) {
		cout << "[" << i << "] " << reg->readReg(i) << endl;
	}
}

void MemoryManagerUnit::listMem(int start, int stop) {
	if (start > stop) {
		int tmp = start;
		start = stop;
		stop = tmp;
	}
	cout << "memory address: " << start << " to " << stop << endl;
	for (int i = start; i < stop; i++)
		cout << "[" << i << "] " << mem->readWord(i << 2) << endl;
}
