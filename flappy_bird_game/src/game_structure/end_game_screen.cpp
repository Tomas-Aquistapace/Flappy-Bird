#include "end_game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_structure/initialice.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace End_game
	{
		static int fontSubTittle = 30;

		void Input()
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				ResetValues();
				Menu::scenes = Menu::menu;
			}
		}

		void DrawEndGame()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawText(FormatText("Points ~ %i", Player_Things::player.points), GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 + 60, fontSubTittle, DARKGREEN);

			EndDrawing();
		}
	}
}