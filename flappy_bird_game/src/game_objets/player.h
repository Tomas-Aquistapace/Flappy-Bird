#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Player
	{
		enum WIN_OR_LOSE 
		{
			win, lose, inGame
		};
		enum JUMP
		{
			jumping, falling
		};

		struct PLAYER 
		{
			Vector2 position;
			float radius;

			JUMP state;
			float force;
			int points;
			int maxPoints;
			bool exitGame;
			WIN_OR_LOSE winOrLose;
			int skinSelected;
			int maxSkins;
			Texture2D spriteMovement1;
			Texture2D spriteMovement2;
			Texture2D spriteJump1;
			Texture2D spriteJump2;
		};

		extern Texture2D frameworkSkin1;
		extern Texture2D frameworkSkin2;

		extern PLAYER player;
		extern bool pause;
		
		extern void Initialize();
		extern void Reset();
		extern void Unload();
		extern void Input(Rectangle pauseButtom, Rectangle menuButtom);
		extern void LoseOrWin();
		extern void EarnPoint();
		extern void DrawPlayer();
	}
}

#endif // PLAYER_H

