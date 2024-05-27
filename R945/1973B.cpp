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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
bool check(int k, int bt) {
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        if ((1<<bt) & a[i]) {
            v.push_back(1);
        } else {
            v.push_back(0);
        }
    }
    int cnt=0;
    for (int i = 0; i < k; ++i) {
        cnt += v[i];
    }
    int res=(cnt>0);
    for (int i = k; i < n; ++i) {
        cnt -= v[i-k];
        cnt += v[i];
        int cur=(cnt>0);
        if (cur != res) {
            return false;
        }
    }
    return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
      }
      int ans = 0;
      for (int i = 20; i >= 0; --i) {
          int l = 1, r = n;
          while(l < r) {
              int mid=(l+r)/2;
              if (check(mid, i)) {
                  r = mid;
              } else {
                  l = mid+1;
              }
          }
          ans = max(ans, r);
      }
      printf("%d\n", ans);
  }
  return 0;
}
