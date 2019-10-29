#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		struct PIPES {
			Rectangle objet;
		};

		extern PIPES buttomPipe1;
		extern PIPES buttomPipe2;
		extern PIPES superiorPipe1;
		extern PIPES superiorPipe2;
		extern float SPEED_ENEMI;

		void InitialiceEnemies();
		void MovementEnemies();
		void DrawEnemies();
	}
}

#endif // !ENEMIES_H
