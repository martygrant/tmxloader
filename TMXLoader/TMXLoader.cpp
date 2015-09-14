#include "TMXLoader.h"


TMXLoader::TMXLoader()
{
}


TMXLoader::~TMXLoader()
{
}


void TMXLoader::loadLevel(const char* levelPath)
{
	char* xml = (char*)loadFile(levelPath, true);

	rapidxml::xml_document<char> m_currentMap;
	m_currentMap.parse<0>(xml);
	rapidxml::xml_node<> *parentNode = m_currentMap.first_node("map");

    TMXMap newMap;// = new TMXMap();// = std::shared_ptr<TMXMap>(new TMXMap());

	loadMapSettings(newMap, parentNode);
	loadTileSets(newMap, parentNode);
	loadLayers(newMap, parentNode);

	m_mapContainer[levelPath] = newMap;

	// print level data for testing
	m_mapContainer[levelPath].printData();

}


void TMXLoader::loadMapSettings(TMXMap& map, rapidxml::xml_node<> *parentNode)
{
	std::vector<std::string> mapData;

	for (rapidxml::xml_attribute<char> *attr = parentNode->first_attribute(); attr; attr = attr->next_attribute())
	{
		mapData.push_back(attr->value());
	}

	std::string colourString = mapData[6];
	std::string colourSubstring = colourString.substr(1, colourString.length());

	unsigned int colour = stoi(colourSubstring, 0, 16);

	mapData.push_back(std::to_string(colour / 0x10000));
	mapData.push_back(std::to_string((colour / 0x100) % 0x100));
	mapData.push_back(std::to_string(colour / 0x10000));

	std::unordered_map<std::string, std::string> propertiesMap;

	loadProperties(propertiesMap, parentNode);

 	//map = std::shared_ptr<TMXMap>(new TMXMap(mapData, propertiesMap));
    map = TMXMap(mapData, propertiesMap);
}


void TMXLoader::loadTileSets(TMXMap& map, rapidxml::xml_node<> *parentNode)
{
	// Create a new node based on the parent node
	rapidxml::xml_node<> *currentNode = parentNode;

	// Check if there is a tileset node
	if (currentNode->first_node("tileset") != nullptr)
	{
		// Move to the first tileset node
		currentNode = currentNode->first_node("tileset");

		// Use a map to hold data for creating a tile set
		std::unordered_map<std::string, std::string> tileSetData;

		// Use a map to hold tileset properties
		std::unordered_map<std::string, std::string> propertiesMap;

		// Use a vector and map for individual tiles that have properties
		std::vector<TMXTile> tileVector;
		std::unordered_map<std::string, std::string> tileProperties;

		// Loop whilst there are tileset nodes found
		while (currentNode != nullptr)
		{
			// Read tileset data 
			for (rapidxml::xml_attribute<char> *attr = currentNode->first_attribute(); attr; attr = attr->next_attribute())
			{
				tileSetData[attr->name()] = attr->value();
			}

			// Check for offset node
			rapidxml::xml_node<> *offsetNode = currentNode;
			if (offsetNode->first_node("tileoffset") != nullptr)
			{
				offsetNode = offsetNode->first_node("tileoffset");

				tileSetData["tileoffsetX"] = offsetNode->first_attribute()->value();
				tileSetData["tileoffsetY"] = offsetNode->first_attribute()->next_attribute()->value();
			}

			// Clear the properties map of the data from the previous tileset
			propertiesMap.clear();
			// Load tileset properties
			loadProperties(propertiesMap, currentNode);

			// Move to the image childnode and read data
			currentNode = currentNode->first_node("image");
			for (rapidxml::xml_attribute<char> *attr = currentNode->first_attribute(); attr; attr = attr->next_attribute())
			{
				if (strcmp(attr->name(), "trans") == 0)
				{
					unsigned int colour = std::stoi(attr->value(), 0, 16);
		
					tileSetData["red"] = std::to_string(colour / 0x10000);
					tileSetData["green"] = std::to_string((colour / 0x100) % 0x100);
					tileSetData["blue"] = std::to_string(colour / 0x10000);
				}
				else
				{
					tileSetData[attr->name()] = attr->value();
				}
			}

			// Check and load if any individual tiles have properties
			tileVector.clear();
			rapidxml::xml_node<> *tileNode = currentNode->parent()->first_node("tile");
			while (tileNode != nullptr)
			{
				unsigned int tileID = atoi(tileNode->first_attribute()->value());
				loadProperties(tileProperties, tileNode);
				tileVector.push_back(TMXTile(tileID, tileProperties));

				tileProperties.clear();

				if (tileNode->next_sibling("tile") != nullptr)
				{
					tileNode = tileNode->next_sibling("tile");
				}
				else
				{
					break;
				}
			}

			// Pass the new tileset data to the level
 			map.addTileSet(TMXTileSet(tileSetData, propertiesMap, tileVector));

			// Move to the next tileset node and increment the counter
			if (currentNode->parent()->next_sibling("tileset") == nullptr)
			{
				break;
			}
			else
			{
				tileSetData.clear();
				currentNode = currentNode->parent()->next_sibling("tileset");
			}
		}
	}
}


void TMXLoader::loadLayers(TMXMap& map, rapidxml::xml_node<> *parentNode)
{
	// Create a new node based on the parent node
	rapidxml::xml_node<> *currentNode = parentNode;

	// MJove to first layer node
	currentNode = currentNode->first_node("layer");
	
	std::vector<std::vector<char*>> layerVector;

    std::vector<unsigned int**> tiles;
    unsigned int** tileLayer = new unsigned int*[map.getHeight()];
    for (int i = 0; i < map.getHeight(); ++i)
    {
        tileLayer[i] = new unsigned int[map.getWidth()];
    }
    
    
	unsigned int counter = 0;
	char* layerName = "";
	unsigned int layerWidth = 0;
	unsigned int layerHeight = 0;
	std::unordered_map<std::string, std::string> layerProperties;

	while (currentNode != nullptr)
	{
		layerProperties.clear();

		// Push a new vector onto the layer vector
		std::vector<char*> tempLayerVec;
		layerVector.push_back(tempLayerVec);
        
		// Read data into the current layer vector
		for (rapidxml::xml_attribute<char> *attr = currentNode->first_attribute(); attr; attr = attr->next_attribute())
		{
			layerVector[counter].push_back(attr->value());
		}

		// Load any properties for the layer
		loadProperties(layerProperties, currentNode);

		currentNode = currentNode->first_node("data");
		// Move to the tile nodes for the current layer
		currentNode = currentNode->first_node("tile");

        
        tiles.push_back(new unsigned int*[map.getHeight()]);
        for (int i = 0; i < map.getHeight(); ++i)
        {
            tiles.back()[i] = new unsigned int[map.getWidth()];
        }
        
        int numberOfTilesInRow = map.getWidth();
        int currentTile = 0;
        int currentRow = 0;
        // Loop whilst there are still tiles to be read and add them to the vector
        while (currentNode != nullptr)
        {
            if (currentTile < numberOfTilesInRow)
            {
                
                std::stringstream ss; ss << currentNode->first_attribute()->value();
                unsigned int tile; ss >> tile;
                tiles.back()[currentRow][currentTile] = tile;

                currentTile++;
                if (currentNode->next_sibling("tile") == nullptr)
                    break;
                else
                    currentNode = currentNode->next_sibling("tile");
            }
            else
            {
                currentTile = 0;
                currentRow++;
            }
                             
        }
        
		layerName = layerVector[counter][0];
		layerWidth = atoi(layerVector[counter][1]);
		layerHeight = atoi(layerVector[counter][2]);

		// Add the newly read layer to the level
		map.addLayer(TMXTileLayer(layerName, layerWidth, layerHeight, layerProperties, tiles));
		
		// Move to the next layer
		currentNode = currentNode->parent()->parent()->next_sibling("layer");
		counter++;
	}
}


void TMXLoader::loadProperties(std::unordered_map<std::string, std::string>& propertiesMap, rapidxml::xml_node<> *parentNode)
{
	// Create a new node based on the parent node
	rapidxml::xml_node<> *currentNode = parentNode;

	// Check if there is a properties node
	if (currentNode->first_node("properties") != nullptr)
	{
		// Move to the properties node
		currentNode = currentNode->first_node("properties");
		// Move to the first property node
		currentNode = currentNode->first_node("property");

		// Loop whilst there are property nodes found
		while (currentNode != nullptr)
		{
			propertiesMap[currentNode->first_attribute()->value()] = currentNode->first_attribute()->next_attribute()->value();
			currentNode = currentNode->next_sibling("property");
		}
	}
}


void* TMXLoader::loadFile(const char * filename, bool appendNull) 
{
	FILE* f = fopen(filename, "r");
	if (!f) {
		return 0;
	}

	fseek(f, 0, SEEK_END);
	auto length = ftell(f) + appendNull;
	fseek(f, 0, SEEK_SET);

	void* buffer = malloc(length);
	fread(buffer, length, 1, f);
	fclose(f);

	if (appendNull) {
		((char*)buffer)[length - 1] = 0;
	}

	return buffer;
}


