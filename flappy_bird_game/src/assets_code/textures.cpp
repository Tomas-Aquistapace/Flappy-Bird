#include "textures.h"

#include "game_objets/player.h"

namespace Flappy_Bird
{
	namespace Textures
	{	
		Font tittleFont;
		Font textFont;

		static float scrolling_floor = 0.0f;
		static float scrolling_trees_layer_1 = 0.0f;
		static float scrolling_mist = 0.0f;
		static float scrolling_trees_layer_2 = 0.0f;
		static float scrolling_trees_layer_3 = 0.0f;
		static float scrolling_trees_layer_4 = 0.0f;
		static float scrolling_stars = 0.0f;

		static Texture2D trees_layer_1;
		static Texture2D mist;
		static Texture2D trees_layer_2;
		static Texture2D trees_layer_3;
		static Texture2D trees_layer_4;
		static Texture2D floor;
		static Texture2D stars;
		static Texture2D moon;
		static Texture2D base;

		void LoadTextures()
		{
			//--------------
			// Background

			trees_layer_1 = LoadTexture("assets/textures/scenarios/trees_layer_1.png");
			mist = LoadTexture("assets/textures/scenarios/mist.png");
			trees_layer_2 = LoadTexture("assets/textures/scenarios/trees_layer_2.png");
			trees_layer_3 = LoadTexture("assets/textures/scenarios/trees_layer_3.png");
			trees_layer_4 = LoadTexture("assets/textures/scenarios/trees_layer_4.png");
			floor = LoadTexture("assets/textures/scenarios/floor.png");
			stars = LoadTexture("assets/textures/scenarios/stars.png");
			moon = LoadTexture("assets/textures/scenarios/moon.png");
			base = LoadTexture("assets/textures/scenarios/base.png");

			//--------------
			// Fonts

			tittleFont = LoadFontEx("assets/font/dark_power.ttf", 300, 0, 240);
			textFont = LoadFontEx("assets/font/enchanted_land.otf", 300, 0, 240);
		}

		void UnloadTextures()
		{
			UnloadTexture(trees_layer_1);
			UnloadTexture(mist);
			UnloadTexture(trees_layer_2);
			UnloadTexture(trees_layer_3);
			UnloadTexture(trees_layer_4);
			UnloadTexture(floor);
			UnloadTexture(stars);
			UnloadTexture(moon);
			UnloadTexture(base);

			UnloadFont(tittleFont);
			UnloadFont(textFont);
		}

		void MovementBackgrounds()
		{
			if (Player::pause != true)
			{
				scrolling_stars -= 15.0f * GetFrameTime();
				scrolling_trees_layer_4 -= 35.0f * GetFrameTime();
				scrolling_trees_layer_3 -= 60.0f * GetFrameTime();
				scrolling_trees_layer_2 -= 110.0f * GetFrameTime();
				scrolling_mist -= 80.0f * GetFrameTime();
				scrolling_trees_layer_1 -= 120.0f * GetFrameTime();
				scrolling_floor -= 120.0f * GetFrameTime();
			}

			if (scrolling_stars <= -stars.width)
				scrolling_stars = 0.0f;
			if (scrolling_trees_layer_4 <= -trees_layer_4.width)
				scrolling_trees_layer_4 = 0.0f;
			if (scrolling_trees_layer_3 <= -trees_layer_3.width)
				scrolling_trees_layer_3 = 0.0f;
			if (scrolling_trees_layer_2 <= -trees_layer_2.width)
				scrolling_trees_layer_2 = 0.0f;
			if (scrolling_mist <= -mist.width)
				scrolling_mist = 0.0f;
			if (scrolling_trees_layer_1 <= -trees_layer_1.width)
				scrolling_trees_layer_1 = 0.0f;
			if (scrolling_floor <= -floor.width)
				scrolling_floor = 0.0f;
		}

		void DrawBackground()
		{
			float positionY = 100;

			DrawTextureV(base, Vector2{ 0, 0 }, WHITE);
			
			DrawTextureV(moon, Vector2{ static_cast<float>(moon.width / -3), 0 }, WHITE);

			DrawTextureV(stars, Vector2{ scrolling_stars, 0 }, WHITE);
			DrawTextureV(stars, Vector2{ stars.width + scrolling_stars, 0 }, WHITE);
			
			DrawTextureV(trees_layer_4, Vector2{ scrolling_trees_layer_4, positionY }, WHITE);
			DrawTextureV(trees_layer_4, Vector2{ trees_layer_4.width + scrolling_trees_layer_4, positionY }, WHITE);
			
			DrawTextureV(trees_layer_3, Vector2{ scrolling_trees_layer_3, positionY }, WHITE);
			DrawTextureV(trees_layer_3, Vector2{ trees_layer_3.width + scrolling_trees_layer_3, positionY }, WHITE);
			
			DrawTextureV(trees_layer_2, Vector2{ scrolling_trees_layer_2, positionY }, WHITE);
			DrawTextureV(trees_layer_2, Vector2{ trees_layer_2.width + scrolling_trees_layer_2, positionY }, WHITE);
			
			DrawTextureV(mist, Vector2{ scrolling_mist, positionY }, WHITE);
			DrawTextureV(mist, Vector2{ mist.width + scrolling_mist, positionY }, WHITE);

			DrawTextureV(trees_layer_1, Vector2{ scrolling_trees_layer_1, positionY }, WHITE);
			DrawTextureV(trees_layer_1, Vector2{ trees_layer_1.width + scrolling_trees_layer_1, positionY }, WHITE);

			DrawTextureV(floor, Vector2{ scrolling_floor, positionY }, WHITE);
			DrawTextureV(floor, Vector2{ floor.width + scrolling_floor, positionY }, WHITE);
		}
	}
}