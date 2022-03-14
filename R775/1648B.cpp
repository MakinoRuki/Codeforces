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
#define M 202
#define N 1000005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
bool vis[N];
int idx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int c;
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= c; ++i) {
      vis[i] = false;
    }
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[a[i]] = true;
    }
    sort(a+1, a+n+1);
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 || a[i] != a[i-1]) {
        rk.push_back(a[i]);
      }
    }
    bool ok = true;
    if (!vis[1]) {
      puts("No");
      continue;
    }
    int j = rk.size();
    for (int i = c; i >= 1; --i) {
      if (i == c) idx[i] = rk.size();
      else idx[i] = idx[i+1];
      while(j-1 >= 0 && rk[j-1] >= i) {
        j--;
      }
      idx[i] = j;
      //cout<<"i="<<i<<" "<<idx[i]<<endl;
    }
    for (int i = 0; i < rk.size() - 1; ++i) {
      for (int j = 2; j < c/rk[i]; ++j) {
        auto id1 = idx[j * rk[i]];
        auto id2 = idx[(j+1) * rk[i]];
        id2--;
        if (id1 <= id2) {
          if (!vis[j]) {
            ok=false;
            break;
          }
        }
      }
      int id = idx[c/rk[i] * rk[i]];
      if (id < rk.size()) {
        if (!vis[c/rk[i]]) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
