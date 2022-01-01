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
#define N 500000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, q, k;
int a[N];
int idx[N];
int dp[N];
ll sum[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
int query(int id) {
  if (id <= 0) return 0;
  int res = 0;
  while(id > 0) {
    res = max(res, bit[id]);
    id -= lowbit(id);
  }
  return res;
}
void update(int id, int v) {
  while(id <= n) {
    bit[id] = max(bit[id], v);
    id += lowbit(id);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0] = 0LL;
    bit[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      bit[i] = 0;
      // a[i] = rand()%10;
      // cout<<a[i]<<" ";
    }
    int x; //= rand() % 10;
    // cout<<endl;
    // cout<<x<<endl;
    scanf("%d", &x);
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i] - x;
      sum[i] = sum[i-1] + (ll)a[i];
    }
    // vector<pair<int,int>> sg;
    // sg.clear();
    // int bg = -1;
    // for (int i = 1; i <= n; ++i) {
    //   if (a[i] >= 0) {
    //     if (bg < 0) bg = i;
    //   } else {
    //     if (bg >= 1) {
    //       sg.push_back(make_pair(bg, i-1));
    //     }
    //     bg = -1;
    //   }
    // }
    // if (bg >= 1) {
    //   sg.push_back(make_pair(bg, n));
    // }
    // int ans=0;
    // for (int i = 0; i < sg.size(); ++i) {

    // }
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= 0) {
        if (pre <= 0) idx[i] = 1;
        else {
          if (a[pre] + a[pre+1] >= 0) {
            idx[i] = idx[pre];
          } else {
            idx[i] = pre+1;
          }
        }
      } else {
        if (pre <= 0) {
          if (i-1>=1 && a[i-1] + a[i] >= 0) {
            idx[i] = idx[i-1];
          } else {
            idx[i] = i;
          }
        } else {
          if (pre == i-1) {
            idx[i] = i;
          } else if (a[i] + a[i-1] <0) {
            idx[i] = i;
          } else {
            if (a[pre] + a[pre+1] >= 0 && sum[i] - sum[pre-1] >= 0) {
              idx[i] = idx[pre];
            } else {
              idx[i] = pre+1;
            }
          }
        }
        pre = i;
      }
     // cout<<i<<" "<<idx[i]<<endl;
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      int pre = idx[i];
      dp[i] = 1;
      dp[i] = max(dp[i], query(pre-2) + i-pre+1);
      ans=max(ans, dp[i]);
      update(i, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
