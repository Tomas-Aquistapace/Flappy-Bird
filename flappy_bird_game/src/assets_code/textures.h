#ifndef TEXTURES_H
#define TEXTURES_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Textures
	{
		//extern Texture2D player;
		extern Texture2D stageBackground;
		extern Texture2D background;
		extern Texture2D midground;
		extern Texture2D foreground;

		void InitialiceTextures();
		void UnloadTextures();
		void MovementBackgrounds();
		void DrawBackground();
	}
}

#endif // !TEXTURES_H
