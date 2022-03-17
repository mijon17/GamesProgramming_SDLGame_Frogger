// MM_GameProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//C++ Headers
#include <iostream> // functions for printing things out
#include <string> // functions for strings

#include "SDL.h"
#include "MM_Timer.h"
#include "MM_GameProgramming.h"
#include "MM_Square.h"


MM_Timer aTimer;
const int DELTA_TIME = 50;
bool done = false;
int x;

MM_Square ExampleSquare;

SDL_Event _event;

using namespace std;
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;

	
	//Create a window
	
	SDL_Window* window = SDL_CreateWindow("Mijon Mohammed", 300, 300, 800, 600, SDL_WINDOW_RESIZABLE);

	//Create a renderer which draws to the window surface
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while (!done)
	{
		//use home made timer provided by Olivier
		aTimer.resetTicksTimer(); // resets a frame timer to zero

		/*SDL_SetRenderDrawColor(renderer, 255, 0, 20, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		ExampleSquare.Render(renderer);
		SDL_RenderPresent(renderer);*/

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_Rect r;

		r.x = 60;
		r.y = 60;
		r.w = 100;
		r.h = 100;

		
		//move square that was created previously in lecture

		//r.x++;
		
		
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); //Colour Rectangle
		SDL_RenderDrawRect(renderer, &r); //Draw The rectangle


		//Tell SDL we have finished drawing, SDL will actually show our changes:
		SDL_RenderPresent(renderer); 

		//Inputs
		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
				done = true;
			if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)

			{
				switch (_event.key.keysym.sym) {
				case SDLK_ESCAPE:
					done = true;
					printf("Application Quit");
					break;
				case SDLK_g:
					printf("G key is Pressed! \n");
					//r.x + 100;
					break;
				case SDLK_f:
					printf("Window is now fullscreen! \n");
					SDL_SetWindowFullscreen(window, 1);
					break;
					case SDLK_h:
						printf("H key is pressed!");
						//SDL_GetWindowMinimumSize(window);
					break;

				}

			}
		}
	


		SDL_Delay(1000);
	}

	if (aTimer.getTicks() < DELTA_TIME)
	{
		SDL_Delay(DELTA_TIME - aTimer.getTicks());

	}
	SDL_Quit;
}