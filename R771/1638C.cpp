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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int p[N];
int id[N];
int mn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      id[p[i]] = i;
    }
    int cnt=0;
    for (int i = n; i >= 1; --i) {
      if (i == n) {
        mn[i] = i;
      } else {
        mn[i] = mn[i+1];
        if (p[i] < p[mn[i]]) {
          mn[i] = i;
        }
      }
    }
    set<int> ss;
    ss.clear();
    int x = 1;
    int cur=1;
    for (int i = 1; i <= n; ++i) {
      if (ss.empty() || i > (*ss.rbegin())) {
        cnt++;
        ss.clear();
      }
      int y = id[i];
      while(cur <= y) {
        ss.insert(p[cur]);
        cur++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
