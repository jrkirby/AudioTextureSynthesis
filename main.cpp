
#define WINDOW_SIZE 1024
#define SYNTHESIS_SIZE 2000
#include "Audio.hpp"
#include "AudioWindow.hpp"
#include "FreqVector.hpp"
#include "Neighbors.hpp"
#include <vector>

int main()
{
	Audio sample = Audio((char *)"test.flac");
	int num_windows = (sample.length / WINDOW_SIZE);
	AudioWindow * windows = (AudioWindow *) malloc(sizeof(AudioWindow) * num_windows);
	FreqVector * vectors = (FreqVector *) malloc(sizeof(FreqVector) * num_windows);

	Neighbors knn = Neighbors();

	for( int i = 0; i < num_windows; i++ )
	{
		windows[i] = AudioWindow(&sample, i * WINDOW_SIZE, WINDOW_SIZE);
		vectors[i] = FreqVector(&(windows[i]));
		knn.AddVector(vectors[i]);
	}

	int random_window = 0;
	double * synthesis = (double *) malloc(sizeof(double) * SYNTHESIS_SIZE);

	memcpy((void *)synthesis, windows[random_window].audio->data, WINDOW_SIZE);

	Audio synthesis_audio = Audio(&synthesis, 1, SYNTHESIS_SIZE);

	for(int i = 0; i < SYNTHESIS_SIZE - WINDOW_SIZE; i++)
	{
		AudioWindow synthesis_window = AudioWindow(&synthesis_audio, i, WINDOW_SIZE);
		FreqVector query_vector = FreqVector(&synthesis_window);
		vector<FreqVector> nearest_neighbors = knn.KNN(query_vector, 4);
		printf("Testing: %f\n", nearest_neighbors[3].data[0]);

	}
}