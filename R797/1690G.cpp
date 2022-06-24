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
#define N 100005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<int> ss;
    for (int i = 1; i <= n; ++i) {
      // if (stk.empty() || a[i] < a[stk.back()]) {
      //   stk.push_back(i);
      // }
      if (ss.empty() || a[i] < a[*ss.rbegin()]) {
        ss.insert(i);
      }
    }
    int ans = (int)ss.size();
    int cnt;
    vector<int> res;
    res.clear();
    for (int i = 1; i <= m; ++i) {
      int d;
      scanf("%d%d", &k, &d);
      auto itr = ss.upper_bound(k);
      itr--;
      int id = *itr;
      a[k] -= d;
      if (k!=id && a[k] >= a[id]) {
        res.push_back(ans);
        //printf("%d\n", ans);
        continue;
      }
      if (k!=id) ans++;
      auto itr2 = itr;
      itr2++;
      while(itr2 != ss.end() && a[*itr2]>=a[k]) {
      //  if (i == 3) cout<<"v="<<(*itr2)<<endl;
        ss.erase(itr2++);
        ans--;
      }
      ss.insert(k);
      res.push_back(ans);
      //printf("%d\n", ans);
    }
    for (int i = 0; i < res.size(); ++i) {
      printf("%d", res[i]);
      if (i < res.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
