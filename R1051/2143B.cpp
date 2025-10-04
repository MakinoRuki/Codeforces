
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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &b[i]);
    }
    sort(a+1, a+n+1);
    ll ans=0LL;
    sort(b+1, b+k+1);
    int cur=n;
    for (int i = 1; i <= k; ++i) {
      if (cur - b[i]+1 >= 1) {
        for (int j = cur; j > cur-b[i]; --j) {
          if (j > cur-b[i]+1) ans += a[j];
        }
        cur -= b[i];
      } else {
        break;
      }
    }
    while(cur) {
      ans += a[cur];
      cur--;
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
