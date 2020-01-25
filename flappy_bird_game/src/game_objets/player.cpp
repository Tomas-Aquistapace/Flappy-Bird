#include "player.h"

#include "enemies.h"
#include "game_structure/menu_screen.h"
#include "game_structure/game_screen.h"
#include "game_structure/initialice.h"

namespace Flappy_Bird
{
	using namespace Enemies;

	namespace Player_Things
	{
		PLAYER player;

		bool pause;

		const float SPEEDPJ = 150.0f;

		static void Jump();

		void InitialicePlayer()
		{
			player.winOrLose = inGame;

			player.state = falling;
			player.force = 0.0f;

			player.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight() / 2) };
			player.radius = 15;
			player.points = 0;
			player.exitGame = false;

			pause = false;
		}

		void Input()
		{
			if (IsKeyPressed(KEY_ESCAPE) == true)
			{
				ResetValues();
				scenes = menu;
			}

			if (IsKeyPressed(KEY_ENTER) == true)
			{
				pause = !pause;
			}

			if (pause == false)
			{
				Jump();
			}
		}

		void LoseOrWin()
		{
			if (CheckCollisionCircleRec(player.position, player.radius, superiorPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, superiorPipe2.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe2.objet) == true)
			{
				scenes = endGame;
			}

			if ((player.position.y + player.radius >= GetScreenHeight()) ||
				(player.position.y - player.radius <= 0))
			{
				scenes = endGame;
			}
		}

		void EarnPoint()
		{
			if (player.position.x > (buttomPipe1.objet.x + buttomPipe1.objet.width - 3.5f) &&
				player.position.x <= (buttomPipe1.objet.x + buttomPipe1.objet.width)
				||
				player.position.x > (buttomPipe2.objet.x + buttomPipe2.objet.width - 3.5f) &&
				player.position.x <= (buttomPipe2.objet.x + buttomPipe2.objet.width))
			{
				player.points++;
			}
		}

		void DrawPlayer()
		{
			DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, GREEN);
			DrawUI();
		}

		void DrawUI()
		{
			short fontUI = 20;
			short pixelsAxis = 20;

			DrawText(FormatText("Points ~ %i", player.points), pixelsAxis, GetScreenHeight() - pixelsAxis, fontUI, WHITE);
		}

		//------------------------------------------

		static void Jump()
		{
			const float MIN_GRAVITY = -150.0f;
			const short GRAVITY = 90;

			if (IsKeyPressed(KEY_SPACE) == true)
			{
				if (player.state == falling)
				{
					player.state = jumping;
					player.force = SPEEDPJ;
				}
				else if (player.state == jumping)
				{
					player.state = falling;
					player.force = 0;
				}
			}

			if (player.force <= 0)
			{
				player.state = falling;		
			}
			
			player.position.y -= player.force * GetFrameTime();

			if (player.force > MIN_GRAVITY)
			{
				player.force -= GRAVITY * GetFrameTime();
			}
		}
	}
}