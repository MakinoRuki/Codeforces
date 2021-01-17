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
#define N 500002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, c;
int a[N];
int cnt[N];
vector<int> cnt2[N];
int main() {
  cin>>n>>c;
  memset(cnt, 0, sizeof(cnt));
  int tot=0;
  for (int i = 1; i<= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    if (a[i] ==c) {
      tot++;
    } else {
      cnt2[a[i]].push_back(cnt[a[i]]-cnt[c]);
    }
  }
  int ans=tot;
  for (int i = 1; i <= 500000; ++i) {
    if (cnt2[i].size() > 0) {
      int maxv = 0;
      int pre=0;
      for (int j = 0; j < cnt2[i].size(); ++j) {
        if (j == 0) {
          maxv = max(maxv, 1);
          pre = cnt2[i][j];
        } else {
          maxv = max(maxv, cnt2[i][j]-pre+1);
          pre = min(pre, cnt2[i][j]);
        }
      }
      ans = max(ans, tot+maxv);
    }
  }
  cout<<ans<<endl;
  return 0;
}
