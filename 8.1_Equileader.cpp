/*
	https://codility.com/demo/results/trainingA3X9AF-UEX/
*/

#include <map>

int solution(vector<int> &A) {
	map<int,int> mymap;
	int currentmax = 0, leader = A[0];
	for (int i = 0 ; i < (int) A.size() ; i++) {
		mymap[A[i]]++; 
		if (mymap[A[i]] > currentmax) {
			currentmax = max(currentmax, mymap[A[i]]);
			leader = A[i];
		}
	}
	
	int leadersfound = 0, leadersremaining = currentmax;
	int equileaders = 0;
	for (int i = 0 ; i < (int) A.size()-1 ; i++) {
		if (A[i] == leader) {
			leadersfound++;
			leadersremaining--;
		}
	
		//cout << "Leaders found: " << leadersfound << " and remaining: " << leadersremaining << endl;
		//cout << "Threshold A is: " << (i+1)/2 << " and B is: " << (A.size()-i-1)/2 << endl;
		if (leadersfound > (i+1)/2 && leadersremaining > ((int) A.size()-i-1)/2 )
			equileaders++;
	}
	
	
	return equileaders;
}