#ifndef AUDIO_CONTROLLER_H
#define AUDIO_CONTROLLER_H

#include <vector>

#include <raylib.h>

namespace RayEngine {

    namespace Audio {

        class AudioController {
        private:
            std::vector<Sound> soundFxs;
            std::vector<Music> musics;

            int currentMusicIndex = -1;
        
        public:
            AudioController();
            AudioController(const AudioController &other) = delete; // Disable copy constructor

            virtual ~AudioController();

            void loadSoundFx(const char *path);
            void loadMusic(const char *path, bool loop = false);

            void playFx(int fxIndex);

            void playMusic(int musicIndex);
            void pauseMusic();
            void stopMusic();

            void clearAudio();
        };

    }

}

#endif