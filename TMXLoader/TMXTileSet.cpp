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

#include "TMXTileSet.h"


TMXTileSet::TMXTileSet(std::unordered_map<std::string, std::string>& tileSetData, std::unordered_map<std::string, std::string>& propertiesMap, std::vector<TMXTile>& tileVector) : m_propertiesMap(propertiesMap),
	m_tileVector(tileVector)	
{
	m_name = tileSetData["name"];
	m_source = tileSetData["source"];
	m_firstGID = atoi(tileSetData["firstgid"].c_str());
	m_imageWidth = atoi(tileSetData["width"].c_str());
	m_imageHeight = atoi(tileSetData["height"].c_str());
	m_tileWidth = atoi(tileSetData["tilewidth"].c_str());
	m_tileHeight = atoi(tileSetData["tileheight"].c_str());
	m_offsetX = atoi(tileSetData["tileoffsetX"].c_str());
	m_offsetY = atoi(tileSetData["tileoffsetY"].c_str());
	m_spacing = atoi(tileSetData["spacing"].c_str());
	m_margin = atoi(tileSetData["margin"].c_str());
    m_tileCount = atoi(tileSetData["tilecount"].c_str());
    
    m_transparentColourArray[0] = atoi(tileSetData["red"].c_str());
    m_transparentColourArray[1] = atoi(tileSetData["green"].c_str());
    m_transparentColourArray[2] = atoi(tileSetData["blue"].c_str());
}


TMXTileSet::~TMXTileSet()
{
    m_propertiesMap.clear();
    std::unordered_map<std::string, std::string>().swap(m_propertiesMap);
    
    m_tileVector.clear();
    std::vector<TMXTile>().swap(m_tileVector);
}


std::string TMXTileSet::getName()
{
	return m_name;
}


std::string TMXTileSet::getSource()
{
	return m_source;
}


unsigned int TMXTileSet::getFirstGID()
{
	return m_firstGID;
}


unsigned int TMXTileSet::getLastGID()
{
	return m_lastGID;
}


unsigned int TMXTileSet::getImageWidth()
{
	return m_imageWidth;
}


unsigned int TMXTileSet::getImageHeight()
{
	return m_imageHeight;
}


unsigned int TMXTileSet::getTileWidth()
{
	return m_tileWidth;
}


unsigned int TMXTileSet::getTileHeight()
{
	return m_tileHeight;
}


unsigned int TMXTileSet::getSpacing()
{
	return m_spacing;
}


unsigned int TMXTileSet::getMargin()
{
	return m_margin;
}


unsigned int TMXTileSet::getOffsetX()
{
	return m_offsetX;
}


unsigned int TMXTileSet::getOffsetY()
{
	return m_offsetY;
}


std::array<unsigned int, 3> TMXTileSet::getTransparentColourArray()
{
	return m_transparentColourArray;
}


unsigned int TMXTileSet::getTileCount()
{
    return m_tileCount;
}


std::string TMXTileSet::getProperty(std::string propertyName)
{
    std::unordered_map<std::string, std::string>::const_iterator iterator = m_propertiesMap.find(propertyName);
    
    if (iterator == m_propertiesMap.end())
    {
        std::cout << "TMXLoader: property '" << propertyName << "' not found." << std::endl;
    }
    else
    {
        return iterator->second;
    }
    
    return nullptr;
}


TMXTile* TMXTileSet::getTile(unsigned int tileID)
{
    for (unsigned int index = 0; index < m_lastGID; ++index)
    {
        if (tileID == m_tileVector[tileID].getTileID())
        {
            return &m_tileVector[tileID];
        }
    }
    
    std::cout << "TMXLoader: tile with ID '" << tileID << "' not found." << std::endl;
    
    return nullptr;
}


void TMXTileSet::printData()
{
	std::cout << "\nName: " << m_name
		<< "\nSource: " << m_source
		<< "\nfirstGID: " << m_firstGID
		<< "\nlastGID: " << m_lastGID
		<< "\nimageWidth:" << m_imageWidth
		<< "\nimageHeight: " << m_imageHeight
		<< "\ntileWidth: " << m_tileWidth
		<< "\ntileHeight: " << m_tileHeight
		<< "\nSpacing: " << m_spacing
		<< "\nMargin: " << m_margin
		<< "\noffsetX: " << m_offsetX
		<< "\noffsetY: " << m_offsetY
		<< "\ntransparentColour: " << m_transparentColourArray[0] << "," << m_transparentColourArray[1] << "," << m_transparentColourArray[2]
        << "\nTile Count: " << m_tileCount;

	std::cout << "\n Tileset properties:";
	for (auto index = m_propertiesMap.begin(); index != m_propertiesMap.end(); ++index)
	{
		std::cout << "\n" << index->first << " - " << index->second << std::endl;
	}

	std::cout << "\n Tile properties:";
	for (unsigned int index = 0; index < m_tileVector.size(); ++index)
	{
		m_tileVector[index].printData();
	}
}