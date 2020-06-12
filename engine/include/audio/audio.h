#pragma once
#define AUDIO_H

int audioerror;
int startaudio();

SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8 *wavBuffer;