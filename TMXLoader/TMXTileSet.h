//
//  TMXTileSet.h
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
#include <iostream>
#include <unordered_map>
#include <string>
#include <array>

#include "TMXTile.h"

class TMXTileSet
{
	/* Class constructors & destructors */
public:
	TMXTileSet(std::unordered_map<std::string, std::string>& tileSetData, std::unordered_map<std::string, std::string>& propertiesMap, std::vector<TMXTile>& tileVector);
	~TMXTileSet();

    /* Getter functions */
public:
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
    unsigned int getTileCount();
    std::string getProperty(std::string propertyName);
    TMXTile* getTile(unsigned int tileID);

    /* Debug functions */
public:
	void printData();

	/* TileSet variables */
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
    unsigned int m_tileCount;
	std::vector<TMXTile> m_tileVector;
    
    /* User-defined properties */
private:
    std::unordered_map<std::string, std::string> m_propertiesMap;
};