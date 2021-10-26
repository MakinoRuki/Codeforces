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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
int cnt[40];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] > 0) {
        found=true;
      }
    }
    if (!found) {
      for (int i = 1; i <= n; ++i) {
        printf("%d", i);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
      continue;
    }
    for (int i = 0; i <= 31; ++i) {
      cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 30; ++j) {
        if ((1LL<<j) & a[i]) {
          cnt[j]++;
        }
      }
    }
    int g = -1;
    for (int i = 0; i <= 30; ++i) {
      if (cnt[i] > 0) {
        if (g < 0) g = cnt[i];
        else {
          g = getgcd(g, cnt[i]);
        }
      } 
    }
    vector<int> ps;
    ps.clear();
    for (int i = 1; i * i <= g; ++i) {
      if (g % i == 0) {
        ps.push_back(i);
        if (g/i != i) {
          ps.push_back(g/i);
        }
      }
    }
    sort(ps.begin(), ps.end());
    for (int i = 0; i <ps.size(); ++i) {
      printf("%d", ps[i]);
      if (i < ps.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
