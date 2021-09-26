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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int cnt[N];
int main() {
  cin>>n>>k;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  int l = 1, r = n;
  while(l < r) {
    int mid=(l+r+1)/2;
    int tot=0;
    for (int i = 1; i < N; ++i) {
      if (cnt[i] > 0) {
        tot += cnt[i]/mid;
      }
    }
    if (tot >= k) {
      l = mid;
    } else {
      r = mid-1;
    }
  }
  vector<int> ans;
  ans.clear();
  for (int i = 1; i < N; ++i) {
    if (ans.size() >= k) break;
    if (cnt[i] > 0) {
      int num = cnt[i]/r;
      for (int j = 1; j <= num; ++j) {
        ans.push_back(i);
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    printf("%d", ans[i]);
    if (i < k-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
