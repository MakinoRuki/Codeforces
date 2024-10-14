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
#include <stack>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    int cur = 1;
    set<int> ss;
    ss.clear();
    bool ok=true;
    for (int i = 1; i <= m; ++i) {
      if (cur <= n && b[i] == a[cur]) {
        ss.insert(a[cur]);
        cur++;
      } else if (ss.find(b[i]) != ss.end()) {
        continue;
      } else {
        ok=false;
        break;
      }
    }
    if (ok) puts("YA");
    else puts("TIDAK");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

