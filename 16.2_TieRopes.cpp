/*
Very simple greedy algorithm

	https://codility.com/demo/results/trainingS6VPET-V38/
*/

int solution(int K, vector<int> &A) {
	int currentrope = 0, bigropes=0;
	for (int i = 0 ; i < (int) A.size() ; i++) {
		if (A[i] >= K || A[i] + currentrope >= K) {
			bigropes++;
			currentrope = 0;
		}
		else {
			currentrope += A[i];
		}
	}
	
	return bigropes;
}