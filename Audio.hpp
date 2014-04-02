
#ifndef _AUDIO_HPP_
#define _AUDIO_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>

#include <cmath>

class Audio
{
	public:
		Audio(double ** data_, int channels, int length);
		Audio(char * filename);
		int channels;
		int length;
		double ** data;
};

#endif