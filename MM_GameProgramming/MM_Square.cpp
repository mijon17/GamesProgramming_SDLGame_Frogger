#include "MM_Square.h" 
SDL_Event event;
bool quit = false;

MM_Square::MM_Square()
{

}
MM_Square::~MM_Square()
{

}

void MM_Square::Init()
{
	rec.x = 70;
	rec.y = 70;
	rec.w = 140;
	rec.h = 140;

	rec1.x = 300;
	rec1.y = 70;
	rec1.w = 140;
	rec1.h = 140;

	



}

void MM_Square::Update() 
{

}
void MM_Square::Input()

{
	while (SDL_PollEvent(&event))
		if (event.type == SDL_QUIT)
			quit = true;

	//if (event.type == SDL_KEYDOWN && event.key.repeat == NULL)

	switch (event.key.keysym.sym)
	{
	
	case SDLK_a:
		printf("Left Arrow key is Pressed! \n");
		rec.x--;
		break;
	case SDLK_d:
		printf("Right Arrow key is pressed! \n");
		rec.x++;
		break;
	case SDLK_w:
		printf("Up Arrow key is pressed! \n");
		rec.y--;
		break;
	case SDLK_s:
		printf("Down Arrow key is pressed! \n");
		rec.y++;
		break;
	case SDLK_q:
		quit = true;
		SDL_Quit();
		printf("Application Quit");
	}
}


void MM_Square::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &rec);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rec1);
	
}
