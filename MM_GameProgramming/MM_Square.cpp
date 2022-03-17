#include "MM_Square.h" 

MM_Square::MM_Square()
{

}
MM_Square::~MM_Square()
{

}

void MM_Square::Init()
{
	r.x = 70;
	r.y = 70;
	r.w = 100;
	r.h = 100;

}

void MM_Square::Update() 
{

}
void MM_Square::Input
(int whichKey)
{
	switch
		(whichKey)
	{
		case 'w': { printf("Square: W is pressed \n"); break; }
	}
}


void MM_Square::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderDrawRect(aRenderer, &r);
}
