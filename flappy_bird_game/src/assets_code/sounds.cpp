#include "sounds.h"

namespace Flappy_Bird
{
	namespace Sounds
	{
		//Music loopMusic;
		Music player_flames;
		Sound jump;
		Sound die_sound;

		void LoadMusic_Sound()
		{
			InitAudioDevice();

			//loopMusic = LoadMusicStream("assets/loop_songs/main_song.ogg");
			player_flames = LoadMusicStream("assets/sounds/player_sounds/player_flames.ogg");
			
			jump = LoadSound("assets/sounds/player_sounds/jump.ogg");
			die_sound = LoadSound("assets/sounds/player_sounds/lose.ogg");

			PlayMusicStream(player_flames);
		}

		/*void SetSoundsVolume(bool mute)
		{
			if (mute == true)
			{
				PauseMusicStream(player_flames);

				SetMusicVolume(player_flames, 0.0f);

				SetSoundVolume(jump, 0.0f);
				SetSoundVolume(die_sound, 0.0f);
			}
			else
			{
				ResumeMusicStream(player_flames);

				SetMusicVolume(player_flames, 1.0f);

				SetSoundVolume(jump, 1.0f);
				SetSoundVolume(die_sound, 1.0f);
			}
		}*/

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

		//void StateMenuMusic(STATE states)
		//{
		//	switch (states)
		//	{
		//	case stop:
		//		StopMusicStream(menuMusic);
		//		break;
		//	case play:
		//		PlayMusicStream(menuMusic);
		//		break;
		//	case update:
		//		UpdateMusicStream(menuMusic);
		//		break;
		//	}
		//}

		//void StateGameMusic(STATE states)
		//{
		//	switch (states)
		//	{
		//	case stop:
		//		StopMusicStream(gameMusic);
		//		break;
		//	case play:
		//		PlayMusicStream(gameMusic);
		//		break;
		//	case update:
		//		UpdateMusicStream(gameMusic);
		//		break;
		//	}
		//}

		//void StateWinMusic(STATE states)
		//{
		//	switch (states)
		//	{
		//	case stop:
		//		StopMusicStream(winMusic);
		//		break;
		//	case play:
		//		PlayMusicStream(winMusic);
		//		break;
		//	case update:
		//		UpdateMusicStream(winMusic);
		//		break;
		//	}
		//}

		void UnloadMusic_Sound()
		{
			UnloadMusicStream(player_flames);
			UnloadSound(jump);
			UnloadSound(die_sound);

			CloseAudioDevice();
		}

	}
}