#include "enemies.h"

#include "player.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Enemies
	{
		using namespace Player;

		SkULLS skull;

		WALLS bottomWall1;
		WALLS bottomWall2;
		WALLS superiorWall1;
		WALLS superiorWall2;

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

			skull.appears = false;

			// firts walls
			superiorWall1.objet.height = HEIGHT;
			superiorWall1.objet.width = WIDTH;
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));
			superiorWall1.texture = LoadTexture("assets/textures/objects/superior wall.png");

			bottomWall1.objet.height = HEIGHT;
			bottomWall1.objet.width = WIDTH;
			bottomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			bottomWall1.objet.y = superiorWall1.objet.y + HEIGHT + GetScreenHeight() / 3;
			bottomWall1.texture = LoadTexture("assets/textures/objects/bottom wall.png");

			// seconds walls
			superiorWall2.objet.height = HEIGHT;
			superiorWall2.objet.width = WIDTH;
			superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
			superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));
			superiorWall2.texture = LoadTexture("assets/textures/objects/superior wall.png");

			bottomWall2.objet.height = HEIGHT;
			bottomWall2.objet.width = WIDTH;
			bottomWall2.objet.x = static_cast<float>(GetScreenWidth());
			bottomWall2.objet.y = superiorWall2.objet.y + HEIGHT + GetScreenHeight() / 3;
			bottomWall2.texture = LoadTexture("assets/textures/objects/bottom wall.png");

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
			
			skull.appears = false;

			// firts walls
			superiorWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			bottomWall1.objet.x = static_cast<float>(GetScreenWidth() + HEIGHT / 2);
			bottomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;

			// seconds walls
			superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
			superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

			bottomWall2.objet.x = static_cast<float>(GetScreenWidth());
			bottomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 200;

			screenCenter = false;
			moveSecondPipe = false;
		}

		void Unload()
		{
			UnloadTexture(bottomWall1.texture);
			UnloadTexture(bottomWall2.texture);
			UnloadTexture(superiorWall1.texture);
			UnloadTexture(superiorWall2.texture);
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

			if (skull.position.x <= GetScreenWidth() && skull.position.x >= 0 && skull.appears == false)
			{
				PlaySound(Sounds::screamSkull);
				skull.appears = true;
			}
			else if (skull.position.x <= 0)
			{
				skull.appears = false;
			}

			//walls

			if ((bottomWall1.objet.x + WIDTH < 0) && (superiorWall1.objet.x + WIDTH < 0))
			{
				superiorWall1.objet.x = static_cast<float>(GetScreenWidth());
				superiorWall1.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

				bottomWall1.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					bottomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 200;
				}
				else
				{
					bottomWall1.objet.y = superiorWall1.objet.y + HEIGHT + 150;
				}

				screenCenter = false;
			}

			if ((bottomWall1.objet.x + WIDTH / 2 < GetScreenWidth() / 2) && ((superiorWall1.objet.x + WIDTH / 2 < GetScreenWidth() / 2)) &&
				(screenCenter == false))
			{
				superiorWall2.objet.x = static_cast<float>(GetScreenWidth());
				superiorWall2.objet.y = static_cast<float>(GetRandomValue(-(static_cast<int>(HEIGHT / 2)), 0));

				bottomWall2.objet.x = static_cast<float>(GetScreenWidth());

				if (player.points < 9)
				{
					bottomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 200;
				}
				else
				{
					bottomWall2.objet.y = superiorWall2.objet.y + HEIGHT + 150;
				}

				screenCenter = true;
				moveSecondPipe = true;
			}

			superiorWall1.objet.x -= SPEED_WALL * GetFrameTime();
			bottomWall1.objet.x -= SPEED_WALL * GetFrameTime();

			if (moveSecondPipe == true)
			{
				superiorWall2.objet.x -= SPEED_WALL * GetFrameTime();
				bottomWall2.objet.x -= SPEED_WALL * GetFrameTime();
			}
		}

		void DrawEnemies()
		{
			DrawTexture(superiorWall1.texture, static_cast<int>(superiorWall1.objet.x), static_cast<int>(superiorWall1.objet.y), GRAY);
			DrawTexture(bottomWall1.texture, static_cast<int>(bottomWall1.objet.x), static_cast<int>(bottomWall1.objet.y), GRAY);

			DrawTexture(superiorWall2.texture, static_cast<int>(superiorWall2.objet.x), static_cast<int>(superiorWall2.objet.y), GRAY);
			DrawTexture(bottomWall2.texture, static_cast<int>(bottomWall2.objet.x), static_cast<int>(bottomWall2.objet.y), GRAY);

			DrawCircleV(skull.position, skull.radius, RED);
		}
	}
}