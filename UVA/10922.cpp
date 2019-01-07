#include <bits/stdc++.h>

using namespace std;

int ss(string s) {
	int sum = 0;
	for(int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}
	return sum;
}

int ss(int s) {
	int sum = 0;
	while(s) {
		sum += s%10;
		s /= 10;
	}
	return sum;
	
}


int main() {
	string s;
	
	int sum = 0;
	
	cin >> s;
	sum = ss(s);
	
	while(sum  != 0) {
		int depth;
		depth = 1;
		
		while(sum > 9) {
			depth++;
			sum = ss(sum);
		}
		
		cout << s;
		if(sum == 9) {
			printf(" is a multiple of 9 and has 9-degree %d.\n", depth);
		} else {
			printf(" is not a multiple of 9.\n");
		}
		
		
		cin >> s;
		sum = ss(s);
	}
	
	
}