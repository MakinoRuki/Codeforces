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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int sum[N];
int nxt[N];
int dp[N];
int dp2[N][20];
struct node {
  int l, r;
  int mx;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l == r) {
    tree[id].mx = sum[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].mx=max(tree[id*2].mx, tree[id*2+1].mx);
}
int query(int l, int r) {
 // cout<<"lr="<<l<<" "<<r<<endl;
  // if (tree[id].l == tree[id].r) {
  //   return tree[id].mx;
  // }
  // int mid=(tree[id].l+tree[id].r)/2;
  // if (r <= mid) {
  //   return query(id*2, l ,r);
  // } else if (l > mid) {
  //   return query(id*2+1, l, r);
  // } else {
  //   return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
  // }
  int len=r-l+1;
  int pw=0;
  while((1<<pw)<=len) {
    pw++;
  }
  pw--;
//  cout<<pw<<endl;
  return max(dp2[l][pw], dp2[r-(1<<pw)+1][pw]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    // for (int i = 0; i <= n + 2; ++i) {
    //   bit[i] = 0;
    // }
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1];
      if (s[i-1] == '(') sum[i]++;
      else sum[i]--;
    }
    build(1, 1, n);
    for (int i = 0; i < 20; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp2[j][i] = -1;
      }
    }
    for (int i = 0; i < 20; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == 0) {
          dp2[j][i] = sum[j];
        } else {
          dp2[j][i] = dp2[j][i-1];
          if (j+(1<<(i-1)) <= n) {
            dp2[j][i] = max(dp2[j][i], dp2[j+(1<<(i-1))][i-1]);
          }
        }
      }
    }
   // cout<<"x"<<endl;
    ll ans=0LL;
    for (int i = 0; i <= n; ++i) {
      nxt[i] = n+1;
      dp[i] = 0;
    }
    for (int i = n; i >= 0; --i) {
      if (nxt[sum[i]] >= n+ 1) {
        dp[i] = 0;
      } else {
        if (i + 1 <= nxt[sum[i]]) {
          int mx = query(i+1, nxt[sum[i]]);
         // cout<<"i="<<i<<endl;
          // cout<<"x="<<i+1<<" "<<nxt[sum[i]]<<" "<<mx<<endl;
          // if (i == 1) cout<<"i="<<i<<" "<<sum[i]
          // if (i == 0) {
          //   cout<<"x="<<i+1<<" "<<nxt[sum[i]]<<" "<<mx<<endl;
          // }
          if (2*sum[i] >= mx) {
            dp[i] = dp[nxt[sum[i]]]+1;
          } else {
            dp[i] = 0;
          }
        } else {
          dp[i] = 0;
        }
      }
      nxt[sum[i]] = i;
     // cout<<"i="<<i<<" "<<dp[i]<<endl;
      ans += dp[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
