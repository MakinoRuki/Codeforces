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
#define M 21
#define N 50005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t,q;
vector<int> res[N];
bool check(int x, int y) {
  int cnt=0;
  for (int j = 1; j <= 5; ++j) {
    if (res[x][j-1] < res[y][j-1]) {
      cnt++;
    }
  }
  return cnt>=3;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int id = 1;
    for (int i = 1; i <= n; ++i) {
      res[i].clear();
      for (int j = 1; j <= 5; ++j) {
        int x;
        scanf("%d", &x);
        res[i].push_back(x);
      }
    }
    for (int i = 2; i <= n; ++i) {
      if (check(i, id)) {
        id = i;
      }
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      if (i == id) continue;
      if (!check(id ,i)) {
        ok=false;
        break;
      }
    }
    if (ok) printf("%d\n", id);
    else puts("-1");
  }
  return 0;
}
