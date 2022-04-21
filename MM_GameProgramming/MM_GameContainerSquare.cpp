#include "MM_GameContainerSquare.h"

MM_GameContainerSquare::MM_GameContainerSquare()
{
}
void MM_GameContainerSquare::Init(int eY, int eX, float eDirX, float eDirY, int eNum)
{
	X = eX;
	Y = eY;
	dirX = eDirX;
	dirY = eDirY;
	Num = eNum;
	for (int i = 0; i <= Num; i++)
	{
		
		int PosX = X + (i * (dirX * 10));
		int PosY = Y + (i * (dirY * 10));
		Add(PosX, PosY);
	}
}

void MM_GameContainerSquare::Add(int x, int y)
{
	{
		MM_Square* aSquare = new MM_Square();
		aSquare->Init(220, 220, 100, 100);
		this->aListofSquares.push_back(aSquare);
	}
}
void MM_GameContainerSquare::Render(SDL_Renderer* aRenderer)
{
	for (auto& element : aListofSquares)
	{
		element->Render(aRenderer);
	}
}

void MM_GameContainerSquare::Update()
{
	for (auto& element : aListofSquares)
	{
		
		element->rec.x+=1;
		/*element->rec.y += 1;*/
		
		
	}
}
MM_GameContainerSquare::~MM_GameContainerSquare() {
	for (auto& element : aListofSquares)
	{
		delete element;
		
	}
}
