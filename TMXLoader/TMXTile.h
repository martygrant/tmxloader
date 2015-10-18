//
//  TMXTile.h
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

#include <unordered_map>
#include <string>
#include <iostream>

class TMXTile
{
    /* Class constructors & destructors */
public:
	TMXTile(unsigned int tileID, std::unordered_map<std::string, std::string>& propertiesMap);
	~TMXTile();

    /* Getter functions */
public:
    unsigned int getTileID();
    std::string getProperty(std::string propertyName);
    
    /* Debug functions */
public:
	void printData();

    /* Tile variables */
private:
	unsigned int m_tileID;
    
    /* User-defined properties */
private:
	std::unordered_map<std::string, std::string> m_propertiesMap;
};

