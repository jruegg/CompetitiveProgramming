#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int n;

vector<int> L(0);
vector<int> R(0);

lli ways(int v) {
	vector<int>::iterator i = upper_bound(R.begin(), R.end(), v);
	if(i == R.end()) return 0;
	return R.end() - i;
}	

int main() {
	
	
	cin >> n;
	vector<lli> a(n+1, 0);
	
	cin >> a[1];
	for(int i = 2; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	
	lli sum = a[n];
	
	if(sum%3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	
	
	for(int i = 1; i <= n; i++) {
		if(a[i] == sum/3 and i < n) {
			L.push_back(i);
		}
		if(a[i] == 2 * sum/3 and i > 1 and i < n) {
			R.push_back(i);
		}
	}
	
	lli sol = 0;
	
	int l, r;
	int ls = L.size();
	int rs = R.size();
	l = r = 0;
	while(l < ls and r < rs) {
		if(L[l] < R[r]) {
			sol += rs-r;
			l++;
		} else r++;
		
	}
	
	cout << sol << endl;
	
}