//
//  TMXTile.h
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
//

#pragma once

#include <string>
#include <unordered_map>

class TMXTile final
{
public:
    /* Class constructors & destructors */
    TMXTile(unsigned TileID, std::unordered_map<std::string, std::string> const &propertiesMap);
    ~TMXTile() noexcept;

    /* Getter functions */
    unsigned getTileID() const noexcept;
    std::string getProperty(std::string const &propertyName) noexcept;

    /* Debug functions */
    void printData();

private:
    /* TMXTile variables */
    unsigned m_TileID;

    /* User-defined properties */
    std::unordered_map<std::string, std::string> m_propertiesMap;
};