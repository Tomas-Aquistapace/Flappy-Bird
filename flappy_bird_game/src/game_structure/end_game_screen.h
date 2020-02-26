#ifndef END_GAME_SCREEN_H
#define END_GAME_SCREEN_H

#include "raylib.h"

namespace Spooky_Ghost
{
	namespace End_game
	{
		struct BUTTOM
		{
			Rectangle rec;
			Texture2D texture;
			Texture2D texturePressed;
		};

		extern void Initialize();
		extern void Unload();
		extern void EndGame();
	}
}

#endif // !END_GAME_SCREEN_H