#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
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
				scenes = menu;
			}
		}

		void DrawOptions()
		{
			BeginDrawing();

			ClearBackground(BLANK);

			DrawText("OPTIONS", GetScreenWidth() / 2 - 150, GetScreenHeight() / 5, fontTittle, GREEN);

			EndDrawing();
		}
	}
}