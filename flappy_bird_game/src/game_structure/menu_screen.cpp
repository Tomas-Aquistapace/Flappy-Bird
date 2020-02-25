#include "menu_screen.h"

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

		static Rectangle playButtom;
		static Rectangle exitButtom;

		static Texture2D menuTittle;

		static const int MOUSERADIUS = 0;
		
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

			playButtom.height = 100;
			playButtom.width = 200;
			playButtom.x = static_cast<float>(GetScreenWidth() / 2 - playButtom.width / 2);
			playButtom.y = static_cast<float>(GetScreenHeight() / 2 + playButtom.height / 2);

			exitButtom.height = 50;
			exitButtom.width = 50;
			exitButtom.x = exitButtom.height;
			exitButtom.y = static_cast<float>(GetScreenHeight() - (exitButtom.height + exitButtom.height / 2));

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
					DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = place;
				}
			}
			else
			{
				DrawTexture(leftArrow.menuArrows, static_cast<int>(leftArrow.rec.x), static_cast<int>(leftArrow.rec.y), GRAY);
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
					DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = place;
				}
			}
			else
			{
				DrawTexture(rightArrow.menuArrows, static_cast<int>(rightArrow.rec.x), static_cast<int>(rightArrow.rec.y), GRAY);
			}
		}

		// ----------------------------

		static void ButtomPlayPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, playButtom))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawRectangleRec(playButtom, DARKGRAY);
				}
				else
				{
					DrawRectangleRec(playButtom, GRAY);
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
				DrawRectangleRec(playButtom, GRAY);
			}
		}

		static void ButtomExitPressed()
		{
			if (CheckCollisionCircleRec(GetMousePosition(), MOUSERADIUS, exitButtom))
			{
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					DrawRectangleRec(exitButtom, RED);
				}
				else
				{
					DrawRectangleRec(exitButtom, MAROON);
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				{
					scene = exit;
					Sounds::StateGameMusic(Sounds::stop);
				}
			}
			else
			{
				DrawRectangleRec(exitButtom, MAROON);
			}
		}

		static void DrawMenu()
		{			
			BeginDrawing();
			ClearBackground(BLACK);

			//Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(menuTittle, GetScreenWidth() / 2 - menuTittle.width / 2, GetScreenHeight() / 2 - menuTittle.height, GRAY);

			KeysLeftPressed(options);
			KeysRightPressed(credits);
			ButtomPlayPressed();
			ButtomExitPressed();

			EndDrawing();
		}
	}
}