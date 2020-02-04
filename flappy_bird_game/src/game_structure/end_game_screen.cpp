#include "end_game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "game_structure/initialice.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	namespace End_game
	{
		static int fontTittle = 50;
		static int fontSubTittle = 25;

		void Input()
		{
			if (IsKeyPressed(KEY_ENTER) == true)
			{
				Player_Things::ResetPlayer();
				Enemies::InitialiceEnemies();
				Menu::scenes = Menu::menu;
			}
		}

		void DrawEndGame()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 6, 400, 95, DARKGRAY);
			DrawText("Game Over", GetScreenWidth() / 2 - 200, GetScreenHeight() / 5, fontTittle, GREEN);

			DrawRectangle(GetScreenWidth() / 2 - 125, GetScreenHeight() / 2 - 75, 250, 100, GRAY);
			DrawText(FormatText("Points ~ %i", Player_Things::player.points), GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 - 50, fontSubTittle, GREEN);

			DrawRectangle(GetScreenWidth() / 2 - 125, GetScreenHeight() / 2 + 75, 250, 100, DARKGRAY);
			DrawText(FormatText("Max Points ~ %i", Player_Things::player.maxPoints), GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 + 100, fontSubTittle, GREEN);

			EndDrawing();
		}
	}
}