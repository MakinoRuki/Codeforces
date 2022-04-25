#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int st = -1;
    int ed = -1;
    int cnt=0;
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i= 1; i <= n; ++i) {
      if (i == 1 || a[i] == a[i-1]) {
        cnt++;
      } else {
        if (cnt > 1) {
          rk.push_back(make_pair(i-cnt, i-1));
        }
        cnt = 1;
      }
    }
    if (cnt > 1) {
      rk.push_back(make_pair(n+1-cnt, n));
    }
    if (rk.empty()) {
      puts("0");
    } else {
      int bg = rk[0].first;
      int ed = rk.back().second;
      if (ed - bg+1 <= 2) {
        puts("0");
      } else if (ed -bg+1 <= 3) {
        puts("1");
      } else {
        int len = ed-bg+1-2;
        printf("%d\n", len-1);
      }
    }
  }
  return 0;
}
