//
//  TMXLoader.h
//  TMXLoader
//
//  Created by Marty on 06/09/2015.
//  Copyright (c) 2015 Martin Grant. All rights reserved.
//  Available under MIT license. See License.txt for more information.
//
//  Uses RapidXML for file parsing.
//  Copyright (c) 2006, 2007 Marcin Kalicinski
//  http://rapidxml.sourceforge.net/
//  See /RapidXML/License.txt for more information.
//
//  www.midnightpacific.com
//  contact@midnightpacific.com
//  @_martingrant
//  http://bitbucket.org/martingrant/tmxloader
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <memory>

#include "rapidxml.hpp"

#include "TMXMap.h"
#include "TMXTileLayer.h"
#include "TMXTileSet.h"
#include "TMXTile.h"

class TMXLoader
{
    /* Class constructors & destructors */
public:
	TMXLoader();
	~TMXLoader();

    /* Map methods */
public:
    void loadMap(std::string mapName, std::string filePath);
    TMXMap* getMap(std::string mapName);
    
    /* Debug methods */
public:
    void printMapData(std::string mapName);
    
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

