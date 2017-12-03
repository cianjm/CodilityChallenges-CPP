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
    
    for (unsigned int i = 0 ; i < divisors.size(); i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;
    
    // STEP 2: Find locations of all peaks
    for (int i = 1 ; i < N-1 ; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks.push_back(i);
        }
    }
    
    for (unsigned int i = 0 ; i < peaks.size(); i++) {
        cout << peaks[i] << " ";
    }
    
    // STEP 3: For each divisible number, check if the locations of the peaks work
    
    return 0;
}