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
* TMXLoader stores a collection of TMXMaps, so you can load a group of maps and access their data later as you please.
```
#!c++

TMXLoader* loader = new Loader();
loader->loadMap("testmap", "Assets/testmap.tmx"); 
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

loader->getMap("testmap")->getTileSet("defaulttileset")->getName();
loader->getMap("testmap")->getTileSet("defaulttileset")->getSource();
loader->getMap("testmap")->getTileSet("defaulttileset")->getFirstGID();
loader->getMap("testmap")->getTileSet("defaulttileset")->getLastGID();

loader->getMap("testmap")->getTileSet("defaulttileset")->getImageWidth();
loader->getMap("testmap")->getTileSet("defaulttileset")->getImageHeight();
loader->getMap("testmap")->getTileSet("defaulttileset")->getTileWidth();
loader->getMap("testmap")->getTileSet("defaulttileset")->getTileHeight();
loader->getMap("testmap")->getTileSet("defaulttileset")->getSpacing();
loader->getMap("testmap")->getTileSet("defaulttileset")->getMargin();
loader->getMap("testmap")->getTileSet("defaulttileset")->getOffsetX();
loader->getMap("testmap")->getTileSet("defaulttileset")->getOffsetY();
loader->getMap("testmap")->getTileSet("defaulttileset")->getTransparentColourArray();
loader->getMap("testmap")->getTileSet("defaulttileset")->getTileCount();
loader->getMap("testmap")->getTileSet("defaulttileset")->getProperty("property1");

loader->getMap("testmap")->getTileSet("defaulttileset")->getTile(1);
loader->getMap("testmap")->getTileSet("defaulttileset")->getTile(1)->getProperty("tileproperty1");

loader->getMap("testmap")->getTileLayer("Tile Layer 1")->getName();
loader->getMap("testmap")->getTileLayer("Tile Layer 1")->getWidth();
loader->getMap("testmap")->getTileLayer("Tile Layer 1")->getHeight();
loader->getMap("testmap")->getTileLayer("Tile Layer 1")->getTileVector();
loader->getMap("testmap")->getTileLayer("Tile Layer 1")->getProperty();
 
```


### Usage ###

* I am providing my code under the MIT license, meaning you can use the code however you like for free, as long as you credit me and don't hold me liable to any problems you may have with the code. See License.txt in the source for more information.

* The project makes use of [RapidXML](http://rapidxml.sourceforge.net/) which also comes with the MIT license. See /TMXLoader/RapidXML/License.txt


### Who do I talk to? ###

If you find the code useful, or have problems/suggestions I would love to hear from you.

* [@_martingrant](https://twitter.com/_martingrant)
* www.martingrant.net
* martingrant@outlook.com