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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
ll a[N];
ll sum[N];
int idx[N];
struct node {
  int l, r;
  int mx[2];
} tree[N<<2];
int dp[N];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (tree[id].l==tree[id].r) {
    tree[id].mx[0]=-inf;
    tree[id].mx[1]=-inf;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].mx[0] = max(tree[id*2].mx[0], tree[id*2+1].mx[0]);
  tree[id].mx[1] = max(tree[id*2].mx[1], tree[id*2+1].mx[1]);
}
void update(int id, int pos, int v, int p) {
  if (tree[id].l==tree[id].r) {
    tree[id].mx[0] = max(tree[id].mx[0], v+p);
    tree[id].mx[1] = max(tree[id].mx[1], v-p);
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (pos<=mid) update(id*2, pos, v, p);
  else update(id*2+1, pos, v, p);
  tree[id].mx[0] = max(tree[id*2].mx[0], tree[id*2+1].mx[0]);
  tree[id].mx[1] = max(tree[id*2].mx[1], tree[id*2+1].mx[1]);
}
int query(int id, int l, int r, int tp) {
  if (tree[id].l==l && tree[id].r==r) {
    return tree[id].mx[tp];
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r<=mid) return query(id*2, l, r, tp);
  else if (l >mid) return query(id*2+1, l, r, tp);
  else {
    int res1=query(id*2, l, mid, tp);
    int res2=query(id*2+1, mid+1, r, tp);
    return max(res1, res2);
  }
}
int main() {
  cin>>t;
  //mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<ll,int>> rk;
    rk.clear();
    map<ll, int> mp;
    mp.clear();
    sum[0] = 0LL;
    rk.push_back(make_pair(0, 0));
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      sum[i] = sum[i-1]+a[i];
      rk.push_back(make_pair(sum[i], i));
      // a[i] = rnd()%10;
      // if (a[i] != 0) {
      //   int x = rnd()%2;
      //   if (x==0) a[i] *= -1;
      // }
      // cout<<a[i]<<" ";
      // idx[0][i] = -1;
      // idx[1][i] = -1;
      // sum[i] = a[i];
      // len[i] = 1;
      // if (a[i] == 0) len[i] = 0;
      // else if (a[i] < 0) len[i] = -1;
      // par[i] = i;
    }
    sort(rk.begin(), rk.end());
    int cnt=0;
    for (int i = 0; i < rk.size(); ++i) {
      if (i == 0 || rk[i].first != rk[i-1].first) {
        cnt++;
      }
      idx[rk[i].second] = cnt;
    }
    dp[0] = 0;
    build(1, 1, cnt);
    update(1, idx[0], dp[0], 0);
    // cout<<"cnt="<<cnt<<" "<<idx[0]<<endl;
    // cout<<"q="<<query(1, 4, n, 0)<<endl;
    for (int i = 1; i <= n; ++i) {
      int id = idx[i];
      int res = -inf;
      dp[i]=-inf;
     // cout<<"id="<<i<<" "<<id<<endl;
      if (id+1<=cnt) {
        int res=query(1, id+1, cnt, 0);
        if (res>-inf) dp[i]=max(dp[i],res -i);
      }
    //  cout<<"res="<<res<<endl;
      if (1<=id-1) {
        int res=query(1, 1, id-1, 1);
        if (res>-inf) dp[i]=max(dp[i], res+i);
      }
    //  cout<<"res="<<res<<endl;
      if (mp.find(sum[i]) != mp.end()) {
        dp[i]=max(dp[i], mp[sum[i]]);
      }
    //  cout<<"res="<<res<<endl;
      update(1, id, dp[i], i);
      if (mp.find(sum[i]) == mp.end()) {
        mp[sum[i]] = dp[i];
      } else {
        mp[sum[i]] = max(mp[sum[i]], dp[i]);
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
