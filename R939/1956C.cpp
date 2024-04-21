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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    int c=1, r=2;
    int tp=2;
    for (int i = 1; i < 2*n; ++i) {
      if (i%2) {
        v.push_back(make_pair(tp, c));
        for (int i = 1; i <= n; ++i) {
          a[i][c] = n+1-i;
        }
        c++;
      } else {
        v.push_back(make_pair(tp, r));
        for (int j = 1; j <= n; ++j) {
          a[r][j] = n+1-j;
        }
        r++;
      }
      tp = 3-tp;
    }
    int ans=0;
    for (int i= 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ans += a[i][j];
      }
    }
    printf("%d %d\n", ans, 2*n-1);
    for (int i = 0; i < v.size(); ++i) {
      printf("%d %d", v[i].first, v[i].second);
      for (int j = n; j >= 1; --j) {
        printf(" %d", j);
      }
      cout<<endl;
    }
  }
  return 0;
}
