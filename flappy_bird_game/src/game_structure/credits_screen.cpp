#include "credits_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_structure/initialice.h"
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
				ResetValues();
				scenes = menu;
			}
		}

		void DrawCredits()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawText("Credits", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, fontTittle, GREEN);
			
			EndDrawing();
		}
	}
}