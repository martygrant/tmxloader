#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

class TMXTileLayer
{
	/* Class Constructors & Destructors */
public:
	TMXTileLayer(const char* name, unsigned int width, unsigned int height, std::unordered_map<std::string, std::string> layerProperties, std::vector<unsigned int**> tiles);
	~TMXTileLayer();

	/* Getter Functions  */
public:
	const char* getName();
	unsigned int getWidth();
	unsigned int getHeight();
    
    std::vector<unsigned int**> getTileLayer() { return m_tiles; }
    
	void printData();

	/* Layer Properties */
private:
	const char* m_name;
	unsigned int m_width;
	unsigned int m_height;
    std::vector<unsigned int**> m_tiles;

	/* User-defined Properties */
private:
	std::unordered_map<std::string, std::string> m_layerProperties;
};