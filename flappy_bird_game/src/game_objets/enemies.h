#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		struct WALLS 
		{
			Rectangle objet;
		};

		extern WALLS buttomWall1;
		extern WALLS buttomWall2;
		extern WALLS superiorWall1;
		extern WALLS superiorWall2;

		extern const float SPEED_ENEMI;

		extern void Initialize();
		extern void Reset();
		extern void Unload();
		extern void MovementEnemies();
		extern void DrawEnemies();
	}
}

#endif // !ENEMIES_H
