/*
序列是树的dfs序的条件是，对于u和它的儿子v们，需要满足L[u]<min(L[v]) && R[u]>=max(R[v])。其中L[u],R[u]是u在dfs序中的位置边界。
关于本题，可以用set维护顶点u的儿子们的位置。然后每次改值，其实最多只会影响x,fa[x],y,fa[y]四个位置的值。
*/

#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int idx[N];
//bool vis[N];
int cnt[N];
set<int> son[N];
int calc(int x) {
  // 序列是树的dfs序的条件：每个L[fa[u]]<L[u]&&R[fa[u]]>=R[u]。
  if (son[x].empty()) return 1;
  int mn = *son[x].begin();
  int mx = *son[x].rbegin();
  if (idx[x] < mn && idx[x] + cnt[x]>=mx+cnt[p[mx]]) {
    return 1;
  }
  return 0;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    a[1]=0;
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      cnt[i]=0;
      son[i].clear();
    }
    for (int i = n; i >= 1; --i) {
      cnt[a[i]] += cnt[i]+1;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      idx[p[i]] = i;
      son[a[p[i]]].insert(i);
    }
    int tot=0;
    for (int i = 1; i <= n; ++i) {
      tot += calc(i);
    }
  //  cout<<"tot="<<tot<<endl;
    while(q-->0) {
      int i,j;
      scanf("%d%d", &i, &j);
      int x= p[i];
      int y=p[j];
      set<int> ss;
      ss.clear();
      ss.insert(a[x]);
      ss.insert(a[y]);
      ss.insert(x);
      ss.insert(y);
      for (auto v : ss) {
        if (v) tot -= calc(v);
      }
      son[a[x]].erase(i);
      son[a[y]].erase(j);
      swap(p[i], p[j]);
      swap(idx[x], idx[y]);
      son[a[x]].insert(j);
      son[a[y]].insert(i);
      for (auto v : ss) {
        if (v) tot += calc(v);
      }
      if (tot == n) {
        puts("Yes");
      } else {
        puts("No");
      }
    }
  }
  return 0;
}

