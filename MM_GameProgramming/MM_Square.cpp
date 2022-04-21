#include "MM_Square.h" 
#include "MM_GameWorld.h"
#include <vector>



std::vector<MM_Square*> aSquareList;

SDL_Event event;
bool quit = false;


MM_Square::MM_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Constructed with Param(%p)", this);
}
MM_Square::~MM_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Destroyed with Param(%p)", this);
}

void MM_Square::Init(int px, int py, int pw, int ph)
{
	

	rec.x = px;
	rec.y = py;
	rec.w = pw;
	rec.h = ph;

}

void MM_Square::Update() 
{
	
		//rec.y += 1;

	
		

	
}
void MM_Square::Input()
{
	while (SDL_PollEvent(&event))
	{
		/*	if (event.type == SDL_QUIT)
				done = true;*/
		if (event.type == SDL_KEYDOWN)

		{
			switch (event.key.keysym.sym)
			{
	
			case SDLK_a:
				printf("A key is Pressed!\n");
				rec.x -= 10;
				break;
			case SDLK_d:
				printf("D key is pressed! \n");
				rec.x += 10;
				break;
			case SDLK_w:
				printf("W key is pressed! \n");
				rec.y -= 10;
				break;
			case SDLK_s:
				printf("S key is pressed! \n");
				rec.y += 10;
				break;
			}
		

		}
	}

}

void MM_Square::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 150, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &rec);
	SDL_RenderFillRect(renderer, &rec);


	
}
