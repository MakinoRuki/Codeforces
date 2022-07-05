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
#define eps 1e-8
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  ll b, q, l;
  cin>>b>>q>>l>>m;
  set<int> ss;
  ss.clear();
  for (int i =1; i <= m; ++i) {
    scanf("%d", &a[i]);
    ss.insert(a[i]);
  }
  if (b == 0) {
    if (ss.find(0) != ss.end()) {
      puts("0");
    } else {
      puts("inf");
    }
  } else if (q == 0) {
    if (abs(b) > l) {
      puts("0");
    } else {
      if (ss.find(0) == ss.end()) {
        puts("inf");
      } else {
        if (ss.find(b) == ss.end()) {
          puts("1");
        } else {
          puts("0");
        }
      }
    }
  } else if (abs(q) == 1) {
    if (abs(b) > l) {
      puts("0");
    } else {
      if (q == 1) {
        if (ss.find(b) != ss.end()) {
          puts("0");
        } else {
          puts("inf");
        }
      } else {
        if (ss.find(b) != ss.end() && ss.find(-b) != ss.end()) {
          puts("0");
        } else {
          puts("inf");
        }
      }
    }
  } else {
    ll cur = b;
    int tot = 0;
    while(abs(cur) <= l) {
      if (ss.find(cur) == ss.end()) {
        tot++;
      }
      if (abs(cur)>1000000000 || abs(q) >1000000000) break;
      cur = cur * (ll)q;
    }
    printf("%d\n", tot);
  }
  return 0;
}
