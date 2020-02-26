#include "options_screen.h"

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

		static BUTTOM musicButtom;
		static BUTTOM soundButtom;

		static Rectangle skinsButtom;

		static Texture2D optionsTittle;
		static Texture2D optionsEffects;

		static void ButtomsMuteSound();
		static void ButtomsMuteMusic();
		static void ButtomSkinSelected();
		static void Draw();

		void Initialize()
		{
			musicButtom.rec.height = HEIGHT;
			musicButtom.rec.width = WIDTH;
			musicButtom.rec.x = musicButtom.rec.width;
			musicButtom.rec.y = static_cast<float>(GetScreenHeight() - (musicButtom.rec.height + musicButtom.rec.height / 2));
			musicButtom.texture = LoadTexture("assets/textures/buttoms/Boton Musica On.png");
			musicButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Musica Off.png");

			soundButtom.rec.height = HEIGHT;
			soundButtom.rec.width = WIDTH;
			soundButtom.rec.x = musicButtom.rec.x + soundButtom.rec.width * 2;
			soundButtom.rec.y = static_cast<float>(GetScreenHeight() - (soundButtom.rec.height + soundButtom.rec.height / 2)); 
			soundButtom.texture = LoadTexture("assets/textures/buttoms/Boton Sonido On.png");
			soundButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton Sonido Mute.png");

			skinsButtom.height = static_cast<float>(Player::frameworkSkin1.height);
			skinsButtom.width = static_cast<float>(Player::frameworkSkin1.width);
			skinsButtom.x = static_cast<float>(GetScreenWidth() / 2 - Player::frameworkSkin1.width / 2);
			skinsButtom.y = static_cast<float>(GetScreenHeight() / 2 - Player::frameworkSkin1.height / 3);

			optionsTittle = LoadTexture("assets/textures/framework/frameworkOptionsTittle.png");
		}

		void Unload()
		{
			UnloadTexture(optionsTittle);
			UnloadTexture(musicButtom.texture);
			UnloadTexture(musicButtom.texturePressed);
			UnloadTexture(soundButtom.texture);
			UnloadTexture(soundButtom.texturePressed);
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
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, musicButtom.rec))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					muteMusic = !muteMusic;
				}
			}
			
			if (muteMusic == false)
			{
				DrawTexture(musicButtom.texture, static_cast<int>(musicButtom.rec.x), static_cast<int>(musicButtom.rec.y), GRAY);
			}
			else
			{
				DrawTexture(musicButtom.texturePressed, static_cast<int>(musicButtom.rec.x), static_cast<int>(musicButtom.rec.y), RED);
			}
		}

		static void ButtomsMuteSound()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, soundButtom.rec))
			{
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					muteEffects = !muteEffects;
				}
			}

			if (muteEffects == false)
			{
				DrawTexture(soundButtom.texture, static_cast<int>(soundButtom.rec.x), static_cast<int>(soundButtom.rec.y), GRAY);
			}
			else
			{
				DrawTexture(soundButtom.texturePressed, static_cast<int>(soundButtom.rec.x), static_cast<int>(soundButtom.rec.y), RED);
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