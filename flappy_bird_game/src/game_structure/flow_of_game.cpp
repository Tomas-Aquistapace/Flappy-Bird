#include "flow_of_game.h"

#include "raylib.h"

#include "menu_screen.h"
#include "credits_screen.h"
#include "options_screen.h"
#include "end_game_screen.h"
#include "initialice.h"
#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"
#include "assets_code/textures.h"

namespace Flappy_Bird
{
	void FlowOfGame()
	{
		InitialiceAll();

		while (!WindowShouldClose() && Player_Things::player.exitGame != true)
		{
			switch (Menu::scenes)
			{
			case Menu::menu:
				Menu::InputMenu();
				Menu::DrawMenu();
				break;

			case Menu::game:
				Player_Things::Input();
				if (Player_Things::pause == false)
				{
					Enemies::MovementEnemies();
					Player_Things::EarnPoint();
					Player_Things::LoseOrWin();
				}
				Game::DrawGame();
				break;

			case Menu::options:
				Options::Input();
				Options::DrawOptions();
				break;

			case Menu::credits:
				Credits::Input();
				Credits::DrawCredits();
				break;

			case Menu::endGame:
				End_game::Input();
				End_game::DrawEndGame();
				break;

			case Menu::exit:
				
				Player_Things::player.exitGame = true;
				break;
			}
		}
		Textures::UnloadTextures();
	}
}