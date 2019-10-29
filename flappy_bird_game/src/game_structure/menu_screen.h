#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

namespace Flappy_Bird
{
	enum STATE {
		game, exit, menu, options, credits, endGame
	};

	extern STATE scenes;

	void InitialiceMenu();
	void InputMenu();
	void DrawMenu();
}

#endif // !MENU_SCREEN_H

