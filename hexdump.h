#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <filesystem>


class HexDump {

private: 
	const char* _FileName;
	const long _MemBlock = 0;
	unsigned char _Buffer[16];
	int _NumBytesTrav = 0;
	int _FileSize = 0;
	

public:
	
	HexDump(const char* FileName);
	void Model();
	void PrintDump();
};