#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>

#include <cmath>
#include "AudioWindow.hpp"


AudioWindow::AudioWindow(Audio * audio_, int start_, int size_)
{
	audio = audio_;
	start = start_;
	size = size_;
}