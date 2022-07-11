#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 500005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    // for (int i = 1; i <= n; ++i) {
    //   c[i] = i;
    // }
  //  do {
      // for (int i = 1; i <= n; ++i) {
      //   cout<<c[i]<<" ";
      //   b[i] = i/c[i];
      // }
      // cout<<endl;
      // for (int i = 1; i <= n; ++i) {
      //   cout<<b[i]<<" ";
      // }
      // cout<<endl;
      vector<pair<pair<int,int>,int>> rk;
      rk.clear();
      set<int> ss;
      ss.clear();
      for (int i = 1; i <= n; ++i) {
        ss.insert(i);
      }
      for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        if (b[i] == 0) {
          rk.push_back(make_pair(make_pair(inf, i/(b[i]+1)+1), i));
        } else {
          rk.push_back(make_pair(make_pair(i/b[i], i/(b[i]+1)+1), i));
        }
      }
      sort(rk.begin(), rk.end());
      for (int i= 0; i < rk.size(); ++i) {
        int l = rk[i].first.second;
        int r = rk[i].first.first;
        auto itr = ss.lower_bound(l);
        a[rk[i].second] = *itr;
        ss.erase(*itr);
      }
      for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
      
      // bool ok = true;
      // for (int i = 1; i <= n; ++i) {
      //   if (i/a[i] != b[i]) {
      //     ok=false;
      //     break;
      //   }
      // }
      // if (!ok) cout<<"!!!"<<endl;
      // cout<<endl;
   // } while(next_permutation(c+1, c+n+1));
  }
  return 0;
}
