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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
int main() {
  cin>>n>>q;
  map<int, int> mp;
  mp.clear();
  int tot = 0;
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &l, &r, &k);
    if (k == 1) {
      int l1 = l, r1 = r;
      auto itr = mp.lower_bound(l);
      if (itr != mp.begin()) {
        auto itr2 = itr;
        itr2--;
        if (itr2->second >= l) {
          tot -= itr2->second-itr2->first+1;
          l1 = min(l1, itr2->first);
          r1 = max(r1, itr2->second);
          mp.erase(itr2);
        }
      }
      while(itr!= mp.end()) {
        if (itr->first <= r1) {
          tot -= itr->second - itr->first+1;
          l1 = min(l1, itr->first);
          r1 = max(r1, itr->second);
          mp.erase(itr++);
        } else {
          break;
        }
      }
      tot += r1-l1+1;
      mp[l1] = r1;
    } else {
      auto itr = mp.lower_bound(l);
      if (itr != mp.begin()) {
        auto itr2 = itr;
        itr2--;
        if (itr2->second >= l) {
          if (r >= itr2->second) {
            int det = itr2->second-l+1;
            tot -= det;
            itr2->second = l-1;
            if (itr2->second < itr2->first) {
              mp.erase(itr2);
            }
          } else {
            tot -= r-l+1;
            int l1 = itr2->first;
            int r1 = itr2->second;
            mp.erase(itr2);
            if (l1 <= l-1) {
              mp[l1] = l-1;
            }
            if (r+1 <= r1) {
              mp[r+1] = r1;
            }
          }
        }
      }
      while(itr!= mp.end()) {
        if (itr->second <= r) {
          tot -= itr->second - itr->first+1;
          mp.erase(itr++);
        } else if (itr->first <= r) {
          int det = r - itr->first +1;
          tot -= det;
          int r2 = itr->second;
          mp.erase(itr);
          mp[r+1] = r2;
          break;
        } else {
          break;
        }
      }
    }
    printf("%d\n", n-tot);
  }
  return 0;
}
