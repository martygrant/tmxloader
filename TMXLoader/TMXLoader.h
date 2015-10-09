#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <fstream>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

#include "Levels/TMXMap.h"
#include "Levels/TMXTileLayer.h"
#include "Levels/TMXTileSet.h"
#include "Levels/TMXTile.h"

class TMXLoader
{
    /* Class constructors & destructors */
public:
	TMXLoader();
	~TMXLoader();

    /* Map methods */
public:
    void loadMap(std::string levelPath);
    TMXMap* getMap(std::string mapName);

    /* Map loading helper functions */
private:
	void loadMapSettings(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadTileSets(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadLayers(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadProperties(std::unordered_map<std::string, std::string>& propertiesMap, rapidxml::xml_node<> *parentNode);

    /* File loading helper functions */
private:
    std::string loadFile(std::string filePath);

    /* Unordered map container for loaded Maps */
private:
	std::unordered_map<std::string, TMXMap> m_mapContainer;
};

