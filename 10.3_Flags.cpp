/*

	Report: https://codility.com/demo/results/trainingYCR9J8-YTS/

*/

#include <math.h>

int solution(vector<int> &A) {
	if (A.size() < 3) {
		return 0;
	}
	
	// STEP 1: Find the numbers that N is divisible by
	int N = A.size();
	vector<int> divisors, peaks;
	for (int i = 2 ; i <= N/2; i++) {
		if (N%i == 0) {
			divisors.push_back(i);
		}
	}
	
	// for (unsigned int i = 0 ; i < divisors.size(); i++) {
		// cout << divisors[i] << " ";
	// }
	// cout << endl;
	
	// STEP 2: Find locations of all peaks
	for (int i = 1 ; i < N-1 ; i++) {
		if (A[i] > A[i-1] && A[i] > A[i+1]) {
			peaks.push_back(i);
		}
	}

	// If there are no peaks, return 0
	if (peaks.empty())
		return 0;
	// If there is just one peak, the only block size can be 1
	else if (peaks.size() == 1)
		return 1;
	
	// for (unsigned int i = 0 ; i < peaks.size(); i++) {
	//     //cout << peaks[i] << " ";
	// }
	// cout << endl;
	
	// STEP 3: For each divisible number, check if the locations of the peaks work
	//int maxblocks = min(N/A[i], peaks.length());
	
	// Loop through each divisor
	int start, end;
	for (unsigned int i = 0; i < divisors.size() ; i++) {
		start = 0;
		end = divisors[i]-1;
		//cout << "\nStart: " << start << " and End: " << end << endl;
		// Loop through the peaks
		for (unsigned int j = 0; j < peaks.size() ; j++) {
			// cout << "Peak " << j << " is " << peaks[j] << endl;
			// If the peak falls within the range of the block
			if (peaks[j] <= end && peaks[j] >= start) {
				//cout << "Acceptable" << endl;
				start += divisors[i];
				end += divisors[i];
				//cout << "NEW Start: " << start << " and End: " << end << endl;
			}
			// If the next peak comes after the block
			else if (peaks[j] > end) {
				break;
			}
			// If the end of the original array is reached
			if (start == N) {
				//cout << "The end: " << N/divisors[i] << endl;
				return N/divisors[i];
			}
		}
	}
	// If there were peaks but they couldn't be divided up
	if (!peaks.empty())
		return 1;
	
	return 0;
}