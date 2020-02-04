#include "textures.h"

#include "game_objets/player.h"
#include "game_structure/menu_screen.h"

namespace Flappy_Bird
{
	namespace Textures
	{	
		static float scrolling_floor = 0.0f;
		static float scrolling_trees_layer_1 = 0.0f;
		static float scrolling_mist = 0.0f;
		static float scrolling_trees_layer_2 = 0.0f;
		static float scrolling_trees_layer_3 = 0.0f;
		static float scrolling_stars = 0.0f;

		Texture2D trees_layer_1;
		Texture2D mist;
		Texture2D trees_layer_2;
		Texture2D trees_layer_3;
		Texture2D floor;
		Texture2D stars;
		Texture2D moon;
		Texture2D base;

		Texture2D player;
		Texture2D walls;
		Texture2D menuArrows;
		Texture2D menuTittle;

		void LoadTextures()
		{
			Image playerImage;
			Image wallsImage;
			Image arrowImage;
			Image menuTittleImage;			
			
			playerImage = LoadImage("assets/objects/player.png");
			wallsImage = LoadImage("assets/objects/wall.png");
			arrowImage = LoadImage("assets/menu/arrow.png");

			menuTittleImage = LoadImage("assets/menu/framework.png");

			//--------------
			// Background

			trees_layer_1 = LoadTexture("assets/scenarios/trees_layer_1.png");
			mist = LoadTexture("assets/scenarios/mist.png");
			trees_layer_2 = LoadTexture("assets/scenarios/trees_layer_2.png");
			trees_layer_3 = LoadTexture("assets/scenarios/trees_layer_3.png");
			floor = LoadTexture("assets/scenarios/floor.png");
			stars = LoadTexture("assets/scenarios/stars.png");
			moon = LoadTexture("assets/scenarios/moon.png");
			base = LoadTexture("assets/scenarios/base.png");

			//--------------

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
			UnloadTexture(trees_layer_1);
			UnloadTexture(mist);
			UnloadTexture(trees_layer_2);
			UnloadTexture(trees_layer_3);
			UnloadTexture(floor);
			UnloadTexture(stars);
			UnloadTexture(moon);
			UnloadTexture(base);

			UnloadTexture(player);
			UnloadTexture(walls);
			UnloadTexture(menuArrows);
			UnloadTexture(menuTittle);
		}

		void MovementBackgrounds()
		{
			if (Player_Things::pause != true)
			{
				scrolling_stars -= 20.0f * GetFrameTime();
				scrolling_trees_layer_3 -= 25.0f * GetFrameTime();
				scrolling_trees_layer_2 -= 75.0f * GetFrameTime();
				scrolling_mist -= 80.0f * GetFrameTime();
				scrolling_trees_layer_1 -= 120.0f * GetFrameTime();
				scrolling_floor -= 120.0f * GetFrameTime();
			}

			if (scrolling_stars <= -stars.width)
				scrolling_stars = 0.0f;
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
			DrawTextureV(base, Vector2{ 0, 0 }, WHITE);
			
			DrawTextureV(moon, Vector2{ static_cast<float>(moon.width / -3), 0 }, WHITE);

			DrawTextureV(stars, Vector2{ scrolling_stars, 0 }, WHITE);
			DrawTextureV(stars, Vector2{ stars.width + scrolling_stars, 0 }, WHITE);
			
			DrawTextureV(trees_layer_3, Vector2{ scrolling_trees_layer_3, 100 }, WHITE);
			DrawTextureV(trees_layer_3, Vector2{ trees_layer_3.width + scrolling_trees_layer_3, 100 }, WHITE);
			
			DrawTextureV(trees_layer_2, Vector2{ scrolling_trees_layer_2, 100 }, WHITE);
			DrawTextureV(trees_layer_2, Vector2{ trees_layer_2.width + scrolling_trees_layer_2, 100 }, WHITE);
			
			DrawTextureV(mist, Vector2{ scrolling_mist, 100 }, WHITE);
			DrawTextureV(mist, Vector2{ mist.width + scrolling_mist, 100 }, WHITE);

			DrawTextureV(trees_layer_1, Vector2{ scrolling_trees_layer_1, 100 }, WHITE);
			DrawTextureV(trees_layer_1, Vector2{ trees_layer_1.width + scrolling_trees_layer_1, 100 }, WHITE);

			DrawTextureV(floor, Vector2{ scrolling_floor, 100 }, WHITE);
			DrawTextureV(floor, Vector2{ floor.width + scrolling_floor, 100 }, WHITE);
		}
	}
}