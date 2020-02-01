#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace Options
	{
		static int fontTittle = 50;
		static int fontSubTittle = 20;

		void Input()
		{
			if (IsKeyPressed(KEY_RIGHT) == true)
			{
				Menu::scenes = Menu::menu;
			}
		}

		void DrawOptions()
		{
			BeginDrawing();
			ClearBackground(BLANK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawText("OPTIONS", GetScreenWidth() / 2 - 150, GetScreenHeight() / 5, fontTittle, GREEN);

			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::rightArrow.rec.x), static_cast<int>(Menu::rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}