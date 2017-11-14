// https://codility.com/demo/results/training4KWFB3-JYJ/

#include <algorithm>
int solution(vector<int> &A) {
	sort(A.begin(), A.end() );
	if (A.empty() || A.size() < 3)
		return 0;

	for (int i = 0 ; i < int (A.size()-2) ; i++) {
		if ( (long long) A[i] + (long long) A[i+1] > A[i+2])
			return 1;
	}
	
	return 0;
}