#include "credits_screen.h"

#include "raylib.h"

#include "menu_screen.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	namespace Credits
	{
		static int fontTittle = 50;
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
			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 6, 400, 95, DARKGRAY);
			DrawText("Credits", GetScreenWidth() / 2 - 100, GetScreenHeight() / 5, fontTittle, GREEN);

			DrawRectangle(GetScreenWidth() / 2 - 175, GetScreenHeight() / 2 - 100, 350, 300, GRAY);
			DrawText("Main programer: Tomas Aquistapace\nMain artist: Joaquin\n\nMusic:\n Halloween Fun - by pinkzebra\n We all gonna die - by Loyalty_Freak_Music", (GetScreenWidth() / 2 - 175) + (350 / 2) - (MeasureText("Main programer: Tomas Aquistapace\nMain artist: Joaquin\n\nMusic:\n Halloween Fun - by pinkzebra\n We all gonna die - by Loyalty_Freak_Music", fontSubTittle) / 2), 300, fontSubTittle, WHITE);

			DrawTexture(Textures::menuArrows, static_cast<int>(Menu::leftArrow.rec.x), static_cast<int>(Menu::leftArrow.rec.y), GRAY);
			
			EndDrawing();
		}
	}
}