#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

#include "TMXTileSet.h"
#include "TMXTileLayer.h"

class TMXMap 
{
	/* Class Constructors & Destructors */
public:
	TMXMap(std::vector<std::string>& mapData, std::unordered_map<std::string, std::string>& propertiesMap);
	~TMXMap();

	/* Map Settings */
public:
	float getVersion();
	std::string getOrientation();
	unsigned int getWidth();
	unsigned int getHeight();
	unsigned int getTileWidth();
	unsigned int getTileHeight();
	std::vector<unsigned int> getBackgroundColour();

	void printData();

private:
	float m_version;
	std::string m_orientation;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_tileWidth;
	unsigned int m_tileHeight;
	std::vector<unsigned int> m_backgroundColour;

	/* User-defined Properties */
private:
	std::unordered_map<std::string, std::string> m_propertiesMap;

	/* TileSets */
public:
	void addTileSet(TMXTileSet newTileSet);

private:
	std::vector<TMXTileSet> m_tileSetVector;

	/* Layers */
public:
	void addLayer(TMXTileLayer newLayer);

private:
	std::vector<TMXTileLayer> m_layerVector;
};





