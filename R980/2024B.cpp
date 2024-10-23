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
#define N 500005
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
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int k2=k;
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    vector<pair<int,int>> v;
    v.clear();
    for (auto itr : mp) {
      v.push_back(make_pair(itr.first, itr.second));
    }
    ll ans=0LL;
    ll cnt = n;
    ll dt = 0;
    for (int i = 0; i < v.size(); ++i) {
      ll res = cnt * (ll)(v[i].first-dt);
      if (res >= k) {
        ans += k;
        break;
      }
      k -= res;
      ans += res;
      ans += v[i].second;
      cnt -= v[i].second;
      dt += (v[i].first-dt);
    }
    // if (cas==1477) {
    //   string ss = to_string(n)+"#"+to_string(k2);
    //   for (int i = 1; i <= n; ++i) {
    //     ss += "#" + to_string(a[i]);
    //   }
    //   cout<<ss<<endl;
    // }
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

