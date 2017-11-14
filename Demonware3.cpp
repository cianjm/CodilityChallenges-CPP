#include <sstream>

string solution(string &S) {
	stringstream output, ss;
	string spaceless;
	int i, end;
	
	// Create new sequence with all dashes and spaces removed
	for (i = 0 ; i < (int) S.length() ; i++) {
		if (S[i] != ' ' && S[i] != '-'){
			ss << S[i];
		}
	}

	spaceless = ss.str();
	end = spaceless.length();
	
	for (i = 0 ; i < end; i++) {
		// Special case for when number would have single digit after the dash. For the last 3 characters,
		// just add the dash and final two numbers manually and break the loop.
		if (i == end-2 && end%3 == 1) {
			output << '-' << spaceless[i] << spaceless[i+1];
			break;
		}
		else if (i%3 == 0 && i > 1) {
			output << '-';
		}
		output << spaceless[i];
	}
	
	//cout << output.str();
	return output.str();
}