#include "TMXTileLayer.h"

#pragma region Class Constructors & Destructors 

TMXTileLayer::TMXTileLayer(const char* name, unsigned int width, unsigned int height, std::unordered_map<std::string, std::string> layerProperties, std::vector<unsigned int**> tiles) : m_name(name), m_width(width),
	m_height(height), m_layerProperties(layerProperties), m_tiles(tiles)
{
}


TMXTileLayer::~TMXTileLayer()
{

}

#pragma region

#pragma region Getter Functions

/*
* Gets the name of a TMXTileLayer instance.
*
* @return const char* - the name of the TMXTileLayer instance.
*/
const char* TMXTileLayer::getName()
{
	return m_name;
}

/*
* Gets the width of a TMXTileLayer instance.
*
* @return unsigned int - the width of the TMXTileLayer instance.
*/
unsigned int TMXTileLayer::getWidth()
{
	return m_width;
}

/*
* Gets the height of a TMXTileLayer instance.
*
* @return unsigned int - the height of the TMXTileLayer instance.
*/
unsigned int TMXTileLayer::getHeight()
{
	return m_height;
}

#pragma endregion


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
/*
	std::cout << "\nTiles: ";
	for (unsigned int index = 0; index < m_tileVector.size(); ++index)
	{
		std::cout << "\n Tile " << index << ": " << m_tileVector[index];
	}*/
}