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
#define N 3000005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
ll p[N], q[N];
int bit[N];
ll lv[N], rv[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int x, ll ub) {
  while(x <= ub) {
    bit[x]++;
    x += lowbit(x);
  }
}
int query(int x) {
  if (x <= 0) return 0;
  int res=0;
  while(x) {
    res += bit[x];
    x -= lowbit(x);
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &p[i]);
    }
    vector<ll> v;
    v.clear();
    for (int i = 1; i <= k; ++i) {
      scanf("%lld", &q[i]);
      v.push_back(q[i]);
    }
    for (int i = 0; i <= max(2*n, k); ++i) {
      bit[i] = 0;
    }
    for (int i = 0; i <= 21; ++i) {
      lv[i]=0;
      rv[i]=0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= 20; ++i) {
      int id = 0;
      for (int j = 0; j < v.size(); ++j) {
        while(id < v.size() && (v[j]+i)>v[id]) {
          id++;
        }
        rv[i] += (int)v.size()-id;
      }
    }
    for (int i = 0; i <= 20; ++i) {
      int id = 0;
      for (int j = 0; j < v.size(); ++j) {
        while(id < j && (v[id]+i)<v[j]) {
          id++;
        }
        lv[i] += (int)v.size()-id;
      }
    }
    ll tot=0LL;
    for (int i = 1; i <= k; ++i) {
      int cur = q[i]+1;
      tot += (query(k)%mod2 - query(cur)%mod2 + mod2)%mod2;
      update(cur, k);
    }
    ll ans = tot  * (ll)n % mod2;
    for (int i = 1; i <= max(2*n, k); ++i) {
      bit[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
    //  cout<<"i="<<i<<" "<<p[i]<<endl;
      for (int j = 1; j <= 20; ++j) {
        ll lb = p[i]>>j;
        ll rb = (p[i]+(1LL<<(j-1))-1)>>(j-1);
        if (lb+1<=rb-1) {
          ll cur = (query(rb-1)%mod2 - query(lb)%mod2 + mod2) % mod2;
         // cout<<"cur1="<<cur<<endl;
          ans = (ans + cur * rv[j] % mod2) % mod2;
        }
      }
      for (int j = 0; j <= 20; ++j) {
        ll lb = p[i]<<j;
        ll rb = min((ll)2*n-1, (p[i]<<(j+1))-1);
        if (lb + 1 <= rb) {
          ll cur = (query(rb)%mod2 - query(lb)%mod2+mod2) % mod2;
         // cout<<"cur2="<<cur<<endl;
          ans = (ans + cur * lv[j] % mod2) % mod2;
        }
      }
      update(p[i], 2*n-1);
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

