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
#define N 1000006
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
bool vis[N];
int ans[N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[i] = false;
    }
    if (n == 1) {
      puts("-1");
      continue;
    }
    bool ok=true;
    set<int> ss;
    for (int i =1; i <= n; ++i) {
      ss.insert(i);
    }
    for (int i =1; i <= n; ++i) {
      // int j;
      // for (j = 1; j <= n; ++j) {
      //   if (!vis[j] && j != a[i]) {
      //     break;
      //   }
      // }
      // if (j > n) {
      //   ok=false;
      //   break;
      // }
      // vis[j] = true;
      // ans[i] = j;
      if (i < n-1) {
        if (a[i] != (*ss.begin())) {
          ans[i] = *ss.begin();
          ss.erase(ans[i]);
        } else {
          auto x = *ss.begin();
          ss.erase(x);
          ans[i] = *ss.begin();
          ss.erase(ans[i]);
          ss.insert(x);
        }
      } else {
        if (a[i] == *ss.begin()) {
          auto x = *ss.begin();
          ss.erase(x);
          ans[i] = *ss.begin();
          ss.erase(ans[i]);
          ss.insert(x);
        } else {
          auto x = *ss.begin();
          ss.erase(x);
          if (a[n] == *ss.begin()) {
            ans[i] = *ss.begin();
            ss.erase(ans[i]);
            ss.insert(x);
          } else {
            ans[i] = x;
          }
        }
      }
    }
    if (!ok) {
      puts("-1");
    } else {
      for (int i =1; i <= n; ++i) {
        printf("%d", ans[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
