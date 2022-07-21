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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> rk;
    rk.clear();
    int n0 = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] > 0) rk.push_back(a[i]);
      else n0++;
    }
    for (int i = 1; i < n; ++i) {
      vector<int> tmp;
      tmp.clear();
      if (n0 > 0) {
        if (rk.size()> 0) {
          tmp.push_back(rk[0]);
        }
        n0--;
      }
      for (int j = 1; j <rk.size(); ++j) {
        tmp.push_back(rk[j]-rk[j-1]);
      }
      sort(tmp.begin(), tmp.end());
      rk.clear();
      for (int j= 0; j < tmp.size(); ++j) {
        if (tmp[j] == 0) n0++;
        else rk.push_back(tmp[j]);
      }
//       cout<<"i="<<i<<" "<<n0<<endl;
//       for (int j = 0; j < rk.size(); ++j) {
//         cout<<rk[j]<<" ";
//       }
//       cout<<endl;
    }
    printf("%d\n", (rk.empty() ? 0 : rk[0]));
  }
  return 0;
}
