#include <stdlib.h>
#include "SDL.h"

bool IsRunning = true;

int main(int, char**)
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// show error
	}
	else
	{
		window = SDL_CreateWindow("Module 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

		screenSurface = SDL_GetWindowSurface(window);

		SDL_Event e;

		while (IsRunning)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_KEYUP:
					IsRunning = false;
				}
			}

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, rand() % 0xFF, rand() % 0xFF, rand() % 0xFF));

			SDL_UpdateWindowSurface(window);

			// update our game if it's time to
			// draw graphics if it's time to
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}