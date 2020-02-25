#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Options
	{
		//static const float FONT_OPTIONS = 130;
		//static const float FONT_PRESS_SPACE = 30;

		static const int MOUSERADIUS = 0;

		static const float HEIGHT = 50;
		static const float WIDTH = 50;

		static bool muteEffects = false;
		static bool muteMusic = false;

		static Rectangle musicButtom;
		static Rectangle soundButtom;
		static Rectangle skinsButtom;

		static Texture2D optionsTittle;
		static Texture2D optionsEffects;

		//static void Input();
		static void ButtomsMuteSound();
		static void ButtomsMuteMusic();
		static void ButtomSkinSelected();
		static void Draw();

		void Initialize()
		{
			//Image optionsImage;

			musicButtom.height = HEIGHT;
			musicButtom.width = WIDTH;
			musicButtom.x = musicButtom.width;
			musicButtom.y = static_cast<float>(GetScreenHeight() - (musicButtom.height + musicButtom.height / 2));

			soundButtom.height = HEIGHT;
			soundButtom.width = WIDTH;
			soundButtom.x = musicButtom.x + soundButtom.width * 2;
			soundButtom.y = static_cast<float>(GetScreenHeight() - (soundButtom.height + soundButtom.height / 2));

			skinsButtom.height = static_cast<float>(Player::frameworkSkin1.height);
			skinsButtom.width = static_cast<float>(Player::frameworkSkin1.width);
			skinsButtom.x = static_cast<float>(GetScreenWidth() / 2 - Player::frameworkSkin1.width / 2);
			skinsButtom.y = static_cast<float>(GetScreenHeight() / 2 - Player::frameworkSkin1.height / 3);

			optionsTittle = LoadTexture("assets/textures/framework/frameworkOptionsTittle.png");

			//optionsImage = LoadImage("assets/textures/framework/framework.png");
			//ImageResize(&optionsImage, 100, 100);
			//optionsEffects = LoadTextureFromImage(optionsImage);

			//UnloadImage(optionsImage);
		}

		void Unload()
		{
			UnloadTexture(optionsTittle);
			//UnloadTexture(optionsEffects);
		}

		void Options()
		{
			//Input();
			Sounds::SetMusicVolume(muteMusic);
			Sounds::SetEffectsVolume(muteEffects);
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// --------------------

		//static void Input()
		//{
			/*if (IsKeyPressed(KEY_S) == true) 
			{
				muteEffects = !muteEffects;
			}
			if (IsKeyPressed(KEY_M) == true) 
			{
				muteMusic = !muteMusic;
			}*/

			/*if (IsKeyPressed(KEY_SPACE) == true) 
			{
				Player::player.skinSelected++;
				if (Player::player.skinSelected > Player::player.maxSkins)
				{
					Player::player.skinSelected = 1;
				}
			}*/
		//}

		static void ButtomsMuteMusic()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, musicButtom))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					muteMusic = !muteMusic;
				}
			}
			
			if (muteMusic == false)
			{
				DrawRectangleRec(musicButtom, GRAY);
			}
			else
			{
				DrawRectangleRec(musicButtom, RED);	
			}
		}

		static void ButtomsMuteSound()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, soundButtom))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					muteEffects = !muteEffects;
				}
			}

			if (muteEffects == false)
			{
				DrawRectangleRec(soundButtom, GRAY);
			}
			else
			{
				DrawRectangleRec(soundButtom, RED);
			}			
		}

		static void ButtomSkinSelected()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, skinsButtom))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Player::player.skinSelected++;
					if (Player::player.skinSelected > Player::player.maxSkins)
					{
						Player::player.skinSelected = 1;
					}
				}
			}

			if (Player::player.skinSelected == 1)
			{
				DrawTexture(Player::frameworkSkin1, GetScreenWidth() / 2 - Player::frameworkSkin1.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin1.height / 3, WHITE);
			}
			else if (Player::player.skinSelected == 2)
			{
				DrawTexture(Player::frameworkSkin2, GetScreenWidth() / 2 - Player::frameworkSkin2.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin2.height / 3, WHITE);
			}
		}

		static void Draw()
		{
			//int extraPixels = 10;

			//Vector2 text1Pos;
			//Vector2 text2Pos;
			//Vector2 text3Pos;
			//
			//text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - optionsEffects.width - optionsEffects.width / 2 - optionsEffects.width / 3);
			//text1Pos.y = static_cast<float>(GetScreenHeight() - (optionsEffects.height + optionsEffects.height / 3) - extraPixels);
			//
			//text2Pos.x = static_cast<float>(GetScreenWidth() / 2 + optionsEffects.width + extraPixels);
			//text2Pos.y = static_cast<float>(GetScreenHeight() - (optionsEffects.height + optionsEffects.height / 3) - extraPixels);
			//
			//text3Pos.x = static_cast<float>(GetScreenWidth() / 2 - FONT_PRESS_SPACE * 2);
			//text3Pos.y = static_cast<float>(GetScreenHeight() - Player::frameworkSkin1.height / 2 - extraPixels);

			BeginDrawing();
			ClearBackground(BLANK);

			//Textures::MovementBackgrounds();
			Textures::DrawBackground();
			
			DrawTexture(optionsTittle, GetScreenWidth() / 2 - optionsTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);


			/*if (Player::player.skinSelected == 1)
			{
				DrawTexture(Player::frameworkSkin1, GetScreenWidth() / 2 - Player::frameworkSkin1.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin1.height / 3, WHITE);
			}
			else if (Player::player.skinSelected == 2)
			{
				DrawTexture(Player::frameworkSkin2, GetScreenWidth() / 2 - Player::frameworkSkin2.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin2.height / 3, WHITE);
			}
			DrawTextEx(Textures::textFont, "press SPACE", text3Pos, FONT_PRESS_SPACE, 2, WHITE);*/

			ButtomSkinSelected();
			ButtomsMuteMusic();
			ButtomsMuteSound();


			//DrawTexture(optionsEffects, GetScreenWidth() / 2 - optionsEffects.width * 2, GetScreenHeight() - (optionsEffects.height + optionsEffects.height / 3), BLUE);
			//if (!muteEffects)
			//{
			//	DrawTextEx(Textures::textFont, "S", text1Pos, FONT_OPTIONS, 2, BLACK);
			//}
			//else
			//{
			//	DrawTextEx(Textures::textFont, "S", text1Pos, FONT_OPTIONS, 2, MAROON);
			//}
			//
			//DrawTexture(optionsEffects, GetScreenWidth() / 2 + optionsEffects.width, GetScreenHeight() - (optionsEffects.height + optionsEffects.height / 3), DARKBLUE);
			//if (!muteMusic)
			//{
			//	DrawTextEx(Textures::textFont, "M", text2Pos, FONT_OPTIONS, 2, BLACK);
			//}
			//else
			//{
			//	DrawTextEx(Textures::textFont, "M", text2Pos, FONT_OPTIONS, 2, MAROON);
			//}

			Menu::KeysRightPressed(Menu::menu);

			EndDrawing();
		}
	}
}