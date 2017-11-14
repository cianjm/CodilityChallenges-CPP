/*
Literally the easiest one. My solution to the previous problem was robust enought to also work here. I just removed the
other brackets from the problem because they were unneccessary. 100% first time.

	https://codility.com/demo/results/trainingDY6V88-NM6/
*/
#include <vector>

int solution(string &S) {
	vector<int> stack;
	for (int i = 0 ; i < (int) S.length() ; i++ ) {
		
		if (S[i] == '(' || stack.empty() ) {
			stack.push_back(S[i]);
		}
		else if (S[i] == ')' && stack.back() == '(' ) {
			stack.pop_back();
		}
		else {
			return 0;
		}
	}
	
	if (stack.empty())
		return 1;
	else
		return 0;
}