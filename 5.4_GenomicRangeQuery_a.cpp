/* This is a solution to the problem that works but which is highly inefficient. It takes O(N*M) time to compute so it
fails on every single performance metric. However, it is the only solution I was able to imagine and which I didn't
need help for so I'm keeping it. The Codility report can be found at the link below:

	https://codility.com/demo/results/trainingSKYGYF-J2N/

*/

#include <algorithm>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	vector<int> solution, values(S.length(), 1);
	vector<int>::iterator min;
	int start, end;
	//cout << S << endl;
	for (unsigned int i = 0 ; i < S.length() ; i++) {
		if ( S[i] == 'C' )
			values[i] = 2;
		else if (S[i] == 'G')
			values[i] = 3;
		else if (S[i] == 'T')
			values[i] = 4;
		//cout << values[i];    
	}    
	
	for (unsigned int i = 0 ; i < P.size() ; i++) {
		start = P[i];
		end = Q[i]+1;
		min = min_element(values.begin()+start, values.begin()+end);
		//cout << "Between elements "<< start << " and " << end << ", lowest is " << *min << endl;
		solution.push_back(*min);
	}
	return solution;
}   