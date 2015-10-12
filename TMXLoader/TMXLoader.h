//
//  TMXLoader.h
//  TMXLoader
//
//  Created by Marty on 06/09/2015.
//  Copyright (c) 2015 Martin Grant. All rights reserved.
//
//  www.midnightpacific.com
//  contact@midnightpacific.com
//  @_martingrant
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <memory>

#include "rapidxml.hpp"

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
    void loadMap(std::string filePath);
    std::unique_ptr<TMXMap> const &getMap(std::string mapName);
    
    /* Map loading helper functions */
private:
    void loadMapSettings(std::unique_ptr<TMXMap> const &map, rapidxml::xml_node<> *parentNode);
	void loadTileSets(std::unique_ptr<TMXMap> const &map, rapidxml::xml_node<> *parentNode);
	void loadLayers(std::unique_ptr<TMXMap> const &map, rapidxml::xml_node<> *parentNode);
	void loadProperties(std::unordered_map<std::string, std::string>& propertiesMap, rapidxml::xml_node<> *parentNode);

    /* File loading helper functions */
private:
    bool loadFile(std::string filePath, std::string &fileContents);

    /* Unordered map container for loaded Maps */
private:
    std::unordered_map<std::string, std::unique_ptr<TMXMap>> m_mapContainer;
};

