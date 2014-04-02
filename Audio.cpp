

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>

#include <cmath>
#include "Audio.hpp"

#define BUFFER_LEN 1024

Audio::Audio(char * filename)
{
	int readcount;
	SNDFILE *infile;
	SF_INFO sfinfo;
	if (! (infile = sf_open(filename, SFM_READ, &sfinfo)))
	{
		/* Open failed so print an error message. */
		printf ("Not able to open input file %s.\n", filename) ;
		/* Print the error message fron libsndfile. */
		sf_perror (NULL) ;
		return;
	}

	channels = sfinfo.channels;
	data = (double **) malloc(sizeof(double *) * channels);
	double *  data_read = (double *) malloc(sizeof(double) * BUFFER_LEN * channels);

	int total_samples = 0;
	while ((readcount = sf_read_double (infile, data_read, BUFFER_LEN * channels)))
	{
		int samples_read = (readcount - (readcount % channels)) / channels;
		for(int chan = 0; chan < channels; chan++)
		{
			data[chan] = (double *) realloc(data[chan], total_samples + samples_read);
			for(int i = 0; i < samples_read; i++)
			{
				data[chan][i + total_samples] = data_read[i * channels + chan];
			}
		}
		total_samples += samples_read;
	}
	length = total_samples;
}

Audio::Audio(double ** data, int channels)
{}
