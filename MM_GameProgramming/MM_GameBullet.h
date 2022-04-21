#pragma once
#ifndef aBulletFile
#define aBulletFile

#include <iostream>
#include "SDL.h"
#include "MM_Vector2d.h"

class MM_GameBullet
{
public:
	MM_GameBullet();
	~MM_GameBullet();



	void Init(int px, int py, int pw, int ph);
	void Update();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	void setColour(int R, int G, int B);

	MM_Vector2D velocity;


	int x, y, height, width, R, G, B;
	int LifeCounter;

private:
	SDL_Rect aBullet;
	//MM_Vector2D velocity;

};


#endif