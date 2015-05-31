#include "Memory.h"

Memory::Memory(int size, bool endian) {
	this->Mem = new unsigned int[size];
	this->MemSize = size - 1;
	this->Endian = endian;
}

Memory::~Memory() {
	delete Mem;
}

unsigned int extend(unsigned int res, int bits, bool sign) {
	if (sign)
		for (int i = bits + 1; i < 32; i++)
			res += ((res & (1 << bits)) >> bits) << i;
	return res;
}

unsigned int Memory::readWord(int addr) {
	unsigned int ans = 0;
	if ((addr < 0) || (addr > (MemSize << 2))) {
		cout << "memory read out of range";
	}
	if (Endian) {
		ans = (readHalfWord(addr, 0) << 16) + readHalfWord(addr + 2, 0);
		/*
		 *ans = Mem[addr >> 2] << ((addr % 4) * 4);
		 *if ((addr & 3) != 0) {
		 *    ans += Mem[(addr >> 2) + 1] >> ((4 - (addr %4)) << 3);
		 *}
		 */
	} else {
		ans = (readHalfWord(addr + 2, 0) << 16) + readHalfWord(addr, 0);
		/*
		 *if ((addr & 3) != 0) {
		 *    for (int i = addr % 4 - 1; i >= 0; i--)
		 *        ans = (ans << 8) + (Mem[(addr >> 2) + 1] >> ((3 - i) << 3)) % 256;
		 *}
		 */
	}
	return ans;
}

unsigned int Memory::readHalfWord(int addr, bool sign) {
	unsigned int ans = 0;
	if ((addr < 0) || (addr > (MemSize << 2) + 2)) {
		cout << "memory read out of range";
	}
	if (Endian) {
		ans = (readByte(addr, 0) << 8) + readByte(addr + 1, 0);
	} else {
		ans = (readByte(addr + 1, 0) << 8) + readByte(addr, 0);
	}
	return extend(ans, 15, sign);
}

unsigned int Memory::readByte(int addr, bool sign) {
	unsigned int ans = 0;
	if ((addr < 0) || (addr > (MemSize << 2))) {
		cout << "memory read out of range";
	}
	ans = (Mem[addr >> 2] >> ((3 - (addr & 3)) << 3)) % 256;
	return extend(ans, 7, sign);
}

void Memory::writeByte(int addr, unsigned int byte) {
	unsigned int mask[4] = {
		16777215, //00000000 11111111 11111111 11111111
		4278255615, //11111111 00000000 11111111 11111111
		4294902015, //11111111 11111111 00000000 11111111
		4294967040 //11111111 11111111 11111111 00000000
	};

	for (int i = 0; i < 3; i++)
		byte &= mask[i];
	Mem[addr >> 2] &= mask[addr & 3];
	Mem[addr >> 2] += byte << ((3 - addr % 4) * 8);
}

void Memory::writeHalfWord(int addr, unsigned int halfword) {
	unsigned int mask[2] = {
		511, //00000000 00000000 00000000 11111111
		65280 //00000000 00000000 11111111 00000000
	};

	if ((addr < 0) || (addr > (MemSize << 2) + 2)) {
		cout << "memory read out of range";
	}
	if (Endian) {
		writeByte(addr, halfword & mask[0]);
		writeByte(addr + 1, halfword & mask[1]);
	} else {
		writeByte(addr + 1, halfword & mask[0]);
		writeByte(addr, halfword & mask[1]);
	}
}

void Memory::writeWord(int addr, unsigned int word) {
	unsigned int mask[2] = {
		65535, //00000000 00000000 11111111 11111111
		4294901760 //11111111 11111111 00000000 00000000
	};

	if ((addr < 0) || (addr > (MemSize << 2) + 2)) {
		cout << "memory read out of range";
	}
	if (Endian) {
		writeByte(addr, word & mask[0]);
		writeByte(addr + 2, word & mask[1]);
	} else {
		writeByte(addr + 2, word & mask[0]);
		writeByte(addr, word & mask[1]);
	}
}
