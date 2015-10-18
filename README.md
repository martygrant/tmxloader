# README #

### What is this repository for? ###

* C++ loader and data structure for .tmx maps created by [Tiled Map Editor](http://www.mapeditor.org/).
* Version 1.0.
* Supports:
     * Tiled .tmx maps exported as XML
     * TileSets
     * Layers
     * Properties
* Not-supported yet:
     * Objects
     * Terrain
     * Tile-flipping
     * Image layers


### How do I get set up? ###

* [Clone](https://martingrant@bitbucket.org/martingrant/tmxloader.git) the repository using git, or [Download](https://bitbucket.org/martingrant/tmxloader/downloads) the full repository.
* Demo code is provided using SDL to help you get started.

### Using the code ###

* Export your Tilemap using XML
* The following code snippet shows how to get access to your map's data:
```
#!c++

TMXLoader* loader = new Loader();
loader->loadMap("testmap", "Assets/testmap.tmx"); // loads and stores a map, provide a name to access the map later, and its filepath to be loaded from
loader->printMapData("testmap"); // prints map data to console, useful for debugging

loader->getMap("testmap"); // gets a map loaded and held by TMXLoader
loader->getMap("testmap")->getVersion();
loader->getMap("testmap")->getOrientation();
loader->getMap("testmap")->getWidth();
loader->getMap("testmap")->getHeight();
loader->getMap("testmap")->getTileWidth();
loader->getMap("testmap")->getTileHeight();
loader->getMap("testmap")->getBackgroundColourArray();
loader->getMap("testmap")->getRenderOrder();
loader->getMap("testmap")->getLayer(); 
```




### Usage ###

* I am providing my code under the MIT license, meaning you can use the code however you like for free, as long as you credit me and don't hold me liable to any problems you may have with the code. See License.txt in the source for more information.

* The project makes use of [RapidXML](http://rapidxml.sourceforge.net/) which also comes with the MIT license. See /TMXLoader/RapidXML/License.txt


### Who do I talk to? ###

* [@_martingrant](https://twitter.com/_martingrant)
* www.midnightpacific.com
* contact@midnightpacific.com