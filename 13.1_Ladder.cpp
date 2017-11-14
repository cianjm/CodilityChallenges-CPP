/*
Note: fails if you use long long instead of unsigned long long. I don't fully understand this because to my knowledge,
unsigned essentially only doubles the maximum value and the signed long long failed at about the 46,000 Fibonacci number
so I would have expected 50,000 to still fail too, since the Fibonacci sequence more than doubles every second term.

	https://codility.com/demo/results/training9P6DWT-R99/
*/

#include <cmath>

vector<int> solution(vector<int> &A, vector<int> &B) {
	// Number of ways to climb each number of rungs corresponds to Fibonnaci sequence
	vector<unsigned long long> fibonacci = {1, 1};
	vector<int> result;
	unsigned long long ans, fib, power;
	for (int i = 2 ; i <= 50000 ; i++) {
		fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
	}
	
	//cout << fibonacci[50000] << endl;
	
	for (int i = 0 ; i < (int) A.size() ; i++) {
		fib = fibonacci[A[i]];
		power = pow( 2, B[i] );
		ans = (fib % power );
		result.push_back( ans );
	}
	return result;
}