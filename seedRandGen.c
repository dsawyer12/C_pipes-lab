#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "api.h"

void seedRandGenerator(){
	time_t seed;

	seed = time(NULL);
	srand(seed);
	return;
}