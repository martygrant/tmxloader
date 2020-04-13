//
//  TMXTileLayer.h
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

#include <vector>
#include <unordered_map>

class TMXTileLayer final
{
public:
    /* Class constructors & destructors */
    TMXTileLayer(std::string const &name, unsigned width, unsigned height,
                 std::unordered_map<std::string, std::string> const &layerProperties,
                 std::vector<std::vector<unsigned>> const &tileVector);
    ~TMXTileLayer() noexcept;

    /* Getter functions  */
    unsigned getWidth() const noexcept;
    unsigned getHeight() const noexcept;
    std::string getName() const noexcept;
    std::string getProperty(std::string const &propertyName) noexcept;
    std::vector<std::vector<unsigned>> getTiles() const noexcept;

    /* Debug functions */
    void printData();

private:
    /* Layer variables */
    unsigned m_width, m_height;
    std::string m_name;
    std::vector<std::vector<unsigned>> m_tileVector;
    std::unordered_map<std::string, std::string> m_layerProperties;
};
