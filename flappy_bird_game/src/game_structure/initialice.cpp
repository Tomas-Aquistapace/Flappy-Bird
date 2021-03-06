#include "initialice.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "game_structure/menu_screen.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	int screenWidth = 600;
	int screenHeight = 600;

	void InitialiceAll()
	{
		InitWindow(screenWidth, screenHeight, "Flappy Bird - Tomas Aquistapace");
		HideCursor();

		SetExitKey(KEY_BACK);

		Menu::InitialiceMenu();
		Player_Things::InitialicePlayer();
		Enemies::InitialiceEnemies();
		Textures::LoadTextures();

		SetTargetFPS(60);
	}
}