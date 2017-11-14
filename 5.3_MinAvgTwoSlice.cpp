/* This one was tricky. To get the solution, you need to realise that the minimum average will have to be either 3 or 2
elements long. Anything longer than this could be broken up into groups of 2 or 3. If you have two groups of 2, either
one group will be higher than the other (in which case the average would be lower with that group removed) or they will
both be the same, in which case the second group is redundant. Once you understand this, the solution is simple. I only
found this out after looking for a solution, it's not immediately obvious and can be frustrating if you don't notice it.

To solve, you just need to find all of the 2 and 3-length averages and pick the lowest one. I did this with two loops.*/

int solution(vector<int> &A) {
	vector<double> averages;
	double avg2, avg3, lowest;
	int position = 0;
	lowest = double (A[0]+A[1]) / 2;
	//cout << "Doubles" << endl;
	for (unsigned int i = 1 ; i < A.size()-1 ; i++){
		avg2 = double (A[i]+A[i+1]) / 2;
		//cout << avg2 << endl;
		if (avg2 < lowest) {
			lowest = avg2;
			position = i;
			//cout << "New low!" << endl;
		}    
	}
	
	//cout << "\nTriples" << endl;
	for (unsigned int i = 0 ; i < A.size()-2 ; i++){
		avg3 = double (A[i]+A[i+1]+A[i+2]) / 3;
		//cout << avg3 << endl;
		if (avg3 < lowest) {
			lowest = avg3;
			position = i;
			//cout << "New low!" << endl;
		}
	}

	return position;
}