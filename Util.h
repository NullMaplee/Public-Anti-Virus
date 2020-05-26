#include <sstream>
#include <fstream>

#include "Storage.h"

#define ScanFileText(Text) FileText.find(Text) != std::string::npos
#define ScanHexText(Hex) HexText.find(Hex) != std::string::npos

string FileText;
string HexText;

int ReadFile(string Name)
{
	stringstream Stream;
	uint8_t* MemoryBlock;
	ifstream::pos_type Size;

	ifstream File(Name, ios::in | ios::ate | ios::binary);

	if (File.is_open())
	{
		Size = File.tellg(); // Get Input Stream MemoryBlock
		MemoryBlock = new uint8_t[Size]; // Create memoryblock with new size
		File.seekg(0, ios::beg); // Set input stream position
		File.read((char*)MemoryBlock, Size); // Read the data
		File.close(); // Close file stream

		for (int i = 0; i < Size; ++i)
		{
			Stream << MemoryBlock[i]; // loop through adding MemoryBlock[pos] to Stream
		}

		FileText = Stream.str();
		delete[] MemoryBlock; // Delete MemoryBlock so we dont cause memory leaks
	}
	return 0;
}

int ReadHex(string Name)
{
	stringstream Stream;
	uint8_t* MemoryBlock;
	ifstream::pos_type Size;

	ifstream File(Name, ios::in | ios::ate | ios::binary);

	if (File.is_open())
	{
		Size = File.tellg(); // Get Input Stream MemoryBlock
		MemoryBlock = new uint8_t[Size]; // Create memoryblock with new size
		File.seekg(0, ios::beg); // Set input stream position
		File.read((char*)MemoryBlock, Size); // Read the data
		File.close(); // Close file stream

		for (int i = 0; i < Size; ++i)
		{
			Stream << std::hex << (int)MemoryBlock[i]; // loop through adding MemoryBlock[pos] to Stream
		}

		HexText = Stream.str();
		delete[] MemoryBlock; // Delete MemoryBlock so we dont cause memory leaks
	}
	return 0;
}

void WriteFile(string text)
{
	ofstream File;
	File.open("File.txt");
	File << text;
	File.close();
}
