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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> v0, v1;
    v0.clear();
    v1.clear();
    int mx=0,mn=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx=max(mx, a[i]);
      mn=min(mn, a[i]);
      if (a[i] >= 0) {
        v1.push_back(a[i]);
      } else {
        v0.push_back(a[i]);
      }
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    ll sum=0LL;
    int j0=0,j1=0;
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      if (sum >= 0) {
        if ((j1 < v1.size() && sum + v1[j1] < mx-mn) || j0>=v0.size()) {
          sum += v1[j1];
          ans[i] = v1[j1];
          j1++;
        } else {
          sum += v0[j0];
          ans[i] = v0[j0];
          j0++;
        }
      } else {
        if ((j0 < v0.size() && abs(sum + v0[j0]) < mx-mn) || j1>=v1.size()) {
          sum += v0[j0];
          ans[i] = v0[j0];
          j0++;
        } else {
          sum += v1[j1];
          ans[i] = v1[j1];
          j1++;
        }
      }
      if (abs(sum) >= mx-mn) {
        ok=false;
        break;
      }
    }
    if (!ok) puts("No");
    else {
      puts("Yes");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    }
  }
  return 0;
}
