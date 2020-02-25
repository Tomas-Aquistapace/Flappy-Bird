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
			Texture2D texture;
			Texture2D textureDegrade;
		};

		struct SkULLS
		{
			Vector2 position;
			float radius;
			bool appears;
			Texture2D texture;
		};

		extern SkULLS skull;

		extern WALLS bottomWall1;
		extern WALLS bottomWall2;
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
