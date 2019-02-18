/*
 * Rumor
 *
 * @author Josias Ruegg
 * @tags graphs bfs
 * @idea For every connected component of the graph, we find the minimum value of
 * gold that a person in that component has, and the answer would be the sum of all
 * those values for every connected component.
 *
 */
 
 #include <bits/stdc++.h>

using namespace std;


typedef long long int lli;
const int MAX_N = 100010;

vector<int> g[MAX_N];
bool p[MAX_N];
lli gold[MAX_N];

int n, m;

// min gold from connected component s
lli bfs(int s) {
  lli r = gold[s];
  
  for(auto i:g[s]) {
    if(p[i]) continue;
    p[i] = true;
    r = min(r, gold[i]);
    r = min(bfs(i), r);
  }
  return r;
}


int main() {
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) {
    lli t;
    cin >> t;
    gold[i] = t;
  }
  
  
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  lli sol = 0;
  for(int i = 0; i < n; i++) {
    if(!p[i]) sol += bfs(i);
  }
  
  cout << sol << endl;
  
}
