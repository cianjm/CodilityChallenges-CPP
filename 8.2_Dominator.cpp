/*
	https://codility.com/demo/results/trainingQJ4EYQ-2CM/
*/

#include <map>

int solution(vector<int> &A) {
	if (A.empty())
		return -1;
	
	map<int,int> mymap;
	int currentmax = 0, dominator = A[0];
		
	for (int i = 0 ; i < (int) A.size() ; i++) {
		mymap[A[i]]++; 
		if (mymap[A[i]] > currentmax) {
			currentmax = max(currentmax, mymap[A[i]]);
			dominator = A[i];
		}
	}
	
	if (currentmax <= (int) A.size() / 2)
		return -1;
		
	for (int i = 0 ; i < (int) A.size() ; i++) {
		if (A[i] == dominator)
			return i;
	}
	return 0;
}