#include "../../include/engine.h"
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    int audioerror;

int startaudio(){
    // load WAV file
    SDL_LoadWAV("doom.wav", &wavSpec, &wavBuffer, &wavLength);

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    // play audio
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (success == 0) {
        audioerror = 1;
    } 
    SDL_PauseAudioDevice(deviceId, 0);

}

