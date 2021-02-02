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
int t, n, q;
string s,f;
struct node {
  int l, r;
  int cv;
  int sum;
} tree[N<<2];
void build(int id, int l, int r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l==r) {
    tree[id].cv = (f[l-1]=='1');
    tree[id].sum = (f[l-1] == '1');
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].cv = -1;
  tree[id].sum = tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    if (tree[id].cv>=0) {
      return (r-l+1)*tree[id].cv;
    }
    return tree[id].sum;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (tree[id].cv==1) {
    tree[id*2].cv=1;
    tree[id*2].sum = tree[id*2].r-tree[id*2].l+1;
    tree[id*2+1].cv=1;
    tree[id*2+1].sum = tree[id*2+1].r-tree[id*2+1].l+1;
  } else if (tree[id].cv==0) {
    tree[id*2].cv=0;
    tree[id*2].sum = 0;
    tree[id*2+1].cv=0;
    tree[id*2+1].sum = 0;
  }
  if (r <= mid) {
    return query(id*2, l, r);
  } else if (l > mid) {
    return query(id*2+1, l, r);
  } else {
    return query(id*2, l, mid) + query(id*2+1, mid+1, r);
  }
}
void update(int id, int l, int r, int v) {
  if (tree[id].l==l && tree[id].r == r) {
    tree[id].cv=v;
    tree[id].sum = (r-l+1)*v;
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  if (tree[id].cv==1) {
    tree[id*2].cv=1;
    tree[id*2].sum = tree[id*2].r-tree[id*2].l+1;
    tree[id*2+1].cv=1;
    tree[id*2+1].sum = tree[id*2+1].r-tree[id*2+1].l+1;
  } else if (tree[id].cv==0) {
    tree[id*2].cv=0;
    tree[id*2].sum = 0;
    tree[id*2+1].cv=0;
    tree[id*2+1].sum = 0;
  }
  tree[id].cv=-1;
  if (r <= mid) {
    update(id*2, l, r, v);
  } else if (l > mid) {
    update(id*2+1, l, r, v);
  } else {
    update(id*2, l, mid, v);
    update(id*2+1, mid+1, r, v);
  }
  tree[id].sum = tree[id*2].sum + tree[id*2+1].sum;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    cin>>s>>f;
    build(1, 1, n);
    vector<pair<int,int>> qs;
    qs.clear();
    while(q-->0) {
      int l,r;
      scanf("%d%d", &l, &r);
      qs.push_back(make_pair(l,r));
    }
    reverse(qs.begin(), qs.end());
    bool ok = true;
    for (int i = 0; i < qs.size(); ++i) {
      int l = qs[i].first;
      int r = qs[i].second;
      int res = query(1, l, r);
      int len = r-l+1;
      //cout<<l<<" "<<r<<" "<<len<<" "<<res<<endl;
      if (len%2==0) {
        if (res == len/2) {
          ok=false;
          break;
        } else if (res < len/2) {
          update(1, l, r, 0);
        } else {
          update(1, l, r, 1);
        }
      } else {
        if (res <= len/2) {
          update(1, l, r, 0);
        } else {
          update(1, l, r, 1);
        }
      }
    }
    //cout<<"sum="<<query(1, 1, n)<<endl;
    for (int i = 1; i <= n; ++i) {
      int res=query(1, i, i);
      if (res != s[i-1]-'0') {
        ok=false;
        break;
      }
    }
    if (ok) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
//  set<int> ss;
//  ss.clear();
  // vector<int> vv;
  // vv.clear();
  // for (int i = 1; i <= n; ++i) {
  //   int x;
  //   scanf("%d", &x);
  // //  ss.insert(x);
  //   vv.push_back(x);
  // }
  // int cnt=0;
  // while(cnt<3) {
  //   cnt++;
  //   cout<<"cnt="<<cnt<<" "<<vv.size()<<endl;
  //   int sz=vv.size();
  //   for (int i = 0; i< sz; ++i) {
  //     for (int j = i+1; j< sz; ++j) {
  //       vv.push_back(2*vv[i]-vv[j]);
  //       vv.push_back(2*vv[j]-vv[i]);
  //     }
  //   }
  // }
  // set<int> ss(vv.begin(), vv.end());
  // vector<int> vv2(ss.begin(), ss.end());
  // for (int i = 0; i < vv2.size(); ++i) {
  //   cout<<i<<" "<<vv2[i]<<endl;
  // }
  return 0;
}
