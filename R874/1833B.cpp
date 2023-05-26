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
#define M 22
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
int b[N];
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<pair<int,int>> rk1;
    vector<pair<int,int>> rk2;
    rk2.clear();
    rk1.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk1.push_back(make_pair(a[i], i));
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      rk2.push_back(make_pair(b[i], i));
    }
    sort(rk1.begin(), rk1.end());
    sort(rk2.begin(), rk2.end());
    for (int i = 0; i < n; ++i) {
      c[rk1[i].second] = b[rk2[i].second];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", c[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
