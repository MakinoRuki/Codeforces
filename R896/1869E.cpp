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
#define N 200005
#define M 5005
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
map<ll, vector<vector<int>>> mp;
int pw[N][130];
int getpw(int x, ll y) {
    int res=1;
    while(y) {
        if (y&1) res=(int)((ll)res*(ll)x%mod2);
        x=(int)((ll)x*(ll)x%mod2);
        y/=2;
    }
    return res;
}
vector<vector<int>> dfs(ll nn) {
    if (mp.count(nn)) {
        return mp[nn];
    }
  //  cout<<"nn="<<nn<<endl;
  //  cout<<"n="<<nn<<endl;
    if (nn == 0) {
        return mp[nn] = {{0,0}};
    }
    if (nn == 1) {
        return mp[nn] = {{0,1}};
    }
    if (nn==2) {
        return mp[nn] = {{1, 1}, {0,1}};
    }
   //  int pp = 0;
   //  while((1LL<<pp)<=nn+1) {
   //      pp++;
   //  }
   //  pp--;
   //  // ll ln = (n-tmp-1)/2;
   //  // ln += min(tmp, 1LL<<(p-2));
   // // int pp = std::log(2, n + 1);
   //  ll ln=((1LL << (pp - 1)) - 1) + min(1LL << (pp - 1), nn - (1LL << pp) + 1);

    int pp=0;
    ll tmp=nn;
    while((1LL<<pp)<=tmp) {
        tmp -= 1LL<<pp;
        pp++;
    }
    ll ln = (nn-1-tmp)/2;
    if (tmp) {
        ln += min(tmp, 1LL<<(pp-1));
    }

    ll rn = nn-1-ln;
  //  cout<<"ln="<<ln<<" "<<rn<<endl;
    auto ls = dfs(ln);
    auto rs = dfs(rn);
    //if (nn==7) cout<<"??"<<endl;
    vector<vector<int>> res(128, {0, 0});
    for (int i = 0; i < ls.size(); ++i) {
        for (int i2 = 0; i2 < rs.size(); ++i2) {
            if (i+i2+2<128) res[i+i2+2][0] = (res[i+i2+2][0] + (int)((ll)ls[i][1]*(ll)rs[i2][1]%mod2)) % mod2;
        }
    }

    for (int i = 0; i < ls.size(); ++i) {
        res[i][0] = (res[i][0]+ls[i][0])%mod2;
        res[i][0] = (res[i][0]+ls[i][1])%mod2;
        if (i+1<res.size()) res[i+1][1] = (res[i+1][1] + ls[i][1])%mod2;
    }
    for (int i = 0; i < rs.size(); ++i) {
        res[i][0] = (res[i][0]+rs[i][0])%mod2;
        res[i][0] = (res[i][0]+rs[i][1])%mod2;
        if (i+1<res.size()) res[i+1][1] = (res[i+1][1] + rs[i][1])%mod2;
    }
    res[0][1] = (res[0][1]+1) % mod2;
   // cout<<"nn="<<nn<<endl;
    return mp[nn] = res;
}
int main() {
//  cout<<std::log(2, 3)<<" "<<std::log(2,4)<<endl;
  for (int i = 1; i <= 100000; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j <= 129; ++j) {
        pw[i][j] = (int)((ll)pw[i][j-1] * (ll)i % mod2);
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld%d", &n, &m);
    //记忆化，千万不能clear！！
    //mp.clear();

    dfs(n);
    ll ans=0LL;
    auto v = mp[n];
    for (int i = 0; i < v.size(); ++i) {
       // cout<<"i="<<i<<endl;
        int len = i;
        if (len+1>n) break;
        int cnt = (v[i][0]+v[i][1]) % mod2;
        int rem = getpw(m, n-(len+1));
        int tot=0;
        for (int mx = 1; mx <= m; ++mx) {
            if (mx == 1) tot += 1;
            else {
                tot = (tot + (int)((ll)((pw[mx][len+1]-pw[mx-1][len+1]+mod2)%mod2)*(ll)mx%mod2)) % mod2;
            }
        }
        tot = (int)((ll)tot * (ll)rem % mod2);
        ans = (ans + (int)((ll)tot * (ll)cnt % mod2)) % mod2;
      //  cout<<"i2="<<i<<endl;
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
