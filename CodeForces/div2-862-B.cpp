/*
 * Mahmoud and Ehab and the bipartiteness 
 *
 * @author Josias Ruegg
 * @tags graphs bfs
 * @idea A bipartite graph is one that can be coloured with 2 colors, in such a way
 * that every pair of neighbours are from distinct colors.
 * We make a bfs starting on the root, and every level gets an alternating color.
 * In the end we know how many nodes are for every color, and so the bipartite 
 * graph with those nodes would have : k x l edges (we have k nodes from color 1
 * and l nodes with color 2) now we just substract n-1 from that quantity and we
 * get how many edges we can add.
 *
 */
 
 #include <bits/stdc++.h>

using namespace std;


typedef long long int lli;
const int MAX_N = 100010;

vector<int> g[MAX_N];
int color[MAX_N];
bool vis[MAX_N];

int n;

int total[2];

void bfs(int s) {
  vis[s] = true;
  for(auto i:g[s]) {
    if(vis[i]) continue;
    color[i] = (1+color[s])%2;
    total[color[i]]++;
    bfs(i);
  }
}


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
  
  color[0] = 1;
  total[color[0]]++;
  bfs(0);
  
  lli sol = total[0];
  sol *= total[1];
  
  cout << sol - n + 1 << endl;
  
}
