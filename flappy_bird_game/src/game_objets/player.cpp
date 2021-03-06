#include "player.h"

#include "enemies.h"
#include "game_structure/menu_screen.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Spooky_Ghost
{
	using namespace Enemies;

	namespace Player
	{
		PLAYER player;
		bool pause;

		Texture2D frameworkSkin1;
		Texture2D frameworkSkin2;

		static const int MOUSERADIUS = 0;

		static const float HEIGHT_PLAYER = 30;
		static const float WIDTH_PLAYER = 30;
		static const float FORCE = 120.0f;
		static const float GRAVITY = 90;
		static const float MIN_FORCE = -150.0f;

		// animations
		static Vector2 position;
		static Rectangle frameRec;
		static float currentFrame = 0;
		static float framesCounter = 0;
		static float maxCounter = 0.25f;

		static Rectangle frameRecJump;
		static float currentFrameJump = 0;
		static float framesCounterJump = 0;
		static float maxCounterJump = 0.30f;
		// ---------

		static void Jump(Rectangle pauseButtom, Rectangle menuButtom);
		static void AnimationMove();
		static void AnimationJump();

		void Initialize()
		{
			player.position.x = static_cast <float>(GetScreenWidth() / 3);
			player.position.y = static_cast <float>(GetScreenHeight() / 2);
			player.radius = 15;

			player.state = falling;
			player.force = 0.0f;

			player.winPoint = false;
			player.points = 0;
			player.maxPoints = 0;

			player.exitGame = false;
			player.winOrLose = inGame;
			
			player.skinSelected = 1;
			player.maxSkins = 2;

			player.spriteMovement1 = LoadTexture("assets/textures/character/gosthiidle-Sheet1.png");
			player.spriteMovement2 = LoadTexture("assets/textures/character/gosthiidle-Sheet2.png");
			frameRec = { 0.0f, 0.0f, static_cast<float>(player.spriteMovement1.height), static_cast<float>(player.spriteMovement1.width / 4) };

			player.spriteJump1 = LoadTexture("assets/textures/character/gosthisalto-Sheet1.png");
			player.spriteJump2 = LoadTexture("assets/textures/character/gosthisalto-Sheet2.png");
			frameRecJump = { 0.0f, 0.0f, static_cast<float>(player.spriteJump1.height), static_cast<float>(player.spriteJump1.width / 2) };

			frameworkSkin1 = LoadTexture("assets/textures/character/framework-skin-1.png");
			frameworkSkin2 = LoadTexture("assets/textures/character/framework-skin-2.png");

			pause = false;
		}

		void Reset()
		{
			player.winOrLose = inGame;

			player.state = falling;
			player.force = 0.0f;

			player.position.x = static_cast <float>(GetScreenWidth() / 3);
			player.position.y = static_cast <float>(GetScreenHeight() / 2);

			player.points = 0;
			player.exitGame = false;

			pause = false;
		}

		void Unload()
		{
			UnloadTexture(player.spriteMovement1);
			UnloadTexture(player.spriteMovement2);
			UnloadTexture(player.spriteJump1);
			UnloadTexture(player.spriteJump2);
			UnloadTexture(frameworkSkin1);
			UnloadTexture(frameworkSkin2);
		}

		void Input(Rectangle pauseButtom, Rectangle menuButtom)
		{
			if (pause == false)
			{
				Jump(pauseButtom, menuButtom);
			}
		}

		void LoseOrWin()
		{
			if (CheckCollisionCircleRec(player.position, player.radius, superiorWall1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, superiorWall2.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, bottomWall1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, bottomWall2.objet) == true
				||
				(player.position.y + player.radius >= GetScreenHeight()) ||
				(player.position.y <= 0)
				||
				(CheckCollisionCircles(player.position, player.radius, skull.position, skull.radius) == true))
			{
				Sounds::StateEndMusic(Sounds::play);
				PlaySound(Sounds::die_sound);
				
				Menu::scene = Menu::endGame;

				if (player.points > player.maxPoints)
				{
					player.maxPoints = player.points;
				}
			}
		}

		void EarnPoint()
		{
			if (player.position.x > (bottomWall1.objet.x + bottomWall1.objet.width - 3.5f) &&
				player.position.x <= (bottomWall1.objet.x + bottomWall1.objet.width)
				||
				player.position.x > (bottomWall2.objet.x + bottomWall2.objet.width - 3.5f) &&
				player.position.x <= (bottomWall2.objet.x + bottomWall2.objet.width)
				&&
				player.winPoint == false)
			{
				player.points++;
				player.winPoint = true;
			}
			else
			{
				player.winPoint = false;
			}
		}

		void DrawPlayer()
		{
			if (player.state == jumping)
			{
				AnimationJump();
			}
			else
			{
				AnimationMove();
				currentFrameJump = 0;
				framesCounterJump = 0;
			}
		}

		//------------------------------------------

		static void Jump(Rectangle pauseButtom, Rectangle menuButtom)
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true && CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, pauseButtom) == false && CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, menuButtom) == false)
			{
				if (player.state == falling)
				{
					player.state = jumping;
					player.force = FORCE;

					PlaySound(Sounds::jump);
				}
			}

			if (player.force <= 0)
			{
				player.state = falling;		
			}
			
			player.position.y -= player.force * GetFrameTime() * 2;

			if (player.force > MIN_FORCE)
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

					frameRec.x = static_cast<float>(currentFrame * (player.spriteMovement1.width / 4));
				}
				position = { player.position.x - player.radius * 2, player.position.y - player.radius };
			}

			if (player.skinSelected == 1)
			{
				DrawTextureRec(player.spriteMovement1, frameRec, position, WHITE);
			}
			else if (player.skinSelected == 2)
			{
				DrawTextureRec(player.spriteMovement2, frameRec, position, WHITE);
			}
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

					frameRecJump.x = static_cast<float>(currentFrameJump * (player.spriteJump1.width / 2));
				}
				position = { player.position.x - player.radius * 2, player.position.y - player.radius };
			}

			if (player.skinSelected == 1)
			{
				DrawTextureRec(player.spriteJump1, frameRecJump, position, WHITE);
			}
			else if (player.skinSelected == 2)
			{
				DrawTextureRec(player.spriteJump2, frameRecJump, position, WHITE);
			}
		}
	}
}