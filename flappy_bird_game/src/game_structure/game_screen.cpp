#include "game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Game
	{
		static const short FONT_PAUSE = 80;

		static const int MOUSERADIUS = 0;

		static const float HEIGHT = 50;
		static const float WIDTH = 50;

		static Rectangle menuButtom;
		static Rectangle pauseButtom;

		static void Draw();
		static void ButtomMenuPressed();
		static void ButtomPausePressed();

		void Initialiaze()
		{
			menuButtom.height = HEIGHT;
			menuButtom.width = WIDTH;
			menuButtom.x = static_cast<float>(GetScreenWidth() - menuButtom.width * 2);
			menuButtom.y = static_cast<float>(GetScreenHeight() - (menuButtom.height + menuButtom.height / 2));

			pauseButtom.height = HEIGHT;
			pauseButtom.width = WIDTH;
			pauseButtom.x = static_cast<float>(GetScreenWidth() - pauseButtom.width * 4);
			pauseButtom.y = static_cast<float>(GetScreenHeight() - (pauseButtom.height + pauseButtom.height / 2));
		}
		
		void Unload()
		{

		}


		void Game()
		{
			Player::Input(pauseButtom, menuButtom);
			if (Player::pause == false)
			{
				Enemies::MovementEnemies();
				Player::EarnPoint();
				Player::LoseOrWin();
				Sounds::StatePlayerMusic(Sounds::update);
			}
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// -----------------------

		static void ButtomMenuPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, menuButtom))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawRectangleRec(menuButtom, DARKGRAY);
				}
				else
				{
					DrawRectangleRec(menuButtom, GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Menu::scene = Menu::menu;
					Sounds::StatePlayerMusic(Sounds::stop);
				}
			}
			else
			{
				DrawRectangleRec(menuButtom, GRAY);
			}
		}

		static void ButtomPausePressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, pauseButtom))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawRectangleRec(pauseButtom, DARKGRAY);
				}
				else
				{
					DrawRectangleRec(pauseButtom, GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Player::pause = !Player::pause;
				}
			}
			else
			{
				DrawRectangleRec(pauseButtom, GRAY);
			}
		}

		static void Draw()
		{
			Vector2 textPos;
			
			textPos.x = static_cast<float>(GetScreenWidth() / 2 - FONT_PAUSE);
			textPos.y = static_cast<float>(GetScreenHeight() / 2);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			Enemies::DrawEnemies();

			Player::DrawPlayer();

			if (Player::pause == true)
			{
				DrawTextEx(Textures::tittleFont, "Pause", textPos, FONT_PAUSE, 2, BLACK);
			}

			ButtomMenuPressed();
			ButtomPausePressed();

			EndDrawing();
		}
	}
}