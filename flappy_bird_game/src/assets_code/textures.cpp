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

		Texture2D walls;
		Texture2D menuArrows;
		Texture2D menuTittle;
		Texture2D credits;
		Texture2D creditsTittle;
		Texture2D optionsTittle;
		Texture2D optionsEffects;
		Texture2D raylibCredits;

		Font tittleFont;
		Font textFont;

		void LoadTextures()
		{
			//--------------
			// Textures various

			Image wallsImage;
			Image arrowImage;
			Image menuTittleImage;
			Image creditsImage;
			Image optionsImage;

			wallsImage = LoadImage("assets/textures/objects/wall.png");
			arrowImage = LoadImage("assets/textures/menu/arrow.png");
			menuTittleImage = LoadImage("assets/textures/framework/frameworkTittle.png");
			creditsImage = LoadImage("assets/textures/framework/frameworkCredits.png");
			creditsTittle = LoadTexture("assets/textures/framework/frameworkCreditsTittle.png");
			optionsTittle = LoadTexture("assets/textures/framework/frameworkOptionsTittle.png");
			optionsImage = LoadImage("assets/textures/framework/framework.png");
			raylibCredits = LoadTexture("assets/textures/credits/raylib_48x48.png");

			ImageResize(&arrowImage, static_cast<int>(Menu::leftArrow.rec.width), static_cast<int>(Menu::leftArrow.rec.height));
			ImageResize(&creditsImage, 350, 300);
			ImageResize(&optionsImage, 100, 100);

			walls = LoadTextureFromImage(wallsImage);
			menuArrows = LoadTextureFromImage(arrowImage);
			menuTittle = LoadTextureFromImage(menuTittleImage);
			credits = LoadTextureFromImage(creditsImage);
			optionsEffects = LoadTextureFromImage(optionsImage);

			//--------------
			// Background

			trees_layer_1 = LoadTexture("assets/textures/scenarios/trees_layer_1.png");
			mist = LoadTexture("assets/textures/scenarios/mist.png");
			trees_layer_2 = LoadTexture("assets/textures/scenarios/trees_layer_2.png");
			trees_layer_3 = LoadTexture("assets/textures/scenarios/trees_layer_3.png");
			floor = LoadTexture("assets/textures/scenarios/floor.png");
			stars = LoadTexture("assets/textures/scenarios/stars.png");
			moon = LoadTexture("assets/textures/scenarios/moon.png");
			base = LoadTexture("assets/textures/scenarios/base.png");

			//--------------
			// Fonts

			tittleFont = LoadFontEx("assets/font/dark_power.ttf", 300, 0, 240);
			textFont = LoadFontEx("assets/font/enchanted_land.otf", 300, 0, 240);

			// -------------

			UnloadImage(wallsImage);
			UnloadImage(arrowImage);
			UnloadImage(menuTittleImage);
			UnloadImage(creditsImage);
			UnloadImage(optionsImage);
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

			UnloadTexture(Player_Things::player.spriteMovement);
			UnloadTexture(Player_Things::player.spriteJump);
			UnloadTexture(walls);
			UnloadTexture(menuArrows);
			UnloadTexture(menuTittle);
			UnloadTexture(credits);
			UnloadTexture(creditsTittle);
			UnloadTexture(optionsTittle);
			UnloadTexture(optionsEffects);
			UnloadTexture(raylibCredits);

			UnloadFont(tittleFont);
			UnloadFont(textFont);
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