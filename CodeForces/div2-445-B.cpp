/*
 * DZY Loves Chemistry 
 *
 * @author Josias Ruegg
 * @tags graphs bfs
 * @idea For every connected component of the graph, we get it's size.
 * the number of reactions will be size - 1
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int const MAX_N = 55;

vector<int> g[MAX_N];
bool vis[MAX_N];

int n;
int m;

//return size of connected component s
int bfs(int s) {
  int r = 1;
  vis[s] = true;
  
  for(auto i:g[s]) {
    if(vis[i]) continue;
    vis[i] = true;
    r+= bfs(i);
  }
  
  return r;
}



int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    
  }
 
  int sol = 0;
  
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      sol += bfs(i);
      sol--;
    }
  }
  
  long long int xyz = 1;
  xyz <<= sol;
  
  cout << xyz << endl;
  
}
