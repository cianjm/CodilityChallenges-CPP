int solution(vector<int> &A) {

	/* Idea is to create a boolean vector to keep track of which numbers have come up already. When a number
	comes up, set that position in the boolean vector = 1. Then on a second pass, you can just go through this
	check vector to see which position still has a 0, and that position will be the missing number. This is 
	possible because an input vector of N elements will have to be missing some number between 1 and N+1. */

	/* If input vector is 6, we want to have a check vector that goes up to 7. But, it also starts at 0, so we
	have to use N+2 when creating it instead of just N+1. */
	int N = A.size();
	vector<bool> checks(N+2, 0);

	// Loop through all elements in the A vector.
	for (int i = 0 ; i < N ; i++) {
		// Only change the checkbit if the position is greater than zero and not greater than N+1
		if (A[i] > 0 && A[i] <= N+1) {
			checks[A[i]] = 1;
		}
	}

	// Loop through again looking for the missing element
	for (int i = 1 ; i <= N+1 ; i++) {
		if (checks[i] == 0)
			return i;
	}

	return 0;
}