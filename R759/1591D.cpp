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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
int id[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[i] = false;
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    bool found=false;
    for (int i = 0; i < rk.size(); ++i) {
      id[rk[i].second] = i+1;
      if (i > 0 && rk[i].first == rk[i-1].first) {
        found=true;
      }
    }
    if (found) {
      puts("YES");
      continue;
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        int cur=i;
        int len=0;
        while(true) {
          if (id[cur] != i) {
            len++;
            cur = id[cur];
            vis[cur] = true;
          } else {
            break;
          }
        }
        vis[i] = true;
        len++;
        if (len > 1) {
          if (len % 2 == 0) {
            cnt++;
          }
        }
      }
    }
    if (cnt % 2 == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
