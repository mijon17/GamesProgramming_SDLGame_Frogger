#ifndef aBulletContainerFILE
#define aBulletContainerFILE
#include <vector>
#include <iostream>
#include "SDL.h"
#include "MM_GameBullet.h"
using namespace std;
class MM_BulletContainer
{
public:
	MM_BulletContainer();
	~MM_BulletContainer();
	void Init(int eY, int eX, int eNum, int TTL);
	void Add(int X, int Y);
	void Input(int whichKey, bool isPressed);
	void Render(SDL_Renderer* aRenderer);
	void Update();
	vector<MM_GameBullet*> aListofBullets;

	void Shoot(); // if able, it sends a bullet downwards
	int X, Y, Num; // position and max bullets it can spawn
	int TTL; // time to live of Bullets
	SDL_Rect aRect;
};
#endif //