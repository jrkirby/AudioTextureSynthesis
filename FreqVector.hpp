
#ifndef _FREQVECTOR_HPP_
#define _FREQVECTOR_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>
#include <fftw3.h>

#include <cmath>
#include "AudioWindow.hpp"
#include "Audio.hpp"

class FreqVector
{
	public:
		FreqVector(AudioWindow * source);
		double distance(FreqVector other);
		double * data;

	private:
		void init(AudioWindow * source);
		static double * FFTW_IN;
		static double * FFTW_OUT;
		static int inited;
		static int size;
		static fftw_plan plan_forward;
};


#endif