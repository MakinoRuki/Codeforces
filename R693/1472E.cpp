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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
vector<pair<pair<int,int>,int>> hwv;
int hw[N], wh[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    hwv.clear();
    for (int i = 1; i <= n; ++i) {
      ans[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
      int h,w;
      scanf("%d%d", &h, &w);
      hwv.push_back(make_pair(make_pair(h, w),i+1));
    }
    sort(hwv.begin(), hwv.end());
    for (int i = 1; i <= n; ++i) {
      hw[i] = i;
      if (i > 1) {
        int id=hw[i-1];
        if (hwv[id-1].first.second < hwv[i-1].first.second) {
          hw[i] = id;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      int l = 0, r = n;
      while(l < r) {
        int mid=(l+r+1)/2;
        if (hwv[mid-1].first.first < hwv[i-1].first.first) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      if (r > 0 && hwv[hw[r]-1].first.second < hwv[i-1].first.second) {
        ans[hwv[i-1].second] = hwv[hw[r]-1].second;
      }
    }
  //  cout<<ans[2]<<endl;
    for (int i = 0; i < n; ++i) {
      swap(hwv[i].first.first, hwv[i].first.second);
    }
    sort(hwv.begin(), hwv.end());
    for (int i = 1; i <= n; ++i) {
      hw[i] = i;
      if (i > 1) {
        int id=hw[i-1];
        if (hwv[id-1].first.second < hwv[i-1].first.second) {
          hw[i] = id;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      int l = 0, r = n;
      while(l < r) {
        int mid=(l+r+1)/2;
        if (hwv[mid-1].first.first < hwv[i-1].first.second) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
      if (r > 0 && hwv[hw[r]-1].first.second < hwv[i-1].first.first) {
        ans[hwv[i-1].second] = hwv[hw[r]-1].second;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", ans[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
