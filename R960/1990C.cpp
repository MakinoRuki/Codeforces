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
#define N 500005
#define M 505
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
int b[N];
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (ll)a[i];
    }
    map<int,int> cnt;
    cnt.clear();
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
      if (cnt[a[i]] > 1) {
        ss.insert(a[i]);
      }
      if (!ss.empty()) {
        b[i] = (*ss.rbegin());
      } else {
        b[i] = 0;
      }
    }
    int pre=0;
    int num=0;
    for (int i = 1; i <= n; ++i) {
      c[i] = pre;
      if (i == 1 || b[i] != b[i-1]) {
        num=1;
      } else {
        num++;
      }
      if (num > 1) pre = b[i];
    }
    for (int i = n; i >= 1; --i) {
      if (i-1>=1 && b[i]==b[i-1]) {
        tot += (ll)b[i] * (ll)(n-i+1);
      } else if (i+1 <= n && b[i] == b[i+1]) {
        tot += (ll)b[i] * (ll)(n-i+1);
      } else {
        tot += b[i];
        tot += (ll)c[i] * (ll)(n-i);
      }
    }
    printf("%lld\n", tot);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
