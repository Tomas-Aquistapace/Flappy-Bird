#include "game_screen.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Spooky_Ghost
{
	namespace Game
	{
		static const short FONT_PAUSE = 80; 
		static const short PIXELS_AXIS = 20;
		static const short FONT_UI = 40;

		static const int MOUSERADIUS = 0;

		static const float HEIGHT = 50;
		static const float WIDTH = 50;

		static BUTTOM menuButtom;
		static BUTTOM pauseButtom;

		static void Draw();
		static void ButtomMenuPressed();
		static void ButtomPausePressed();

		void Initialiaze()
		{
			menuButtom.rec.height = HEIGHT;
			menuButtom.rec.width = WIDTH;
			menuButtom.rec.x = static_cast<float>(GetScreenWidth() - menuButtom.rec.width * 2);
			menuButtom.rec.y = static_cast<float>(GetScreenHeight() - (menuButtom.rec.height + menuButtom.rec.height / 2));
			menuButtom.texture = LoadTexture("assets/textures/buttoms/Boton Menu.png");
			menuButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Menu Pressed.png");

			pauseButtom.rec.height = HEIGHT;
			pauseButtom.rec.width = WIDTH;
			pauseButtom.rec.x = static_cast<float>(GetScreenWidth() - pauseButtom.rec.width * 4);
			pauseButtom.rec.y = static_cast<float>(GetScreenHeight() - (pauseButtom.rec.height + pauseButtom.rec.height / 2));
			pauseButtom.texture = LoadTexture("assets/textures/buttoms/Boton Pausa.png");
			pauseButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Pausa Pressed.png");
		}
		
		void Unload()
		{
			UnloadTexture(menuButtom.texture);
			UnloadTexture(menuButtom.texturePressed);
			UnloadTexture(pauseButtom.texture);
			UnloadTexture(pauseButtom.texturePressed);
		}

		void Game()
		{
			Player::Input(pauseButtom.rec, menuButtom.rec);
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
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, menuButtom.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(menuButtom.texturePressed, static_cast<int>(menuButtom.rec.x), static_cast<int>(menuButtom.rec.y), GRAY);
				}
				else
				{
					DrawTexture(menuButtom.texture, static_cast<int>(menuButtom.rec.x), static_cast<int>(menuButtom.rec.y), GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Menu::scene = Menu::menu;
					Sounds::StatePlayerMusic(Sounds::stop);
				}
			}
			else
			{
				DrawTexture(menuButtom.texture, static_cast<int>(menuButtom.rec.x), static_cast<int>(menuButtom.rec.y), GRAY);
			}
		}

		static void ButtomPausePressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, pauseButtom.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(pauseButtom.texturePressed, static_cast<int>(pauseButtom.rec.x), static_cast<int>(pauseButtom.rec.y), GRAY);
				}
				else
				{
					DrawTexture(pauseButtom.texture, static_cast<int>(pauseButtom.rec.x), static_cast<int>(pauseButtom.rec.y), GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Player::pause = !Player::pause;
				}
			}
			else
			{
				DrawTexture(pauseButtom.texture, static_cast<int>(pauseButtom.rec.x), static_cast<int>(pauseButtom.rec.y), GRAY);
			}
		}

		static void Draw()
		{
			Vector2 text1Pos;
			Vector2 text2Pos;
			
			text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - FONT_PAUSE);
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2);

			text2Pos.x = static_cast<float>(PIXELS_AXIS);
			text2Pos.y = static_cast<float>(GetScreenHeight() - menuButtom.rec.height);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			Enemies::DrawEnemies();
			Player::DrawPlayer();

			if (Player::pause == true)
			{
				DrawTextEx(Textures::tittleFont, "Pause", text1Pos, FONT_PAUSE, 2, BLACK);
			}

			DrawTextEx(Textures::textFont, FormatText("Points   %i", Player::player.points), text2Pos, FONT_UI, 2, WHITE);

			ButtomMenuPressed();
			ButtomPausePressed();

			EndDrawing();
		}
	}
}