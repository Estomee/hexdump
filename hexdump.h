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
	uint16_t _MemBlock = 0;
	unsigned char _Buffer[16] = {0};
	int _NumBytesTrav = 0;
	size_t _FileSize = 0;
	size_t _SizeOfLastString = 0;
	

public:
	
	HexDump(const char* FileName);
	void Model();
};