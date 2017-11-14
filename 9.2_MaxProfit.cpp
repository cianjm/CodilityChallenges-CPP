/*
	https://codility.com/demo/results/trainingQHXH5E-WUW/
*/


int solution(vector<int> &A) {
	if (A.empty() || A.size() == 1)
		return 0;
	int lowestprice = A[0] , maxprofit = 0;
	for (int i = 1 ; i < (int) A.size() ; i++ ) {
		if (A[i] < lowestprice) {
			lowestprice = A[i];
		}
		else if (A[i]-lowestprice > maxprofit) {
			maxprofit = A[i] - lowestprice;
		}
	}
	return maxprofit;
}