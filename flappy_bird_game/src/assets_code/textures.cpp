#include "textures.h"

namespace Flappy_Bird
{
	namespace Textures
	{
		static float scrollingStage = 0.0f;
		static float scrollingBack = 0.0f;
		static float scrollingMid = 0.0f;
		static float scrollingFore = 0.0f;

		Texture2D stageBackground;
		Texture2D background;
		Texture2D midground;
		Texture2D foreground;

		void InitialiceTextures()
		{
			stageBackground = LoadTexture("assets/scenarios/stageBackground.png");
			background = LoadTexture("assets/scenarios/background.png");
			midground = LoadTexture("assets/scenarios/midground.png");
			foreground = LoadTexture("assets/scenarios/foreground.png");
		}

		void UnloadTextures()
		{
			UnloadTexture(stageBackground);
			UnloadTexture(background);
			UnloadTexture(midground);
			UnloadTexture(foreground);
		}

		void MovementBackgrounds()
		{
			scrollingStage -= 10.0f * GetFrameTime();
			scrollingBack -= 25.0f * GetFrameTime();
			scrollingMid -= 75.0f * GetFrameTime();
			scrollingFore -= 150.0f * GetFrameTime();

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