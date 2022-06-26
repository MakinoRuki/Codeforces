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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int pmn[N];
int smn[N];
int pmx[N];
int smx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int id1 = 0, idn = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 1) id1 = i;
      if (a[i] == n) idn = i;
    }
    if (n == 1) {
      puts("0");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      pmn[i] = i;
      pmx[i] = i;
      if (i > 1) {
        if (a[pmn[i-1]] < a[pmn[i]]) pmn[i] = pmn[i-1];
        if (a[pmx[i-1]] > a[pmx[i]]) pmx[i] = pmx[i-1];
      }
    }
    for (int i = n; i >= 1; --i) {
      smx[i] = i;
      smn[i] = i;
      if (i < n) {
        if (a[smx[i+1]] > a[smx[i]]) smx[i] = smx[i+1];
        if (a[smn[i+1]] < a[smn[i]]) smn[i] = smn[i+1];
      }
    }
    // for (int i = idn; i <= n; ++i) {
    //   cout<<"i="<<i<<" "<<smx[i]<<" "<<smn[i]<<endl;
    // }
    int ans = 1;
    if (id1 < idn) {
      int cur = id1;
      bool f = false;
      while(cur > 1) {
     //   cout<<"cur="<<cur<<endl;
        ans++;
        if (!f) cur = pmx[cur-1];
        else cur = pmn[cur-1];
        f = !f;
      }
      cur = idn;
      f = false;
      while(cur < n) {
      //  cout<<"cur2="<<cur<<" "<<f<<endl;
        ans++;
        if (!f) cur = smn[cur+1];
        else cur = smx[cur+1];
        f = !f;
      }
    } else {
      int cur = idn;
      bool f = false;
      while(cur > 1) {
        ans++;
        if (!f) cur = pmn[cur-1];
        else cur = pmx[cur-1];
        f = !f;
      }
      cur= id1;
      f = false;
      while(cur < n) {
        ans++;
        if (!f) cur = smx[cur+1];
        else cur = smn[cur+1];
        f = !f;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
