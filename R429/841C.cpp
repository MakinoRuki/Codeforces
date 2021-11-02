#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N], b[N];
int ans[N];
int main() {
  cin>>n;
  vector<pair<int,int>> rk1;
  rk1.clear();
  vector<int> rk2;
  rk2.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk2.push_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    rk1.push_back(make_pair(b[i], i));
  }
  sort(rk1.begin(), rk1.end());
  sort(rk2.begin(), rk2.end());
  for (int i = 0; i < rk1.size(); ++i) {
    ans[rk1[i].second] = rk2[n-1-i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
