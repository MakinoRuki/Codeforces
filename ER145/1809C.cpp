#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 5005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int num;
int ans[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    ll dt = n*(n+1)/2-k;
    for (int i = 1; i <= n; ++i) {
      ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      if (dt <= n+1-i) {
        ans[i] = -dt;
        if (i+dt<=n) {
          ans[i+dt] = 2;
        }
        break;
      } else {
        ans[i] = -1000;
        dt -= n+1-i;
      }
    }
    for (int i =1; i <= n; ++i) {
      printf("%d", ans[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
