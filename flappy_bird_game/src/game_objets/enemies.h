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
			//Texture2D texture;
		};

		struct SkULLS
		{
			Vector2 position;
			float radius;
			//Texture2D texture;
		};

		extern SkULLS skull;

		extern WALLS buttomWall1;
		extern WALLS buttomWall2;
		extern WALLS superiorWall1;
		extern WALLS superiorWall2;

		extern const float SPEED_WALL;

		extern void Initialize();
		extern void Reset();
		extern void Unload();
		extern void MovementEnemies();
		extern void DrawEnemies();
	}
}

#endif // !ENEMIES_H
