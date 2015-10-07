#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <array>

#include "TMXTileSet.h"
#include "TMXTileLayer.h"

class TMXMap 
{
	/* Class Constructors & Destructors */
public:
    TMXMap() { }
	TMXMap(const std::vector<std::string>& mapData, const std::unordered_map<std::string, std::string>& propertiesMap);
	~TMXMap();

	/* Map Settings */
public:
	float getVersion();
	std::string getOrientation();
	unsigned int getWidth();
	unsigned int getHeight();
	unsigned int getTileWidth();
	unsigned int getTileHeight();
    std::array<unsigned int, 3> getBackgroundColourArray();

	void printData();
    
    TMXTileLayer getLayer(std::string layerName);

private:
	float m_version;
	std::string m_orientation;
    std::string m_renderOrder;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_tileWidth;
	unsigned int m_tileHeight;
    std::array<unsigned int, 3> m_backgroundColourArray;

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





