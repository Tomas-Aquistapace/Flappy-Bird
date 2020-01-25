#include "menu_screen.h"

#include "raylib.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	STATE scenes;

	static int fontTittle = 50;
	static int fontSubTittle = 20;

	void InitialiceMenu()
	{
		scenes = menu;
	}

	void InputMenu()
	{
		if (IsKeyPressed(KEY_SPACE) == true)
		{
			Player_Things::InitialicePlayer();
			scenes = game;
		}

		if (IsKeyPressed(KEY_LEFT) == true)
		{
			scenes = options;
		}

		if (IsKeyPressed(KEY_RIGHT) == true)
		{
			scenes = credits;
		}

		if (IsKeyPressed(KEY_ESCAPE) == true)
		{
			scenes = exit;
		}
	}

	void DrawMenu()
	{
		int TriangleWidth = 40;
		int TriangleHeight = 60;
		int leftTriangleX = GetScreenWidth() / 2 - GetScreenWidth() / 3 - TriangleWidth;
		int leftTriangleY = GetScreenHeight() / 2 + TriangleHeight / 2;

		int rightTriangleX = GetScreenWidth() / 2 + GetScreenWidth() / 3;
		int rightTriangleY = GetScreenHeight() / 2 + TriangleHeight / 2;

		Textures::MovementBackgrounds();

		BeginDrawing();
		ClearBackground(BLACK);

		Textures::DrawBackground();

		DrawText("FLAPPY FLAME", GetScreenWidth() / 2 - 150, GetScreenHeight() / 5, fontTittle, GREEN);
		DrawText("press SPACE", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 60, fontSubTittle, WHITE);

		DrawRectangle(leftTriangleX, leftTriangleY, TriangleWidth, TriangleHeight, BLUE);
		DrawRectangle(rightTriangleX, rightTriangleY, TriangleWidth, TriangleHeight, BLUE);

		EndDrawing();
	}
}