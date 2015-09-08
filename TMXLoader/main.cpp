//
//  main.cpp
//  TMXLoader
//
//  Created by Marty on 06/09/2015.
//  Copyright (c) 2015 Midnight Pacific. All rights reserved.
//

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* tex1;


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


void renderRectOutline(SDL_Rect& rect, Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_TRANSPARENT);
    SDL_RenderDrawRect(renderer, &rect);
}


void renderRectFilled(SDL_Rect& rect, Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_TRANSPARENT);
    SDL_RenderFillRect(renderer, &rect);
}


void renderTexture(SDL_Texture* texture, SDL_Rect& destRect)
{
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}


void render()
{
    SDL_SetRenderDrawColor(renderer, 10, 255, 255, SDL_ALPHA_TRANSPARENT);
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 50;
    rect.y = 50;
    rect.w = 100;
    rect.h = 100;
    
    renderRectOutline(rect, 255, 50, 50);
    
    SDL_Rect rect2;
    rect2.x = 200;
    rect2.y = 50;
    rect2.w = 100;
    rect2.h = 100;
    
    renderRectFilled(rect2, 50, 50, 255);
    
    renderTexture(tex1, rect2);
    
    
    SDL_RenderPresent(renderer);
}


int main(int argc, const char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    
    Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("TMXLoader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, windowFlags);
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(renderer, 10, 255, 255, SDL_ALPHA_TRANSPARENT);
    
    tex1 = IMG_LoadTexture(renderer, "Assets/button.png");
    
    
    bool running = true;
    SDL_Event events;
    while (running == true)
    {
        running = update(events);
        render();
    }
    
    return 0;
}
