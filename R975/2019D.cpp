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
#include <stack>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      v.push_back(make_pair(i+1-a[i], a[i]+i-1));
    }
    sort(v.begin(), v.end());
    int l = max(1, v[0].first);
    int r = min(v[0].second, n);
    bool ok = true;
    for (int i = 1; i < v.size(); ++i) {
      int nl = v[i].first;
      int nr = v[i].second;
      if (nl > r || nr < l) {
        ok=false;
        break;
      }
      l = max(l, nl);
      r = min(r, nr);
    }
    v.clear();
    for (int i = 1; i <= n; ++i) {
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    int ll = n+1, rr = 0;
    for (auto pr : v) {
      ll = min(ll, pr.second);
      rr = max(rr, pr.second);
      if (rr-ll+1 > pr.first) {
        ok=false;
        break;
      }
    }
    if (!ok) puts("0");
    else printf("%d\n", r-l+1);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

