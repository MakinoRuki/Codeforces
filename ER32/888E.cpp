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
#define M 500005
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<int> getres(int l, int r) {
  int det = r-l+1;
  vector<int> res;
  res.clear();
  for (int i = 0; i < (1<<det); ++i) {
    int cur=0;
    for (int j = 0; j < det; ++j) {
      if ((1<<j) & i) {
        cur = (cur + a[l+j]) % m;
      }
    }
    res.push_back(cur);
  }
  return res;
}
int main() {
  cin>>n>>m;
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    printf("%d\n", a[1] % m);
    return 0;
  }
  auto v1 = getres(1, n/2);
  auto v2 = getres(n/2+1, n);
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int ans=0;
  for (int i = 0; i < v1.size(); ++i) {
    ans = max(ans, (v1[i] + v2.back())%m);
    auto id = lower_bound(v2.begin(), v2.end(), m-v1[i]) - v2.begin();
    if (id-1>=0) {
      ans = max(ans, (v1[i]+v2[id-1])%m);
    }
  }
  cout<<ans<<endl;
  return 0;
}
