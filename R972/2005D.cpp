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
#define M 16
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
map<pair<int,int>,ll> dp[2];
int pa[N], pb[N];
int getgcd(int x, int y) {
    return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = n; i >= 1; --i) {
        if (i == n) {
            pa[i] = a[i];
            pb[i] = b[i];
        } else {
            pa[i] = getgcd(pa[i+1], a[i]);
            pb[i] = getgcd(pb[i+1], b[i]);
        }
    }
    dp[0].clear();
    dp[1].clear();
    dp[0][make_pair(a[1], b[1])]++;
    dp[1][make_pair(b[1], a[1])]++;
    int ag = 0;
    ll ac = 0LL;
    for (int i = 1; i < n; ++i) {
        map<pair<int,int>, ll> tmp[2];
        tmp[0].clear();
        tmp[1].clear();
       // if (i==3) cout<<"v="<<dp[1][make_pair(1,2)]<<endl;
        for (int j = 0; j < 2; ++j) {
            for (auto itr : dp[j]) {
                int g1 = itr.first.first;
                int g2 = itr.first.second;
                ll cnt = itr.second;
                int g11 = getgcd(g1, a[i+1]);
                int g12 = getgcd(g1, b[i+1]);
                int g21 = getgcd(g2, a[i+1]);
                int g22 = getgcd(g2, b[i+1]);
                if (j == 0) {
                    tmp[0][make_pair(g11, g22)] += cnt;
                    tmp[1][make_pair(g12, g21)] += cnt;
                } else {
                    tmp[1][make_pair(g12, g21)] += cnt;
                    int x = getgcd(g1, pa[i+1]);
                    int y = getgcd(g2, pb[i+1]);
                    if (x + y > ag) {
                        ag = x+y;
                        ac = cnt;
                       // cout<<"i="<<i<<" "<<ag<<" "<<ac<<endl;
                    } else if (x + y == ag) {
                        ac += cnt;
                    }
                }
            }
        }
        dp[0] = tmp[0];
        dp[1] = tmp[1];

    }
    for (auto itr : dp[1]) {
        int x = itr.first.first;
        int y = itr.first.second;
        ll cnt = itr.second;
        if (x + y > ag) {
            ag = x+y;
            ac = cnt;
        } else if (x+y == ag) {
            ac += cnt;
        }
    }
    printf("%d %lld\n", ag, ac);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

