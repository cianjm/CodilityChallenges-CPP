/* Nailed it first time */

int solution(vector<int> &A) {
	vector<int>::iterator pizza = A.begin();
	int count = 0;
	int P = 0;
	for ( ; pizza != A.end() ; pizza++) {
		if (*pizza)
			count += P;
		else
			P++;
			
		if (count > 1000000000)
			return -1;
	}
	return count;
}