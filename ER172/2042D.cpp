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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
ll k;
int t;
int a[N];
int ans[N];
int cnt;
struct node {
  int l, r;
  int mx;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l==r) {
    tree[id].mx=0;
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1,r);
  tree[id].mx=max(tree[id*2].mx, tree[id*2+1].mx);
}
void update(int id, int p, int v) {
  if (tree[id].l == tree[id].r) {
    tree[id].mx = max(tree[id].mx, v);
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (p <= mid) update(id*2, p, v);
  else update(id*2+1, p, v);
  tree[id].mx=max(tree[id*2].mx, tree[id*2+1].mx);
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].mx;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> sg;
    sg.clear();
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      int l,r;
      scanf("%d%d", &l, &r);
      sg.push_back(make_pair(l, r));
      ss.insert(l);
      ss.insert(r);
    }
    vector<int> v(ss.begin(), ss.end());
    map<int,int> mp;
    mp.clear();
    for (int i = 0; i < v.size(); ++i) {
      mp[v[i]] = i+1;
    }
    cnt = (int)v.size();
    vector<pair<pair<int,int>,int>> vv;
    vv.clear();
    for (int i = 0; i < n; ++i) {
      int l = sg[i].first;
      int r = sg[i].second;
      vv.push_back(make_pair(make_pair(mp[l], -mp[r]), i));
    }
    sort(vv.begin(), vv.end());
    set<int> sr;
    sr.clear();
    build(1, 1, cnt);
    for (int i = 0; i < vv.size(); ++i) {
      int l = vv[i].first.first;
      int r = -vv[i].first.second;
      if (i > 0 && vv[i].first.first == vv[i-1].first.first && vv[i].first.second==vv[i-1].first.second) {
        ans[vv[i].second]=0;
      } else if (i+1<vv.size() && vv[i].first.first == vv[i+1].first.first && vv[i].first.second==vv[i+1].first.second) {
        ans[vv[i].second] = 0;
      } else {
        auto itr = sr.lower_bound(r);
        if (itr == sr.end()) {
          ans[vv[i].second] = 0;
        } else {
          int rr = *itr;
          int ll = query(1, r, cnt);
          if (ll && ll <= rr) {
            int len2 = v[rr-1]-v[ll-1]+1;
            int len1 = v[r-1]-v[l-1]+1;
            if (len2 >= len1) ans[vv[i].second] = len2-len1;
          } else {
            ans[vv[i].second] = 0;
          }
        }
      }
      if (i == 0 || !(vv[i].first.first==vv[i-1].first.first && vv[i].first.second==vv[i-1].first.second)) {
        update(1, r, l);
        sr.insert(r);
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d\n", ans[i]);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

