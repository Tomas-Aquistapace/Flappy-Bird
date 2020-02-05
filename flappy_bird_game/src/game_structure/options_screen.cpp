#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Options
	{
		static int fontTittle = 50;
		static int fontSubTittle = 20;

		static void Input();
		static void Draw();

		void Options()
		{
			Input();
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// --------------------

		static void Input()
		{
			if (IsKeyPressed(KEY_RIGHT) == true)
			{
				Menu::scenes = Menu::menu;
			}
		}

		static void Draw()
		{
			BeginDrawing();
			ClearBackground(BLANK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 6, 400, 95, DARKGRAY);

			DrawText("OPTIONS", GetScreenWidth() / 2 - 150, GetScreenHeight() / 5, fontTittle, GREEN);

			DrawRectangle(GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 + GetScreenHeight() / 3, 75, 75, BLUE);
			DrawText("S", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, GREEN);

			DrawRectangle(GetScreenWidth() / 2 + 75, GetScreenHeight() / 2 + GetScreenHeight() / 3, 75, 75, DARKBLUE);
			DrawText("M", GetScreenWidth() / 2 + 100, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, GREEN);

			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::rightArrow.rec.x), static_cast<int>(Menu::rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}