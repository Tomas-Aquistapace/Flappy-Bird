#include "end_game_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace End_game
	{
		static int fontTittle = 50;
		static int fontSubTittle = 25;

		static void Input();
		static void DrawEndGame();

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
				Player_Things::ResetPlayer();
				Enemies::InitialiceEnemies();
				Sounds::StateEndMusic(Sounds::stop);
				Sounds::StateGameMusic(Sounds::play);
				Menu::scenes = Menu::menu;
			}
		}

		static void DrawEndGame()
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