
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
		Audio(char * filename);
		float * create_buffer();
		int channels;
		int length;
		double ** data;
};

#endif