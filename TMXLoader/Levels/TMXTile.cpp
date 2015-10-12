//
//  TMXTile.cpp
//  TMXLoader
//
//  Created by Marty on 06/09/2015.
//  Copyright (c) 2015 Martin Grant. All rights reserved.
//
//  www.midnightpacific.com
//  contact@midnightpacific.com
//  @_martingrant
//

#include "TMXTile.h"


TMXTile::TMXTile(unsigned int tileID, std::unordered_map<std::string, std::string>& propertiesMap) : m_tileID(tileID), m_propertiesMap(propertiesMap)
{
}


TMXTile::~TMXTile()
{
    m_propertiesMap.clear();
    std::unordered_map<std::string, std::string>().swap(m_propertiesMap);
}


void TMXTile::printData()
{
	std::cout << "Tile ID: " << m_tileID << "\n Tile Properties: " << std::endl;
	for (auto index = m_propertiesMap.begin(); index != m_propertiesMap.end(); ++index)
	{
		std::cout << "\n" << index->first << " - " << index->second << std::endl;
	}
}
