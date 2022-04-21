#include "MM_GameItem.h"
#include "MM_GameWorld.h"
#include "MM_Square.h"
#include "MM_GameContainerSquare.h"


SDL_Event evn;


MM_GameItem::MM_GameItem()
{
}

MM_GameItem::~MM_GameItem()
{
}

void MM_GameItem::Init(int x, int y, int w, int h)
{
	rect.x = x;
	rect.y = y;
	rect.w = w; 
	rect.h = h;

	this->x = x; this->y = y;
	this->width = w; this->height = h;
	//MOVE_LEFT = false; MOVE_RIGHT = false;

	R = 255; G = 128; B = 80;

	velocity.X = 0;
	velocity.Y = 0;
}

void MM_GameItem::Update()
{
	rect.x = x;
	rect.y = y;
	rect.h = height;
	rect.w = width;
	// finally update the x/y according to velocity


	velocity.Y = velocity.Y + 1;
	if (y >= 500)
	{
		velocity.Y = -15;
	}
	if (x <= 0) {
		velocity.Y = 5;
	}
	if (x >= 700)
	{
		velocity.X = -5;
	}

	//if (MOVE_LEFT == true)
	//{
	//	velocity.X = velocity.X - 1;
	//}
	//if (MOVE_RIGHT == true)
	//{
	//	velocity.X = velocity.X + 1;
	//}






	x = x + velocity.X;
	y = y + velocity.Y;

}

void MM_GameItem::Input()
{
	
	while (SDL_PollEvent(&evn))
	{
		/*	if (event.type == SDL_QUIT)
				done = true;*/
		if (evn.type == SDL_KEYDOWN)

		{
			switch (evn.key.keysym.sym)
			{

			case SDLK_a:
				printf("A key is Pressed!\n");
				velocity.X = velocity.X - 1;
				break;
			case SDLK_d:
				printf("D key is pressed! \n");
				velocity.X = velocity.X + 1;
				break;
		
			}


		}
	}

}

void MM_GameItem::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 175, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);
}

void MM_GameItem::SetColour(int eR, int eG, int eB)
{
	R = eR;
	G = eG;
	B = eB;
}
