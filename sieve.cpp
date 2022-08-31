#include <bits/stdc++.h>
using namespace std;

bool prime[n + 1];
void sieveofEratosthenes(int n)
{
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  sieveofEratosthenes(n);
  return 0;
}