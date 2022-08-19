#include <bits/stdc++.h>
using namespace std;

#define fill(a, b) memset(a, b, sizeof(a))
#define endl "\n";

typedef long long ll;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef pair<ll, ll> pll;
typedef pair<ll, pair<ll, ll>> plll;

const int N = 1000010;
const ll MOD = 1e9 + 7;

struct segtree {
  int size;
  vl seg;
  ll dummy;

  ll rule(ll a, ll b) {
    // return (a + b);
    return max(a, b);
    // return min(a, b);
  }

  void init(int n) {
    // dummy = 0LL;  // SUM,MAX
    dummy = -1e18;  // MAX
    // dummy = 1e18;  // MIN
    size = 1;
    while (size < n) size *= 2;
    seg.assign(2 * size, dummy);
  }
  void build(vl &vect, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)vect.size()) {
        seg[x] = vect[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(vect, 2 * x + 1, lx, m);
    build(vect, 2 * x + 2, m, rx);
    seg[x] = rule(seg[2 * x + 1], seg[2 * x + 2]);
  }

  void build(vl &vect) { build(vect, 0, 0, size); }

  void set(int i, ll v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      seg[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      set(i, v, 2 * x + 1, lx, m);
    else
      set(i, v, 2 * x + 2, m, rx);
    seg[x] = rule(seg[2 * x + 1], seg[2 * x + 2]);
  }

  void set(int i, ll v) { set(i, v, 0, 0, size); }

  ll get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return dummy;
    if (l <= lx && rx <= r) return seg[x];
    int m = (lx + rx) / 2;
    ll s1 = get(l, r, 2 * x + 1, lx, m);
    ll s2 = get(l, r, 2 * x + 2, m, rx);
    return rule(s1, s2);
  }

  ll get(int l, int r) { return get(l, r, 0, 0, size); }
};


void solve() {
  int n, m;
  cin >> n >> m;

  segtree st;
  st.init(n);
  vl vect(n);
  for (int i = 0; i < n; i++) {
    cin >> vect[i];
  }
  st.build(vect);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      st.set(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.sum(l, r) << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // for (int i = 0; i < t; i++) {
  //   solve();
  // }
  solve();
}