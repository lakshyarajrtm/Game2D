#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
GameObject* player;
GameObject* enemy;
Map* map;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = 0;
		if (fullscreen) 
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		std::cout << "Subsystem Inititalized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			std::cout << "Renderer Initialized" << std::endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	player = new GameObject("src/assets/mario.png",0, 0);
	enemy = new GameObject("src/assets/lugi.png",50, 50);	
	map = new Map();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
	default:
		break;
	}
}

void Game::update()
{
	
	player->Update();
	enemy->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Renderer();
	enemy->Renderer();
	SDL_RenderPresent(renderer);
	
	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned" << std::endl;
}

