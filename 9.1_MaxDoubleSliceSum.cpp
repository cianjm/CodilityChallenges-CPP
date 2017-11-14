/*
This took me over 2 hours to do. I got help from (https://stackoverflow.com/questions/20660989/max-double-slice-sum), 
specifically the second answer.


	https://codility.com/demo/results/trainingJ4S8Z8-VR9/
*/

int solution(vector<int> &A) {
	vector<int> max_up_to, max_from;
	max_up_to.push_back(0);
	max_from.push_back(0);
	
	int maxslice = 0;
	
	if (A.size() == 3)
		return 0;
	
	for (int i = 1 ; i < (int) A.size() - 2 ; i++) {
		max_up_to.push_back( max( 0, max_up_to[i-1] + A[i] ) );
		//cout << max_up_to[i] << endl;
	}
	
	for (int i = A.size()-2 ; i > 1 ; i--) {
		max_from.push_back( max( 0, max_from.back() + A[i] ) );
		//cout << max_from.back() << endl;
	}
	
	for (int i = 0 ; i < (int) A.size()-2 ; i++) {
		//cout << "Y is " << i+1 << ", max is " << max_up_to[i] +  max_from[A.size()-i-3] << endl;
		maxslice = max( maxslice, max_up_to[i] +  max_from[A.size()-i-3]);
	}
	
	return maxslice;
}