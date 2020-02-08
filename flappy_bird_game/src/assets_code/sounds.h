#ifndef SOUNDS_H
#define SOUNDS_H

#include "raylib.h"

namespace Flappy_Bird
{
	namespace Sounds
	{
		enum STATE
		{
			stop, play, update
		};

		extern STATE state;
		
		extern Sound jump;
		extern Sound die_sound;

		void LoadMusic_Sound();
		void SetEffectsVolume(bool mute);
		void SetMusicVolume(bool mute);
		void StateGameMusic(STATE states);
		void StateEndMusic(STATE states);
		void StatePlayerMusic(STATE states);
		void UnloadMusic_Sound();
	}
}

#endif //SOUNDS_H