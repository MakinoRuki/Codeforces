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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i < v.size(); ++i) {
        ll x = v[0].first;
        while(x < v[i].first) {
            x *= 2LL;
        }
        if (x > v[0].first) ans.push_back(make_pair(v[i].second, x-v[i].first));
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}

