#ifndef TEXTURES_H
#define TEXTURES_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Textures
	{
		extern Font tittleFont;
		extern Font textFont;

		extern void LoadTextures();
		extern void UnloadTextures();
		extern void MovementBackgrounds();
		extern void DrawBackground();
	}
}

#endif // !TEXTURES_H
