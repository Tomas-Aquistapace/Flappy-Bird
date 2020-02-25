#include "flow_of_game.h"

#include "raylib.h"

#include "menu_screen.h"
#include "credits_screen.h"
#include "options_screen.h"
#include "game_screen.h"
#include "end_game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"
#include "assets_code/sounds.h"

namespace Flappy_Bird
{
	static void InitialiceAll();
	static void UnloadAll();

	void FlowOfGame()
	{
		InitialiceAll();

		while (!WindowShouldClose() && Player::player.exitGame != true)
		{
			switch (Menu::scene)
			{
			case Menu::menu:
				Menu::Menu();
				break;

			case Menu::game:
				Game::Game();
				break;

			case Menu::options:
				Options::Options();
				break;

			case Menu::credits:
				Credits::Credits();
				break;

			case Menu::endGame:
				End_game::EndGame();
				break;

			case Menu::exit:
				Player::player.exitGame = true;
				break;
			}
		}
		UnloadAll();
	}
	
	// -----------------------------	
	
	static void InitialiceAll()
	{
		const int SCREENWIDTH = 600;
		const int SCREENHEIGHT = 600;

		InitWindow(SCREENWIDTH, SCREENHEIGHT, "Flappy Flame - Tomas Aquistapace");
		//HideCursor();

		SetExitKey(KEY_BACK);

		Player::Initialize();
		Enemies::Initialize();

		Menu::Initialize();
		Options::Initialize();
		Credits::Initialize();
		End_game::Initialize();
		Textures::LoadTextures();

		Sounds::LoadMusic_Sound();

		SetTargetFPS(60);
	}

	static void UnloadAll()
	{
		Player::Unload();
		Enemies::Unload();

		Menu::Unload();
		Options::Unload();
		Credits::Unload();
		End_game::Unload();
		Textures::UnloadTextures();

		Sounds::UnloadMusic_Sound();
	}
}