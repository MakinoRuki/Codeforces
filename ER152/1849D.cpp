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
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
bool mk[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mk[i] = false;
  }
  vector<int> v;
  v.clear();
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      if (mx > 0) {
        v.push_back(mx);
      }
      v.push_back(0);
      mx = 0;
    } else {
      mx = max(mx, a[i]);
    }
  }
  if (mx > 0) {
    v.push_back(mx);
  }
  // for (int i = 0; i < v.size(); ++i) {
  //   cout<<"i="<<i<<" "<<v[i]<<endl;
  // }
  int ans=0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] > 0) ans++;
    else mk[i] = true;
  }
  //cout<<"ans="<<ans<<endl;
  for (int i = 0; i < v.size(); ++i) {
    if (mk[i]) {
      if (i > 0 && v[i-1] > 0) {
        continue;
      }
      if (i < v.size()-1 && v[i+1] > 0) {
        v[i+1]--;
        continue;
      }
     // cout<<"i="<<i<<" "<<ans<<endl;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
