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
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      cin>>s;
      for (int j = 0; j < m; ++j) {
        a[i*m+j] = s[j]-'0';
      }
    }
    vector<vector<int>> ans;
    ans.clear();
    bool ok = true;
    for (int i = n-1; i >= 0; --i) {
      for (int j = m-1; j >= 0; --j) {
        if (a[i * m + j]) {
          if (j-1>=0) {
            ans.push_back({i+1, j, i+1, j + 1});
          } else if (i-1>=0) {
            ans.push_back({i, j+1, i+1, j+1});
          } else {
            ok=false;
            break;
          }
        }
      }
    }
    if (!ok) {
      puts("-1");
    } else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
      }
    }
  }
  return 0;
}
