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

		static bool muteEffects = false;
		static bool muteMusic = false;

		static void Input();
		static void Draw();

		void Options()
		{
			Input();
			Sounds::SetMusicVolume(muteMusic);
			Sounds::SetEffectsVolume(muteEffects);
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

			if (IsKeyPressed(KEY_S) == true) 
			{
				muteEffects = !muteEffects;
			}
			if (IsKeyPressed(KEY_M) == true) 
			{
				muteMusic = !muteMusic;
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

			if (!muteEffects)
			{
				DrawText("S", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, GREEN);
			}
			else
			{
				DrawText("S", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, RED);
			}


			DrawRectangle(GetScreenWidth() / 2 + 75, GetScreenHeight() / 2 + GetScreenHeight() / 3, 75, 75, DARKBLUE);
			
			if(!muteMusic)
			{
				DrawText("M", GetScreenWidth() / 2 + 100, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, GREEN);
			}
			else
			{
				DrawText("M", GetScreenWidth() / 2 + 100, GetScreenHeight() / 2 + GetScreenHeight() / 3 + 20, fontTittle, RED);
			}

			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::rightArrow.rec.x), static_cast<int>(Menu::rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}