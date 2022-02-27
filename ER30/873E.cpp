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
#define N 3005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int dp[N][15];
int ans[N];
vector<pair<int,int>> rk;
int query(int l, int r) {
  int len = r-l+1;
  int pw=0;
  while((1<<pw) <= len) {
    pw++;
  }
  pw--;
  int id1 = dp[l][pw];
  int id2 = dp[r-(1<<pw)+1][pw];
  int d1 = (id1 == n ? rk[id1-1].first : rk[id1-1].first - rk[id1].first);
  int d2 = (id2 == n ? rk[id2-1].first : rk[id2-1].first - rk[id2].first);
  if (d1 >= d2) return id1;
  return id2;
}
int main() {
  cin>>n;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  reverse(rk.begin(), rk.end());
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= 12; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dp[j][i-1] >= 0 && (j + (1<<(i-1))) <= n && dp[j+(1<<(i-1))][i-1] >= 0) {
        int idx = dp[j][i-1];
        int idy = dp[j+(1<<(i-1))][i-1];
        int x = (idx < n ? rk[idx-1].first - rk[idx].first : rk[idx-1].first);
        int y = (idy < n ? rk[idy-1].first - rk[idy].first : rk[idy-1].first);
      //  if (j == 3 && i == 1) cout<<idx<<" "<<idy<<" "<<x<<" "<<y<<endl;
        dp[j][i] = (x >= y ? idx : idy);
      }
    }
  }
//  cout<<"dp="<<dp[3][1]<<endl;
  int id1 = 0, id2 = 0, id3 = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int c1 = i;
      int c2 = j - i;
      if (c1 > 2*c2 || c2 > 2*c1) continue;
      int l = max(1, max((c1+1)/2, (c2+1)/2));
      int r = min(n-j, min(c1, c2) * 2);
      if (j + l <= j + r) {
        int id = query(j + l, j + r);
     //   if (j+l==3 && j+r==4) cout<<"id="<<id<<endl;
       // if (id == -1) cout<<"x="<<j<<" "<<l<<" "<<r<<endl;
        if (id1 == 0 || rk[i-1].first - rk[i].first > rk[id1-1].first - rk[id1].first) {
          id1 = i;
          id2 = j;
          id3 = id;
        } else if (rk[i-1].first - rk[i].first == rk[id1-1].first - rk[id1].first && (id2 == 0 || rk[j-1].first-rk[j].first > rk[id2-1].first-rk[id2].first)) {
          id1 = i;
          id2 =j;
          id3 = id;
        } else if (rk[i-1].first-rk[i].first==rk[id1-1].first-rk[id1].first && rk[j-1].first-rk[j].first==rk[id2-1].first-rk[id2].first) {
          int det = (id == n ? rk[id-1].first : rk[id-1].first - rk[id].first);
          if (id3 == 0 || det > rk[id3-1].first-rk[id3].first) {
            id1=i;
            id2=j;
            id3 = id;
          }
        }
      }
    }
  }
//  cout<<id1<<" "<<id2<<" "<<id3<<endl;
  for (int i = 1; i <= n; ++i) {
    int id = rk[i-1].second;
    if (i <= id1) ans[id] = 1;
    else if (i <= id2) ans[id] = 2;
    else if (i <= id3) ans[id] = 3;
    else ans[id] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
