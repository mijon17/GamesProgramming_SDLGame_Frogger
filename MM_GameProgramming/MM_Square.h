#pragma once
#ifndef aSquareFile
#define aSquareFile

#include <iostream>
#include <SDL.h>

class MM_Square
{
public:
	MM_Square();
	~MM_Square();

	void Init();
	void Update();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect rec;
	SDL_Rect rec1;

	int x, y, height, width, R, G, B;
};
#endif