/*
This is the solution that actually works 100% on both correctness and performance. It works by initially keeping 3
vectors that count the number of As, Cs and Gs that have appeared at each point in time. You can then use these vectors
to quickly figure out if these letters appeared already by subtracting them. If there are 4 As in position 10 but only
3 As in position 7, then clearly an A has appeared between these two positions. If there are 3 As in both 10 and 7, then
obviously an A has not appeared in between these two, so in that case you do the same check for Cs, then Gs. You don't 
need to track Ts. If none of the other 3 appeared then you know the only thing in between the two positions is T. This 
solution was found online done by James Chen at this link:
	https://sites.google.com/site/spaceofjameschen/home/codibility/5-3-genomicrangequery

My Codility report on it can be found here:
	https://codility.com/demo/results/trainingYZJ3WF-WN7/
*/
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	vector<int> result, Avec, Cvec, Gvec;
	int A_count = 0 , C_count = 0, G_count = 0, start, end;
	for (int i = 0 ; i < int (S.length()) ; i++) {
		if (S[i] == 'A')
			A_count++;
		else if (S[i] == 'C')
			C_count++;
		else if (S[i] == 'G')
			G_count++;
		
		Avec.push_back(A_count);
		Cvec.push_back(C_count);
		Gvec.push_back(G_count);
		
		//cout << A_count << "\t" << C_count << "\t" << G_count << endl;
			
	}
	
	for (int i = 0 ; i < int(P.size()) ; i++) {
		start = P[i];
		end = Q[i];
		if (Avec[end] - Avec[start] > 0 || S[start] == 'A')
			result.push_back(1);
		else if (Cvec[end] - Cvec[start] > 0 || S[start] == 'C')
			result.push_back(2);
		else if (Gvec[end] - Gvec[start] > 0 || S[start] == 'G')
			result.push_back(3);
		else result.push_back(4);
	}
	return result;
}