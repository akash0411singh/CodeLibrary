#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> adj(27);
vector<bool> visited;
vi ans;
int n = 26;

void dfs(int v)
{
  visited[v] = true;
  for (int u : adj[v])
  {
    if (!visited[u])
      dfs(u);
  }
  ans.push_back(v);
}

void topological_sort()
{
  visited.assign(n, false);
  ans.clear();
  for (int i = 0; i < n; ++i)
  {
    if (!visited[i])
      dfs(i);
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans)
  {
    cout << char(x + 97) << " ";
  }
  cout << endl;
}
int main()
{
  int t;
  scanf("%d", &t);
  // int curr, prev;
  string curr, prev;
  cin >> prev;
  for (int i = 1; i < t; i++)
  {
    cin >> curr;
    adj[prev[0] - 'a'].push_back(curr[0] - 'a');
    // scanf("%d %d", &prev, &curr);
    // adj[prev].push_back(curr);
    prev = curr;
  }
  topological_sort();
}