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
ll p[N];
ll d[N];
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &d[i]);
    }
    scanf("%d", &q);
    while(q-->0) {
        ll cur=0LL;
        scanf("%lld", &cur);
        ll pre=0;
        ll tm = 0LL;
        bool dr = true;
        map<pair<ll,ll>, int> mp;
        mp.clear();
        bool ok=false;
        for (int i = 1; i <= n; ++i) {
            if (p[i] == cur && d[i] == 0) {
                dr = false;
                break;
            }
        }
        while(true) {
            bool found=false;
            if (dr) {
                for (int i = 1; i <= n; ++i) {
                    if (p[i] > cur) {
                        ll dt= p[i]-cur;
                        if ((tm + dt)%k == d[i]) {
                            tm += dt;
                            dr = !dr;
                            found=true;
                            pre=cur;
                            cur = p[i];
                            break;
                        }
                    }
                }
            } else {
                for (int i = n; i >= 1; --i) {
                    if (p[i] < cur) {
                        ll dt = cur-p[i];
                        if ((tm + dt) % k == d[i]) {
                            tm += dt;
                            dr = !dr;
                            found=true;
                            pre = cur;
                            cur = p[i];
                            break;
                        }
                    }
                }
            }
            if (!found) {
                ok=true;
                break;
            }
            if (mp.find(make_pair(pre, cur)) != mp.end()) {
                break;
            }
            mp[make_pair(pre, cur)]++;
        }
        if (ok) puts("Yes");
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
