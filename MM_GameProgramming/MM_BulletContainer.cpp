#include "MM_BulletContainer.h"

MM_BulletContainer::MM_BulletContainer()
{
}

MM_BulletContainer::~MM_BulletContainer()
{
}

void MM_BulletContainer::Init(int eY, int eX, int eNum, int TTL)
{
	X = eX; Y = eY;
	Num = eNum;
	aRect.x = X; aRect.y = Y;
	aRect.w = 20; aRect.h = 20;
	for (int i = 0; i < Num; i++)
	{
		int PosX = X;
		int PosY = Y;
		Add(PosX, PosY);
	}
	this->TTL = TTL;
}

void MM_BulletContainer::Add(int X, int Y)
{
	MM_GameBullet* aBullet = new MM_GameBullet();
	aBullet->setColour(255, 128, 0);
	aBullet->velocity.X = 0;
	aBullet->velocity.Y = 0;
	aBullet->Init(X, Y, 3, 25);
	this->aListofBullets.push_back(aBullet);

}

void MM_BulletContainer::Input(int whichKey, bool isPressed)
{

}

void MM_BulletContainer::Render(SDL_Renderer* aRenderer)
{
	// render controller for debugging
	SDL_SetRenderDrawColor(aRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect(aRenderer, &aRect);
	for (auto& element : aListofBullets)
	{
		if (element->velocity.Y != 0)
		{
			element->Render(aRenderer);
		}
	}
}

void MM_BulletContainer::Update()
{
	for (auto& element : aListofBullets)
	{
		element->Update();
		if (element->velocity.Y > 0)
		{
			element->LifeCounter++;
		}
		else
		{
			element->x = X;
			element->y = Y;
		}
		if (element->LifeCounter > TTL)
		{
			element->LifeCounter = 0;
			element->x = X;
			element->y = Y;
			element->velocity.Y = 0;
		}
	}
	aRect.x = X;
	aRect.y = Y;

}

void MM_BulletContainer::Shoot()
{
	int i = 0;
	bool NotFound = true;
	while ((i < aListofBullets.size()) && (NotFound))
	{
		if (aListofBullets[i]->velocity.Y == 0)
		{
			aListofBullets[i]->x = X;
			aListofBullets[i]->y = Y;
			aListofBullets[i]->LifeCounter = 0;
			aListofBullets[i]->velocity.Y = 10;
			NotFound = false;

		}
		i++;
	}
}
