/*
This failed on time until I switched from using i*i <= N as the condition to i < squareroot. The numbers near the max
integer value kept going past 6s for some reason with it, even though numbers only marginally smaller had no problem at
all. This method means you only have to caluclate the thing once instead of every time.

    https://codility.com/demo/results/trainingKFZ23Z-TWF/
*/

#include <cmath>

int solution(int N) {
    if (N == 1)
        return 1;
        
    int divisors = 2, i = 2;
    int squareroot = sqrt(N);
    for ( ; i <= squareroot ; i++ ) {
        if (N%i == 0 && N/i == i)
            divisors++;
        else if (N%i == 0) {
            //cout << i << endl;
            divisors+=2;
        }
    }

    return divisors;
}