/*
This one was a bit of a pain in the butt but I still did it solo. Made an early mistake of not realising that there 
might be multiple fish going downstream, so I couldn't just discard them. Stack2 was previously a vector before I
realised it was unneccesary to have it be one, because the fish swimming up can be discarded after they're either eaten
or swim away, it's only the ones going down we have to keep track of. 

	https://codility.com/demo/results/training5J4RVT-GU6/

*/

int solution(vector<int> &A, vector<int> &B) {
	vector<int> stack1;
	int stack2 = 0;
	int fishremaining = 0;

	for (unsigned int i = 0 ; i < A.size() ; i++ ) {
		// If a fish is going downstream, add it to the stack
		if (B[i] == 1)
			stack1.push_back(A[i]);
		// If the fish is going upstream and there were previously some fish going downstream, note the size of the 
		// current one going up for comparing.
		else if (!stack1.empty() )
			stack2 = A[i];
		// If there's no fish going downstream, any fish going upstream will just swim away safely
		else if (stack1.empty()) {
			fishremaining++;
		}
		
		// If there were fish going downstream before and if the latest upstream fish is bigger than at least the most
		// recent one, the downstream fish will get eaten, so pop them off the stack. If the upstream fish eats them all
		// then it swims away safely (add to fishremaining). 
		while (!stack1.empty() && stack1.back() < stack2) {
			stack1.pop_back();
			if (stack1.empty() )
				fishremaining++;
		}

		// Since the upstream fish will either be eaten or swim away, reset it to zero.
		stack2 = 0;
	}

	return fishremaining + stack1.size();
}