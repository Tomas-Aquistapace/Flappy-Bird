#include "credits_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace Credits
	{
		static int fontTittle = 50;
		static int fontSubTittle = 20;

		void Input()
		{
			if (IsKeyPressed(KEY_LEFT) == true)
			{
				//Player_Things::ResetPlayer();
				//Enemies::InitialiceEnemies();
				Menu::scenes = Menu::menu;
			}
		}

		void DrawCredits()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 6, 400, 95, DARKGRAY);

			DrawText("Credits", GetScreenWidth() / 2 - 100, GetScreenHeight() / 5, fontTittle, GREEN);
			
			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::leftArrow.rec.x), static_cast<int>(Menu::leftArrow.rec.y), GRAY);

			DrawRectangle(GetScreenWidth() / 2 - 175, GetScreenHeight() / 2 - 100, 350, 300, GRAY);

			EndDrawing();
		}
	}
}