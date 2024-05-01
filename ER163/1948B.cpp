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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ans;
    ans.clear();
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      if (a[i] < 10) {
        ans.push_back(a[i]);
      } else {
        int x=a[i]/10;
        int y=a[i]%10;
        if (x > y) {
          ans.push_back(a[i]);
        } else {
          if (ans.empty() || x >= ans.back()) {
            ans.push_back(x);
            ans.push_back(y);
          } else {
            ans.push_back(a[i]);
          }
        }
      }
    }
    if (ok) {
      for (int i = 1; i < ans.size(); ++i) {
        if (ans[i] < ans[i-1]) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
