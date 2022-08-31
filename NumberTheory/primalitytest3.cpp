#include <bits/stdc++.h>
using namespace std;

int modular_exponent(int a, unsigned int n, int p)
{
  int res = 1;
  while (n > 0)
  {
    if (n & 1)
    {
      res = (res * a) % p;
    }

    n = n >> 1;
    a = (a * a) % p;
  }
  return res;
}

bool millerTest(int n, int d)
{
  int a = 2 + rand() % (n - 4);

  int x = modular_exponent(a, d, n);

  if (x == 1 || x == n - 1)
    return true;

  while (d != n - 1)
  {
    x = (x * x) % n;
    d *= 2;

    if (x == 1)
      return false;
    if (x == n - 1)
      return true;
  }
  return false;
}

bool isPrime(unsigned int n, int k)
{
  if (n <= 1 || n == 4)
    return false;
  if (n <= 3)
    return true;
  int d = n - 1;
  while (d % 2 == 0)
    d /= 2;
  for (int i = 0; i < k; i++)
    if (!millerTest(d, n))
      return false;
  return true;
}

int main()
{
  int n;
  cin >> n;
  isPrime(n, 3) ? cout << "Prime" << endl : cout << "Composite" << endl;
  return 0;
}