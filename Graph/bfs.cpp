#include <bits/stdc++.h>
using namespace std;

#define MAX 20
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<bool> vect;
vector<vector<int>> adj;

void bfs(int u)
{
  queue<int> q;
  q.push(u);
  vect[u] = true;

  while (!q.empty())
  {
    int f = q.front();
    q.pop();
    cout << f << " ";

    for (auto i = 0; i < adj[f].size(); i++)
    {
      if (!vect[adj[f][i]])
      {
        q.push(adj[f][i]);
        vect[adj[f][i]] = true;
      }
    }
  }
}

int main()
{
  int v, e;
  cin >> v >> e;

  vect.assign(v, false);
  adj.assign(v, vector<int>());
  int a, b;
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vect.assign(v, false);
  // for (int i = 0; i < v; i++)
  // if (vect[i] == false)
  bfs(4);
}
