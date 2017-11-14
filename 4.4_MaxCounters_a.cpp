/* This solution runs at the correct efficiency O(N+M) but on one of the tests it takes 0.104 seconds instead of the 
required 0.1 seconds, so it does not get 100%. */

vector<int> solution(int N, vector<int> &A) {
    int maxval = 0;
    bool maxflag = 0;
    vector<int> counters(N, 0);
    for (vector<int>::iterator itta = A.begin(); itta != A.end() ; itta++) {
        //cout << *itta << endl; 
        if (*itta <= N ) {
            counters[*itta-1]++;
            maxval = max(counters[*itta-1], maxval);
            maxflag = 0;

        }
        else if (*itta == N+1 && !maxflag) {
            fill(counters.begin(), counters.end(), maxval);
            maxflag = 1;
        }    
    }    
    return counters;
