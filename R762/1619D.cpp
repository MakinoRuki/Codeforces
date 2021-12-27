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
#define N 100005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
ll x;
ll p[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%lld", &p[i * n + j]);
      }
    }
    ll l = 0, r = 1000000000;
    while(l < r) {
      ll mid = (l+r+1)/2;
  //   cout<<l<<" "<<r<<endl;
      bool found=false;
      for (int i = 0; i < n; ++i) {
        vis[i] = false;
      }
      int tot=0;
      for (int i = 0; i < m; ++i) {
        int cnt=0;
        for (int j = 0; j < n; ++j) {
          if (p[i*n+j] >= mid) {
            if (!vis[j]) {
              vis[j] = true;
              tot++;
            }
            cnt++;
          }
        }
        if (cnt >= 2) {
          found=true;
        }
      }
      if (!found || tot < n) {
        r = mid-1;
      } else {
        l = mid;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
