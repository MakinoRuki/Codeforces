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
#include <list>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
ll ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld", &n);
    ll x = n;
    vector<int> bs;
    bs.clear();
    int cnt=0;
    while(x) {
      if (x%2) cnt++;
      bs.push_back(x%2);
      x/=2;
    }
    if (cnt == 1) {
      puts("1");
      printf("%lld\n", n);
      continue;
    }
    //reverse(bs.begin(), bs.end());
    int cur=0;
    for (int i = 1; i <= cnt+1; ++i) {
      ans[i] = 0;
    }
    for (int i = bs.size()-1; i >= 0; --i) {
      if (bs[i] == 0) continue;
      cur++;
      for (int j = 1; j <= cnt+1; ++j) {
        if (j != cur) {
          ans[j] |= (1LL<<i);
        }
      }
    }
    printf("%d\n", cnt+1);
    for (int i = 1; i <= cnt+1; ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
