#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "raylib.h"

namespace Spooky_Ghost
{
	namespace Menu
	{
		enum SCENE 
		{
			game, exit, menu, options, credits, endGame
		};

		struct BUTTOM
		{
			Rectangle rec;
			Texture2D texture;
			Texture2D texturePressed;
		};

		struct ARROW
		{
			Rectangle rec;
			Texture2D menuArrows;
			Texture2D menuArrowsPressed;
		};

		extern SCENE scene;
		extern ARROW leftArrow;
		extern ARROW rightArrow;

		extern void Initialize();
		extern void Unload();
		extern void Menu();
		extern void KeysLeftPressed(SCENE place);
		extern void KeysRightPressed(SCENE place);
	}
}

#endif // !MENU_SCREEN_H

