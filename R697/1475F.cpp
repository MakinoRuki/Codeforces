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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
vector<string> a;
vector<string> b;
vector<int> edges[N];
int col[2*N];
bool rec[2*N][2*N];
bool dfs(int u, int c) {
  if (col[u] >= 0) {
    return col[u] == c;
  }
  col[u] = c;
  if (u > n) {
    for (int i = 1; i <= n; ++i) {
      if (rec[i][u]) {
        if (!dfs(i, !c)) return false;
      } else {
        if (!dfs(i, c)) return false;
      }
    }
  } else {
    for (int i = n+1; i <= 2*n; ++i) {
      if (rec[u][i]) {
        if (!dfs(i, !c)) return false;
      } else {
        if (!dfs(i, c)) return false;
      }
    }
  }
  return true;
}
// bool check() {
//   for (int i = 1; i <= n; ++i) {
//     for (int j = 1; j <= n; ++j) {
//       if (a[i-1][j-1] != b[i-1][j-1]) {
//         if (col[i] == col[j+n]) return false;
//       } else {
//         if (col[i] != col[j+n]) return false;
//       }
//     }
//   }
//   return true;
// }
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    a.clear();
    b.clear();
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      a.push_back(s);
      edges[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      b.push_back(s);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i-1][j-1] != b[i-1][j-1]) {
          // edges[i].push_back(j+n);
          // edges[j+n].push_back(i);
          rec[i][j+n] = 1;
        } else {
          rec[i][j+n] = 0;
        }
      }
    }
    for (int i = 1; i <= 2*n; ++i) {
      col[i] = -1;
    }
    if (dfs(1, 0)) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
    // bool ok = true;
    // if (dfs(1, 0) && check()) {
    //   cout<<"YES"<<endl;
    //   continue;
    // }
    // for (int i = 1; i <= 2*n; ++i) {
    //   col[i] = -1;
    // }
    // if (dfs(1, 1) && check()) {
    //   cout<<"YES"<<endl;
    //   continue;
    // }
    // cout<<"NO"<<endl;
  }
  return 0;
}
