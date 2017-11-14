/*
Easy enough. Report says efficiency might be as low as O(N*log(N)) but it passes performance tests fine.

	https://codility.com/demo/results/trainingZTVSQG-5RF/
*/

#include <cmath>
#include <map>

int solution(vector<int> &A) {
    
    map <int, int> mymap;    
    for (int i = 0 ; i < (int) A.size() ; i++) {
        mymap[abs(A[i])]++;
        //cout << "i is: " << i << " map is " << mymap[abs(A[i])] << endl;
    }
    
    return mymap.size();
}