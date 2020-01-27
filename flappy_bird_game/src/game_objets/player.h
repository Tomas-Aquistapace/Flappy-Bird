#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Player_Things
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
			bool exitGame;
			WIN_OR_LOSE winOrLose;
		};

		extern PLAYER player;
		extern bool pause;

		void InitialicePlayer();
		void Input();
		void LoseOrWin();
		void EarnPoint();
		void DrawPlayer();
	}
}

#endif // PLAYER_H

