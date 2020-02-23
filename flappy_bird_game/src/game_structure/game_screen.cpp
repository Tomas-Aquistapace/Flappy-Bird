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
		static const short FONT_PAUSE = 80;

		static void Draw();

		void Game()
		{
			Player::Input();
			if (Player::pause == false)
			{
				Enemies::MovementEnemies();
				Player::EarnPoint();
				Player::LoseOrWin();
				Sounds::StatePlayerMusic(Sounds::update);
			}
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// -----------------------

		static void Draw()
		{
			Vector2 textPos;
			
			textPos.x = static_cast<float>(GetScreenWidth() / 2 - FONT_PAUSE);
			textPos.y = static_cast<float>(GetScreenHeight() / 2);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			Enemies::DrawEnemies();

			Player::DrawPlayer();

			if (Player::pause == true)
			{
				//DrawText("PAUSE", GetScreenWidth() / 2 - fontSubTittle, GetScreenHeight() / 2, fontSubTittle, WHITE);
				DrawTextEx(Textures::tittleFont, "Pause", textPos, FONT_PAUSE, 2, BLACK);
			}

			EndDrawing();
		}
	}
}