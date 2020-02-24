#include "enemies.h"

#include "player.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		using namespace Player;

		SkULLS skull;

		WALLS buttomWall1;
		WALLS buttomWall2;
		WALLS superiorWall1;
		WALLS superiorWall2;

		static Texture2D walls;

		const float SPEED_WALL = 200.0f;
		const float SPEED_SKULL = 300.0f;
		static const float HEIGHT = 300;
		static const float WIDTH = 50;

		static bool screenCenter;
		static bool moveSecondPipe;

		void Initialize()
		{
			// skulls
			skull.radius = 20;
			skull.position.x = static_cast<float>(GetScreenWidth() * 4);
			do
			{
				skull.position.y = static_cast<float>(GetRandomValue(GetScreenHeight() / 5, GetScreenHeight() - GetScreenHeight() / 5));
			} while ((skull.position.y >= GetScreenHeight() / 3) && (skull.position.y <= GetScreenHeight() - GetScreenHeight() / 3));

			walls = LoadTexture("assets/textures/objects/wall.png");

			// firts walls
			superiorWall1.objet.height = HEIGHT;
			superiorWall1.objet.width = WIDTH;
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall1.objet.height = HEIGHT;
			buttomWall1.objet.width = WIDTH;
			buttomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;

			// seconds walls
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
			// skull
			skull.position.x = static_cast<float>(GetScreenWidth() * 4);
			do
			{
				skull.position.y = static_cast<float>(GetRandomValue(GetScreenHeight() / 5, GetScreenHeight() - GetScreenHeight() / 5));
			} while ((skull.position.y >= GetScreenHeight() / 3) && (skull.position.y <= GetScreenHeight() - GetScreenHeight() / 3));

			// firts walls
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			buttomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			buttomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;

			// seconds walls
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
			// skulls

			if (skull.position.x <= - GetScreenWidth() * 4)
			{
				skull.position.x = static_cast<float>(GetScreenWidth() * 4);
				do
				{
					skull.position.y = static_cast<float>(GetRandomValue(GetScreenHeight() / 5, GetScreenHeight() - GetScreenHeight() / 5));
				} while ((skull.position.y >= GetScreenHeight() / 3) && (skull.position.y <= GetScreenHeight() - GetScreenHeight() / 3));
			}

			if (player.points >= 10)
			{
				skull.position.x -= SPEED_SKULL * GetFrameTime();
			}

			//walls

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

			superiorWall1.objet.x -= SPEED_WALL * GetFrameTime();
			buttomWall1.objet.x -= SPEED_WALL * GetFrameTime();

			if (moveSecondPipe == true)
			{
				superiorWall2.objet.x -= SPEED_WALL * GetFrameTime();
				buttomWall2.objet.x -= SPEED_WALL * GetFrameTime();
			}
		}

		void DrawEnemies()
		{
			DrawCircleV(skull.position, skull.radius, RED);

			DrawTexture(walls, static_cast<int>(superiorWall1.objet.x), static_cast<int>(superiorWall1.objet.y), GRAY);
			DrawTexture(walls, static_cast<int>(buttomWall1.objet.x), static_cast<int>(buttomWall1.objet.y), GRAY);

			DrawTexture(walls, static_cast<int>(superiorWall2.objet.x), static_cast<int>(superiorWall2.objet.y), GRAY);
			DrawTexture(walls, static_cast<int>(buttomWall2.objet.x), static_cast<int>(buttomWall2.objet.y), GRAY);
		}
	}
}