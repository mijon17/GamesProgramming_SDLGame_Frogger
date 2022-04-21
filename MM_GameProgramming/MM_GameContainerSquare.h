#ifndef aGameContainerSquareFILE
#define aGameContainerSquareFILE
#include <vector>
#include <iostream>
#include "SDL.h"
#include "MM_Square.h"
using namespace std;
class MM_GameContainerSquare
{
public:
	MM_GameContainerSquare();
	~MM_GameContainerSquare();
	void Init(int eY, int eX, float eDirX, float eDirY, int eNum);
	void Add(int X, int Y);
	void Render(SDL_Renderer* aRenderer);
	void Update();
	vector<MM_Square*> aListofSquares;
	int X, Y, Num;
	float dirX, dirY;
};
#endif //