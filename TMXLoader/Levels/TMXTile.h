#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

class TMXTile
{
public:
	TMXTile(unsigned int tileID, std::unordered_map<std::string, std::string>& propertiesMap);
	~TMXTile();

	void printData();

private:
	unsigned int m_tileID;
	std::unordered_map<std::string, std::string> m_propertiesMap;
};

