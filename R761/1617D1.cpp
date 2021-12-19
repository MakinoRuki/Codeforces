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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n-2; i++) {
      printf("? %d %d %d\n", i, i+1, i+2);
      fflush(stdout);
   //   int res;
      scanf("%d", &a[i]);
    }
    int id0, id1;
    for (int i = 2; i <= n-2; ++i) {
      if (a[i] != a[i-1]) {
        id0 = i;
        id1 = i+1;
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == id0 || i == id1) {
        continue;
      }
      printf("? %d %d %d\n", i, id0, id1);
      fflush(stdout);
   //   int res;
      scanf("%d", &ans[i]);
    }
    int idx0 = -1, idx1 = -1;
    for (int i = 1; i <= n; ++i) {
      if (i == id0 || i == id1) continue;
      if (ans[i] == 1 && idx1<0) idx1= i;
      if (ans[i] == 0 && idx0<0) idx0 = i;
    }
    printf("? %d %d %d\n", idx0, idx1, id0);
    fflush(stdout);
 //   int res;
    scanf("%d", &ans[id0]);
    printf("? %d %d %d\n", idx0, idx1, id1);
    fflush(stdout);
 //   int res;
    scanf("%d", &ans[id1]);
    vector<int> ans2;
    ans2.clear();
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == 0) ans2.push_back(i);
    }
    printf("! %d", (int)ans2.size());
    for (int i = 0; i < ans2.size(); ++i) {
      printf(" %d", ans2[i]);
    }
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
