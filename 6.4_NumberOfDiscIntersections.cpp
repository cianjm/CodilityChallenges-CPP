/* 
This is the "correct" solution to this problem. It's a little more confusing but it's similar to the problem before
where I tried to find the DNA element with the lowest value in a certain range and I did it by counting the number of 
each kind at different points. In this one, we imagine that instead of discs, we just have line sections from the left 
side of the disc to the right side, and we want to see how many overlap. A good explanation with visualisations can be
found in solution 2 on this page: http://codility-lessons.blogspot.ie/2015/02/lesson-4-numberofdiscintersections.html. 

	https://codility.com/demo/results/trainingA4EM8B-QU5/
*/

#include <algorithm>

int solution(vector<int> &A) {

	// P is the opening location of a line segment, Q is the closing location.
	vector<long long> P, Q;
	int count=0;
	int active = 0;
	
	for (int i = 0 ; i < (int) A.size() ; i++ ){
		P.push_back((long long) i - (long long) A[i]);
		Q.push_back((long long) i + (long long) A[i]);
		//cout << "Range of circle " << i << " is from " << P[i] << " to " << Q[i] << endl;
	}
	
	sort(P.begin(), P.end());
	sort(Q.begin(), Q.end());

	// j has to remain consistent so we set it outside both loops.
	int j = 0;
	for (int i = 0 ; i < (int) P.size() ; i++ ) {
		// Add to j until 
		for ( ; P[j] <= Q[i] && j < (int) Q.size() ; j++) {
			//cout << "j at " << j << ", P is " << P[j] << endl;
			   active++;
		}
		// One of the Ps before Q[i] will be from the same line segment, so always subtract 1 to counteract this
		active--;
		//cout << active << endl;
		count += active;
		if (count > 10000000)
			return -1;
	}
	
	return count;
}