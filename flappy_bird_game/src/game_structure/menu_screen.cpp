#include "menu_screen.h"

#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Spooky_Ghost
{
	namespace Menu
	{
		SCENE scene;

		ARROW leftArrow;
		ARROW rightArrow;

		static BUTTOM playButtom;
		static BUTTOM exitButtom;

		static Texture2D menuTittle;

		static const int MOUSERADIUS = 0;
		
		static const float FONT_VERSION = 30;

		static const float HEIGHT = 100;
		static const float WIDTH = 80;

		static void ButtomPlayPressed();
		static void ButtomExitPressed();
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

			// ------------------

			playButtom.rec.height = 100;
			playButtom.rec.width = 200;
			playButtom.rec.x = static_cast<float>(GetScreenWidth() / 2 - playButtom.rec.width / 2);
			playButtom.rec.y = static_cast<float>(GetScreenHeight() / 2 + playButtom.rec.height / 2);
			playButtom.texture = LoadTexture("assets/textures/buttoms/boton play.png");
			playButtom.texturePressed = LoadTexture("assets/textures/buttoms/boton play pressed.png");

			exitButtom.rec.height = 50;
			exitButtom.rec.width = 50;
			exitButtom.rec.x = exitButtom.rec.height;
			exitButtom.rec.y = static_cast<float>(GetScreenHeight() - (exitButtom.rec.height + exitButtom.rec.height / 2));
			exitButtom.texture = LoadTexture("assets/textures/buttoms/Boton exit.png");
			exitButtom.texturePressed = LoadTexture("assets/textures/buttoms/Boton exit pressed.png");

			// ------------------

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
			UnloadTexture(playButtom.texture);
			UnloadTexture(playButtom.texturePressed);
			UnloadTexture(exitButtom.texture);
			UnloadTexture(exitButtom.texturePressed);
		}

		void Menu()
		{
			Sounds::StateGameMusic(Sounds::update);
			DrawMenu();
		}

		void KeysLeftPressed(SCENE place)
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, leftArrow.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(leftArrow.menuArrowsPressed, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
				}
				else
				{
					DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), BLACK);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = place;
				}
			}
			else
			{
				DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), BLACK);
			}
		}

		void KeysRightPressed(SCENE place)
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, rightArrow.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(rightArrow.menuArrowsPressed, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);
				}
				else
				{
					DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), BLACK);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = place;
				}
			}
			else
			{
				DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), BLACK);
			}
		}

		// ----------------------------

		static void ButtomPlayPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, playButtom.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(playButtom.texturePressed, static_cast<int>(playButtom.rec.x), static_cast<int>(playButtom.rec.y), GRAY);
				}
				else
				{
					DrawTexture(playButtom.texture, static_cast<int>(playButtom.rec.x), static_cast<int>(playButtom.rec.y), BLACK);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					Player::Reset();
					Enemies::Reset();
					Sounds::StatePlayerMusic(Sounds::play);
					scene = game;
				}
			}
			else
			{
				DrawTexture(playButtom.texture, static_cast<int>(playButtom.rec.x), static_cast<int>(playButtom.rec.y), BLACK);
			}
		}

		static void ButtomExitPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, exitButtom.rec))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawTexture(exitButtom.texturePressed, static_cast<int>(exitButtom.rec.x), static_cast<int>(exitButtom.rec.y), RED);
				}
				else
				{
					DrawTexture(exitButtom.texture, static_cast<int>(exitButtom.rec.x), static_cast<int>(exitButtom.rec.y), MAROON);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = exit;
					Sounds::StateGameMusic(Sounds::stop);
				}
			}
			else
			{
				DrawTexture(exitButtom.texture, static_cast<int>(exitButtom.rec.x), static_cast<int>(exitButtom.rec.y), MAROON);
			}
		}

		static void DrawMenu()
		{			
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::DrawBackground();

			DrawTexture(menuTittle, GetScreenWidth() / 2 - menuTittle.width / 2, GetScreenHeight() / 2 - menuTittle.height, GRAY);

			KeysLeftPressed(options);
			KeysRightPressed(credits);
			ButtomPlayPressed();
			ButtomExitPressed();

			DrawTextEx(Textures::textFont, "v2.2", Vector2{ GetScreenWidth() - FONT_VERSION * 2, GetScreenHeight() - FONT_VERSION }, FONT_VERSION, 2, WHITE);

			EndDrawing();
		}
	}
}