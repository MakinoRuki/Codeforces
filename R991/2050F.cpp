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
    int l,r;
    int g;
} tree[N<<2];
int getgcd(int x, int y) {
    return y == 0 ? x : getgcd(y, x%y);
}
void build(int id, int l, int r) {
    tree[id].l=l;
    tree[id].r=r;
    if (l == r) {
        tree[id].g = abs(a[l+1]-a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id].g = getgcd(tree[id*2].g, tree[id*2+1].g);
}
int query(int id, int l, int r) {
    if (tree[id].l==l && tree[id].r==r) {
        return tree[id].g;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if (r<=mid) return query(id*2, l, r);
    else if (l > mid) return query(id*2+1, l, r);
    else {
        return getgcd(query(id*2, l, mid), query(id*2+1, mid+1, r));
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n > 1) build(1, 1, n-1);
    vector<int> ans;
    ans.clear();
    while(q-->0) {
        int l,r;
        scanf("%d%d", &l, &r);
        if (l == r) ans.push_back(0);
        else {
           int res = query(1, l, r-1);
           ans.push_back(res); 
        }
    }
    for (int  i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

