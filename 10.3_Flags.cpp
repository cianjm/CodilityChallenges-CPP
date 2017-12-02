/*
It took several attempts to get this right:

    1) 33% https://codility.com/demo/results/trainingPZXYU2-N8Z/
    2) 53% https://codility.com/demo/results/trainingQ8HZUB-CHU/
    3) 93% https://codility.com/demo/results/training76JBJ8-A25/
    4) 100% https://codility.com/demo/results/trainingGX6JKR-F4S/
*/

#include <iomanip>
#include <math.h>
#include <algorithm>

int solution(vector<int> &A) {
    int lastpeak = 0;
    vector<int> distances;
    
    if (A.size() < 3)
        return 0;
    
    for (unsigned int i = 1; i < A.size()-1 ; i++) {
        // If peak is found
        if ( A[i] > A[i-1] && A[i] > A[i+1] ) {
            //cout << "i is " << i << endl;
            distances.push_back(i - lastpeak);
            lastpeak = i;
        }
    }
    
    if (distances.empty())
        return 0;
    
    // for (unsigned int i = 0; i < distances.size() ; i++) {
    //     cout << distances[i] << " " ;
    // }
    int X;
    double N = lastpeak+1 - distances[0];
    X = (1 + sqrt( 1 + 4*(N-1) ) ) / 2;
    //cout << "\nN is " << N << ", X is " << X << endl;
    
    int flags, accumulator, maxflags = 1;
    for (int i = X ; i > maxflags ; i--) {
        accumulator = 0;
        flags = 1;
        for (unsigned int j = 1 ; j < distances.size() ; j++) {
            accumulator += distances[j];
            if (accumulator >= i) {
                flags++;
                if (flags == X)
                    return flags;
                accumulator = 0;
            }
        }
        maxflags = max(flags, maxflags);
        //cout << "i is " << i << " and maxflags is " << maxflags << endl;
    }
        
    return maxflags;
}