//
//  TMXMap.h
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
#include <unordered_map>
#include <iostream>
#include <array>

#include "TMXTileSet.h"
#include "TMXTileLayer.h"

class TMXMap 
{
	/* Class constructors & destructors */
public:
	TMXMap();
    TMXMap(TMXMap& other) { }
	~TMXMap();

    /* Setter functions for map settings */
    void setMapSettings(const std::vector<std::string>& mapData, const std::unordered_map<std::string, std::string>& propertiesMap);
    
	/* Getter functions for map settings */
public:
	float getVersion();
	std::string getOrientation();
	unsigned int getWidth();
	unsigned int getHeight();
	unsigned int getTileWidth();
	unsigned int getTileHeight();
    std::array<unsigned int, 3> getBackgroundColourArray();
    std::string getRenderOrder();
    
    /* Debug functions */
public:
	void printData();

    /* Map variables */
private:
	float m_version;
	std::string m_orientation;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_tileWidth;
	unsigned int m_tileHeight;
    std::array<unsigned int, 3> m_backgroundColourArray;
    std::string m_renderOrder;
    
	/* User-defined properties */
private:
	std::unordered_map<std::string, std::string> m_propertiesMap;

	/* TileSets */
public:
	void addTileSet(TMXTileSet newTileSet);
    TMXTileSet* getTileSet(std::string tileSetName);

private:
	std::vector<TMXTileSet> m_tileSetVector;

	/* Layers */
public:
	void addLayer(TMXTileLayer newLayer);
    TMXTileLayer* getTileLayer(std::string layerName);

private:
	std::vector<TMXTileLayer> m_layerVector;
};





