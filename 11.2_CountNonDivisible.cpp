/*
	Took 3 attempts to get the details right. The first time there was a problem because of the declaration of the size 
	of the occurences vector. I needed to add the +1 to make sure it was big enough. The second problem was the special
	square root check after the j loop.

		1: https://codility.com/demo/results/trainingY8Y8TJ-VUZ/
		2: https://codility.com/demo/results/training9P6THB-K7B/
		3: https://codility.com/demo/results/trainingR3V3AG-G3D/

	I did not figure this out by myself. Credit is owed to
		http://codility-lessons.blogspot.ie/2015/03/lesson-9-countnondivisible.html
*/

#include <cmath>
vector<int> solution(vector<int> &A) {
	// STEP 1: Count occurances of each number in A and put them in a vector
	int N = A.size();
	vector<int> occurances(2*N+1, 0);
	for (int i = 0; i < N ; i++) {
		occurances[ A[i] ]++; 
	}
	
	// STEP 2: Using occurences vector, for each value in A, find the number of divisors that exist in A
	int sqroot;
	vector<int> divisors(N, 0);
	for (int i = 0 ; i < N ; i++) {
		sqroot = ceil( sqrt( A[i] ) );
		//cout <<"\nElement is " << A[i] << ", root is " << sqroot << endl;
		// Loop through integers to find the divisors
		for (int j = 1 ; j < sqroot ; j++ ) {
			// If j is a divisor of the current element
			if ( A[i] % j == 0) {
				// Add the number of occurances of j to the result
				divisors[i] += occurances[j];
				// Also add the number of occurances of j's counterpart divisor
				divisors[i] += occurances[ A[i]/j ];
			}
		}
		// If the current element is a square number, add number of occurances of square root
		if (sqroot * sqroot == A[i]) {
			divisors[i] += occurances[ sqroot ];
		}
	}
	
	// STEP 3: Invert all  divisor values to show non-divisors instead
	for (int i = 0 ; i < N ; i++ ) {
		divisors[i] = N - divisors[i];
	}
	return divisors;
}