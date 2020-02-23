#include "end_game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace End_game
	{
		const float FONT_POINT = 50;
		const float FONT_EXIT = 40;

		static Texture2D endScreenTittle;
		static Texture2D endScreenPoints;

		static void Input();
		static void DrawEndGame();

		void Initialize()
		{
			Image endGameImage;

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
		}

		void EndGame()
		{
			Input();
			Sounds::StateEndMusic(Sounds::update);
			DrawEndGame();
		}

		// -----------------------

		static void Input()
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				Sounds::StateEndMusic(Sounds::stop);
				Sounds::StateGameMusic(Sounds::play);
				Menu::scenes = Menu::menu;
			}
		}

		static void DrawEndGame()
		{
			int extraPixels = 10;

			Vector2 text1Pos;
			Vector2 text2Pos;
			Vector2 text3Pos;

			text1Pos.x = static_cast<float>((GetScreenWidth() / 2 + endScreenPoints.width / 3.5f) - ((MeasureText("Points  %i", static_cast<int>(FONT_POINT)) / 2)));
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2 - endScreenPoints.height / 2 + extraPixels);

			text2Pos.x = static_cast<float>((GetScreenWidth() / 2 + endScreenPoints.width / 2.5f) - ((MeasureText("Max Points  %i", static_cast<int>(FONT_POINT)) / 2)));
			text2Pos.y = static_cast<float>(GetScreenHeight() / 2 + endScreenPoints.height);
			
			text3Pos.x = static_cast<float>(GetScreenWidth() / 2 - (FONT_EXIT + FONT_EXIT / 2));
			text3Pos.y = static_cast<float>(GetScreenHeight() / 2 + GetScreenHeight() / 3);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawTexture(endScreenTittle, GetScreenWidth() / 2 - endScreenTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			DrawTexture(endScreenPoints, GetScreenWidth() / 2 - endScreenPoints.width / 2, GetScreenHeight() / 2 - (endScreenPoints.height - endScreenPoints.height / 3), GRAY);
			DrawTextEx(Textures::textFont, FormatText("Points  %i", Player::player.points), text1Pos, FONT_POINT, 2, BLACK);

			DrawTexture(endScreenPoints, GetScreenWidth() / 2 - endScreenPoints.width / 2, GetScreenHeight() / 2 + (endScreenPoints.height - endScreenPoints.height / 3), DARKGRAY);
			DrawTextEx(Textures::textFont, FormatText("Max Points  %i", Player::player.maxPoints), text2Pos, FONT_POINT, 2, WHITE);

			DrawTextEx(Textures::textFont, "Press Enter", text3Pos, FONT_EXIT, 2, WHITE);

			EndDrawing();
		}
	}
}