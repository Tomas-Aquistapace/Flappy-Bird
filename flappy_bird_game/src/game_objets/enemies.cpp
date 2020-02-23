#include "enemies.h"

#include "player.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		using namespace Player;

		WALLS buttomWall1;
		WALLS buttomWall2;
		WALLS superiorWall1;
		WALLS superiorWall2;

		static Texture2D walls;

		const float SPEED_ENEMI = 200.0f;
		static const float HEIGHT = 300;
		static const float WIDTH = 50;

		static bool screenCenter;
		static bool moveSecondPipe;

		void Initialize()
		{
			walls = LoadTexture("assets/textures/objects/wall.png");

			//firts traps
			superiorWall1.objet.height = HEIGHT;
			superiorWall1.objet.width = WIDTH;
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall1.objet.height = HEIGHT;
			buttomWall1.objet.width = WIDTH;
			buttomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;

			//seconds traps
			superiorWall2.objet.height = HEIGHT;
			superiorWall2.objet.width = WIDTH;
			superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
			superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall2.objet.height = HEIGHT;
			buttomWall2.objet.width = WIDTH;
			buttomWall2.objet.x = static_cast<float>(GetScreenWidth());
			buttomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 200;

			screenCenter = false;
			moveSecondPipe = false;
		}

		void Reset()
		{
			//firts traps
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;

			//seconds traps
			superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
			superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall2.objet.x = static_cast<float>(GetScreenWidth());
			buttomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 200;

			screenCenter = false;
			moveSecondPipe = false;
		}

		void Unload()
		{
			UnloadTexture(walls);
		}

		void MovementEnemies()
		{
			if ((buttomWall1.objet.x + WIDTH < 0) && (superiorWall1.objet.x + WIDTH < 0))
			{
				superiorWall1.objet.x = static_cast<float>(GetScreenWidth());
				superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

				buttomWall1.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;
				}
				else
				{
					buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 150;
				}

				screenCenter = false;
			}

			//seconds traps
			if ((buttomWall1.objet.x + WIDTH / 2 < GetScreenWidth() / 2) && ((superiorWall1.objet.x + WIDTH / 2 < GetScreenWidth() / 2)) &&
				(screenCenter == false))
			{
				superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
				superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

				buttomWall2.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					buttomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 200;
				}
				else
				{
					buttomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 150;
				}

				screenCenter = true;
				moveSecondPipe = true;
			}


			superiorWall1.objet.x -= SPEED_ENEMI * GetFrameTime();
			buttomWall1.objet.x -= SPEED_ENEMI * GetFrameTime();

			if (moveSecondPipe == true)
			{
				superiorWall2.objet.x -= SPEED_ENEMI * GetFrameTime();
				buttomWall2.objet.x -= SPEED_ENEMI * GetFrameTime();
			}
		}

		void DrawEnemies()
		{
			DrawTexture(walls, static_cast<int>(superiorWall1.objet.x), static_cast<int>(superiorWall1.objet.y), GRAY);
			DrawTexture(walls, static_cast<int>(buttomWall1.objet.x), static_cast<int>(buttomWall1.objet.y), GRAY);

			DrawTexture(walls, static_cast<int>(superiorWall2.objet.x), static_cast<int>(superiorWall2.objet.y), GRAY);
			DrawTexture(walls, static_cast<int>(buttomWall2.objet.x), static_cast<int>(buttomWall2.objet.y), GRAY);
		}
	}
}