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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok=false;
    set<int> ss;
    ss.clear();
    int cur=n;
    int sum=0;
    int i;
    for (i = 1; i <= k; ++i) {
      if (a[cur] > n) {
        break;
      }
      if (ss.find(cur) != ss.end()) {
        ok=true;
        break;
      }
      ss.insert(cur);
      sum = (sum + a[cur]) % n;
      cur = n - sum;
    }
    if (i > k) ok=true;
    // int cur=0;
    // int x=n;
    // int cnt=0;
    // while(true) {
    //   if (cnt > k) break;
    //   if (ss.find(x) != ss.end()) {
    //     ok=true;
    //     break;
    //   }
    //   if (a[x] > n) {
    //     break;
    //   }
    //   if (cnt == k) {
    //     ok=true;
    //     break;
    //   }
    //   ss.insert(x);
    //   cur = (cur + a[x]) % n;
    //   x = n-cur;
    //   cnt++;
    // }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
