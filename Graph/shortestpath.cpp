#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef queue<int> qi;

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, +1, -1};
int R = 5, C = 7;
qii qu;
int sr = 0, sc = 0;
int er = 4, ec = 3;
vector<vector<char>> adj;
int mov[5][6] = {{1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
bool reached_end = false;
int moves = 0;

void printgrid()
{
  for (auto x : adj)
  {
    for (auto y : x)
    {
      cout << y << " ";
    }
    cout << "\n";
  }
  for (int x = 0; x < R; x++)
  {
    for (int y = 0; y < C; y++)
    {
      cout << mov[x][y] << " ";
    }
    cout << "\n";
  }
}

void shortest_path()
{
  qu.push(ii(sr, sc));
  int rr, cc;
  while (!qu.empty())
  {
    cout << "test\n";
    int r = qu.front().first;
    int c = qu.front().second;

    qu.pop();
    for (int i = 0; i < 4; i++)
    {
      rr = r + dr[i];
      cc = c + dc[i];
      if (rr < 0 || cc < 0)
        continue;
      if (rr >= R || cc >= C)
        continue;
      if (adj[rr][cc] == '#' || adj[rr][cc] == 'S')
        continue;
      adj[rr][cc] = '#';
      qu.push(ii(rr, cc));
      mov[rr][cc] = mov[r][c] + 1;
    }
    if (adj[er][ec] == '#')
      break;
  }
}

int main()
{
  adj.push_back({'S', '.', '.', '#', '.', '.', '.'});
  adj.push_back({'.', '#', '.', '.', '.', '#', '.'});
  adj.push_back({'.', '#', '.', '.', '.', '.', '.'});
  adj.push_back({'.', '.', '#', '#', '.', '.', '.'});
  adj.push_back({'#', '.', '#', 'E', '.', '#', '.'});
  shortest_path();
  if (reached_end)
    cout << "Shortest path\n";
  else
    cout << "No path\n";
  printgrid();
}