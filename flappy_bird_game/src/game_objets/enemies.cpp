#include "enemies.h"

#include "player.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		using namespace Player_Things;

		PIPES buttomPipe1;
		PIPES buttomPipe2;
		PIPES superiorPipe1;
		PIPES superiorPipe2;
		float SPEED_ENEMI = 200.0f;

		static float height = 300;
		static float width = 50;

		static bool screenCenter;
		static bool moveSecondPipe;

		void InitialiceEnemies()
		{
			superiorPipe1.objet.height = height;
			superiorPipe1.objet.width = width;
			superiorPipe1.objet.x = static_cast<float>(GetScreenWidth() + height / 2);
			superiorPipe1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(height / 2)), 0));

			buttomPipe1.objet.height = height;
			buttomPipe1.objet.width = width;
			buttomPipe1.objet.x = static_cast<float>(GetScreenWidth() + height / 2);
			buttomPipe1.objet.y = superiorPipe1.objet.y + height + 200;

			//seconds traps
			superiorPipe2.objet.height = height;
			superiorPipe2.objet.width = width;
			superiorPipe2.objet.x = static_cast<float>(GetScreenWidth());
			superiorPipe2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(height / 2)), 0));

			buttomPipe2.objet.height = height;
			buttomPipe2.objet.width = width;
			buttomPipe2.objet.x = static_cast<float>(GetScreenWidth());
			buttomPipe2.objet.y = superiorPipe2.objet.y + height + 200;

			screenCenter = false;
			moveSecondPipe = false;
		}

		void MovementEnemies()
		{
			if ((buttomPipe1.objet.x + width < 0) && (superiorPipe1.objet.x + width < 0))
			{
				superiorPipe1.objet.x = static_cast<float>(GetScreenWidth());
				superiorPipe1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(height / 2)), 0));

				buttomPipe1.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					buttomPipe1.objet.y = superiorPipe1.objet.y + height + 200;
				}
				else
				{
					buttomPipe1.objet.y = superiorPipe1.objet.y + height + 150;
				}

				screenCenter = false;
			}

			//seconds traps
			if ((buttomPipe1.objet.x + width / 2 < GetScreenWidth() / 2) && ((superiorPipe1.objet.x + width / 2 < GetScreenWidth() / 2)) &&
				(screenCenter == false))
			{
				superiorPipe2.objet.x = static_cast<float>(GetScreenWidth());
				superiorPipe2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(height / 2)), 0));

				buttomPipe2.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					buttomPipe2.objet.y = superiorPipe2.objet.y + height + 200;
				}
				else
				{
					buttomPipe2.objet.y = superiorPipe2.objet.y + height + 150;
				}

				screenCenter = true;
				moveSecondPipe = true;
			}


			superiorPipe1.objet.x -= SPEED_ENEMI * GetFrameTime();
			buttomPipe1.objet.x -= SPEED_ENEMI * GetFrameTime();

			if (moveSecondPipe == true)
			{
				superiorPipe2.objet.x -= SPEED_ENEMI * GetFrameTime();
				buttomPipe2.objet.x -= SPEED_ENEMI * GetFrameTime();
			}
		}

		void DrawEnemies()
		{
			DrawRectangleRec(superiorPipe1.objet, RED);
			DrawRectangleRec(buttomPipe1.objet, RED);

			DrawRectangleRec(superiorPipe2.objet, RED);
			DrawRectangleRec(buttomPipe2.objet, RED);
		}
	}
}