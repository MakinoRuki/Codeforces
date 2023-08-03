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
#define N 500005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
ll a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
      cnt[i] = 0;
    }
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
      scanf("%lld", &a[i]);
    }
    bool found=false;
    for (int i = 1; i < n; ++i) {
      if (a[i]-a[i-1] > 2*n) {
        found=true;
        break;
      }
    }
    if (found) {
      puts("NO");
      continue;
    }
    cnt[a[1]]++;
    for (int i = 2; i < n; ++i) {
      cnt[a[i]-a[i-1]]++;
    }
    vector<int> v0;
    vector<int> v1;
    v0.clear();
    v1.clear();
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] == 0) {
        v0.push_back(i);
      } else {
        if (cnt[i] > 1) {
          for (int j = 1; j < cnt[i]; ++j) {
            v1.push_back(i);
          }
        }
      }
    }
    for (int i = n+1; i <= 2*n; ++i) {
      if (cnt[i]) {
        for (int j = 1; j <= cnt[i]; ++j) {
          v1.push_back(i);
        }
      }
    }
   // cout<<v0.size()<<" "<<v1.size()<<" "<<v0[0]<<" "<<v0[1]<<" "<<v1[0]<<endl;
    if (v0.size() == 1 && v1.empty()) {
      puts("YES");
    } else if (v0.size() == 2 && v1.size() == 1 && v1[0]==v0[0]+v0[1]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
