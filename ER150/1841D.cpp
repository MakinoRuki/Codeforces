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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
vector<pair<int,int>> sg;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sg.clear();
    for (int i = 1; i <= n; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      sg.push_back(make_pair(r, l));
    }
    sort(sg.begin(), sg.end());
    int ans=0;
    int pre=-1;
    int cur=0;
    int id=-1;
    for (int i = 0; i < sg.size(); ++i) {
      if (sg[i].second <= pre) {
        ans++;
        continue;
      }
      if (!cur) {
        id=i;
        cur = !cur;
      } else {
        if (sg[i].second <= sg[id].first && sg[id].second <= sg[i].first) {
          cur = 0;
          pre = sg[i].first;
        } else {
          id=i;
          ans++;
        }
      }
    }
    if (cur) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
