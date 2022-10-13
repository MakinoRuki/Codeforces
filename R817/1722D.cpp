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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int b[N];
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<int> rk;
    rk.clear();
    ll tot=0LL;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        int dt = n-1-i-i;
        rk.push_back(dt);
        tot += (ll)i;
      } else {
        int dt = i-(n-1-i);
        rk.push_back(dt);
        tot += (ll)n-1-i;
      }
    }
    sort(rk.begin(), rk.end());
    reverse(rk.begin(), rk.end());
    for (int i = 1; i <= n; ++i) {
      if (rk[i-1] > 0) {
        tot += (ll)rk[i-1];
      }
      printf("%lld", tot);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
