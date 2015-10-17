//
//  TMXTileLayer.cpp
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

#include "TMXTileLayer.h"


TMXTileLayer::TMXTileLayer(std::string name, unsigned int width, unsigned int height, std::unordered_map<std::string, std::string> layerProperties, unsigned int** tileArray) : m_name(name), m_width(width),
	m_height(height), m_layerProperties(layerProperties), m_tileArray(tileArray)
{
}


TMXTileLayer::~TMXTileLayer()
{
    m_layerProperties.clear();
    std::unordered_map<std::string, std::string>().swap(m_layerProperties);
}


std::string TMXTileLayer::getName()
{
	return m_name;
}


unsigned int TMXTileLayer::getWidth()
{
	return m_width;
}


unsigned int TMXTileLayer::getHeight()
{
	return m_height;
}


unsigned int** TMXTileLayer::getTileArray()
{
    return m_tileArray;
}


void TMXTileLayer::printData()
{
	std::cout << "\nName: " << m_name
		<< "\nWidth: " << m_width
		<< "\nHeight: " << m_height
		<< "\nLayer Properties:";
	
	for (auto index = m_layerProperties.begin(); index != m_layerProperties.end(); ++index)
	{
		std::cout << "\n" << index->first << " - " << index->second << std::endl;
	}

	std::cout << "\nTiles:\n";
    unsigned int count = 0;
	for (unsigned int row = 0; row < m_width; ++row)
	{
        for (unsigned int column = 0; column < m_height; ++column)
        {
            //std::cout << "\n Tile " << count << ": " << m_tileArray[row][column];
            //++count;
            std::cout << m_tileArray[row][column] << " ";
        }
        std::cout << std::endl;
	}
}