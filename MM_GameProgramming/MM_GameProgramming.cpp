// MM_GameProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//C++ Headers
#include <iostream> // functions for printing things out
#include <string> // functions for strings

#include "SDL.h"
#include "MM_Timer.h"
#include "MM_GameProgramming.h"
#include "MM_Square.h"
#include "MM_GameContainerSquare.h"
#include "MM_GameItem.h"
#include "MM_Vector2D.h"



MM_GameContainerSquare GSquare;
MM_GameItem GameItem1;



MM_Timer aTimer;
const int DELTA_TIME = 1;

int x;

#define window_width 800
#define window_height 800

MM_Square aSquare;

SDL_Event _event;
bool running = false;
Uint32 starting_tick;

using namespace std;
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;
	SDL_Window* window = NULL;

	
	//Create a window
	
	 window = SDL_CreateWindow("Mijon Mohammed",
		 300, //Window Pos
		 300, //Window Pos
		 window_width, //window_width
		 window_height, //window_height	
		 SDL_WINDOW_RESIZABLE);

	 if (window == NULL) 
	 {
		 printf("There was an error initializing the window", SDL_GetError());
	 }

	//Create a renderer which draws to the window surface
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



	GameItem1.Init(200, 200, 100, 50); // Phyics movement
	//GSquare.Init(100, 50, 0.0f, 0.5f, 2); //Instantiate multiple squares
	//aSquare.Init(50,50,100,100); //Single Square with movement



//REMINDER put objects outside of while loop

//start of gameloop
while (!running)


{
	//use home made timer provided by Olivier
	aTimer.resetTicksTimer(); // resets a frame timer to zero
	
	
	


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	GameItem1.Input();
	GameItem1.Update();
	GameItem1.SetColour(50, 100, 200);
	GameItem1.Render(renderer);



	/*aSquare.Input();
	aSquare.Update();
	aSquare.Render(renderer);*/



	/*GSquare.Add(2,10);
	GSquare.Update();
	GSquare.Render(renderer);*/

		//Tell SDL we have finished drawing, SDL will actually show our changes:
	SDL_RenderPresent(renderer);

	//Inputs
	while (SDL_PollEvent(&_event))
	{
		if (_event.type == SDL_QUIT)
			running = true;
		if (_event.type == SDL_KEYDOWN)

		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				running = true;
				printf("Application Quit");
				break;

			case SDLK_f:
				printf("Window is now fullscreen! \n");
				SDL_SetWindowFullscreen(window, 1);
				break;
			}
		/*	if (aTimer.getTicks() < DELTA_TIME)
			{
				SDL_Delay(DELTA_TIME - aTimer.getTicks());

			}*/

			if ((DELTA_TIME) > aTimer.getTicks())
			{
				SDL_Delay(DELTA_TIME - (aTimer.getTicks()));
				
			}  //FPS 60

		
	
			}
		}
	}

	SDL_Quit();

	//end of gameloop
}