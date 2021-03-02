#pragma once
#ifndef Gamehpp
#define Gamehpp

#include<iostream>
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();

	void handleEvents();

	static SDL_Renderer* renderer;

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	
	int cnt = 0;
};

#endif