#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
  if (a < b)
    return gcd(b, a);
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a,int b)
{
  return (a*b)/gcd(a,b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout<<gcd(a,b)<<endl<<lcm(a,b)<<endl;
}