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
#define N 500005
#define M 505
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
ll k;
int t;
ll p[N], d[N];
ll getl(map<ll, vector<ll>>& mpl, ll x, ll tt) {
    ll res = (tt+x)%k;
    if (!mpl.count(res)) {
        return -1;
    }
    // 会被卡常数！！
    auto &v = mpl[res];
    auto itr = lower_bound(v.begin(), v.end(), x);
    if (itr == v.begin()) return -1;
    itr--;
    return *itr;
}
ll getr(map<ll, vector<ll>>& mpr, ll x, ll tt) {
   ll res = ((tt-x)%k+k)%k;
   if (!mpr.count(res)) {
       return -1;
   }
   // 会被卡常数！！
   auto &v = mpr[res];
   auto itr = upper_bound(v.begin(), v.end(), x);
   if (itr == v.end()) return -1;
   return *itr;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%lld", &n, &k);
    map<ll, ll> mp;
    mp.clear();
    map<ll, vector<ll>> mpl;
    map<ll, vector<ll>> mpr;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &d[i]);
        
    }
    for (int i = 1; i <= n; ++i) {
        mp[p[i]] = d[i];
       // cout<<"i="<<i<<" "<<d[i]<<" "<<p[i]<<" "<<((d[i]-p[i])%k+k)%k<<endl;
        mpr[((d[i]-p[i])%k+k)%k].emplace_back(p[i]);
        mpl[(d[i]+p[i])%k].emplace_back(p[i]);
    }
    map<pair<ll,int>, bool> dp;
    dp.clear();
    scanf("%d", &q);
    while(q-->0) {
        ll x;
        scanf("%lld", &x);
        int dr = 1;
        ll tt = 0LL;
        if (mp.count(x) && mp[x] == 0) {
            dr = 0;
        }
        bool found=false;
        set<pair<ll, int>> st;
        st.clear();
        for (int i = 0; i < 2*n; ++i) {
            if (dr) {
                ll nxt = getr(mpr, x, tt);
                if (nxt < 0) {
                    found=true;
                    break;
                }
                tt += abs(nxt-x);
                dr = !dr;
                x = nxt;
            } else {
                ll nxt = getl(mpl, x, tt);
                if (nxt < 0) {
                    found=true;
                    break;
                }
                tt += abs(x-nxt);
                dr = !dr;
                x = nxt;
            }
           // cout<<"st==="<<x<<" "<<dr<<" "<<tt<<endl;
            if (st.count(make_pair(x, dr))) {
                break;
            }
            st.insert(make_pair(x, dr));
            if (dp.count(make_pair(x, dr))) {
                found=dp[make_pair(x, dr)];
                break;
            }
        }
        for (auto itr : st) {
            dp[itr] = found;
        }
        if (found) puts("Yes");
        else puts("No");
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
