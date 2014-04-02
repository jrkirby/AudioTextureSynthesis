
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fftw3.h>


#include "FreqVector.hpp"
#include "AudioWindow.hpp"
#include "Audio.hpp"

int FreqVector::inited = 0;
double * FreqVector::FFTW_IN;
double * FreqVector::FFTW_OUT;
int FreqVector::size;
fftw_plan FreqVector::plan_forward;

FreqVector::FreqVector(AudioWindow * source)
{
	if(!inited)
	{
		init(source);
	}
	else
	{
		if(source->size != size)
		{
			printf("Error: Can't use multiple window sizes yet. Fix in FreqVector.cpp\n");
		}
		int n = size;
		//put our data into FFTW's memory
		memcpy( FFTW_IN, source->audio->data[0], size * sizeof(double) );

		//run our plan on it
		fftw_execute ( plan_forward );

		//put the result into our data
		memcpy( data, FFTW_OUT, size * sizeof(double) );
	}

}

void FreqVector::init(AudioWindow * source)
{
	size = source->size;
	
	//Allocate our static arrays which will be used for all future DHTs
	FFTW_IN = (double *) fftw_malloc ( sizeof(double) * size );
	FFTW_OUT = (double *) fftw_malloc ( sizeof(double) * size );
	
	//put our first data into the input array
	memcpy( FFTW_IN, source->audio->data[0], size * sizeof(double) );
	
	//create the plan that FFTW uses. we reuse this plan every execution
	plan_forward = fftw_plan_r2r_1d ( size, FFTW_IN, FFTW_OUT, FFTW_DHT, FFTW_ESTIMATE );
	
	//run it for the first time
	fftw_execute ( plan_forward );

	//put the result into data
	memcpy( data, FFTW_OUT, size * sizeof(double) );

}

double FreqVector::distance(FreqVector other)
{
	int dist = 0;
	for(int i = 0; i < size; i++)
	{
		dist += (other.data[i] - data[i]) * (other.data[i] - data[i]);
	}
	return dist;
}