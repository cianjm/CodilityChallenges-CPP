/* This is the version of this that actually works 100% */

vector<int> solution(int N, vector<int> &A) {
	int maxval = 0, lastboost = 0;
	vector<int> counters(N, 0);
	for (vector<int>::iterator itta = A.begin(); itta != A.end() ; itta++) {
		//cout << *itta << endl; 
		if (*itta <= N ) {
			counters[*itta-1] = max(counters[*itta-1], lastboost);
			counters[*itta-1]++;
			maxval = max(counters[*itta-1], maxval);
		}
		else if (*itta == N+1) {
			lastboost = maxval;
		}  
		
	}    
	
	for (vector<int>::iterator itta = counters.begin(); itta != counters.end() ; itta++) {
		*itta = max(*itta, lastboost);    
	}
	return counters;
	
}