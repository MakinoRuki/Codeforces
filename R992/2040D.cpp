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
#define N 200005
#define M 16
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
vector<int> edges[N];
void dfs(int u, int p, int& v) {
    v++;
  //  cout<<"u="<<u<<" "<<v<<endl;
    if (p == 0) {
        a[u] = v;
    } else if (a[p] + 1 == v) {
        a[u] = v;
    } else if (a[p] + 2 == v) {
        v += 2;
        a[u] = v;
    } else {
        int dt = abs(a[p] - v);
        if (dt % 2) {
            v++;
        }
        a[u] = v;
    }
    for (int i = 0; i < edges[u].size(); ++i) {
        int x = edges[u][i];
        if (x == p) continue;
        dfs(x, u, v);
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u,v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int v=0;
    dfs(1, 0, v);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
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

