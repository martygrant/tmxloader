#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

#include <rapidxml.hpp>
#include <rapidxml_print.hpp>

#include "../Levels/TMXMap.h"
#include "../Levels/TMXTileLayer.h"
#include "../Levels/TMXTileSet.h"
#include "../Levels/TMXTile.h"

class TMXLoader
{
public:
	/* Class Constructor & Destructor */
	TMXLoader();
	~TMXLoader();

public:
	void loadLevel(const char* levelPath);

private:
	void loadMapSettings(std::shared_ptr<TMXMap>& map, rapidxml::xml_node<> *parentNode);
	void loadTileSets(std::shared_ptr<TMXMap>& map, rapidxml::xml_node<> *parentNode);
	void loadLayers(std::shared_ptr<TMXMap>& map, rapidxml::xml_node<> *parentNode);
	void loadProperties(std::unordered_map<std::string, std::string>& propertiesMap, rapidxml::xml_node<> *parentNode);

private:
	static void* loadFile(const char * filename, bool appendNull);
	
private:
	std::unordered_map<std::string, std::shared_ptr<TMXMap>> m_mapContainer;
};

