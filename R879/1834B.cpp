#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 200010
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string l,r;
    cin>>l>>r;
    reverse(l.begin(), l.end());
    while(l.size() < r.size()) {
      l.push_back('0');
    }
    reverse(l.begin(), l.end());
    ll tot=0;
    for (int i = 0; i < l.size(); ++i) {
      if (l[i] != r[i]) {
        tot += abs(l[i]-r[i]);
        int dt = (int)r.size()-1-i;
        tot += 9LL * dt;
        break;
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
