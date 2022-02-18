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
int a[N];
int b[N];
int oc[N], ec[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, vector<int>> ids;
    ids.clear();
    map<int, int> cur;
    cur.clear();
    oc[0] = 0;
    ec[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      oc[0] = 0;
      ec[0] = 0;
      b[i] = a[i];
      ids[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
      cur[a[i]] = 0;
    }
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) {
      oc[i] = oc[i-1];
      ec[i] = ec[i-1];
      if (a[i]%2) oc[i]++;
      else ec[i]++;
    }
    int c0 = 0, c1 = 0;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      int id = ids[b[i]][cur[b[i]]];
      int cnt1 = ec[id-1] - c0;
      int cnt2 = oc[id-1] - c1;
      if (b[i] % 2) {
        if (cnt2 != 0) {
          ok=false;
          break;
        }
        c1++;
        cur[b[i]]++;
      } else {
        if (cnt1 != 0) {
          ok=false;
          break;
        }
        c0++;
        cur[b[i]]++;
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
