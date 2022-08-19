#include <bits/stdc++.h>
using namespace std;

int tree[1000000]{};
void add(int k, int x, int n)
{
  while (k <= n)
  {
    tree[k] += x;
    k += k & -k;
  }
}

int sum(int k)
{
  int s = 0;
  while (k >= 1)
  {
    s += tree[k];
    k -= k & -k;
  }
  return s;
}
int sum(int a, int b)
{
  return sum(b) - sum(a - 1);
}

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int a;
    cin >> a;
    add(i, a, n);
  }
  int p, q;
  cin >> p >> q;
  cout << sum(p, q);
}