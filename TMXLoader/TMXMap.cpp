//
//  TMXMap.cpp
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

#include "TMXMap.h"


TMXMap::TMXMap()
{
}


TMXMap::~TMXMap()
{
    m_propertiesMap.clear();
    std::unordered_map<std::string, std::string>().swap(m_propertiesMap);

    m_tileSetVector.clear();
    std::vector<TMXTileSet>().swap(m_tileSetVector);
    
    m_layerVector.clear();
    std::vector<TMXTileLayer>().swap(m_layerVector);
}


void TMXMap::setMapSettings(const std::vector<std::string>& mapData, const std::unordered_map<std::string, std::string>& propertiesMap)
{
    m_version = stoi(mapData[0]);
    m_orientation = mapData[1];
    m_renderOrder = mapData[2];
    m_width = stoi(mapData[3]);
    m_height = stoi(mapData[4]);
    m_tileWidth = stoi(mapData[5]);
    m_tileHeight = stoi(mapData[6]);
    m_backgroundColourArray[0] = stoi(mapData[8]);
    m_backgroundColourArray[1] = stoi(mapData[8]);
    m_backgroundColourArray[2] = stoi(mapData[8]);
    
    m_propertiesMap = propertiesMap;
}


float TMXMap::getVersion()
{
	return m_version;
}


std::string TMXMap::getOrientation()
{
	return m_orientation;
}


unsigned int TMXMap::getWidth()
{
	return m_width;
}


unsigned int TMXMap::getHeight()
{
	return m_height;
}


unsigned int TMXMap::getTileWidth()
{
	return m_tileWidth;
}


unsigned int TMXMap::getTileHeight()
{
	return m_tileHeight;
}


std::array<unsigned int, 3> TMXMap::getBackgroundColourArray()
{
    return m_backgroundColourArray;
}


std::string TMXMap::getRenderOrder()
{
    return m_renderOrder;
}


void TMXMap::addTileSet(TMXTileSet newTileSet)
{
	m_tileSetVector.push_back(newTileSet);
}


TMXTileSet* TMXMap::getTileSet(std::string tileSetName)
{
    for (unsigned int index = 0; index < m_tileSetVector.size(); ++index)
    {
        if (m_tileSetVector[index].getName() == tileSetName)
        {
            return &m_tileSetVector[index];
        }
    }
    
    std::cout << "TMXLoader: tileset layer '" << tileSetName << "' could not be found." << std::endl;
    
    return nullptr;
}


void TMXMap::addLayer(TMXTileLayer newLayer)
{
	m_layerVector.push_back(newLayer);
}


TMXTileLayer* TMXMap::getTileLayer(std::string layerName)
{
    for (unsigned int index = 0; index < m_layerVector.size(); ++index)
    {
        if (m_layerVector[index].getName() == layerName)
        {
            return &m_layerVector[index];
        }
    }
    
    std::cout << "TMXLoader: tile layer '" << layerName << "' could not be found." << std::endl;
    
    return nullptr;
}


void TMXMap::printData()
{
	std::cout << "\nVersion: " << m_version
		<< "\nOrientation: " << m_orientation
		<< "\nWidth: " << m_width
		<< "\nHeight: " << m_height
		<< "\nTile Width: " << m_tileWidth
		<< "\nTile Height: " << m_tileHeight
		<< "\nBackground Colour: " << m_backgroundColourArray[0] << "," << m_backgroundColourArray[1] << "," << m_backgroundColourArray[2]
        << "\nRender Order: " << m_renderOrder;

	std::cout << "\n\nTest map properties:\n";
	for (auto index = m_propertiesMap.begin(); index != m_propertiesMap.end(); ++index)
	{
		std::cout << index->first << " - " << index->second << std::endl;
	}

	std::cout << "\n\nTest map tilesets:\n";
	for (unsigned int index = 0; index < m_tileSetVector.size(); ++index)
	{
		m_tileSetVector[index].printData();
	}

	std::cout << "\n\nTest map layers:\n";
	for (unsigned int index = 0; index < m_layerVector.size(); ++index)
	{
		m_layerVector[index].printData();
	}
}