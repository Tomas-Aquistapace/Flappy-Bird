#include "game_screen.h"

#include "raylib.h"

#include "game_objets/player.h"
#include "game_objets/enemies.h"

namespace Flappy_Bird
{
	int screenWidth = 600;
	int screenHeight = 600;

	static short fontTitle = 40;
	static short fontSubTittle = 30;
	static short font = 20;

	void DrawGame()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, GREEN);
		DrawUI();

		DrawRectangleRec(pipes.objet, RED);

		if (pause == true)
		{
			DrawText("PAUSE", GetScreenWidth() / 2 - fontSubTittle, GetScreenHeight() / 2, fontSubTittle, WHITE);
		}

		EndDrawing();
	}
}