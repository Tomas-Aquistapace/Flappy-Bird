#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Options
	{
		static float fontOptions = 130;

		static bool muteEffects = false;
		static bool muteMusic = false;

		Texture2D optionsTittle;
		Texture2D optionsEffects;

		static void Input();
		static void Draw();

		void Initialize()
		{
			Image optionsImage;

			optionsTittle = LoadTexture("assets/textures/framework/frameworkOptionsTittle.png");

			optionsImage = LoadImage("assets/textures/framework/framework.png");
			ImageResize(&optionsImage, 100, 100);
			optionsEffects = LoadTextureFromImage(optionsImage);

			UnloadImage(optionsImage);
		}

		void Unload()
		{
			UnloadTexture(optionsTittle);
			UnloadTexture(optionsEffects);
		}

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
			int extraPixels = 10;

			Vector2 text1Pos;
			Vector2 text2Pos;

			text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - optionsEffects.width - optionsEffects.width / 2 - optionsEffects.width / 3);
			text1Pos.y = static_cast<float>(GetScreenHeight() / 2 + optionsEffects.height - extraPixels);

			text2Pos.x = static_cast<float>(GetScreenWidth() / 2 + optionsEffects.width + extraPixels);
			text2Pos.y = static_cast<float>(GetScreenHeight() / 2 + optionsEffects.height - extraPixels);

			BeginDrawing();
			ClearBackground(BLANK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawTexture(optionsTittle, GetScreenWidth() / 2 - optionsTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			DrawTexture(optionsEffects, GetScreenWidth() / 2 - optionsEffects.width * 2, GetScreenHeight() / 2 + optionsEffects.height, BLUE);
			if (!muteEffects)
			{
				DrawTextEx(Textures::textFont, "S", text1Pos, fontOptions, 2, BLACK);
			}
			else
			{
				DrawTextEx(Textures::textFont, "S", text1Pos, fontOptions, 2, RED);
			}

			DrawTexture(optionsEffects, GetScreenWidth() / 2 + optionsEffects.width, GetScreenHeight() / 2 + optionsEffects.height, DARKBLUE);
			if(!muteMusic)
			{
				DrawTextEx(Textures::textFont, "M", text2Pos, fontOptions, 2, BLACK);
			}
			else
			{
				DrawTextEx(Textures::textFont, "M", text2Pos, fontOptions, 2, RED);
			}

			DrawTexture(Menu::menuArrows, static_cast<int>(Menu::rightArrow.rec.x), static_cast<int>(Menu::rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}