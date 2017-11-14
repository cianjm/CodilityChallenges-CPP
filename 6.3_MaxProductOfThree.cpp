/* 
Not that bad a problem but it has a lot of hidden test cases to be aware of. One condition to be aware of is if the 
lowest two values are negative and their product is larger than the product of the 2nd and 3rd highest values. In this
case you'll need to multiply these by the last element. The exception to this is if they're ALL negative, in which case
you will just want to multiply the top three elements together as usual. It took me a few goes to iron out the kinks on
this one.

	https://codility.com/demo/results/trainingQ8PDPY-AV2/

*/


#include <algorithm>

int solution(vector<int> &A) {
	sort(A.begin(), A.end());
	int first2 = A[0]*A[1];
	int last2 = *(A.end()-2) * (*(A.end()-3));
	
	if (first2 > last2 && *(A.end()-1) >= 0 ) {
		return first2 * (*(A.end()-1));
	}
	
	else {
		return *(A.end()-1) * (*(A.end()-2)) * (*(A.end()-3));
	}
}