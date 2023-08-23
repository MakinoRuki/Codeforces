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
int b[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(a[i]-b[i], i));
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    ans.clear();
    for (int i = 0; i < v.size(); ++i) {
      if (v[i].first == v.back().first) {
        ans.push_back(v[i].second);
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
