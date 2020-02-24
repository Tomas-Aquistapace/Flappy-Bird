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

		Texture2D creditsTittle;
		Texture2D credits;
		Texture2D raylibCredits;

		static void Draw();

		void Initialize()
		{
			Image creditsImage;

			creditsTittle = LoadTexture("assets/textures/framework/frameworkCreditsTittle.png");
			raylibCredits = LoadTexture("assets/textures/credits/raylib_48x48.png");

			creditsImage = LoadImage("assets/textures/framework/frameworkCredits.png");
			ImageResize(&creditsImage, 350, 300);
			credits = LoadTextureFromImage(creditsImage);

			UnloadImage(creditsImage);
		}
		
		void Unload()
		{
			UnloadTexture(credits);
			UnloadTexture(creditsTittle);
			UnloadTexture(raylibCredits);
		}

		void Credits()
		{
			Sounds::StateGameMusic(Sounds::update);
			Draw();
		}

		// ---------------------------

		static void Draw()
		{
			Vector2 tittlePos;

			tittlePos.x = static_cast<float>(GetScreenWidth() / 2 - 100);
			tittlePos.y = static_cast<float>(GetScreenHeight() / 5 - 10);

			BeginDrawing();
			ClearBackground(BLACK);

			Textures::MovementBackgrounds();
			Textures::DrawBackground();

			DrawTexture(creditsTittle, GetScreenWidth() / 2 - creditsTittle.width / 2, GetScreenHeight() / 10, DARKGRAY);

			DrawTexture(credits, GetScreenWidth() / 2 - credits.width / 2, GetScreenHeight() / 2 - credits.height / 3, GRAY);

			DrawTexture(raylibCredits, GetScreenWidth() - raylibCredits.width, GetScreenHeight() - raylibCredits.height, WHITE);

			Menu::KeysLeftPressed(Menu::menu);
			
			EndDrawing();
		}
	}
}