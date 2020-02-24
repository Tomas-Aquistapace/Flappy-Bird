#include "sounds.h"

namespace Flappy_Bird
{
	namespace Sounds
	{
		STATE state;

		Sound jump;
		Sound die_sound;
		Sound screamSkull;

		static Music gameMusic;
		static Music endMusic;
		static Music player_flames;

		void LoadMusic_Sound()
		{
			InitAudioDevice();

			gameMusic = LoadMusicStream("assets/sounds/music/halloween-fun_by_pinkzebra.ogg");
			endMusic = LoadMusicStream("assets/sounds/music/Loyalty_Freak_Music_-_We_all_gonna_die.ogg");
			player_flames = LoadMusicStream("assets/sounds/player_sounds/player_flames.ogg");
			
			jump = LoadSound("assets/sounds/player_sounds/jump.ogg");
			die_sound = LoadSound("assets/sounds/player_sounds/lose.ogg");
			screamSkull = LoadSound("assets/sounds/enemies/SCREAM_4.ogg");

			PlayMusicStream(gameMusic);
		}

		void SetEffectsVolume(bool mute)
		{
			if (mute == true)
			{
				PauseMusicStream(player_flames);
				SetMusicVolume(player_flames, 0.0f);

				SetSoundVolume(jump, 0.0f);
				SetSoundVolume(die_sound, 0.0f);
				SetSoundVolume(screamSkull, 0.0f);
			}
			else
			{
				ResumeMusicStream(player_flames);
				SetMusicVolume(player_flames, 1.0f);

				SetSoundVolume(jump, 1.0f);
				SetSoundVolume(die_sound, 1.0f);
				SetSoundVolume(screamSkull, 1.0f);
			}
		}
		
		void SetMusicVolume(bool mute)
		{
			if (mute == true)
			{
				PauseMusicStream(gameMusic);

				SetMusicVolume(gameMusic, 0.0f);
				SetMusicVolume(endMusic, 0.0f);
			}
			else
			{
				ResumeMusicStream(gameMusic);

				SetMusicVolume(gameMusic, 1.0f);
				SetMusicVolume(endMusic, 1.0f);
			}
		}


		void StateGameMusic(STATE states)
		{
			switch (states)
			{
			case stop:
				StopMusicStream(gameMusic);
				break;
			case play:
				PlayMusicStream(gameMusic);
				break;
			case update:
				UpdateMusicStream(gameMusic);
				break;
			}
		}

		void StateEndMusic(STATE states)
		{
			switch (states)
			{
			case stop:
				StopMusicStream(endMusic);
				break;
			case play:
				PlayMusicStream(endMusic);
				break;
			case update:
				UpdateMusicStream(endMusic);
				break;
			}
		}

		void StatePlayerMusic(STATE states)
		{
			switch (states)
			{
			case stop:
				StopMusicStream(player_flames);
				break;
			case play:
				PlayMusicStream(player_flames);
				break;
			case update:
				UpdateMusicStream(player_flames);
				break;
			}
		}

		void UnloadMusic_Sound()
		{
			UnloadMusicStream(gameMusic);
			UnloadMusicStream(endMusic);
			UnloadMusicStream(player_flames);
			UnloadSound(jump);
			UnloadSound(die_sound);
			UnloadSound(screamSkull);

			CloseAudioDevice();
		}
	}
}