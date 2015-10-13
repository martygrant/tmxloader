//
//  main.cpp
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

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "TMXLoader/TMXLoader.h"

bool update(SDL_Event &events)
{
    while (SDL_PollEvent(&events))
    {
        switch (events.type)
        {
            case SDL_WINDOWEVENT:
                switch (events.window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                    return false;
                    break;
                }
                break;
            case SDL_QUIT:
                return false;
                break;
        }
    }
    return true;
}


void renderRectOutline(SDL_Renderer* renderer, SDL_Rect& rect, Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_TRANSPARENT);
    SDL_RenderDrawRect(renderer, &rect);
}


void renderRectFilled(SDL_Renderer* renderer, SDL_Rect& rect, Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_TRANSPARENT);
    SDL_RenderFillRect(renderer, &rect);
}


void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect& destRect)
{
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}


void renderSpriteSheet(SDL_Renderer* renderer, SDL_Texture* texture)
{
    int tileWidth = 25;
    int sheetWidth = 75;
    int numberOfTiles = sheetWidth / tileWidth;
    
    for (int i = 0; i < numberOfTiles; ++i)
    {
        SDL_Rect srcrect = { tileWidth * i, 0, 25, 25 };
        SDL_Rect dstrect = { i * 100, 100, 25, 25 };
        
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    }
}


void testRenderMap(SDL_Renderer* renderer, SDL_Texture* texture, TMXLoader* loader)
{
    char tileID = 0;
    
    int tileWidth = loader->getMap("Assets/testlevel.tmx")->getTileWidth();
    int tileHeight = loader->getMap("Assets/testlevel.tmx")->getTileHeight();

    for (int i = 0; i < loader->getMap("Assets/testlevel.tmx")->getWidth(); ++i)
    {
        for (int j = 0; j < loader->getMap("Assets/testlevel.tmx")->getHeight(); ++j)
        {
            // get the tile at current position
            tileID = loader->getMap("Assets/testlevel.tmx")->getLayer("Tile Layer 1").getTileArray()[i][j];
            
            // only render if it is an actual tile (1, 2 or 3)
            if (tileID > 0)
            {
                SDL_Rect srcrect = { (tileID - 1) * tileHeight, 0 * tileHeight, tileWidth, tileHeight };
                SDL_Rect dstrect = { j * tileWidth, i * tileHeight, tileWidth, tileHeight };
                SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
            }
        }
    }
}


void render(SDL_Renderer* renderer, SDL_Texture* texture, TMXLoader* loader)
{
    SDL_SetRenderDrawColor(renderer, 10, 255, 255, SDL_ALPHA_TRANSPARENT);
    SDL_RenderClear(renderer);
    
    testRenderMap(renderer, texture, loader);
    
    SDL_RenderPresent(renderer);
}


int main(int argc, const char * argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
    }
    
    Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    
    SDL_Window* window = SDL_CreateWindow("TMXLoader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, windowFlags);
    
    if (window == NULL)
    {
        std::cout << "SDL_CreateWindow: " << SDL_GetError() << std::endl;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    
    SDL_Texture* spriteSheet = IMG_LoadTexture(renderer, "Assets/spritesheet1.png");
    
    TMXLoader* loader = new TMXLoader();
    loader->loadMap("Assets/testlevel.tmx");
    
    bool running = true;
    SDL_Event events;
    while (running == true)
    {
        running = update(events);
        render(renderer, spriteSheet, loader);
    }
    
    delete loader;
    
    SDL_DestroyTexture(spriteSheet);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    return 0;
}
