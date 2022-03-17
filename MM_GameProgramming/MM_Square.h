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
	void Input(int whichKey);
	void Render(SDL_Renderer* aRenderer);
	SDL_Rect r;

	int x, y, height, width, R, G, B;
};
#endif