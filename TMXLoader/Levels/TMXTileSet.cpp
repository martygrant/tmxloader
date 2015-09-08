#include "TMXTileSet.h"

#pragma region Class Constructors & Destructors

/*
* Constructor for TMXTileSet. Sets all properties for a TMXTileSet insance.
*
* @param std::unordered_map<std::string, std::string>& tileSetData - reference to a map holding data describing the tileset.
*/
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

	m_transparentColour.reserve(3);
	m_transparentColour.push_back(atoi(tileSetData["red"].c_str()));
	m_transparentColour.push_back(atoi(tileSetData["green"].c_str()));
	m_transparentColour.push_back(atoi(tileSetData["blue"].c_str()));
}


TMXTileSet::~TMXTileSet()
{

}

#pragma endregion

#pragma region Getter Functions

/*
* Gets the name for a instance of TMXTileSet.
*
* @return std::string - returns the name of the tile set instance.
*/
std::string TMXTileSet::getName()
{
	return m_name;
}

/*
* Gets the source image path for an instance of TMXTileSet.
*
* @return std::string - returns the source image path of the tile set instance.
*/
std::string TMXTileSet::getSource()
{
	return m_source;
}

/*
* Gets the first GID for an instance of TMXTileSet.
*
* @return unsigned int - returns the unique ID of the first tile in the set.
*/
unsigned int TMXTileSet::getFirstGID()
{
	return m_firstGID;
}

/*
* Gets the last GID for an instance of TMXTileSet.
*
* @return unsigned int - returns the unique ID of the last tile in the set.
*/
unsigned int TMXTileSet::getLastGID()
{
	return m_lastGID;
}

/*
* Gets the image width for an instance of TMXTileSet.
*
* @return unsigned int - returns the width of the image of a tile set.
*/
unsigned int TMXTileSet::getImageWidth()
{
	return m_imageWidth;
}

/*
* Gets the image height for an instance of TMXTileSet.
*
* @return unsigned int - returns the height of the image of a tile set.
*/
unsigned int TMXTileSet::getImageHeight()
{
	return m_imageHeight;
}

/*
* Gets the tile width for an instance of TMXTileSet.
*
* @return unsigned int - returns the width of a tile in a set.
*/
unsigned int TMXTileSet::getTileWidth()
{
	return m_tileWidth;
}

/*
* Gets the tile height for an instance of TMXTileSet.
*
* @return unsigned int - returns the height of a tile in a set.
*/
unsigned int TMXTileSet::getTileHeight()
{
	return m_tileHeight;
}

/*
* Gets the spacing for an instance of TMXTileSet.
*
* @return unsigned int - returns the spacing of tiles in a set.
*/
unsigned int TMXTileSet::getSpacing()
{
	return m_spacing;
}

/*
* Gets the margin for an instance of TMXTileSet.
*
* @return unsigned int - returns the margin of a tile set.
*/
unsigned int TMXTileSet::getMargin()
{
	return m_margin;
}

/*
* Gets the X offset for an instance of TMXTileSet.
*
* @return unsigned int - returns the X offset of a tile set.
*/
unsigned int TMXTileSet::getOffsetX()
{
	return m_offsetX;
}

/*
* Gets the Y offset for an instance of TMXTileSet.
*
* @return unsigned int - returns the Y offset of a tile set.
*/
unsigned int TMXTileSet::getOffsetY()
{
	return m_offsetY;
}

/*
* Gets the transparent colour of a tileset.
*
* @return std::vector<unsigned int> - vector containing 3 ints which represent a transparency colour for the tileset.
*/
std::vector<unsigned int> TMXTileSet::getTransparentColour()
{
	return m_transparentColour;
}

#pragma endregion

void TMXTileSet::printData()
{
	std::cout << "\nName: " << m_name
		<< "\nSource: " << m_source
		<< "\nfirstGID: " << m_firstGID
		<< "\nlastGID: " << m_lastGID
		<< "\nimageWidth:" << m_imageWidth
		<< "\nimageHeight: " << m_imageHeight
		<< "\ntileWidth: " << m_tileWidth
		<< "\ntileHeight" << m_tileHeight
		<< "\nSpacing: " << m_spacing
		<< "\nMargin: " << m_margin
		<< "\noffsetX: " << m_offsetX
		<< "\noffsetY: " << m_offsetY
		<< "\ntransparentColour: " << m_transparentColour[0] << "," << m_transparentColour[1] << "," << m_transparentColour[2] << "\n";

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