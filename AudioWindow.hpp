
#ifndef _AUDIOWINDOW_HPP_
#define _AUDIOWINDOW_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>

#include <cmath>
#include "Audio.hpp"

class AudioWindow
{
	public:
		AudioWindow(Audio * audio_, int start_, int size_);
		int start;
		int size;
		Audio * audio;
};

#endif