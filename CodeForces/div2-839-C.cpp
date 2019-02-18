/*
 * Journey
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

int len[MAX_N];
double prob[MAX_N];

double sol;

void dfs(int s) {
  vis[s] = true;
  if(g[s].size() == 1 and s!= 0) {
    sol += prob[s] * len[s];
    //cout << s+1 << " IS terminal" << endl;
    return;
  }
  
  for(auto i:g[s]) {
    if(vis[i]) continue;
    vis[i] = true;
    if(s == 0) {
      prob[i] = prob[s] / g[s].size();
    } else {
      prob[i] = prob[s] / (g[s].size()-1);
    }
    len[i] = len[s]+1;
    dfs(i);
  }
}

int n;

int main() {
  cin >> n;
  
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  prob[0] = 1.0;
  dfs(0);
  
  /*
  for(int i = 0; i < n; i++) {
    cout << "Node : " << i+1 << " prob : " << prob[i] << " len : " << len[i] << endl;
  }
  */
  
  cout << setprecision(10) << fixed << sol << endl;
}