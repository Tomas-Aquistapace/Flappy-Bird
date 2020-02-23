#include "menu_screen.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Menu
	{
		STATE scenes;

		ARROW leftArrow;
		ARROW rightArrow;

		Texture2D menuArrows;
		static Texture2D menuTittle;

		static const float FONT_PRESS_SPACE = 40.0f;
		static const float FONT_PRESS_ESCAPE = 35.0f;

		static void InputMenu();
		static void DrawMenu();

		void Initialize()
		{
			Image menuTittleImage;
			Image arrowImage;

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

			arrowImage = LoadImage("assets/textures/menu/arrow.png");
			menuTittleImage = LoadImage("assets/textures/framework/frameworkTittle.png");

			ImageResize(&arrowImage, static_cast<int>(leftArrow.rec.width), static_cast<int>(leftArrow.rec.height));
			menuArrows = LoadTextureFromImage(arrowImage);
			menuTittle = LoadTextureFromImage(menuTittleImage);

			UnloadImage(arrowImage);
			UnloadImage(menuTittleImage);
		}

		void Unload()
		{
			UnloadTexture(menuArrows);
			UnloadTexture(menuTittle);
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
				Player::ResetPlayer();
				Enemies::Reset();
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
			Vector2 text1Pos;
			Vector2 text2Pos;

			text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - 70);
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2 + 20);
			
			text2Pos.x = FONT_PRESS_ESCAPE;
			text2Pos.y = static_cast<float>(GetScreenHeight() - (FONT_PRESS_ESCAPE + FONT_PRESS_ESCAPE / 3));
			
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(menuTittle, GetScreenWidth() / 2 - menuTittle.width / 2, GetScreenHeight() / 2 - menuTittle.height, GRAY);

			DrawTextEx(Textures::textFont, "press SPACE\n     to JUMP", text1Pos, FONT_PRESS_SPACE, 2, WHITE);
			DrawTextEx(Textures::textFont, "press ESCAPE to EXIT", text2Pos, FONT_PRESS_ESCAPE, 2, DARKBLUE);

			DrawTexture(menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			DrawTexture(menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}