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
#define N 100005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
bool isprime[N];
vector<int> ps;
int main() {
  memset(isprime, true, sizeof(isprime));
  ps.clear();
  for (int i = 2; i < N; ++i) {
    if (isprime[i]) {
      ps.push_back(i);
      for (int j = i; j < N; j += i) {
        isprime[j] = false;
      }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<int> ss;
    ss.clear();
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      int x = a[i];
      for (auto p : ps) {
        if (x % p == 0) {
          if (ss.find(p) != ss.end()) {
            found=true;
            break;
          }
          ss.insert(p);
          while(x % p == 0) x/=p;
        }
      }
      if (x >1) {
        if (ss.find(x) != ss.end()) {
          found=true;
          break;
        }
        ss.insert(x);
      }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
