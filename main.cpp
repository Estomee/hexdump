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
	HexDump* app;

	while (true)
	{
		std::cout << "Please, input filepath: ";
		std::getline(std::cin, InputFile);
		if (InputFile.empty())
		{
			std::cout << "Please, input non-empty filepath!" << std::endl;
		}

		if (FileExists(InputFile.c_str()))
		{
			app = new HexDump(InputFile.c_str());
			app->Model();
			delete app;
		}
		else
		{
			std::cout << "File doesn't exist, check validility of path!" << std::endl;
		}

	}

	
}