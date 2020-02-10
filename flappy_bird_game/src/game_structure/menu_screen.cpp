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

		static float fontTittle = 80.0f;
		static float fontSubTittle1 = 40.0f;
		static float fontSubTittle2 = 30.0f;

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
			Vector2 tittlePos;
			Vector2 text1Pos;
			Vector2 text2Pos;

			tittlePos.x = static_cast<float>(GetScreenWidth() / 2 - 180);
			tittlePos.y = static_cast<float>(GetScreenHeight() / 5 - 10);

			text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - 70);
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2 + 20);
			
			text2Pos.x = fontSubTittle2;
			text2Pos.y = static_cast<float>(GetScreenHeight() - fontSubTittle2);
			
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(Textures::menuTittle, GetScreenWidth() / 2 - 250, GetScreenHeight() / 6, GRAY);
			
			DrawTextEx(Textures::tittleFont, "Flappy Flame", tittlePos, fontTittle, 5, BLACK);
			DrawTextEx(Textures::textFont, "press SPACE\n     to JUMP", text1Pos, fontSubTittle1, 2, WHITE);
			DrawTextEx(Textures::textFont, "press ESCAPE to EXIT", text2Pos, fontSubTittle2, 2, DARKBLUE);

			//DrawRectangle(GetScreenWidth()/2 - 250, GetScreenHeight() / 6, 500, 100, GRAY);

			//DrawText("FLAPPY FLAME", GetScreenWidth() / 2 - 200, GetScreenHeight() / 5, fontTittle, GREEN);
			//DrawText("press SPACE\n	  to JUMP", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 60, fontSubTittle, WHITE);
			//DrawText("press ESCAPE to EXIT", 20, GetScreenHeight() - 20, fontSubTittle, WHITE);

			//DrawRectangleRec(leftArrow.rec, BLUE);
			//DrawRectangleRec(rightArrow.rec, BLUE);

			DrawTexture(Textures::menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			DrawTexture(Textures::menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}