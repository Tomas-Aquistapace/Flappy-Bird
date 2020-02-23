#include "player.h"

#include "enemies.h"
#include "game_structure/menu_screen.h"
#include "game_structure/game_screen.h"
//#include "game_structure/initialice.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	using namespace Enemies;

	namespace Player_Things
	{
		PLAYER player;

		bool pause;

		const float HEIGHT_PLAYER = 30;
		const float WIDTH_PLAYER = 30;
		const float SPEEDPJ = 150.0f;

		static Vector2 position;
		static Rectangle frameRec;
		static float currentFrame = 0;
		static float framesCounter = 0;
		static float maxCounter = 0.25f;

		static Rectangle frameRecJump;
		static float currentFrameJump = 0;
		static float framesCounterJump = 0;
		static float maxCounterJump = 0.30f;

		static void Jump();
		static void DrawUI();
		static void AnimationMove();
		static void AnimationJump();

		void InitialicePlayer()
		{
			Image ImageMovement;
			Image ImageJump;

			player.winOrLose = inGame;

			player.state = falling;
			player.force = 0.0f;

			player.body.height = HEIGHT_PLAYER;
			player.body.width = WIDTH_PLAYER;
			player.body.x = static_cast <float>(GetScreenWidth() / 3);
			player.body.y = static_cast <float>(GetScreenHeight() / 2);

			player.points = 0;
			player.maxPoints = 0;
			player.exitGame = false;

			ImageMovement = LoadImage("assets/textures/character/gosthiidle-Sheet.png");
			player.spriteMovement = LoadTextureFromImage(ImageMovement);
			frameRec = { 0.0f, 0.0f, static_cast<float>(player.spriteMovement.height), static_cast<float>(player.spriteMovement.width / 4) };

			ImageJump = LoadImage("assets/textures/character/gosthisalto-Sheet.png");
			player.spriteJump = LoadTextureFromImage(ImageJump);
			frameRecJump = { 0.0f, 0.0f, static_cast<float>(player.spriteMovement.height), static_cast<float>(player.spriteMovement.width / 4) };

			pause = false;

			UnloadImage(ImageMovement);
			UnloadImage(ImageJump);
		}

		void ResetPlayer()
		{
			player.winOrLose = inGame;

			player.state = falling;
			player.force = 0.0f;

			player.body.x = static_cast <float>(GetScreenWidth() / 3);
			player.body.y = static_cast <float>(GetScreenHeight() / 2);
			player.points = 0;
			player.exitGame = false;

			pause = false;
		}

		void Input()
		{
			if (IsKeyPressed(KEY_ESCAPE) == true)
			{
				ResetPlayer();
				InitialiceEnemies();
				Menu::scenes = Menu::menu;
				Sounds::StatePlayerMusic(Sounds::stop);
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
			if (CheckCollisionRecs(player.body, superiorPipe1.objet) == true ||
				CheckCollisionRecs(player.body, superiorPipe2.objet) == true ||
				CheckCollisionRecs(player.body, buttomPipe1.objet) == true ||
				CheckCollisionRecs(player.body, buttomPipe2.objet) == true
				||
				(player.body.y + player.body.height >= GetScreenHeight()) ||
				(player.body.y <= 0))
			{
				Sounds::StateEndMusic(Sounds::play);
				PlaySound(Sounds::die_sound);
				
				Menu::scenes = Menu::endGame;

				if (player.points > player.maxPoints)
				{
					player.maxPoints = player.points;
				}
			}
		}

		void EarnPoint()
		{
			if (player.body.x > (buttomPipe1.objet.x + buttomPipe1.objet.width - 3.5f) &&
				player.body.x <= (buttomPipe1.objet.x + buttomPipe1.objet.width)
				||
				player.body.x > (buttomPipe2.objet.x + buttomPipe2.objet.width - 3.5f) &&
				player.body.x <= (buttomPipe2.objet.x + buttomPipe2.objet.width))
			{
				player.points++;
			}
		}

		void DrawPlayer()
		{
			if (player.state == jumping)
				AnimationJump();
			else
				AnimationMove();
			
			DrawUI();
		}

		//------------------------------------------

		static void DrawUI()
		{
			short fontUI = 40;
			short pixelsAxis = 20;

			Vector2 textPos;

			textPos.x = static_cast<float>(pixelsAxis);
			textPos.y = static_cast<float>(GetScreenHeight() - fontUI);

			DrawTextEx(Textures::textFont, FormatText("Points ~ %i", Player_Things::player.points), textPos, fontUI, 2, WHITE);
		}

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

					PlaySound(Sounds::jump);
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
			
			player.body.y -= player.force * GetFrameTime() * 2;

			if (player.force > MIN_GRAVITY)
			{
				player.force -= GRAVITY * GetFrameTime() * 2;
			}
		}

		static void AnimationMove()
		{
			if (pause == false)
			{
				framesCounter += GetFrameTime();

				if (framesCounter >= (maxCounter))
				{
					framesCounter = 0;

					currentFrame++;
					if (currentFrame > 1)
						currentFrame = 0;

					frameRec.x = static_cast<float>(currentFrame*(player.spriteMovement.width / 4));
				}
				position = { player.body.x - player.body.width / 2, player.body.y };
			}

			DrawTextureRec(player.spriteMovement, frameRec, position, WHITE);
		}

		static void AnimationJump()
		{
			if (pause == false)
			{
				framesCounterJump += GetFrameTime();

				if (framesCounterJump >= (maxCounterJump))
				{
					framesCounterJump = 0;

					currentFrameJump++;
					if (currentFrameJump > 1)
						currentFrameJump = 0;

					frameRecJump.x = static_cast<float>(currentFrameJump * (player.spriteJump.width / 2));
				}
				position = { player.body.x - player.body.width / 2, player.body.y };
			}
			DrawTextureRec(player.spriteJump, frameRecJump, position, WHITE);
		}
	}
}