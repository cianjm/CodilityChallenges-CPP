/*
Much simpler than it looks when you realise that due to how the segments are ordered, if the third segment overlaps the
first then it automatically must overlap the second too (and so on with subsequent ones).

	https://codility.com/demo/results/training9EDDHW-942/
*/

int solution(vector<int> &A, vector<int> &B) {
	
	int last = 0, counter = 1;
	if (A.empty()) {
		return 0;
	}
	for (int i = 1 ; i < (int) A.size() ; i++) {
		if (A[i] > B[last]) {
			counter++;
			last = i;
		}
	}
	
	return counter;
}