/*
Worked this out myself, got 100% the first time.

	https://codility.com/demo/results/trainingQGKTC8-D53/
*/

int solution(vector<int> &H) {
	vector<int> stack;
	int blocks = 1;
	stack.push_back(H[0]);
	for ( int i = 1 ; i < (int) H.size() ; i++) {
	
		if (H[i] > stack.back()) {
			stack.push_back(H[i]);
			blocks++;
		}
	
		else if (H[i] < stack.back()) {
			while ( H[i] < stack.back() ) {
				stack.pop_back();
			}
			if ( H[i] != stack.back() ) {
				stack.push_back(H[i]);
				blocks++;
			}
			
		}
		/*
		cout << "Stack is: " ;
		for (int j = 0 ; j < (int) stack.size(); j++ )
			cout << stack[j] << " ";
		cout << endl ;
		*/
		
	}
	
	return blocks;
}