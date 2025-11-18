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
#define N 400005
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
int amx[N], amn[N];
int bmx[N], bmn[N];
vector<int> v[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
        v[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        amx[i] = a[i];
        amn[i] = a[i];
        if (i-1>=1) {
            amx[i] = max(amx[i], amx[i-1]);
            amn[i] = min(amn[i], amn[i-1]);
        }
    }
    for (int i = n; i >= 1; --i) {
        bmx[i] = b[i];
        bmn[i] = b[i];
        if (i+1<=n) {
            bmx[i] = max(bmx[i], bmx[i+1]);
            bmn[i] = min(bmn[i], bmn[i+1]);
        }
    }
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        int l1=amn[i],r1=amx[i];
        int l2=bmn[i],r2=bmx[i];
        int l=min(l1,l2);
        int r=max(r1,r2);
        v[l].push_back(r);
        mp[r]++;
    }
    ll ans=0LL;
    for (int i = 1; i <= 2*n; ++i) {
        if (!mp.empty()) {
            auto itr = *mp.begin();
            int r= itr.first;
            ans += 2*n-r+1;
            for (auto x : v[i]) {
                mp[x]--;
                if (mp[x] == 0) mp.erase(x);
            }
        }
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
