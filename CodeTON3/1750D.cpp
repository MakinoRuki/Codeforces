
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 600005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok=true;
    for (int i = 2; i <= n; ++i) {
      if (a[i-1]%a[i]) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("0");
      continue;
    }
    vector<int> ps;
    ps.clear();
    
    // 此处只需要分解a[1]因为后面数字都是它的因子。
    int x=a[1];
    for (ll i = 2; i * i <= x; ++i) {
      if ((x%i)==0) {
        ps.push_back(i);
        while((x%i)==0) {
          x/=i;
        }
      }
    }
    if (x>1) ps.push_back(x);
    ll ans=1LL;
    for (int i = 2; i <= n; ++i) {
      vector<int> tmp;
      tmp.clear();
      for (auto p : ps) {
        if ((a[i-1]/a[i]) % p) continue;
        tmp.push_back(p);
      }
      int sz=(int)tmp.size();
      ll tot=m/a[i];
      ll up = m/a[i];
      for (int j = 1; j < (1<<sz); ++j) {
        ll vv = 1LL;
        int cnt=0;
        for (int k = 0; k < sz; ++k) {
          if ((1<<k)&j) {
            cnt++;
            vv *= tmp[k];
          }
        }
        if (cnt%2) tot -= up/vv;
        else tot += up/vv;
      }
      ans = ans * (tot % mod2) % mod2; 
    }
    printf("%lld\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
