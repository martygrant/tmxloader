#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

class TMXTileLayer
{
	/* Class Constructors & Destructors */
public:
	TMXTileLayer(const char* name, unsigned int width, unsigned int height, std::unordered_map<std::string, std::string> layerProperties,
                 unsigned int** tilesArray);
	~TMXTileLayer();

	/* Getter Functions  */
public:
	const char* getName();
	unsigned int getWidth();
	unsigned int getHeight();
    
    unsigned int** getTileArray();
    
	void printData();

	/* Layer Properties */
private:
	const char* m_name;
	unsigned int m_width;
	unsigned int m_height;
    unsigned int** m_tileArray;

	/* User-defined Properties */
private:
	std::unordered_map<std::string, std::string> m_layerProperties;
};