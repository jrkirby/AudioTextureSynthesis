

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>
#include "FreqVector.hpp"
#include "Neighbors.hpp"
#include <vector>

#include <cmath>

Neighbors::Neighbors(){}

void Neighbors::AddVector(FreqVector new_vector)
{
	vectors.push_back(new_vector);
}

//this is a really naive approach
//maybe I'll make it faster later
vector<FreqVector> Neighbors::KNN(FreqVector query, int k)
{
	//sanity test:
	if(k > vectors.size())
	{
		printf("Need more vectors in Neighbors\n");
	}

	//allocate a bit of extra space so we don't have out of bounds accesses
	//just simplifies our loop later
	int * nearest_k_indicies = (int *) malloc(sizeof(int) * (k + 1));
	double * nearest_k_distances = (double *) malloc(sizeof(double) * (k + 1));
	for(int j = 0; j < k; j++)
	{
		nearest_k_distances[j] = 10000000000000000.0; 
		nearest_k_indicies[j] = -1;
	}
	
	for(int i = 0; i < vectors.size(); i++)
	{
		int dist = query.distance(vectors[i]);
		for(int j = 0; j < k; j++)
		{
			if(dist < nearest_k_distances[j])
			{
				//shift all the values back one
				//extra space makes this not go out of bounds
				for(int j2 = j; j2 < k; j2++)
				{
					nearest_k_distances[j2 + 1] = nearest_k_distances[j2];
					nearest_k_indicies[j2 + 1] = nearest_k_indicies[j2];
				}
				nearest_k_distances[j] = dist;
				nearest_k_indicies[j] = i;
			}
		}
	}

	vector<FreqVector> k_nearest_neighbors;
	for(int j = 0; j < k; j++)
	{
		k_nearest_neighbors.push_back(vectors[nearest_k_indicies[j]]);
	}
	return k_nearest_neighbors;
}