#include <bits/stdc++.h>
using namespace std;
int main() {
	unsigned long long T, N;
	cin >> T;
	while(T--){
		cin >> N;
		if(N%6) cout << "Chef\n";
		else cout << "Misha\n";
	}
}