#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "raylib.h"

namespace Spooky_Ghost
{
	namespace Game
	{
		struct BUTTOM
		{
			Rectangle rec;
			Texture2D texture;
			Texture2D texturePressed;
		};

		extern void Initialiaze();
		extern void Unload();
		extern void Game();
	}
}

#endif // !GAME_SCREEN_H

