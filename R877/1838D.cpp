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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int psum[N];
int ssum[N];
struct node {
  int l, r;
  int pc=0,sc=0;
  int pmx=0,pmn=0;
  int smx=0,smn=0;
} tree[N<<2];
void pushup(int id) {
  tree[id].pmx=max(tree[id*2].pmx, tree[id*2+1].pmx);
  tree[id].pmn=min(tree[id*2].pmn, tree[id*2+1].pmn);
  tree[id].smx=max(tree[id*2].smx, tree[id*2+1].smx);
  tree[id].smn=min(tree[id*2].smn, tree[id*2+1].smn);
}
void pushdown(int id) {
  if (tree[id].pc != 0) {
    tree[id*2].pc += tree[id].pc;
    tree[id*2].pmx += tree[id].pc;
    tree[id*2].pmn += tree[id].pc;
    tree[id*2+1].pc += tree[id].pc;
    tree[id*2+1].pmx += tree[id].pc;
    tree[id*2+1].pmn += tree[id].pc;
    tree[id].pc = 0;
  }
  if (tree[id].sc != 0) {
    tree[id*2].sc += tree[id].sc;
    tree[id*2].smx += tree[id].sc;
    tree[id*2].smn += tree[id].sc;
    tree[id*2+1].sc += tree[id].sc;
    tree[id*2+1].smx += tree[id].sc;
    tree[id*2+1].smn += tree[id].sc;
    tree[id].sc = 0;
  }
}
void build(int id, int l, int r) {
  tree[id].l=l;
  tree[id].r=r;
  if (l == r) {
    tree[id].pc=0;
    tree[id].sc=0;
    tree[id].pmx=tree[id].pmn=psum[l];
    tree[id].smx=tree[id].smn=ssum[l];
    return;
  }
  int mid=(l+r)/2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id].pc=tree[id].sc=0;
  pushup(id);
}
void update(int id, int l, int r, int ps, int dt) {
 // cout<<id<<" "<<l<<" "<<r<<endl;
  if (l == tree[id].l && r == tree[id].r) {
    if (ps > 0) {
      tree[id].pc += dt;
      tree[id].pmx += dt;
      tree[id].pmn += dt;
    } else {
      tree[id].sc += dt;
      tree[id].smx += dt;
      tree[id].smn += dt;
    }
    return;
  }
  int mid=(tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (r <= mid) {
    update(id*2, l, r, ps, dt);
  } else if (l > mid) {
    update(id*2+1, l, r, ps, dt);
  } else {
    update(id*2, l, mid, ps, dt);
    update(id*2+1, mid+1, r, ps, dt);
  }
  pushup(id);
}
int pquery(int id) {
  if (tree[id].l == tree[id].r) {
    return tree[id].l;
  }
  if (tree[id].pmn >= 0) {
    return n+1;
  }
  pushdown(id);
  if (tree[id*2].pmn < 0) {
    return pquery(id*2);
  }
  return pquery(id*2+1);
}
int pmxquery(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].pmx;
  }
  int mid = (tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (r <= mid) {
    return pmxquery(id * 2, l, r);
  } else if (l > mid) {
    return pmxquery(id*2+1, l, r);
  } else {
    return max(pmxquery(id*2, l, mid), pmxquery(id*2+1, mid+1, r));
  }
}
int squery(int id) {
  if (tree[id].l == tree[id].r) {
    return tree[id].l;
  }
  if (tree[id].smx <= 0) {
    return 0;
  }
  pushdown(id);
  if (tree[id*2+1].smx > 0) {
    return squery(id*2+1);
  }
  return squery(id*2);
}
int smnquery(int id, int l, int r) {
  if (tree[id].l == l && tree[id].r == r) {
    return tree[id].smn;
  }
  int mid = (tree[id].l+tree[id].r)/2;
  pushdown(id);
  if (r <= mid) {
    return smnquery(id * 2, l, r);
  } else if (l > mid) {
    return smnquery(id*2+1, l, r);
  } else {
    return min(smnquery(id*2, l, mid), smnquery(id*2+1, mid+1, r));
  }
}
int main() {
  //cout<<pr[4]<<endl;
  cin>>n>>q;
  string s;
  cin>>s;
  psum[0] = 0;
  ssum[n+1]=0;
  for (int i = 1; i <= n; ++i) {
    psum[i] = psum[i-1];
    if (s[i-1] == '(') psum[i]++;
    else psum[i]--;
  }
  for (int i = n; i >= 1; --i) {
    ssum[i] = ssum[i+1];
    if (s[i-1] == '(') ssum[i]++;
    else ssum[i]--;
  }
  build(1, 1, n);
  // for (int i = 1; i <= 25; ++i) {
  //       cout<<"i="<<i<<" "<<tree[i].smx<<endl;
  //     }
  while(q-->0) {
    int x;
    scanf("%d", &x);
    if (n % 2) {
      puts("NO");
      continue;
    }
    if (s[x-1] == '(') {
      update(1, x, n, 1, -2);
      update(1, 1, x, -1, -2);
      s[x-1]=')';
    } else {
      update(1, x, n, 1, 2);
      update(1, 1, x, -1, 2);
      s[x-1] ='(';
    }
    //cout<<"xx="<<tree[1].smx<<endl;
  //  if (q == 8) {
      // for (int i = 1; i <= 25; ++i) {
      //   cout<<"i="<<i<<" "<<tree[i].smx<<endl;
      // }
   // }
   // cout<<"???"<<endl;
    int pid = pquery(1);
   // cout<<"pid="<<pid<<endl;
    if (pid <= n) {
      int pmx = pmxquery(1, 1, pid);
     // cout<<"pmx="<<pmx<<endl;
      if (pmx <= 1) {
        puts("NO");
        continue;
      }
    }
    int sid = squery(1);
   // cout<<"sid="<<sid<<endl;
    if (sid >= 1) {
      int smn = smnquery(1, sid, n);
    //  cout<<"smn="<<smn<<endl;
      if (smn >= -1) {
        puts("NO");
        continue;
      }
    }
    puts("YES");
  }
  return 0;
}
