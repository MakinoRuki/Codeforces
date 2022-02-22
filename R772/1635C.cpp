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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    if (a[n-1] > a[n]) {
      puts("-1");
    } else {
      vector<pair<int, pair<int,int>>> ans;
      ans.clear();
      bool ok = true;
      for (int i = n-2; i >= 1; --i) {
        if (a[i] > a[i+1]) {
          a[i] = a[i+1] - a[n];
          if (a[i] > a[i+1]) {
            ok=false;
            break;
          }
          ans.push_back(make_pair(i, make_pair(i+1, n)));
        }
      }
      if (!ok) puts("-1");
      else {
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); ++i) {
          printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
        }
      }
    }
  }
  return 0;
}
