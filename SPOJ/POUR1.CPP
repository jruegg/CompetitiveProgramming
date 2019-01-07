#include <bits/stdc++.h>

using namespace std;

vector<map <int, int> > m;
int A, B, C;
int minSteps;


void solve(int a, int b, int moves);

void update(int valA, int valB, int mov) {
	
	//printf("A %d B %d moves %d\n", valA, valB, mov);
	
	if(valA == C or valB == C) {
		minSteps = min(minSteps, mov);
		
	} 
	
	
	
	if (m[valA].insert(pair<int, int> (valB, mov)).second) {
		solve(valA, valB, mov);
	} else {
		if(m[valA][valB] > mov) {
			m[valA][valB] = mov;
			solve(valA, valB, mov);
		}
	}
}

void solve(int a, int b, int moves) {
	//pasar
	// a -> b
	if(a and b < B) {
		if(a+b <= B) {
			update(0, a+b, moves+1);
		} else {
			update(a+b-B, B, moves+1);
		}
	}
	
	// a <- b
	if(b and a < A) {
		if(a+b <= A) {
			update(a+b, 0, moves+1);
		} else {
			update(A, a+b-A, moves+1);
		}
	}
	
	//Vaciar
	
	if(a) update(0, b, moves+1);
	if(b) update(a, 0, moves+1);
	
	
	//llenar
	if(a != A) {
		update(A, b, moves+1);
	}
	if(b != B) {
		update(a, B, moves+1);
	}
	
}




int main() {
	
	int t;
	cin >> t;
	
	while(t--) {
		cin >> A >> B >> C;
		
		if(A > B) swap(A, B);
		
		m.resize(A + 1, map<int, int>());
		
		for(int i = 0; i <= A ; i++) {
			m[i].clear();
		}
		
		minSteps = 1000000;
		
		//cout << "Problem : " << A << " " << B << " " << C << endl;
		
		if(!C) minSteps = 0;
		if(C) solve(0, 0, 0);
		
		//cout << "SOLUTION : ";
		if(minSteps == 1000000) minSteps = -1;
		
		cout << minSteps << endl;
		
	}
	
	
}
