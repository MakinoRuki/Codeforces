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
#define M 60
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
int sum[N];
struct node {
  int l, r;
  ll g;
} tree[N<<2];
vector<pair<int,int>> v;
ll getgcd(ll x, ll y) {
  return y== 0 ? x : getgcd(y, x%y);
}
bool check(ll x) {
  while((x%2) ==0){
    x/=2;
  }
  return x==1;
}
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l==r) {
    tree[id].g = abs(v[l].first-v[l-1].first);
    return;
  }
  int mid = (l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].g = getgcd(tree[id*2].g, tree[id*2+1].g);
}
ll query(int id, int l, int r) {
  if (tree[id].l ==l && tree[id].r == r) {
    return tree[id].g;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (r <= mid) return query(id*2, l, r);
  else if (l > mid) return query(id*2+1, l, r);
  else {
    return getgcd(query(id*2, l, mid), query(id*2+1, mid+1, r));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (v.empty() || a[i] != v.back().first) {
        v.push_back(make_pair(a[i], 1));
      } else {
        v.back().second++;
      }
    }
    for (int i = 0; i < v.size(); ++i) {
      sum[i] = v[i].second;
      if (i > 0) {
        sum[i] += sum[i-1];
      }
    }
    if (v.size()== 1) {
      printf("%lld\n", (ll)n*(ll)(n+1)/2);
      continue;
    }
    ll ans=0LL;
    build(1, 1, (int)v.size()-1);
    int l = 0;
    for (int r = 0; r < v.size(); ++r) {
     // cout<<"rr="<<r<<endl;
      while(l < r) {
        ll res = query(1, l+1, r);
     //   cout<<"l="<<l<<" "<<res<<endl;
        if (check(res)) {
          l++;
        } else {
          break;
        }
      }
      ll dt = sum[r]-sum[r-1];
      ans += dt*(dt+1)/2;
      if (l > 0) {
        l--;
        ans += (ll)(sum[r]-sum[r-1]) * (ll)sum[l];
      }
     // cout<<"r="<<r<<" "<<ans<<" "<<l<<endl;
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

