
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
#define N 1000005
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
int b[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int en=0;
    int id=0;
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if ((a[i]%2)==0) {
        en++;
        id = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    if (en>1) {
      puts("0");
      continue;
    }
    bool ok=false;
    for (int i = 1; i <= n; ++i) {
      int x=a[i];
      for (int j = 2; j * j <= x; ++j) {
        if ((x%j) == 0) {
          ss.insert(j);
          if (cnt[j]) {
            ok=true;
            break;
          }
          cnt[j]++;
          while((x%j)==0) {
            x/=j;
          }
        }
      }
      if (x>1) {
        if (cnt[x]) {
          ok=true;
        }
        cnt[x]++;
        ss.insert(x);
      }
    }
    vector<int> vv(ss.begin(), ss.end());
    if (ok) {
      for (auto p : vv) {
        cnt[p]=0;
      }
      puts("0");
      continue;
    }
    ll ans=0;
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(b[i], i));
    }
    sort(v.begin(), v.end());
    if (en == 1) {
      if (v[0].second == id) {
        ans = v[1].first;
      } else {
        ans = v[0].first;
      }
    } else {
      ans = (ll)v[0].first+(ll)v[1].first;
    }
    for (auto p : vv) {
      ll r = a[v[0].second] % p;
      if (r) {
        ans = min(ans, (ll)(p-r)*v[0].first);
      }
    }
    for (int i = 1; i <= n; ++i) {
      ll  x = a[i]+1;
      bool found=false;
      for (int j = 2; j * j <= x; ++j) {
        if ((x%j) == 0) {
          if (cnt[j]) {
            found=true;
            break;
          }
          while((x%j)==0) x/=j;
        }
      }
      if (x>1) {
        if (cnt[x]) found=true;
      }
      if (found) ans=min(ans, (ll)b[i]);
    }
    printf("%lld\n", ans);
    for (auto p : vv) {
      cnt[p]=0;
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
