#include "DieRoller.h"

//TODO: write the rest of this file

DieRoller::DieRoller() {	
	std::random_device rd; 
	SeedRNG(rd()); //seeds the rng with a std::random_device
}

int DieRoller::RollDN(int N) {	
	std::uniform_int_distribution<unsigned int> die(1, N); //range[0,N] N is defined by main class
	return die(rng);
}

void DieRoller::SeedRNG(unsigned int seedVal) {		
	rng.seed(seedVal); //seeds the rng with the seedVal
}

int DieRoller::Roll4D6DropLowest() {
	int num = 0;
	int lowest = 20;
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		num = RollDN(6);		
		//testing if the result is the lowest
		if (num < lowest)
		{
			lowest = num;
		}
		sum += num; //sum results
	}
	sum -= lowest;//drops the lowest from the total
	return sum;
}