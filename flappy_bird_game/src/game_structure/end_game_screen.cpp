#include "end_game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_structure/initialice.h"
namespace Flappy_Bird
{
	namespace End_game
	{
		//static int fontTittle = 50;
		static int fontSubTittle = 30;

		void Input()
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				ResetValues();
				scenes = menu;
			}
		}

		void DrawEndGame()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			DrawText(FormatText("Points ~ %i", Player_Things::player.points), GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 + 60, fontSubTittle, DARKGREEN);

			EndDrawing();
		}
	}
}