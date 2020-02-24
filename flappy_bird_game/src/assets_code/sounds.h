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
		extern Sound screamSkull;

		extern void LoadMusic_Sound();
		extern void SetEffectsVolume(bool mute);
		extern void SetMusicVolume(bool mute);
		extern void StateGameMusic(STATE states);
		extern void StateEndMusic(STATE states);
		extern void StatePlayerMusic(STATE states);
		extern void UnloadMusic_Sound();
	}
}

#endif //SOUNDS_H