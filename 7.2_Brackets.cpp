/*
Almost got this one right first time. Only error was in the event that the input string started with a closed bracket.
When this happened, it would fail the first "if" and then segfault on the second one because it couldn't access
"stack.back()". To remedy this, I just added "stack.empty()" as a condition for the first if, so now the first element
always goes in there. 
	https://codility.com/demo/results/trainingHMYNTV-GNG/
*/

#include <vector>

int solution(string &S) {
	vector<int> stack;
	for (int i = 0 ; i < (int) S.length() ; i++ ) {
		
		if (S[i] == '(' || S[i] == '[' || S[i] == '{' || stack.empty() ) {
			stack.push_back(S[i]);
		}
		else if (S[i] == ')' && stack.back() == '(' ) {
			stack.pop_back();
		}
		else if (S[i] == ']' && stack.back() == '[' ) {
			stack.pop_back();
		}
		else if (S[i] == '}' && stack.back() == '{' ) {
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