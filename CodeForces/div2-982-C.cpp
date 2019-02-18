/*
 * Cut 'em all!
 *
 * @author Josias Ruegg
 * @tags trees dfs
 * @idea With a dfs we calculate the size of every subtree, if it's size is even 
 * we can cut there (except if it's the root, that's why we have a -1 on the end)
 * If the entire tree has an odd number of nodes, there is no way to solve it, 
 * because 2 even numbers won't sum up to an odd number.
 *
 */
 
#include <bits/stdc++.h>

using namespace std;

int const MAX_N = 100010;

vector<int> g[MAX_N];
bool vis[MAX_N];

int sub[MAX_N];

void dfs(int s) {
  sub[s] = 1;
  vis[s] = true;
  
  for(auto i:g[s]) {
    if(vis[i]) continue;
    dfs(i);
    sub[s] += sub[i];
  }
}

int n;

int main() {
  cin >> n;
  
  if(n%2) {
    cout << -1 << endl;
    return 0;
  }
  
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    
  }
  
  dfs(0);
  int sol = 0;
  
  for(int i = 0; i < n; i++) {
    if((sub[i]%2) == 0) sol++;
  }
  
  cout << sol - 1 << endl;
  
}