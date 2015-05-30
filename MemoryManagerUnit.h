class MemoryManagerUnit {
public:
	MemoryManagerUnit(int size, bool e);
	virtual ~MemoryManagerUnit();

	void init();
	void display(int adr, int n);

	int getMemSize();
	bool getEndian();
	void setMemSize(int MemSize);
	void setEndian(bool Endian);

	int lw(int adr);
	void sw(int adr, int dat);
	short lh(int adr);
	short lhu(int adr);
	void sh(int adr, short dat);
	short lb(int adr);
	short lbu(int adr);
	void sb(int adr, char dat);

private:
	int MemSize;
	int MemArrLen;
	int Memory[10000];
	bool Endian;
};
