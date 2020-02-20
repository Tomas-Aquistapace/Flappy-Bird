#ifndef TEXTURES_H
#define TEXTURES_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Textures
	{
		extern Texture2D walls;
		extern Texture2D menuArrows;
		extern Texture2D menuTittle;
		extern Texture2D raylibCredits;

		extern Font tittleFont;
		extern Font textFont;

		void LoadTextures();
		void UnloadTextures();
		void MovementBackgrounds();
		void DrawBackground();
	}
}

#endif // !TEXTURES_H
