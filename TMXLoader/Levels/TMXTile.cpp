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
