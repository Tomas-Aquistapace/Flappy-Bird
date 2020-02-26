#include "end_game_screen.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Spooky_Ghost
{
	namespace End_game
	{
		static const float FONT_POINT = 50;

		static const int MOUSERADIUS = 0;

		static const float HEIGHT = 50;
		static const float WIDTH = 50;

		static BUTTOM menuButtom;
		static BUTTOM resetButtom;

		static Texture2D endScreenTittle;
		static Texture2D endScreenPoints;

		static void ButtomMenuPressed();
		static void ButtomResetPressed();
		static void DrawEndGame();

		void Initialize()
		{
			Image endGameImage;
			
			menuButtom.rec.height = HEIGHT;
			menuButtom.rec.width = WIDTH;
			menuButtom.rec.x = static_cast<float>(GetScreenWidth() / 2 + menuButtom.rec.width / 2);
			menuButtom.rec.y = static_cast<float>(GetScreenHeight() / 2 + GetScreenHeight() / 3);
			menuButtom.texture = LoadTexture("assets/textures/buttoms/Boton Menu.png");
			menuButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Menu Pressed.png");

			resetButtom.rec.height = HEIGHT;
			resetButtom.rec.width = WIDTH;
			resetButtom.rec.x = static_cast<float>(GetScreenWidth() / 2 - (resetButtom.rec.width + resetButtom.rec.width / 2));
			resetButtom.rec.y = static_cast<float>(GetScreenHeight() / 2 + GetScreenHeight() / 3);
			resetButtom.texture = LoadTexture("assets/textures/buttoms/Boton Replay.png");
			resetButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Replay Pressed.png");

			endScreenTittle = LoadTexture("assets/textures/framework/frameworkGameOverTittle.png");

			endGameImage = LoadImage("assets/textures/framework/frameworkPoints.png");
			ImageResize(&endGameImage, 250, 100);
			endScreenPoints = LoadTextureFromImage(endGameImage);

			UnloadImage(endGameImage);
		}

		void Unload()
		{
			UnloadTexture(endScreenTittle);
			UnloadTexture(endScreenPoints);
			UnloadTexture(menuButtom.texture);
			UnloadTexture(menuButtom.texturePressed);
			UnloadTexture(resetButtom.texture);
			UnloadTexture(resetButtom.texturePressed);
		}

		void EndGame()
		{
			Sounds::StateEndMusic(Sounds::update);
			DrawEndGame();
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
					Sounds::StateEndMusic(Sounds::stop);
					Sounds::StateGameMusic(Sounds::play);
					Menu::scene = Menu::menu;
				}
			}
			else
			{
				DrawTexture(menuButtom.texture, static_cast<int>(menuButtom.rec.x), static_cast<int>(menuButtom.rec.y), GRAY);
			}
		}

		static void ButtomResetPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, resetButtom.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(resetButtom.texturePressed, static_cast<int>(resetButtom.rec.x), static_cast<int>(resetButtom.rec.y), GRAY);
				}
				else
				{
					DrawTexture(resetButtom.texture, static_cast<int>(resetButtom.rec.x), static_cast<int>(resetButtom.rec.y), GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Sounds::StateEndMusic(Sounds::stop);
					Sounds::StateGameMusic(Sounds::play);
					Sounds::StatePlayerMusic(Sounds::play);
					Menu::scene = Menu::game;
					Player::Reset();
					Enemies::Reset();
				}
			}
			else
			{
				DrawTexture(resetButtom.texture, static_cast<int>(resetButtom.rec.x), static_cast<int>(resetButtom.rec.y), GRAY);
			}
		}

		static void DrawEndGame()
		{
			int extraPixels = 10;

			Vector2 text1Pos;
			Vector2 text2Pos;

			text1Pos.x = static_cast<float>((GetScreenWidth() / 2 + endScreenPoints.width / 3.5f) - ((MeasureText("Points  %i", static_cast<int>(FONT_POINT)) / 2)) - extraPixels);
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2 - endScreenPoints.height / 2 + extraPixels);

			text2Pos.x = static_cast<float>((GetScreenWidth() / 2 + endScreenPoints.width / 2.5f) - ((MeasureText("Max Points  %i", static_cast<int>(FONT_POINT)) / 2)) - extraPixels);
			text2Pos.y = static_cast<float>(GetScreenHeight() / 2 + endScreenPoints.height);
			
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawTexture(endScreenTittle, GetScreenWidth() / 2 - endScreenTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			DrawTexture(endScreenPoints, GetScreenWidth() / 2 - endScreenPoints.width / 2, GetScreenHeight() / 2 - (endScreenPoints.height - endScreenPoints.height / 3), GRAY);
			DrawTextEx(Textures::textFont, FormatText("Points  %i", Player::player.points), text1Pos, FONT_POINT, 2, GRAY);

			DrawTexture(endScreenPoints, GetScreenWidth() / 2 - endScreenPoints.width / 2, GetScreenHeight() / 2 + (endScreenPoints.height - endScreenPoints.height / 3), DARKGRAY);
			DrawTextEx(Textures::textFont, FormatText("Max Points  %i", Player::player.maxPoints), text2Pos, FONT_POINT, 2, GRAY);

			ButtomMenuPressed(); 
			ButtomResetPressed();

			EndDrawing();
		}
	}
}