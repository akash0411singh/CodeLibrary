#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef queue<int> qi;

vector<vii> adj;
vi ans;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra()
{
  pq.push(ii(0, 0));
  while (!pq.empty())
  {
    ii temp = pq.top();
    pq.pop();
    if (ans[temp.second] < temp.first)
      continue;
    else
    {
      ans[temp.second] = temp.first;
      for (auto x : adj[temp.second])
      {
        pq.push(ii(x.second + temp.first, x.first));
      }
    }
  }
  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << endl;
}
int main()
{
  int v, e;
  cin >> v >> e;
  adj.resize(v);
  // visited.resize(v, false);
  ans.resize(v, 9999);
  ans[0] = 0;
  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(ii(b, c));
  }
  dijkstra();
}

/*
Test Case:
5 6
0 1 4
0 2 1
1 3 1
2 1 2
2 3 5
3 4 3
Queue:
0 0
1 4
2 1
1 3
3 6
3 4
4 7
Answer:
0 1 2 3 4
0 3 1 4 7
*/