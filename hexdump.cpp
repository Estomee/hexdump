#include "hexdump.h"


HexDump::HexDump(const char* FileName): _FileName(FileName){}

void HexDump::Model()
{
	std::fstream FIn;

	FIn.open(_FileName, std::ios::in | std::ios::binary | std::ios::ate);

	_FileSize = FIn.tellg();

	FIn.seekg(0, std::ios::beg);

	std::cout << std::setfill('0') << std::uppercase;

	while (fi)
}
