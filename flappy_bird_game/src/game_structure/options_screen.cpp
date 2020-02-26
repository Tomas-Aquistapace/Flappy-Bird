#include "options_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Spooky_Ghost
{
	namespace Options
	{

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

		static void ButtomsMuteSound();
		static void ButtomsMuteMusic();
		static void ButtomSkinSelected();
		static void Draw();

		void Initialize()
		{
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
		}

		void Unload()
		{
			UnloadTexture(optionsTittle);
		}

		void Options()
		{
			Sounds::SetMusicVolume(muteMusic);
			Sounds::SetEffectsVolume(muteEffects);
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// --------------------

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
				DrawTexture(Player::frameworkSkin1, GetScreenWidth() / 2 - Player::frameworkSkin1.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin1.height / 4, WHITE);
			}
			else if (Player::player.skinSelected == 2)
			{
				DrawTexture(Player::frameworkSkin2, GetScreenWidth() / 2 - Player::frameworkSkin2.width / 2, GetScreenHeight() / 2 - Player::frameworkSkin2.height / 4, WHITE);
			}
		}

		static void Draw()
		{
			BeginDrawing();
			ClearBackground(BLANK);

			Textures::DrawBackground();
			
			DrawTexture(optionsTittle, GetScreenWidth() / 2 - optionsTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			ButtomSkinSelected();
			ButtomsMuteMusic();
			ButtomsMuteSound();

			Menu::KeysRightPressed(Menu::menu);

			EndDrawing();
		}
	}
}