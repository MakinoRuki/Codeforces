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
#define N 500005
#define M 1502
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
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok=true;
    for (int i = 1; i <= 5; ++i) {
      int i2 = i-1;
      if ((1<<i2) > n) break;
      vector<int> v;
      v.clear();
      for (int j = (1<<i2)+1; j <= min((1<<i),n); ++j) {
        v.push_back(a[j]);
      }
      sort(v.begin(), v.end());
      int k = 0;
      for (int j = (1<<i2) +1; j <= min(n,(1<<i)); ++j) {
        if (v[k++] != a[j]) {
         // cout<<i<<" "<<k<<" "<<v[k-1]<<" "<<a[j]<<endl;
          ok=false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
