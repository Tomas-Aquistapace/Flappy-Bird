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
			Rectangle body;
			JUMP state;
			float force;
			int points;
			int maxPoints;
			bool exitGame;
			WIN_OR_LOSE winOrLose;
			Texture2D spriteMovement;
			Texture2D spriteJump;
		};

		extern PLAYER player;
		extern bool pause;
		
		extern void Initialize();
		extern void ResetPlayer();
		extern void Unload();
		extern void Input();
		extern void LoseOrWin();
		extern void EarnPoint();
		extern void DrawPlayer();
	}
}

#endif // PLAYER_H

