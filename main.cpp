#include "hexdump.h"

bool FileExists(const char* FilePath)
{
	if (std::filesystem::exists(FilePath))
		return true;
	else
		return false;
}

int main()
{	
	std::string InputFile;

	while (true)
	{
		std::cout << "Please, input filepath: " << std::endl;
		std::getline(std::cin, InputFile);
		if (InputFile.empty())
		{
			std::cout << "Please, input non-empty filepath" << std::endl;
		}

		if (FileExists(InputFile.c_str()))
			std::cout << "File doesn't exist, check validility of path" << std::endl;
		else
		{
			HexDump* app = new HexDump(InputFile.c_str());

			delete app;
		}
			break;
	}

	
}