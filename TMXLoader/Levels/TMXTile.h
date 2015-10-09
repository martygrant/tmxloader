#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

class TMXTile
{
    /* Class constructors & destructors */
public:
	TMXTile(unsigned int tileID, std::unordered_map<std::string, std::string>& propertiesMap);
	~TMXTile();

    /* Debug functions */
public:
	void printData();

    /* Tile variables */
private:
	unsigned int m_tileID;
    
    /* User-defined properties */
private:
	std::unordered_map<std::string, std::string> m_propertiesMap;
};

