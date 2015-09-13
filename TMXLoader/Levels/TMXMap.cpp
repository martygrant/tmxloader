#include "TMXMap.h"

#pragma region Class Constructors & Destructors 

TMXMap::TMXMap(const std::vector<std::string>& mapData, const std::unordered_map<std::string, std::string>& propertiesMap) : m_propertiesMap(propertiesMap)
{
	m_version = stoi(mapData[0]);
	m_orientation = mapData[1];
    m_renderOrder = mapData[2];
	m_width = stoi(mapData[3]);
	m_height = stoi(mapData[4]);
	m_tileWidth = stoi(mapData[5]);
	m_tileHeight = stoi(mapData[6]);
	m_backgroundColour.reserve(3);
	m_backgroundColour.push_back(stoi(mapData[7]));
	m_backgroundColour.push_back(stoi(mapData[8]));
	m_backgroundColour.push_back(stoi(mapData[9]));
}


TMXMap::~TMXMap()
{
	m_backgroundColour.clear();
}

#pragma endregion

#pragma region Map Settings

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


std::vector<unsigned int> TMXMap::getBackgroundColour()
{
	return m_backgroundColour;
}

#pragma endregion

#pragma region User-defined Properties

#pragma endregion

#pragma region TileSets

/*
* Adds a new TileSet to the TileSet vector of this TMXMap instance, including all the properties of the TileSet.
*
* @param const char* name - the name of the tile set.
* @param const char* source - the actual image for the tile set (path to the file).
* @param unsigned int firstGID - the unique ID of the first tile in the tile set.
* @param unsigned int imageWidth - the width of the tile set image.
* @param unsigned int imageHeight - the height of the tile set image.
* @param unsigned int tileWidth - the width of individual tiles in the set.
* @param unsigned int tileHeight - the height of individual tiles in the set.
*/
void TMXMap::addTileSet(TMXTileSet newTileSet)
{
	m_tileSetVector.push_back(newTileSet);
}

#pragma endregion

#pragma region Layers

/*
* Adds a new Tile Layer to this TMXMap instance.
*
* @param const char* name - the name of the layer.
* @param unsigned int width - the width of the layer.
* @param unsigned int height - the height of the layer.
* @param std::vector<unsigned int> tileVector - vector containing all the tiles in the layer, identified by their GID.
*/
void TMXMap::addLayer(TMXTileLayer newLayer)
{
	m_layerVector.push_back(newLayer);
}

#pragma endregion

void TMXMap::printData()
{
	std::cout << "\nTest map settings:"
		<< "\nVersion: " << m_version
		<< "\nOrientation: " << m_orientation
		<< "\nWidth: " << m_width
		<< "\nHeight: " << m_height
		<< "\nTile Width: " << m_tileWidth
		<< "\nTileHeight: " << m_tileHeight
		<< "\nBackground Colour: " << m_backgroundColour[0] << "," << m_backgroundColour[1] << "," << m_backgroundColour[2];

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