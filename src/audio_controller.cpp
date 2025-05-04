#include "audio_controller.h"

namespace RayEngine::Audio {

    AudioController::AudioController() {}

    AudioController::~AudioController() {
        clearAudio();
    }

    void AudioController::loadSoundFx(const char *path) {
        soundFxs.push_back(LoadSound(path));
    }

    void AudioController::loadMusic(const char *path, bool loop) {
        musics.push_back(LoadMusicStream(path));
        musics.back().looping = loop;
    }

    void AudioController::playFx(int fxIndex) {
        if (fxIndex >= 0 && fxIndex < (int)soundFxs.size()) {
            PlaySound(soundFxs[fxIndex]);
        }
    }

    void AudioController::playMusic(int musicIndex) {
        if (musicIndex >= 0 && musicIndex < (int)musics.size()) {
            stopMusic();

            currentMusicIndex = musicIndex;
            PlayMusicStream(musics[currentMusicIndex]);
        }
    }

    void AudioController::pauseMusic() {
        if (currentMusicIndex != -1) {
            PauseMusicStream(musics[currentMusicIndex]);
        }
    }

    void AudioController::stopMusic() {
        if (currentMusicIndex != -1) {
            StopMusicStream(musics[currentMusicIndex]);
            currentMusicIndex = -1;
        }
    }

    void AudioController::clearAudio() {
        for (const Sound& s : soundFxs) { UnloadSound(s); }
        for (const Music& m : musics) { UnloadMusicStream(m); }

        soundFxs.clear();
        musics.clear();
    }

}