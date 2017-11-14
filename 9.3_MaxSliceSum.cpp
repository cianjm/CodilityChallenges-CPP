/*
Note that this one has to allow for the possibility that the max slice might be negative.
	https://codility.com/demo/results/trainingAYN3PR-Z62/
*/

int solution(vector<int> &A) {
	int maxhere = 0 , maxslice = A[0];
	for (int i = 0 ; i < (int) A.size() ; i++) {
		maxhere = max( A[i] , maxhere + A[i] );
		maxslice = max( maxslice, maxhere);
	}
	return maxslice;
}