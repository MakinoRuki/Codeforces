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
#define M 1002
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
map<ll, vector<int>> mp;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll s,x;
    mp.clear();
    scanf("%d%lld%lld", &n, &s, &x);
    ll sum=0;
    mp[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    ll ans=0LL;
    int id=-1;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (a[i] > x) {
            mp.clear();
            id=-1;
        } else {
            if (a[i] == x) id=i;
            if (id>=0 && mp.count(sum-s)) {
                // 不用reference会被卡常
                auto& v = mp[sum-s];
                int j = upper_bound(v.begin(), v.end(), id-1)-v.begin()-1;
                if (j >= 0) {
                    ans += j+1;
                }
            }
        }
        mp[sum].push_back(i);
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
