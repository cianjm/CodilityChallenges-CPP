/*
First attempt was almost perfect. Performance was the only problem, but even then it was the right complexity level and
it took 0.11s instead of 0.1s because of a special case where all input values are equal. Because this is stupid, I'm 
including both reports for posterity:

	90%: https://codility.com/demo/results/trainingNS75Y8-KTF/
	100%: https://codility.com/demo/results/training2YYB7A-7XV/
*/

#include <algorithm>

int solution(vector<int> &A) {

	if (A.empty() || A.size() < 3)
		return 0;
	int N = A.size();    
	sort(A.begin(), A.end());
	
	if ( A[0] == A[N-1] )
		return (N * (N-1) * (N-2))/6;
	
	int back = 0, middle = 1, front = 2, trips=0;
	
	while ( back < N-2 ) {
		while ( middle < N-1) {
			while ( A[back] + A[middle] > A[front] && front < N) {
				//cout << "(" << back << ", " << middle << ", " << front << ")" << endl;
				trips++;
				front++;
			}
			middle++;
			front = middle+1;
		}
		back++;
		middle = back+1;
		front = back+2;
	}
	return trips;
}