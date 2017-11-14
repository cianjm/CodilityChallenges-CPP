int solution(int A, int B, int K) {
	int A2 = A - A%K;
	int ans = (B - A2)/K;
	if (A%K == 0)
		ans++;
		
	return ans;
}