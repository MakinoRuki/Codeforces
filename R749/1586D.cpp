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
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int nxt[N];
int pp[N];
int main() {
  cin>>n;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i <= n; ++i) {
    cout<<"?";
    for (int j = 1; j <= n; ++j) {
      if (i == j) printf(" 1");
      else printf(" 2");
    }
    cout<<endl;
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res != 0 && res != i) {
      nxt[res] = i;
    }
    cout<<"?";
    for (int j = 1; j <= n; ++j) {
      if (i == j) printf(" 2");
      else printf(" 1");
    }
    cout<<endl;
    fflush(stdout);
    scanf("%d", &res);
    if (res != 0 && res != i) {
      nxt[i] = res;
    }
  }
  int id = 0;
  for (id = 1; id <= n; ++id) {
    int i;
    for (i = 1; i <= n; ++i) {
      if (nxt[i] == id) break;
    }
    if (i > n) {
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    pp[id] = i;
    id = nxt[id];
  }
  printf("!");
  for (int i = 1; i <= n; ++i) {
    printf(" %d", pp[i]);
  }
  cout<<endl;
  return 0;
}
