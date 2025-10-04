
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
#define M 305
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
bool vis[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d%d", &l, &r);
    n = r;
    for (int i = 0; i <= n; ++i) {
      a[i] = i;
      vis[i]=false;
    }
    ll ans=0LL;
    for (int i = n; i >= 0; --i) {
      for (int x = 30; x >= 0; --x) {
        ll y = (1LL<<x)-1;
        if ((y ^ i)<=n && !vis[y^i]) {
          a[i] = y^i;
          vis[a[i]] = true;
          ans += y;
          break;
        }
      }
    }
    printf("%lld\n", ans);
    for (int i = 0; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
