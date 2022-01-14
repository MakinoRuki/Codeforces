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
int n, m, q, k;
int t;
int p[N];
int bit[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  int k1, k2, k3;
  cin>>k1>>k2>>k3;
  vector<int> ks;
  ks.clear();
  ks.push_back(k1);
  ks.push_back(k2);
  ks.push_back(k3);
  sort(ks.begin(), ks.end());
  if (ks[0] == 1) {
    puts("YES");
    return 0;
  }
  if (ks[0] == 2 && ks[1] == 2) {
    puts("YES");
    return 0;
  }
  if (ks[2] > 4) {
    puts("NO");
    return 0;
  }
  int lcm = ks[0];
  for (int i = 1; i < 3; ++i) {
    lcm = lcm * ks[i] / getgcd(lcm, ks[i]);
  }
  for (int x = 0; x < ks[0]; ++x) {
    for (int y = 0; y < ks[1]; ++y) {
      for (int z = 0; z < ks[2]; ++z) {
        bool found=false;
        for (int t = 0; t <= 2*lcm; ++t) {
          if ((t-x)%ks[0] != 0 && (t-y)%ks[1] != 0 && (t-z)%ks[2] != 0) {
            found=true;
            break;
          }
        }
        if (!found) {
          puts("YES");
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
