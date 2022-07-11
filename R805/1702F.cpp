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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> v1;
    vector<pair<int,int>> v2;
    v1.clear();
    v2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[i] = false;
      int x = a[i];
      while(x%2==0) {
        x/=2;
      }
      v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      int x = b[i];
      while(x) {
        if (x&1) v2.push_back(make_pair(x, i));
        x/=2;
      }
    }
    sort(v2.begin(), v2.end());
    bool ok=true;
    int j = v2.size()-1;
    for (int i = v1.size()-1; i >= 0; --i) {
      bool found = false;
      while(j >= 0 && v2[j].first >= v1[i]) {
        if (v2[j].first == v1[i] && !vis[v2[j].second]) {
          found=true;
          vis[v2[j].second] = true;
          break;
        }
        j--;
      }
      if (!found) {
        ok=false;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
