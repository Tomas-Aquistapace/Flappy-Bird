#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Menu
	{
		enum STATE {
			game, exit, menu, options, credits, endGame
		};

		struct ARROW
		{
			Rectangle rec;
		};

		extern STATE scenes;
		extern ARROW leftArrow;
		extern ARROW rightArrow;

		void InitialiceMenu();
		void Menu();
		//void InputMenu();
		//void DrawMenu();
	}
}

#endif // !MENU_SCREEN_H

