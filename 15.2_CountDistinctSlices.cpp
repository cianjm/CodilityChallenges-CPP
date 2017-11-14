/*
Tricky one to solve, I used hints from searching online but didn't copy it wholesale. Got 100% on first submission. The
trick is to use a caterpillar system to kick out the oldest values when you hit a duplicate. Each new distinct element 
adds a number of slices equal to the length of the largest ongoing distinct slice.

	https://codility.com/demo/results/training3Y2EKE-PV9/

*/

int solution(int M, vector<int> &A) {
	vector<int> caterpillar(M+1, 0);
	int start=0, end=0, counter = 0, subcounter = 0;
	
	if (M == 0)
		return A.size();
		
	while (start < (int) A.size() ) {
		// i.e. if number is not in current slice
		if (caterpillar[A[start]] == 0 ) {
			subcounter++;
			counter += subcounter;
			if (counter > 1000000000) 
				return 1000000000;
			caterpillar[A[start]] = 1;
			start++;
		}
		else {
			subcounter--;
			caterpillar[A[end]] = 0;
			end++;
		}

	}
	return counter;
}