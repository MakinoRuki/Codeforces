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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
ll k;
int t;
string s;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //  scanf("%d", &n);
    cin>>n>>k;
    ll tot=1LL;
    for (int i = 1; i <= n; ++i) {
      tot = tot * 2LL + 1;
    }
    ll cur = n+1;
    for (int i = n; i >= 1; --i) {
      if (k <= tot/2) {
        cur--;
        tot /= 2;
      } else {
        if (k == (tot+1)/2) {
          break;
        }
        k -= (tot+1)/2;
        cur--;
        tot /= 2;
      }
    }
    cout<<cur<<endl;
  //}
  return 0;
}
