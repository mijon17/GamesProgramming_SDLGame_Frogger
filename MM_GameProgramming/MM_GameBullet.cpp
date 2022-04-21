#include "MM_GameBullet.h"
#include <vector>



void MM_GameBullet::Init(int px, int py, int pw, int ph)
{
	aBullet.x = px;
	aBullet.y = py;
	aBullet.w = pw;
	aBullet.h = ph;

	//velocity.X = 0;
	//velocity.Y = 0;
	
}

void MM_GameBullet::Update()
{

}

void MM_GameBullet::Input()
{
}

void MM_GameBullet::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, 150, 0, 255, 255);
	SDL_RenderDrawRect(aRenderer, &aBullet);
	SDL_RenderFillRect(aRenderer, &aBullet);
}

void MM_GameBullet::setColour(int R, int G, int B)
{

	R = R;
	G = G;
	B = B;
}
