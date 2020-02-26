#ifndef OPTIONS_SCREEN_H
#define OPTIONS_SCREEN_H

#include "raylib.h"

namespace Spooky_Ghost
{
	namespace Options
	{
		struct BUTTOM
		{
			Rectangle rec;
			Texture2D texture;
			Texture2D texturePressed;
		};

		extern void Initialize();
		extern void Unload();
		extern void Options();
	}
}

#endif // !OPTIONS_SCREEN_H