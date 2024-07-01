#include <cassert>
#include <fstream>
#include <sstream>
#include <fmt/core.h>

#define RT(str) fmt::runtime(str) 

static std::string getFileContentAsString(const std::string& path)
{
	std::ifstream ifs{ path };

	if (!ifs)
	{
		fmt::println("Error: can't open the file: {}", path);
	}
	
	std::stringstream buffer{};
	buffer << ifs.rdbuf();

	return buffer.str();
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fmt::println("Error: provide a path to .osw file.");
		return -1;
	}

	std::string file_content{ getFileContentAsString(argv[1]) };
	fmt::println(RT(file_content));

	return 0;
}
