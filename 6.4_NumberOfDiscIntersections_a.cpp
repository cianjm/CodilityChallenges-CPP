/* This one is technically correct, but inefficient. I thought it would do O(N*logN) but it's actually O(N^2). Report
can be found at the following link: 

	https://codility.com/demo/results/trainingD84RUQ-SQG/

*/
int solution(vector<int> &A) {
	vector<long long> P, Q;
	int count=0;
	
	for (int i = 0 ; i < (int) A.size() ; i++ ){
		P.push_back((long long) i - (long long) A[i]);
		Q.push_back((long long) i + (long long) A[i]);
		//cout << "Range of circle " << i << " is from " << P[i] << " to " << Q[i] << endl;
	}

	
	for (int i = 0 ; i < (int) Q.size() ; i++ ) {
		for (int j = i+1 ; j < (int) P.size() ; j++) {
			if (P[j] <= Q[i])
				count++;
			if (count > 10000000)
				return -1;
		}
	}
	
	return count;
}