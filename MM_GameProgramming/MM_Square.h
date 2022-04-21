#pragma once
#ifndef aSquareFile
#define aSquareFile

#include <iostream>
#include <SDL.h>
#include "MM_Vector2d.h"



class MM_Square
{
public:
	MM_Square();
	~MM_Square();

	

	void Init(int px, int py, int pw, int ph);
	void Update();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	//void SetColour(int eR, int eG, int eB);
	//bool MOVE_LEFT, MOVE_RIGHT;

	SDL_Rect rec;
	SDL_Rect rec1;

	int x, y, height, width, R, G, B;

private:
	SDL_Rect rect;
	MM_Vector2D velocity;

};
#endif