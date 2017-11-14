/*
Simple problem because it only expects O(N*logN) time, which means you can just sort the vector. Didn't get it 
completely right at first, you have to make sure to sort it BEFORE declaring the iterator, not after, and you need to 
have a condition for A being an empty vector too.

	 https://codility.com/demo/results/trainingX9YUT9-539/
*/

#include <algorithm>

int solution(vector<int> &A) {
	
	sort(A.begin(), A.end());
	vector<int>::iterator itso = A.begin();
	int prev = *itso, counter = 1;
	if (A.empty())
		return 0;
	//cout << *itso << endl;
	for ( ; itso!=A.end() ; itso++) {
		//cout << "Current element is " << *itso << ", previous is " << prev << endl; 
		if (*itso != prev)
			counter++;
		prev = *itso;
	}
	return counter;
}