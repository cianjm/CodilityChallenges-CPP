/*
	Took several hours to get right.

	https://codility.com/demo/results/trainingD4F8PD-2BG/
*/

#include <algorithm>

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
	
	vector<int> primes, semiprimes, result, spcounter;
	int primesize, j, primecount=0, tracker = 0;
	int startingposition;
	
	if (N <= 3) {
		for (int i = 0 ; i < (int) P.size() ; i++)
			result.push_back(0);
		return result;
	}

	// Create vector of numbers from 0 to N/2.	
	for (int i = 0 ; i <= N/2 ; i++) {
		primes.push_back(i);
	}

	// Create vector of prime numbers.
	primesize = primes.size();
	for (int i = 2; i*i <= primesize ; i++) {
		startingposition = i*i;
		while (startingposition <= primesize ){
			primes[startingposition] = 0;
			startingposition += i;
		}
	}	
	primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());
	primes.erase(primes.begin());

	// Create vector of semiprimes
	for (int i = 0 ; primes[i] * primes[i] <= N ; i++) {
		j = i;
		while (primes[i] * primes[j] <= N && j < (int) primes.size()) {
			semiprimes.push_back(primes[i] * primes[j]);
			j++;
		}
	}
	
	// Create vector counting the number of semiprimes at any given position
	sort(semiprimes.begin(), semiprimes.end());
	for (int i = 0 ; i <= N ; i++) {
		if (i == semiprimes[tracker]) {
			primecount++;
			tracker++;
		}
		spcounter.push_back(primecount);
	}
	
	// Find the number of semiprimes between any two points
	for (int i = 0 ; i < (int) P.size() ; i++) {
		result.push_back( spcounter[Q[i]] - spcounter[P[i]-1] );
		
	}
	
	return result;
}