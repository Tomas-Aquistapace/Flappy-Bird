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
			switch (scenes)
			{
			case menu:

				InputMenu();
				Textures::MovementBackgrounds();
				DrawMenu();
				break;
			case game:

				Player_Things::Input();
				if (Player_Things::pause == false)
				{
					Textures::MovementBackgrounds();
					Enemies::MovementEnemies();
					Player_Things::EarnPoint();
					Player_Things::LoseOrWin();
				}

				DrawGame();

				break;
			case options:

				Options::Input();
				Options::DrawOptions();

				break;
			case credits:

				Credits::Input();
				Credits::DrawCredits();

				break;
			case endGame:

				End_game::Input();
				End_game::DrawEndGame();
				
				break;
			case exit:
				
				Player_Things::player.exitGame = true;

				break;
			}
		}
		Textures::UnloadTextures();
	}
}