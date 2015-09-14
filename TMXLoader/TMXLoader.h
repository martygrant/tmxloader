#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <sstream>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

#include "Levels/TMXMap.h"
#include "Levels/TMXTileLayer.h"
#include "Levels/TMXTileSet.h"
#include "Levels/TMXTile.h"

class TMXLoader
{
public:
	/* Class Constructor & Destructor */
	TMXLoader();
	~TMXLoader();

public:
	void loadLevel(const char* levelPath);
    
    TMXMap getMap() { return m_mapContainer.at("Assets/testlevel.tmx"); }

private:
	void loadMapSettings(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadTileSets(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadLayers(TMXMap& map, rapidxml::xml_node<> *parentNode);
	void loadProperties(std::unordered_map<std::string, std::string>& propertiesMap, rapidxml::xml_node<> *parentNode);

private:
	static void* loadFile(const char * filename, bool appendNull);
	
private:
	std::unordered_map<std::string, TMXMap> m_mapContainer;
};

