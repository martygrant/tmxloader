//
//  TMXTileSet.cpp
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
#include "TMXTileSet.h"

TMXTileSet::TMXTileSet(
	std::unordered_map<std::string, std::string> const&tileSetData,
	std::unordered_map<std::string, std::string> const &propertiesMap,
	std::vector<TMXTile> const &tileVector)
	: m_propertiesMap{propertiesMap}, m_tileVector{tileVector},
	  m_name{tileSetData.at("name")}, m_source{tileSetData.at("source")},
	  m_firstGID{std::stoul(tileSetData.at("firstgid").c_str())},
	  m_imageWidth{std::stoul(tileSetData.at("width").c_str())},
	  m_imageHeight{std::stoul(tileSetData.at("height").c_str())},
	  m_tileWidth{std::stoul(tileSetData.at("tilewidth").c_str())},
	  m_tileHeight{std::stoul(tileSetData.at("tileheight").c_str())},
	  m_offsetX{std::stoul(tileSetData.at("tileoffsetX").c_str())},
	  m_offsetY{std::stoul(tileSetData.at("tileoffsetY").c_str())},
	  m_spacing{std::stoul(tileSetData.at("spacing").c_str())},
	  m_margin{std::stoul(tileSetData.at("margin").c_str())},
	  m_tileCount{std::stoul(tileSetData.at("tilecount").c_str())},
	  m_transparentColour{std::stoul(tileSetData.at("red").c_str()),
						  std::stoul(tileSetData.at("green").c_str()),
						  std::stoul(tileSetData.at("blue").c_str())} {}



TMXTileSet::~TMXTileSet() noexcept
{
	m_propertiesMap.clear();
	std::unordered_map<std::string, std::string>{}.swap(m_propertiesMap);

	m_tileVector.clear();
	std::vector<TMXTile>{}.swap(m_tileVector);
}

unsigned TMXTileSet::getFirstGID() const noexcept { return m_firstGID; }

unsigned TMXTileSet::getImageWidth() const noexcept { return m_imageWidth; }
unsigned TMXTileSet::getImageHeight() const noexcept { return m_imageHeight; }

unsigned TMXTileSet::getTileWidth() const noexcept { return m_tileWidth; }
unsigned TMXTileSet::getTileHeight() const noexcept { return m_tileHeight; }

unsigned TMXTileSet::getSpacing() const noexcept { return m_spacing; }
unsigned TMXTileSet::getMargin() const noexcept { return m_margin; }

unsigned TMXTileSet::getOffsetX() const noexcept { return m_offsetX; }
unsigned TMXTileSet::getOffsetY() const noexcept { return m_offsetY; }

unsigned TMXTileSet::getTileCount() const noexcept { return m_tileCount; }

std::array<unsigned, 3> TMXTileSet::getTransparentColour() const noexcept { return m_transparentColour; }

std::string TMXTileSet::getName() const noexcept { return m_name; }
std::string TMXTileSet::getSource() const noexcept { return m_source; }

std::string TMXTileSet::getProperty(std::string const &propertyName) noexcept
{
	if (std::unordered_map<std::string, std::string>::const_iterator it{m_propertiesMap.find(propertyName)};
		it != m_propertiesMap.end())
		return it->second;
	std::cout << "TMXLoader: property '" << propertyName << "' not found." << std::endl;
	return "";
}

TMXTile *TMXTileSet::getTile(unsigned id) noexcept
{
	for (unsigned idx{0}; idx < m_tileVector.size(); ++idx)
		if (id == m_tileVector[id].getTileID())
			return &m_tileVector[id];
	std::cout << "TMXLoader: tile with ID '" << id << "' not found." << std::endl;
	return nullptr;
}

void TMXTileSet::printData()
{
	std::cout << "\nName: " << m_name
			  << "\nSource: " << m_source
			  << "\nfirstGID: " << m_firstGID
			  << "\nimageWidth:" << m_imageWidth
			  << "\nimageHeight: " << m_imageHeight
			  << "\ntileWidth: " << m_tileWidth
			  << "\ntileHeight: " << m_tileHeight
			  << "\nSpacing: " << m_spacing
			  << "\nMargin: " << m_margin
			  << "\noffsetX: " << m_offsetX
			  << "\noffsetY: " << m_offsetY
			  << "\ntransparentColour: " << m_transparentColour[0] << "," << m_transparentColour[1] << "," << m_transparentColour[2]
			  << "\nTile Count: " << m_tileCount;

	std::cout << "\n Tileset properties:";
	for (auto index{m_propertiesMap.begin()}; index != m_propertiesMap.end(); ++index)
		std::cout << "\n"
				  << index->first << " - " << index->second << std::endl;

	std::cout << "\n Tile properties:";
	for (unsigned index{0}; index < m_tileVector.size(); ++index)
		m_tileVector[index].printData();
}
