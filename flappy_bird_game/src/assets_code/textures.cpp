#include "textures.h"

#include "game_objets/player.h"
#include "game_structure/menu_screen.h"

namespace Flappy_Bird
{
	namespace Textures
	{
		static float scrollingStage = 0.0f;
		static float scrollingBack = 0.0f;
		static float scrollingMid = 0.0f;
		static float scrollingFore = 0.0f;

		Image playerImage;
		Image wallsImage;
		Image arrowImage;
		Image menuTittleImage;

		Texture2D stageBackground;
		Texture2D background;
		Texture2D midground;
		Texture2D foreground;
		Texture2D player;
		Texture2D walls;
		Texture2D menuArrows;
		Texture2D menuTittle;

		void LoadTextures()
		{
			stageBackground = LoadTexture("assets/scenarios/stageBackground.png");
			background = LoadTexture("assets/scenarios/background.png");
			midground = LoadTexture("assets/scenarios/midground.png");
			foreground = LoadTexture("assets/scenarios/foreground.png");
			playerImage = LoadImage("assets/objects/player.png");
			wallsImage = LoadImage("assets/objects/wall.png");
			arrowImage = LoadImage("assets/menu/arrow.png");

			menuTittleImage = LoadImage("assets/menu/framework.png");


			ImageResize(&playerImage, static_cast<int>(Player_Things::player.radius) * 2, static_cast<int>(Player_Things::player.radius) * 2);
			ImageResize(&arrowImage, static_cast<int>(Menu::leftArrow.rec.width), static_cast<int>(Menu::leftArrow.rec.height));
			ImageResize(&menuTittleImage, 500, 100);

			player = LoadTextureFromImage(playerImage);
			walls = LoadTextureFromImage(wallsImage);
			menuArrows = LoadTextureFromImage(arrowImage);
			menuTittle = LoadTextureFromImage(menuTittleImage);

			UnloadImage(playerImage);
			UnloadImage(wallsImage);
			UnloadImage(arrowImage);
			UnloadImage(menuTittleImage);
		}

		void UnloadTextures()
		{
			UnloadTexture(stageBackground);
			UnloadTexture(background);
			UnloadTexture(midground);
			UnloadTexture(foreground);
			UnloadTexture(player);
			UnloadTexture(walls);
			UnloadTexture(menuArrows);
			UnloadTexture(menuTittle);
		}

		void MovementBackgrounds()
		{
			scrollingStage -= 10.0f * GetFrameTime();
			scrollingBack -= 25.0f * GetFrameTime();
			scrollingMid -= 75.0f * GetFrameTime();
			scrollingFore -= 150.0f * GetFrameTime();

			if (scrollingStage <= -stageBackground.width)
				scrollingStage = 0.0f;
			if (scrollingBack <= -background.width)
				scrollingBack = 0.0f;
			if (scrollingMid <= -midground.width)
				scrollingMid = 0.0f;
			if (scrollingFore <= -foreground.width)
				scrollingFore = 0.0f;
		}

		void DrawBackground()
		{
			DrawTextureV(stageBackground, Vector2{ scrollingStage, 0 }, WHITE);
			DrawTextureV(stageBackground, Vector2{ stageBackground.width + scrollingStage, 0 }, WHITE);

			DrawTextureV(background, Vector2{ scrollingBack, -80 }, WHITE);
			DrawTextureV(background, Vector2{ background.width + scrollingBack, -80 }, WHITE);

			DrawTextureV(midground, Vector2{ scrollingMid, -60 }, WHITE);
			DrawTextureV(midground, Vector2{ midground.width + scrollingMid, -60 }, WHITE);

			DrawTextureV(foreground, Vector2{ scrollingFore, -90 }, WHITE);
			DrawTextureV(foreground, Vector2{ foreground.width + scrollingFore, -90 }, WHITE);
		}
	}
}