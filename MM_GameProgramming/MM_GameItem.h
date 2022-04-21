#ifndef aGameItem
#define aGameItem
#include <iostream>
#include "SDL.h"
#include "MM_Vector2d.h"



#define MAX_KEYS (256)
#define MOVE_LEFT 'w'


class MM_GameItem
{
public:
	MM_GameItem();
	~MM_GameItem();

	void Init(int x, int y, int w, int h);

	void Update();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	void SetColour(int eR, int eG, int eB);
		
	int x, y, height, width, R, G, B;
	//bool MOVE_LEFT, MOVE_RIGHT;

private:
	SDL_Rect rect;
	MM_Vector2D velocity;
};
#endif