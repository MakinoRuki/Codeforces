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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
struct node {
    int l, r;
    int cnt;
    int cnt2;
    int sum;
} tree[N<<2];
vector<pair<int,int>> sg[N];
void build(int id, int l, int r) {
    tree[id].l=l;
    tree[id].r=r;
    tree[id].cnt=0;
    tree[id].cnt2=0;
    tree[id].sum=0;
    if (l == r) { 
        return;
    }
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}
void pushup(int id) {
    if (tree[id].cnt > 0) {
        tree[id].sum = tree[id].r-tree[id].l;
    } else {
        tree[id].sum = tree[id*2].sum+tree[id*2+1].sum;
        if (tree[id].cnt2) tree[id].sum++;
        tree[id].sum = min(tree[id].sum, tree[id].r-tree[id].l);
    }
}
void update(int id, int l, int r, int dt) {
    if (tree[id].l == l && tree[id].r == r) {
        tree[id].cnt += dt;
        pushup(id);
        return ;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if (r <= mid) {
        update(id*2, l, r, dt);
    } else if (l > mid) {
        update(id*2+1, l, r, dt);
    } else {
        update(id*2, l, mid, dt);
        update(id*2+1, mid+1, r, dt);
        tree[id].cnt2 += dt;
    }
    pushup(id);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2*n; ++i) {
        sg[i].clear();
    }
    build(1, 1, 2*n);
    for (int i = 1; i <= m; ++i) {
        int x,y;
        scanf("%d%d", &x, &y);
        update(1, x, y, 1);
        sg[x].push_back(make_pair(x, y));
    }
    int ans=tree[1].sum;
    for (int i = 1; i < n; ++i) {
        auto v = sg[i];
        for (auto pr : v) {
            int x=pr.first;
            int y=pr.second;
            update(1, x, y, -1);
            update(1, y, n+x, 1);
            sg[y].push_back(make_pair(y, n+x));
        }
        ans = min(ans, tree[1].sum);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

