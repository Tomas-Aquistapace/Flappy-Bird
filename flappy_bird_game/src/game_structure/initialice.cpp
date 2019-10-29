#include "initialice.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "game_structure/menu_screen.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	void InitialiceAll()
	{
		InitWindow(screenWidth, screenHeight, "Flappy Bird - Tomas Aquistapace");
		HideCursor();

		SetExitKey(KEY_BACK);

		Player_Things::InitialicePlayer();
		Textures::InitialiceTextures();
		Enemies::InitialiceEnemies();
		InitialiceMenu();

		SetTargetFPS(60);
	}

	void ResetValues()
	{
		Player_Things::InitialicePlayer();
		Enemies::InitialiceEnemies();
	}
}