#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Menu
	{
		enum STATE 
		{
			game, exit, menu, options, credits, endGame
		};

		struct ARROW
		{
			Rectangle rec;
		};

		extern STATE scenes;
		extern ARROW leftArrow;
		extern ARROW rightArrow;

		extern Texture2D menuArrows;

		extern void Initialize();
		extern void Unload();
		extern void Menu();
	}
}

#endif // !MENU_SCREEN_H

