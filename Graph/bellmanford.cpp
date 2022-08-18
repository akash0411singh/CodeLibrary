#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef queue<int> qi;

vector<pair<ii, int>> adj;
vi ans;
priority_queue<ii, vector<ii>, greater<ii>> pq;

int v, e;
void bellman_ford()
{
  for (int i = 1; i < v; i++)
  {
    for (auto x : adj)
    {
      if (ans[x.first.first] + x.second < ans[x.first.second])
      {
        ans[x.first.second] = ans[x.first.first] + x.second;
      }
    }
  }
  for (int i = 1; i < v; i++)
  {
    for (auto x : adj)
    {
      if (ans[x.first.first] + x.second < ans[x.first.second])
      {
        ans[x.first.second] = -9999;
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
  cin >> v >> e;
  adj.resize(e);
  // visited.resize(v, false);
  ans.resize(v, 9999);
  ans[0] = 0;
  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj.push_back(pair<ii, int>(ii(a, b), c));
  }
  bellman_ford();
}

/*
Test Case:
10 13
0 1 5
1 2 20
1 5 30
1 6 60
2 3 10
2 4 75
3 2 -15
4 9 100
5 4 25
5 6 5
5 8 50
6 7 -50
7 8 -10
Queue:
...
Answer:
0 1 2 3 4  5  6   7   8 9
0 5 - - - 35 40 -10 -20 -
*/