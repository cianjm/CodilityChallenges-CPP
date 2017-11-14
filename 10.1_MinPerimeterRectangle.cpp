/*
Failed first time. Error was making loop go until i*i<N, should have been i*i<=N.
	https://codility.com/demo/results/training3E8W3P-6P5/
*/

int solution(int N) {
	int smallest = 2*N + 2;
	int divisor;
	for (int i = 2 ; i*i <= N ; i++) {
		if (N%i == 0) {
			divisor = N/i;
			smallest = 2*i + 2*divisor;
		}
	}
	return smallest;
}