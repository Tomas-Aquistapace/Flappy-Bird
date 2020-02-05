#include "menu_screen.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Menu
	{
		STATE scenes;

		ARROW leftArrow;
		ARROW rightArrow;

		static int fontTittle = 50;
		static int fontSubTittle = 20;

		static void InputMenu();
		static void DrawMenu();

		void InitialiceMenu()
		{
			scenes = menu;

			float height = 60;
			float width = 40;

			leftArrow.rec.height = height;
			leftArrow.rec.width = width;
			leftArrow.rec.x = static_cast<float>(GetScreenWidth() / 2 - GetScreenWidth() / 3 - width);
			leftArrow.rec.y = static_cast<float>(GetScreenHeight() / 2 + height / 2);

			rightArrow.rec.height = height;
			rightArrow.rec.width = width;
			rightArrow.rec.x = static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 3);
			rightArrow.rec.y = static_cast<float>(GetScreenHeight() / 2 + height / 2);
		}

		void Menu()
		{
			InputMenu();
			Sounds::StateGameMusic(Sounds::update);
			DrawMenu();
		}

		// ----------------------------

		static void InputMenu()
		{
			if (IsKeyPressed(KEY_SPACE) == true)
			{
				Player_Things::ResetPlayer();
				Sounds::StatePlayerMusic(Sounds::play);
				scenes = game;
			}

			if (IsKeyPressed(KEY_LEFT) == true)
			{
				scenes = options;
			}

			if (IsKeyPressed(KEY_RIGHT) == true)
			{
				scenes = credits;
			}

			if (IsKeyPressed(KEY_ESCAPE) == true)
			{
				scenes = exit;
				Sounds::StateGameMusic(Sounds::stop);
			}
		}

		static void DrawMenu()
		{
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			//DrawRectangle(GetScreenWidth()/2 - 250, GetScreenHeight() / 6, 500, 100, GRAY);

			DrawTexture(Textures::menuTittle, GetScreenWidth() / 2 - 250, GetScreenHeight() / 6, GRAY);

			DrawText("FLAPPY FLAME", GetScreenWidth() / 2 - 200, GetScreenHeight() / 5, fontTittle, GREEN);
			DrawText("press SPACE", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 60, fontSubTittle, WHITE);

			DrawRectangleRec(leftArrow.rec, BLUE);
			DrawRectangleRec(rightArrow.rec, BLUE);

			DrawTexture(Textures::menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			DrawTexture(Textures::menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}