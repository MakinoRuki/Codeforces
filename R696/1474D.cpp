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
#include <random>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
const ll inf2 = 1000000000000000LL;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int a[N];
ll b[N];
struct node {
  int l, r;
  ll minv;
} tree[2][N<<2];
void build(int id, int idx, int l, int r) {
  tree[id][idx].l=l;
  tree[id][idx].r=r;
  if (l==r) {
    if (id == l%2) {
      tree[id][idx].minv=b[l];
    } else {
      tree[id][idx].minv=inf2;
    }
    return;
  }
  int mid=(l+r)/2;
  build(id, idx*2, l, mid);
  build(id, idx*2+1, mid+1, r);
  tree[id][idx].minv=min(tree[id][idx*2].minv, tree[id][idx*2+1].minv);
}
ll query(int id, int idx, int l, int r) {
  if (tree[id][idx].l == l && tree[id][idx].r==r) {
    return tree[id][idx].minv;
  }
  int mid=(tree[id][idx].l+tree[id][idx].r)/2;
  if (r<=mid) return query(id, idx*2, l, r);
  else if (l>mid) return query(id, idx*2+1, l, r);
  else {
    return min(query(id,idx*2, l, mid), query(id,idx*2+1, mid+1, r));
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
      if (i==1) b[i] = a[i];
      else b[i] = (ll)a[i] - b[i-1];
    }
    build(0, 1, 1, n);
    build(1, 1, 1, n);
    // build(0, 1, 1, n);
    // build(1, 1, 1, n);
    bool found=false;
    ll res1=query(0, 1, 1, n);
    ll res2=query(1, 1, 1, n);
    if (res1>=0 && res2>=0 && b[n]==0) {
      found=true;
    }
    if (found) {
      cout<<"YES"<<endl;
      continue;
    }
    for (int i = 1; i < n; ++i) {
      if (i > 1) {
        if (query(0, 1, 1, i-1) < 0 || query(1, 1, 1, i-1)<0) {
          continue;
        }
      }
      ll res0=query(0, 1, i+1, n);
      ll res1=query(1, 1, i+1, n);
      if (b[i] - (ll)a[i] + (ll)a[i+1] >= 0) {
        ll det1=-2*(ll)a[i+1]+2*(ll)a[i];
        ll det2=2*(ll)a[i+1]-2*(ll)a[i];
        // if (((i%2 == n%2) && b[n]+det2==0)) || () {
        // }
        if (i % 2) {
          if (res0+det1>=0 && res1+det2>=0) {
            if ((n%2 && b[n]+det2==0)||(n%2==0 && b[n]+det1==0)) {
              found=true;
              break;
            }
          }
        } else {
          if (res1+det1>=0 && res0+det2>=0) {
            if ((n%2==0 && b[n]+det2==0)||(n%2 && b[n]+det1==0)) {
              found=true;
              break;
            }
          }
        }
      }
    }
    if (found) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
