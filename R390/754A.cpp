#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, h;
int k;
int q;
int a[N];
int main() {
  cin>>n;
  bool found=false;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != 0) found=true;
  }
  if (!found) {
    puts("NO");
  } else {
    vector<pair<int,int>> res;
    res.clear();
    int i = 1;
    while(i <= n) {
      int j = i;
      if (a[i] == 0) {
        while(j <= n && a[j] == 0) j++;
      }
      j++;
      while(j<=n && a[j] == 0) j++;
      res.push_back(make_pair(i, j-1));
      i = j;
    }
    puts("YES");
    printf("%d\n", (int)res.size());
    for (int i = 0; i < res.size(); ++i) {
      printf("%d %d\n", res[i].first, res[i].second);
    }
  }
  return 0;
}
