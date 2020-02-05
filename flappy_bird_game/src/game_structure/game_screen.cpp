#include "game_screen.h"

#include "raylib.h"

#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Game
	{
		static short fontTitle = 40;
		static short fontSubTittle = 30;
		static short font = 20;

		static void Draw();

		void Game()
		{
			Player_Things::Input();
			if (Player_Things::pause == false)
			{
				Enemies::MovementEnemies();
				Player_Things::EarnPoint();
				Player_Things::LoseOrWin();
				Sounds::StatePlayerMusic(Sounds::update);
			}
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// -----------------------

		static void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			Enemies::DrawEnemies();

			Player_Things::DrawPlayer();

			if (Player_Things::pause == true)
			{
				DrawText("PAUSE", GetScreenWidth() / 2 - fontSubTittle, GetScreenHeight() / 2, fontSubTittle, WHITE);
			}

			EndDrawing();
		}
	}
}