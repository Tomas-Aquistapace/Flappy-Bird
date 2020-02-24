#include "menu_screen.h"

//#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Menu
	{
		SCENE scene;

		ARROW leftArrow;
		ARROW rightArrow;

		static Texture2D menuTittle;

		static const float FONT_PRESS_SPACE = 40.0f;
		static const float FONT_PRESS_ESCAPE = 35.0f;
		
		static const float HEIGHT = 100;
		static const float WIDTH = 80;

		static void InputMenu();
		static void DrawMenu();

		void Initialize()
		{
			Image menuTittleImage;
			Image arrowLeftImage;
			Image arrowLeftPressedImage;
			Image arrowRightImage;
			Image arrowRightPressedImage;

			scene = menu;

			leftArrow.rec.height = HEIGHT;
			leftArrow.rec.width = WIDTH;
			leftArrow.rec.x = static_cast<float>(GetScreenWidth() / 2 - GetScreenWidth() / 3 - WIDTH);
			leftArrow.rec.y = static_cast<float>(GetScreenHeight() / 2 + HEIGHT / 2);

			rightArrow.rec.height = HEIGHT;
			rightArrow.rec.width = WIDTH;
			rightArrow.rec.x = static_cast<float>(GetScreenWidth() / 2 + GetScreenWidth() / 3);
			rightArrow.rec.y = static_cast<float>(GetScreenHeight() / 2 + HEIGHT / 2);

			arrowLeftImage = LoadImage("assets/textures/menu/normal left arrow.png");
			arrowLeftPressedImage = LoadImage("assets/textures/menu/pressed left arrow.png");
			arrowRightImage = LoadImage("assets/textures/menu/normal right arrow.png");
			arrowRightPressedImage = LoadImage("assets/textures/menu/pressed right arrow.png");
			menuTittleImage = LoadImage("assets/textures/framework/frameworkTittle.png");

			ImageResize(&arrowLeftImage, static_cast<int>(leftArrow.rec.width), static_cast<int>(leftArrow.rec.height));
			ImageResize(&arrowLeftPressedImage, static_cast<int>(leftArrow.rec.width), static_cast<int>(leftArrow.rec.height));
			ImageResize(&arrowRightImage, static_cast<int>(rightArrow.rec.width), static_cast<int>(rightArrow.rec.height));
			ImageResize(&arrowRightPressedImage, static_cast<int>(rightArrow.rec.width), static_cast<int>(rightArrow.rec.height));
			leftArrow.menuArrows = LoadTextureFromImage(arrowLeftImage);
			leftArrow.menuArrowsPressed = LoadTextureFromImage(arrowLeftPressedImage);
			rightArrow.menuArrows = LoadTextureFromImage(arrowRightImage);
			rightArrow.menuArrowsPressed = LoadTextureFromImage(arrowRightPressedImage);
			menuTittle = LoadTextureFromImage(menuTittleImage);

			UnloadImage(arrowLeftImage);
			UnloadImage(arrowLeftPressedImage);
			UnloadImage(arrowRightImage);
			UnloadImage(arrowRightPressedImage);
			UnloadImage(menuTittleImage);
		}

		void Unload()
		{
			UnloadTexture(leftArrow.menuArrows);
			UnloadTexture(leftArrow.menuArrowsPressed);
			UnloadTexture(rightArrow.menuArrows);
			UnloadTexture(rightArrow.menuArrowsPressed);
			UnloadTexture(menuTittle);
		}

		void Menu()
		{
			InputMenu();
			Sounds::StateGameMusic(Sounds::update);
			DrawMenu();
		}

		void KeysLeftPressed(SCENE place)
		{
			if (IsKeyDown(KEY_LEFT) == true)
			{
				DrawTexture(leftArrow.menuArrowsPressed, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			}
			else
			{
				DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			}
			if (IsKeyReleased(KEY_LEFT) == true)
			{
				scene = place;
			}
		}

		void KeysRightPressed(SCENE place)
		{
			if (IsKeyDown(KEY_RIGHT) == true)
			{
				DrawTexture(rightArrow.menuArrowsPressed, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);
			}
			else
			{
				DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);
			}
			if (IsKeyReleased(KEY_RIGHT) == true)
			{
				scene = place;
			}
		}

		// ----------------------------

		static void InputMenu()
		{
			if (IsKeyPressed(KEY_SPACE) == true)
			{
				Player::ResetPlayer();
				Enemies::Reset();
				Sounds::StatePlayerMusic(Sounds::play);
				scene = game;
			}

			/*if (IsKeyPressed(KEY_LEFT) == true)
			{
				scenes = options;
			}

			if (IsKeyPressed(KEY_RIGHT) == true)
			{
				scenes = credits;
			}
*/
			if (IsKeyPressed(KEY_ESCAPE) == true)
			{
				scene = exit;
				Sounds::StateGameMusic(Sounds::stop);
			}
		}

		static void DrawMenu()
		{
			Vector2 text1Pos;
			Vector2 text2Pos;

			text1Pos.x = static_cast<float>(GetScreenWidth() / 2 - FONT_PRESS_SPACE * 2);
			text1Pos.y = static_cast<float>(leftArrow.rec.y);
			
			text2Pos.x = FONT_PRESS_ESCAPE;
			text2Pos.y = static_cast<float>(GetScreenHeight() - (FONT_PRESS_ESCAPE + FONT_PRESS_ESCAPE / 3));
			
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(menuTittle, GetScreenWidth() / 2 - menuTittle.width / 2, GetScreenHeight() / 2 - menuTittle.height, GRAY);

			DrawTextEx(Textures::textFont, "press SPACE\n      to JUMP", text1Pos, FONT_PRESS_SPACE, 2, WHITE);
			DrawTextEx(Textures::textFont, "press ESCAPE to EXIT", text2Pos, FONT_PRESS_ESCAPE, 2, DARKBLUE);

			KeysLeftPressed(options);
			KeysRightPressed(credits);

			//DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
			//DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);

			EndDrawing();
		}
	}
}