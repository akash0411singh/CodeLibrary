#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef queue<int> qi;

vi ans;
priority_queue<ii, vector<ii>, greater<ii>> pq;

int v, e;
int dist[6][6];

int adj[6][6] = {{0, 2, 3, 999, 999, 999},
                 {999, 0, 1, 1, 999, 999},
                 {999, 999, 0, 999, 1, 999},
                 {999, 999, 999, 0, 2, 3},
                 {999, 999, 999, 999, 0, 999},
                 {999, 999, 999, 999, 2, 0}};

void floyd_warshall()
{
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      dist[i][j] = adj[i][j];

  for (int k = 0; k < 6; k++)
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
  return;
}

int main()
{
  floyd_warshall();
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
      printf("%4d", adj[i][j]);
    cout << endl;
  }
  cout << endl
       << endl;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
      printf("%4d", dist[i][j]);
    cout << endl;
  }
}
