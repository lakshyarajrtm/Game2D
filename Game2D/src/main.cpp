#include "Game.h"

#undef main

Game* game = nullptr;

int main(int argc , char** argv) 
{
	const int FPS = 60;
	int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("2D game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();
		SDL_Delay(3);

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
}
