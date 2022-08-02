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
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> sg;
    sg.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sg.push_back(make_pair(a[i]-m, a[i]+m));
    }
    int tot=0;
    int b = 0, e = 0;
    for (int i = 0; i < sg.size(); ++i) {
      if (i == 0) {
        b = sg[i].first;
        e = sg[i].second;
        tot++;
      } else if (sg[i].first <= e && sg[i].second>=b) {
        b = max(b, sg[i].first);
        e = min(e, sg[i].second);
      } else {
        b = sg[i].first;
        e = sg[i].second;
        tot++;
      }
    }
    printf("%d\n", tot-1);
  }
  return 0;
}
