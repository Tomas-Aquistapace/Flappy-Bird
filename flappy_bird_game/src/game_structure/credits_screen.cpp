#include "credits_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Credits
	{
		static float fontTittle = 80;
		static int fontSubTittle = 15;

		static void Input();
		static void Draw();

		void Credits()
		{
			Input();
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// ---------------------------

		static void Input()
		{
			if (IsKeyPressed(KEY_LEFT) == true)
			{
				Menu::scenes = Menu::menu;
			}
		}

		static void Draw()
		{
			Vector2 tittlePos;

			tittlePos.x = static_cast<float>(GetScreenWidth() / 2 - 100);
			tittlePos.y = static_cast<float>(GetScreenHeight() / 5 - 10);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(Textures::creditsTittle, GetScreenWidth() / 2 - Textures::creditsTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			DrawTexture(Textures::credits, GetScreenWidth() / 2 - Textures::credits.width / 2, GetScreenHeight() / 2 - Textures::credits.height / 3, GRAY);

			DrawTexture(Textures::raylibCredits, GetScreenWidth() - Textures::raylibCredits.width, GetScreenHeight() - Textures::raylibCredits.height, WHITE);
			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::leftArrow.rec.x), static_cast<int>(Menu::leftArrow.rec.y), GRAY);
			
			EndDrawing();
		}
	}
}