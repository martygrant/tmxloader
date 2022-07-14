//
//  TMXMap.cpp
//  TMXLoader
//
//  Created by Marty on 06/09/2015.
//  Copyright (c) 2015 - 2020 Martin Grant. All rights reserved.
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
//  http://github.com/martingrant/tmxloader

#include <iostream>
#include "TMXMap.h"

TMXMap::TMXMap() : m_version(0.0f), m_width(0), m_height(0), m_tileWidth(0), m_tileHeight(0), m_backgroundColour({}) {}

TMXMap::~TMXMap() noexcept
{
    m_propertiesMap.clear();
    std::unordered_map<std::string, std::string>{}.swap(m_propertiesMap);

    m_tileVector.clear();
    std::vector<TMXTileSet>{}.swap(m_tileVector);

    m_layerVector.clear();
    std::vector<TMXTileLayer>{}.swap(m_layerVector);
}

void TMXMap::setMapSettings(std::vector<std::string> const &mapData, std::unordered_map<std::string, std::string> const &mapProps) noexcept
{
    m_version = std::stof(mapData[0]);
    m_orientation = mapData[1];
    m_renderOrder = mapData[2];
    m_width = std::stoi(mapData[3]);
    m_height = std::stoi(mapData[4]);
    m_tileWidth = std::stoi(mapData[5]);
    m_tileHeight = std::stoi(mapData[6]);

    m_backgroundColour[0] = std::stoi(mapData[8]);
    m_backgroundColour[1] = std::stoi(mapData[8]);
    m_backgroundColour[2] = std::stoi(mapData[8]);

    m_propertiesMap = mapProps;
}

float TMXMap::getVersion() const noexcept { return m_version; }

unsigned TMXMap::getWidth() const noexcept { return m_width; }
unsigned TMXMap::getHeight() const noexcept { return m_height; }
unsigned TMXMap::getTileWidth() const noexcept { return m_tileWidth; }
unsigned TMXMap::getTileHeight() const noexcept { return m_tileHeight; }

std::array<unsigned, 3> TMXMap::getBackgroundColor() const noexcept { return m_backgroundColour; }

std::string TMXMap::getOrientation() const noexcept { return m_orientation; }
std::string TMXMap::getRenderOrder() const noexcept { return m_renderOrder; }

void TMXMap::addTileSet(TMXTileSet const &newTileSet) noexcept { m_tileVector.push_back(newTileSet); }

TMXTileSet *TMXMap::getTileset(std::string const &tileSetName) noexcept
{
    for (unsigned idx{0}; idx < m_tileVector.size(); ++idx)
        if (m_tileVector[idx].getName() == tileSetName)
            return &m_tileVector[idx];
    std::cout << "TMXLoader: tileset layer '" << tileSetName << "' could not be found." << std::endl;
    return nullptr;
}

void TMXMap::addLayer(TMXTileLayer const &newLayer) noexcept { m_layerVector.push_back(newLayer); }

TMXTileLayer *TMXMap::getLayer(std::string const &layerName) noexcept
{
    for (unsigned idx{0}; idx < m_layerVector.size(); ++idx)
        if (m_layerVector[idx].getName() == layerName)
            return &m_layerVector[idx];
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
              << "\nBackground Colour: " << m_backgroundColour[0] << "," << m_backgroundColour[1] << "," << m_backgroundColour[2]
              << "\nRender Order: " << m_renderOrder;

    std::cout << "\n\nTest map properties:\n";
    for (auto index = m_propertiesMap.begin(); index != m_propertiesMap.end(); ++index)
    {
        std::cout << index->first << " - " << index->second << std::endl;
    }

    std::cout << "\n\nTest map tilesets:\n";
    for (unsigned int index = 0; index < m_tileVector.size(); ++index)
    {
        m_tileVector[index].printData();
    }

    std::cout << "\n\nTest map layers:\n";
    for (unsigned int index = 0; index < m_layerVector.size(); ++index)
    {
        m_layerVector[index].printData();
    }
}