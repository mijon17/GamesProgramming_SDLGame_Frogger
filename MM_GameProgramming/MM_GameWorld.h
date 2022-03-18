#ifndef aGameWorldFILE
#define aGameWorldFILE

#include <iostream>
#include <SDL.h>
#include "MM_Timer.h"
#include "MM_Square.h"



#define MAX_KEYS (256)
#define MOVE_LEFT 'w'

class MM_GameWorld
{
private:
	
	MM_Timer aTimer;
	const int DELTA_TIME = 50;
	bool done = false;

public:
	MM_GameWorld();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event _event;

	//Rectangle stuff
	SDL_Rect r;
	MM_Square aSquare1;
	MM_Square aSquare2;

	void Init();

	void Run();


	bool gKeys[MAX_KEYS];

	//Gameloop stuff
	void input();
	void update();
	void render();

	void quit();
};
#endif
