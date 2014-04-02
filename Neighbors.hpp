

#ifndef _NEIGHBORS_HPP_
#define _NEIGHBORS_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sndfile.h>
#include "FreqVector.hpp"
#include <vector>

using namespace std;

//K nearest neighbors
class Neighbors
{
	public:
		Neighbors();
		void AddVector(FreqVector new_vector);
		vector<FreqVector> KNN(FreqVector compare, int );
	private:
		vector<FreqVector> vectors;
};

#endif