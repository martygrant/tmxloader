#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <array>

#include "TMXTile.h"

class TMXTileSet
{
	/* Class Constructors & Destructors */
public:
	TMXTileSet(std::unordered_map<std::string, std::string>& tileSetData, std::unordered_map<std::string, std::string>& propertiesMap, std::vector<TMXTile>& tileVector);
	~TMXTileSet();

public:
	/* Getter Functions */
	std::string getName();
	std::string getSource();
	unsigned int getFirstGID();
	unsigned int getLastGID();
	unsigned int getImageWidth();
	unsigned int getImageHeight();
	unsigned int getTileWidth();
	unsigned int getTileHeight();
	unsigned int getSpacing();
	unsigned int getMargin();
	unsigned int getOffsetX();
	unsigned int getOffsetY();
    std::array<unsigned int, 3> getTransparentColourArray();

	void printData();

	/* TileSet Properties */
private:
	std::string m_name;
	std::string m_source;
	unsigned int m_firstGID;
	unsigned int m_lastGID;
	unsigned int m_imageWidth;
	unsigned int m_imageHeight;
	unsigned int m_tileWidth;
	unsigned int m_tileHeight;
	unsigned int m_spacing;
	unsigned int m_margin;
	unsigned int m_offsetX;
	unsigned int m_offsetY;
    std::array<unsigned int, 3> m_transparentColourArray;
	std::unordered_map<std::string, std::string> m_propertiesMap;

	std::vector<TMXTile> m_tileVector;
};