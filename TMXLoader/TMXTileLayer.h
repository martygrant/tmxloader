//
//  TMXTileLayer.h
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
#include <string>

class TMXTileLayer
{
	/* Class constructors & destructors */
public:
    TMXTileLayer(std::string name, unsigned int width, unsigned int height, std::unordered_map<std::string, std::string> layerProperties,
                 unsigned int** tilesArray);
	~TMXTileLayer();

	/* Getter functions  */
public:
	std::string getName();
	unsigned int getWidth();
	unsigned int getHeight();
    unsigned int** getTileArray();
    
    /* Debug functions */
public:
	void printData();

	/* Layer variables */
private:
	std::string m_name;
	unsigned int m_width;
	unsigned int m_height;
    unsigned int** m_tileArray;

	/* User-defined Properties */
private:
	std::unordered_map<std::string, std::string> m_layerProperties;
};