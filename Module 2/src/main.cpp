#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "SDL.h"

typedef long long u64;
typedef signed long long s64;

bool IsRunning = true;

///////////////////////////////////////////////
//		Timer Code
///////////////////////////////////////////////

static double gTimePassed = 0;
static s64 gTimeCount = 0;
static double SecondsPerTick = 0;


float Sys_InitFloatTime()
{
	u64 Frequncy = SDL_GetPerformanceFrequency();
	SecondsPerTick = 1.0 / (double)Frequncy;
	gTimeCount = SDL_GetPerformanceCounter();
	return 0;
}

float Sys_FloatTime()
{
	u64 counter = SDL_GetPerformanceCounter();
	s64 Interval = counter - gTimeCount;
	gTimeCount = counter;
	double SecondsGoneBy = (double)Interval * SecondsPerTick;
	gTimePassed += SecondsGoneBy;

	return (float)gTimePassed;
}

///////////////////////////////////////////////
//		End Timer Code
///////////////////////////////////////////////


void Sys_Shutdown()
{
	IsRunning = false;
}

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
		window = SDL_CreateWindow("Module 2.4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

		screenSurface = SDL_GetWindowSurface(window);

		SDL_Event e;

		

		float timecount = Sys_InitFloatTime();

		while (IsRunning)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					Sys_Shutdown();
					break;
				}
			}

			float newtime = Sys_FloatTime();

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, rand() % 0xFF, rand() % 0xFF, rand() % 0xFF));

			SDL_UpdateWindowSurface(window);

			// update our game if it's time to
			// draw graphics if it's time to

			SDL_Log("Total time: %3.7f \n", newtime);
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}