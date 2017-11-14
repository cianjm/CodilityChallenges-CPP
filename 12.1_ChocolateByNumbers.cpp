/*
    Not that bad. Got 75% 
    the first time because I didn't account for when M%N == 0, which was causing problems.

    https://codility.com/demo/results/trainingSRUF6Y-33E/
*/

int solution(int N, int M) {
    // Find the common denominator
    int large, small, temp;
    large = N;
    small = M%N;
    if (small == 0)
        small = N;
    while (large%small != 0) {
        temp = small;
        small = large%small;
        large = temp;
    }
        
    return N/small;
}