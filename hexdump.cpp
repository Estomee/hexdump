#include "hexdump.h"


HexDump::HexDump(const char* FileName): _FileName(FileName){}


void HexDump::Model()
{
	std::fstream FIn;

	FIn.open(_FileName, std::ios::in | std::ios::binary | std::ios::ate);

	_FileSize = FIn.tellg();
	_SizeOfLastString = _FileSize % 16;

	FIn.seekg(0, std::ios::beg);

	std::cout << std::hex <<std::setfill('0') << std::uppercase;

	while (FIn.good() && _NumBytesTrav < _FileSize)
	{
		std::string TextFromBuffer;
		FIn.read((char*)_Buffer, 16);
		std::cout <<std::setw(8) << _MemBlock << ':' << ' ';

		if (_NumBytesTrav < _FileSize - _SizeOfLastString)
		{
			for (int16_t i = 0; i < 16; i++)
			{
				std::cout << std::setw(2) << uint16_t(_Buffer[i]) << ' ';
				_NumBytesTrav++;

				if (isprint(_Buffer[i]))
				{
					TextFromBuffer += _Buffer[i];
				}
				else
				{
					TextFromBuffer += '.';
				}
			}
		}
		else
		{
			//multiply by 2 to count ' ' and another time by 2 for hex symbols
			TextFromBuffer.append(4 * (16 - _SizeOfLastString) , ' ');
			for (int16_t i = 0; i < _SizeOfLastString; i++)
			{
				std::cout << std::setw(2) << uint16_t(_Buffer[i]) << ' ';
				_NumBytesTrav++;

				if (isprint(_Buffer[i]))
				{

					TextFromBuffer += _Buffer[i];
				}
				else
				{
					TextFromBuffer += '.';
				}
			}
			
		}
		
		std::cout << ' ' << TextFromBuffer << std::endl;
		TextFromBuffer.clear();

		_MemBlock += 16;
		
	}
	FIn.close();
}
